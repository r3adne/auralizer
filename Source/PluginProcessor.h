/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "./libspatialaudio/include/Ambisonics.h"

//==============================================================================
/**
*/
class AuralizerAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AuralizerAudioProcessor();
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

private:

    // buffers
//    CBFormat


    // preset and IR directory system
    String new_preset_name;
    String preset_directory;
    String IR_directory;

    // params
    AudioParameterFloat* wetAmt;
    AudioParameterFloat* dryAmt;

    AudioParameterFloat* inAmt;
    AudioParameterFloat* outAmt;

    AudioParameterFloat* yawAmt;
    AudioParameterFloat* pitchAmt;
    AudioParameterFloat* rollAmt;

    AudioParameterFloat* dirAmt;
    AudioParameterFloat* earlyAmt;
    AudioParameterFloat* lateAmt;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AuralizerAudioProcessor)
};
