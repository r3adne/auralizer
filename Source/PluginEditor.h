/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

#define NUM_SLIDERS 11
#define NUM_LABELS 11



typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;



//==============================================================================
/**
*/

class AuralizerAudioProcessorEditor  :  public AudioProcessorEditor,
                                        private Slider::Listener
{
public:
    AuralizerAudioProcessorEditor (AuralizerAudioProcessor& p, AudioProcessorValueTreeState& vts);
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
    AudioProcessorValueTreeState& valueTreeState;






    // Sliders
    Slider wetSlider;
    Slider drySlider;

    Slider inSlider;
    Slider outSlider;

    Slider yawSlider;
    Slider pitchSlider;
    Slider rollSlider;  // ROLLTOGGLE
    Slider distSlider; // DISTTOGGLE

    Slider directSlider;
    Slider earlySlider;
    Slider lateSlider;

    String vstids[NUM_SLIDERS] = {"wetAmt", "dryAmt", "inAmt", "outAmt",
                                "yawAmt", "pitchAmt", "rollAmt", "distAmt",
                                "dirAmt", "earlyAmt", "lateAmt"};


//    std::unique_ptr<SliderAttachment> wetAttachment, dryAttachment, inAttachment, outAttachment,
//                                      yawAttachment, pitchAttachment, rollAttachment, distAttachment,
//                                        directAttachment, earlyAttachment, lateAttachment;

    Slider* Sliders[NUM_SLIDERS] = {&wetSlider, &drySlider, &inSlider, &outSlider,
                            &yawSlider, &pitchSlider, &rollSlider, &distSlider,
                            &directSlider, &earlySlider, &lateSlider};

    std::unique_ptr<SliderAttachment> SliderAttachments[NUM_SLIDERS];

    // Labels
    Label wetSliderLabel;
    Label drySliderLabel;

    Label inSliderLabel;
    Label outSliderLabel;

    Label yawSliderLabel;
    Label pitchSliderLabel;

    Label rollSliderLabel; // ROLLTOGGLE
    Label distSliderLabel; // DISTTOGGLE

    Label directSliderLabel;
    Label earlySliderLabel;
    Label lateSliderLabel;

    Label* Labels[NUM_LABELS] = {&wetSliderLabel, &drySliderLabel, &inSliderLabel,
                         &outSliderLabel, &yawSliderLabel, &pitchSliderLabel,
                         &rollSliderLabel, &distSliderLabel, &directSliderLabel,
                         &earlySliderLabel, &lateSliderLabel};

//    ComboBox PresetsBox;
    TextButton PresetButton;

    std::unique_ptr<ButtonAttachment> presetAttachment;



    // stuff for scaling the size of the enitre window
    float scalex = 2.0f;
    float scaley = 2.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AuralizerAudioProcessorEditor)
};
