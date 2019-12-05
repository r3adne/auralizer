/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class AuralizerAudioProcessorEditor  :  public AudioProcessorEditor,
                                        private Slider::Listener
{
public:
    AuralizerAudioProcessorEditor (AuralizerAudioProcessor&);
    ~AuralizerAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void changePreset();
    void refreshPresets();

private:
    void sliderValueChanged(Slider* slider) override;
    void presetButtonClicked();

public:
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AuralizerAudioProcessor& processor;


    // Sliders
    Slider wetSlider;
    Slider drySlider;

    Slider inSlider;
    Slider outSlider;

    Slider yawSlider;
    Slider pitchSlider;
//    Slider rollSlider;  // ROLLTOGGLE
    Slider distSlider; // DISTTOGGLE

    Slider directSlider;
    Slider earlySlider;
    Slider lateSlider;

    // Labels
    Label wetSliderLabel;
    Label drySliderLabel;

    Label inSliderLabel;
    Label outSliderLabel;

    Label yawSliderLabel;
    Label pitchSliderLabel;

//    Label rollSliderLabel; // ROLLTOGGLE
    Label distSliderLabel; // DISTTOGGLE

    Label directSliderLabel;
    Label earlySliderLabel;
    Label lateSliderLabel;

//    ComboBox PresetsBox;
    TextButton PresetButton;



    // stuff for scaling the size of the enitre window
    float scalex = 2.0f;
    float scaley = 2.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AuralizerAudioProcessorEditor)
};
