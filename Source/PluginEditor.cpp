/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AuralizerAudioProcessorEditor::AuralizerAudioProcessorEditor (AuralizerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (300, 400);
/*
 // Sliders
 Slider wetSlider;
 Slider drySlider;

 Slider inSlider;
 Slider outSlider;

 Slider yawSlider;
 Slider pitchSlider;
 Slider rollSlider;

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
 Label rollSliderLabel;

 Label directSliderLabel;
 Label earlySliderLabel;
 Label lateSliderLabel;
 */

    // wetSlider
    wetSlider.setSliderStyle(Slider::LinearHorizontal);
    wetSlider.setRange(0.0f, 2.0f, 0.01f);
    wetSlider.setValue(1.0f);

    wetSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    wetSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(wetSlider);

    wetSliderLabel.attachToComponent(&wetSlider, false);
    addAndMakeVisible(wetSliderLabel);

    wetSlider.addListener(this);

    // drySlider;
    drySlider.setSliderStyle(Slider::LinearHorizontal);
    drySlider.setRange(0.0f, 2.0f, 0.01f);
    drySlider.setValue(1.0f);

    drySlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    drySlider.setPopupMenuEnabled(false);
    addAndMakeVisible(drySlider);

    drySliderLabel.attachToComponent(&drySlider, false);
    addAndMakeVisible(drySliderLabel);

    drySlider.addListener(this);

    // inSlider;
    inSlider.setSliderStyle(Slider::Rotary);
    inSlider.setRange(0.0f, 2.0f, 0.01f);
    inSlider.setValue(1.0f);

    inSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    inSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(inSlider);

    inSliderLabel.attachToComponent(&inSlider, false);
    addAndMakeVisible(inSliderLabel);

    inSlider.addListener(this);

    // outSlider;
    outSlider.setSliderStyle(Slider::Rotary);
    outSlider.setRange(0.0f, 2.0f, 0.01f);
    outSlider.setValue(1.0f);

    outSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    outSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(outSlider);

    outSliderLabel.attachToComponent(&outSlider, false);
    addAndMakeVisible(outSliderLabel);

    outSlider.addListener(this);

    // yawSlider;
    yawSlider.setSliderStyle(Slider::LinearHorizontal);
    yawSlider.setRange(-180.0f, 180.0f, 0.1f);
    yawSlider.setValue(0.0f);

    yawSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    yawSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(yawSlider);

    yawSliderLabel.attachToComponent(&yawSlider, false);
    addAndMakeVisible(yawSliderLabel);

    yawSlider.addListener(this);

    // pitchSlider;
    pitchSlider.setSliderStyle(Slider::LinearHorizontal);
    pitchSlider.setRange(0.0f, 2.0f, 0.01f);
    pitchSlider.setValue(1.0f);

    pitchSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    pitchSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(pitchSlider);

    pitchSliderLabel.attachToComponent(&pitchSlider, true);
    addAndMakeVisible(pitchSliderLabel);

    pitchSlider.addListener(this);

    // rollSlider;
    rollSlider.setSliderStyle(Slider::Rotary);
    rollSlider.setRange(0.0f, 2.0f, 0.01f);
    rollSlider.setValue(1.0f);

    rollSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    rollSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(rollSlider);

    rollSliderLabel.attachToComponent(&rollSlider, false);
    addAndMakeVisible(rollSliderLabel);

    rollSlider.addListener(this);


    // directSlider;
    directSlider.setSliderStyle(Slider::LinearHorizontal);
    directSlider.setRange(0.0f, 2.0f, 0.01f);
    directSlider.setValue(1.0f);

    directSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    directSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(directSlider);

    directSliderLabel.attachToComponent(&directSlider, false);
    addAndMakeVisible(directSliderLabel);

    directSlider.addListener(this);

    // earlySlider;
    earlySlider.setSliderStyle(Slider::LinearHorizontal);
    earlySlider.setRange(0.0f, 2.0f, 0.01f);
    earlySlider.setValue(1.0f);

    earlySlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    earlySlider.setPopupMenuEnabled(false);
    addAndMakeVisible(earlySlider);

    earlySliderLabel.attachToComponent(&earlySlider, false);
    addAndMakeVisible(earlySliderLabel);

    earlySlider.addListener(this);

    // lateSlider;
    lateSlider.setSliderStyle(Slider::LinearHorizontal);
    lateSlider.setRange(0.0f, 2.0f, 0.01f);
    lateSlider.setValue(1.0f);

    lateSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    lateSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(lateSlider);

    lateSliderLabel.attachToComponent(&lateSlider, false);
    addAndMakeVisible(lateSliderLabel);

    lateSlider.addListener(this);



    addAndMakeVisible(PresetsBox);
    PresetsBox.onChange = [this] { changePreset(); };

}

AuralizerAudioProcessorEditor::~AuralizerAudioProcessorEditor()
{
}

//==============================================================================
void AuralizerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));



    g.setColour (Colours::black);

    g.drawLine(0, 140, getWidth(), 140);
    g.drawLine(0, 40, getWidth(), 140);
    

    g.setFont (15.0f);
    g.drawFittedText("auralizer", 8, 15, 130, 25, Justification::centred, 1);
    g.drawFittedText("input", 251, 46, 47, 19, Justification::centred, 1);




}



void AuralizerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

//    wetSlider.setBounds(<#int x#>, <#int y#>, <#int width#>, <#int height#>)

    
}

void AuralizerAudioProcessorEditor::sliderValueChanged(Slider* slider){
    if (slider == &wetSlider){
        processor.setSliderValue("wetSlider", wetSlider.getValue());
    }
    else if (slider == &drySlider){
        processor.setSliderValue("drySlider", drySlider.getValue());
    }
    else if (slider == &inSlider){
        processor.setSliderValue("inSlider", inSlider.getValue());
    }
    else if (slider == &outSlider){
        processor.setSliderValue("outSlider", outSlider.getValue());
    }
    else if (slider == &yawSlider){
        processor.setSliderValue("yawSlider", yawSlider.getValue());
    }
    else if (slider == &pitchSlider){
        processor.setSliderValue("pitchSlider", pitchSlider.getValue());
    }
    else if (slider == &rollSlider){
        processor.setSliderValue("rollSlider", rollSlider.getValue());
    }
    else if (slider == &directSlider){
        processor.setSliderValue("directSlider", directSlider.getValue());
    }
    else if (slider == &earlySlider){
        processor.setSliderValue("earlySlider", earlySlider.getValue());
    }
    else if (slider == &lateSlider){
        processor.setSliderValue("lateSlider", lateSlider.getValue());
    }
}
