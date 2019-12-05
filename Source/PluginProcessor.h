#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "./libspatialaudio/include/Ambisonics.h"
#include "./FFTConvolver/FFTConvolver.h"
#include <stdexcept>
#include <string>
#include <boost/filesystem.hpp>
//#include <filesystem>

#define AMBISONIC_ORDER_NUMBER 2

#define CONV_BLOCK_SIZE 512


//==============================================================================
/**
*/
const int getOrder[4] = {1, 4, 9, 16};

class AuralizerAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AuralizerAudioProcessor()
    {
        addParameter (wetAmt = new AudioParameterFloat("wetAmt", "Wet", 0.0f, 2.0f, 1.0f));
        addParameter (dryAmt = new AudioParameterFloat("dryAmt", "Dry", 0.0f, 2.0f, 1.0f));

        addParameter (inAmt = new AudioParameterFloat("inAmt", "Input", 0.0f, 2.0f, 1.0f));
        addParameter (outAmt = new AudioParameterFloat("outAmt", "Output", 0.0f, 2.0f, 1.0f));

        addParameter (yawAmt = new AudioParameterFloat("yawAmt", "Yaw", -180.0f, 180.0f, 0.0f));
        addParameter (pitchAmt = new AudioParameterFloat("pitchAmt", "Pitch", -180.0f, 180.0f, 0.0f));
//        addParameter (rollAmt = new AudioParameterFloat("rollAmt", "Roll", -180.0f, 180.0f, 0.0f)); // ROLLTOGGLE
        addParameter (distAmt = new AudioParameterFloat("distanceAmt", "Distance", 0.1f, 100.0f, 5.0f)); // DISTTOGGLE

        addParameter (dirAmt = new AudioParameterFloat("dirAmt", "Direct Level", 0.0f, 2.0f, 1.0f));
        addParameter (earlyAmt = new AudioParameterFloat("earlyAmt", "Early Level", 0.0f, 2.0f, 1.0f));
        addParameter (lateAmt = new AudioParameterFloat("lateAmt", "Late Level", 0.0f, 2.0f, 1.0f));

        formatManager.registerBasicFormats();


        
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

    void setSliderValue(String name, float Value);
    void setNewPresetName(String name){
        new_preset_name = name;
    };
    void setPresetDirectory(String new_preset_directory){
        preset_directory = new_preset_directory;
    }

    void setXmlFileToLoad(juce::File fileToLoad){
        xmlFileToLoad = juce::File(fileToLoad);
    }

private:

    void loadIRs(boost::filesystem::path IRDirPath);
    void updateIRs();

    // buffers
    CBFormat ambi_buffer;
    AudioBuffer<float> Ambi_block;
    AudioBuffer<float> mono_block;
    float* Current_conv_block[2048];

    // ambisonic processors
    CAmbisonicEncoder Encoder;
    CAmbisonicDecoder Decoder;
//    CAmbisonicProcessor Processor;

    PolarPoint position;


    juce::dsp::ProcessorChain<juce::dsp::Convolution> convolutionEngine;
    // add processorDuplicator for convolution
    

    // preset and IR directory system
    String new_preset_name;
    String preset_directory;
    String IR_directory;

    //    std::filesystem::path
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



    unsigned int ir_length;

    // params
    AudioParameterFloat* wetAmt;
    AudioParameterFloat* dryAmt;

    AudioParameterFloat* inAmt;
    AudioParameterFloat* outAmt;

    AudioParameterFloat* yawAmt;
    AudioParameterFloat* pitchAmt;
//    AudioParameterFloat* rollAmt; // ROLLTOGGLE
    AudioParameterFloat* distAmt; // DISTTOGGLE

    AudioParameterFloat* dirAmt;
    AudioParameterFloat* earlyAmt;
    AudioParameterFloat* lateAmt;

    fftconvolver::FFTConvolver *Convolvers[getOrder[AMBISONIC_ORDER_NUMBER]]; // 9-item array of pointers to FFTConvolver objects gives us a pretty smooth way to work with up to 3nd order signals

    



    int _block_size, _sample_rate;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AuralizerAudioProcessor)
};
