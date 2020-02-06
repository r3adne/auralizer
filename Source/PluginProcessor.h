#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "./libspatialaudio/include/Ambisonics.h"
#include "./FFTConvolver/FFTConvolver.h"
#include <stdexcept>
#include <string>
#include <boost/filesystem.hpp>
//#include <filesystem>


//#define MONO_TO_MONO
//#define MONO_TO_STEREO
//#define STEREO_TO_STEREO


#define AMBISONIC_ORDER_NUMBER 2

// this is the maximum length of the i/o buffers (and therefore the processing buffers). Most platforms don't run past 4096. Check this if we ever get aax license.
#define MAX_BUFFER_LENGTH 4096

#define CONV_BLOCK_SIZE 512

#define ENCODER_DIST



//==============================================================================
/**
*/
// used to grab the number of channels in an ambisonic signal
const int getOrder[4] = {1, 4, 9, 16};

class AuralizerAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AuralizerAudioProcessor() : parameters(*this, nullptr, Identifier("Auralizer"), {
                       std::make_unique<AudioParameterFloat>("wetAmt", "Wet", NormalisableRange<float>(0.0f, 2.0f), 0.5f),
                       std::make_unique<AudioParameterFloat>("dryAmt", "Dry", NormalisableRange<float>(0.0f, 2.0f), 0.5f),
                       std::make_unique<AudioParameterFloat>("inAmt", "Input", NormalisableRange<float>(0.0f, 2.0f), 0.5f),
                       std::make_unique<AudioParameterFloat>("outAmt", "Output", NormalisableRange<float>(0.0f, 2.0f), 0.5f),
                       std::make_unique<AudioParameterFloat>("yawAmt", "Yaw", NormalisableRange<float>(-180.0f, 180.0f), 0.5f),
                       std::make_unique<AudioParameterFloat>("pitchAmt", "Pitch", NormalisableRange<float>(-90.0f, 90.0f), 0.5f),
                       std::make_unique<AudioParameterFloat>("rollAmt", "Roll", NormalisableRange<float>(-180.0f, 180.0f), 0.5f),
                       std::make_unique<AudioParameterFloat>("distAmt", "Distance", NormalisableRange<float>(0.0f, 50.0f), 0.1f),
                       std::make_unique<AudioParameterFloat>("dirAmt", "Direct Level", NormalisableRange<float>(0.0f, 2.0f), 0.5f),
                       std::make_unique<AudioParameterFloat>("earlyAmt", "Early Level", NormalisableRange<float>(0.0f, 2.0f), 0.5f),
                       std::make_unique<AudioParameterFloat>("lateAmt", "Late Level", NormalisableRange<float>(0.0f, 2.0f), 0.5f)
                       })
    {
        // required to read audio files later...
        formatManager.registerBasicFormats();

        // using new[] here despite potentially it being better to use std::array for this?
        Convolvers = new fftconvolver::FFTConvolver [getOrder[AMBISONIC_ORDER_NUMBER]];


        // we'll use std::arrays for this, but perhaps in the future I'll write a
        // nice wrapper with sbrk() and whatnot which mimics realloc but guarentees
        // that if the new length is smaller than the current one no move happens.



        position.fDistance = 5.0f;
        position.fElevation = 0.0f;
        position.fAzimuth = 0.0f;

        wetAmt      =   parameters.getRawParameterValue("wetAmt");
        dryAmt      =   parameters.getRawParameterValue("dryAmt");
        inAmt       =   parameters.getRawParameterValue("inAmt");
        outAmt      =   parameters.getRawParameterValue("outAmt");
        yawAmt      =   parameters.getRawParameterValue("yawAmt");
        pitchAmt    =   parameters.getRawParameterValue("pitchAmt");
        rollAmt     =   parameters.getRawParameterValue("rollAmt");
        distAmt     =   parameters.getRawParameterValue("distAmt");
        dirAmt      =   parameters.getRawParameterValue("dirAmt");
        earlyAmt    =   parameters.getRawParameterValue("earlyAmt");
        lateAmt     =   parameters.getRawParameterValue("lateAmt");


//        orientation = Orientation(*yawAmt, *pitchAmt, *rollAmt); // yaw, pitch, roll

        processlock = true;

    }

    ~AuralizerAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    bool loadPreset();

//    bool checkBusesLayoutSupported(const BusesLayout&) const override{
//        return true;
//    }

    void setSliderValue(String name, float Value);
    float getSliderValue(String name);
    void setNewPresetName(String name){ new_preset_name = name; };
    void setPresetDirectory(String new_preset_directory){ preset_directory = new_preset_directory; }
    void setXmlFileToLoad(juce::File fileToLoad){ xmlFileToLoad = juce::File(fileToLoad); }


//    float* Current_conv_block;
//    float* Processed_conv_block;

private:
    AudioProcessorValueTreeState parameters;


    void loadIRs(boost::filesystem::path IRDirPath);
    void updateIRs();
    void modifyIRs(AudioBuffer<float> *IR_changed, float new_value,
                                            float previous_value, unsigned long length);

    // buffers
    CBFormat ambi_buffer;
    AudioBuffer<float> Ambi_block;
    AudioBuffer<float> mono_block;
//    AudioBuffer<float> Current_conv_block;
//    float* Current_mono_block;

    

    const float* fullIR_ptr[16];


    // ambisonic processors
    // note: there are still currently different versions of the encoder -- one with and one without distance. Further
    // testing is needed to determine if one is better.
#ifndef ENCODER_DIST
    CAmbisonicEncoder Encoder;
#endif
#ifdef ENCODER_DIST
    CAmbisonicEncoderDist EncoderDist;
#endif
    CAmbisonicDecoder Decoder;
    CAmbisonicProcessor Processor;
//    CAmbisonicZoomer Zoomer;

    PolarPoint position;
//    Orientation orientation;

    // preset and IR directory system
    String new_preset_name = "default_presetSaveName";
    String preset_directory;
    String IR_directory = "~/Documents/auralizer/presets/";

    juce::File xmlFileToLoad;
    juce::File dirIRFile;
    juce::File earlyIRFile;
    juce::File lateIRFile;


    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;

    


    AudioBuffer<float> dirIR;
    AudioBuffer<float> earlyIR;
    AudioBuffer<float> lateIR;
    AudioBuffer<float> fullIR[getOrder[AMBISONIC_ORDER_NUMBER]];



    unsigned int ir_length = 10000;
    bool processlock = true;
    float previousValue = 1.0f;
    bool ConvolverActive[getOrder[AMBISONIC_ORDER_NUMBER]];

    // params

    // There's a world in which we're using atomic for this, and it might come soon. It's on Juce develop branch.
    // But honeslty, I'm not sure it's necessary. I need to look into it more, but only one thread writes to these,
    // and it would be difficult for this to cause an actual problem. Currently, this won't work as
    // std::atomic<float>* cannot be assigned to float*, and float* is what parameters.getRawParameterValue() returns.
    // Maybe this will work better with std::atomic_ref in c++20.

//    std::atomic<float>* wetAmt = nullptr;
//    std::atomic<float>* dryAmt = nullptr;
//
//    std::atomic<float>* inAmt  = nullptr;
//    std::atomic<float>* outAmt = nullptr;
//
//    std::atomic<float>* yawAmt   = nullptr;
//    std::atomic<float>* pitchAmt = nullptr;
//    std::atomic<float>* rollAmt  = nullptr;
//    std::atomic<float>* distAmt = nullptr;
//
//    std::atomic<float>* dirAmt = nullptr;
//    std::atomic<float>* earlyAmt = nullptr;
//    std::atomic<float>* lateAmt = nullptr;

    float* wetAmt = nullptr;
    float* dryAmt = nullptr;
    float* inAmt = nullptr;
    float* outAmt = nullptr;
    float* yawAmt = nullptr;
    float* pitchAmt = nullptr;
    float* rollAmt = nullptr;
    float* distAmt = nullptr;
    float* dirAmt = nullptr;
    float* earlyAmt = nullptr;
    float* lateAmt = nullptr;


    std::array<float, MAX_BUFFER_LENGTH> Current_mono_block;
    std::array<float, MAX_BUFFER_LENGTH> Processed_conv_block;
    std::array<float, MAX_BUFFER_LENGTH> Current_conv_block;

    // maybe make this std::array<FFTConvolver> ?
    fftconvolver::FFTConvolver *Convolvers;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AuralizerAudioProcessor)
};
