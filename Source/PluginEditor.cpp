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
    setSize (300 * scalex, 400 * scaley);
/*
 // Sliders
 Slider wetSlider;
 Slider drySlider;

 Slider inSlider;
 Slider outSlider;

 Slider yawSlider;
 Slider pitchSlider;
 // Slider rollSlider;
 Slider distanceSlider;

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
 // Label rollSliderLabel;
 Label distanceSliderLabel;

 Label directSliderLabel;
 Label earlySliderLabel;
 Label lateSliderLabel;
 */

    // wetSlider
    wetSlider.setSliderStyle(Slider::LinearBar);
    wetSlider.setRange(0.0f, 2.0f, 0.01f);
    wetSlider.setValue(1.0f);

    wetSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
//    wetSlider.setColour(Slider::backgroundColourId, Colours::darkgrey);
    wetSlider.setColour(Slider::trackColourId, Colours::darkgrey);

    wetSlider.setPopupMenuEnabled(false);

    addAndMakeVisible(wetSlider);




    wetSliderLabel.attachToComponent(&wetSlider, false);
    addAndMakeVisible(wetSliderLabel);
    wetSliderLabel.setText("wet", dontSendNotification);

    wetSlider.addListener(this);

    // drySlider;
    drySlider.setSliderStyle(Slider::LinearBar);
    drySlider.setRange(0.0f, 2.0f, 0.01f);
    drySlider.setValue(1.0f);

    drySlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    drySlider.setColour(Slider::trackColourId, Colours::darkgrey);
    drySlider.setPopupMenuEnabled(false);
    addAndMakeVisible(drySlider);

    drySliderLabel.attachToComponent(&drySlider, false);
    addAndMakeVisible(drySliderLabel);
    drySliderLabel.setText("dry", dontSendNotification);

    drySlider.addListener(this);

    // inSlider;
    inSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inSlider.setRange(0.0f, 2.0f, 0.01f);
    inSlider.setValue(1.0f);

    inSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    inSlider.setColour(Slider::trackColourId, Colours::darkgrey);
    inSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(inSlider);

    inSliderLabel.attachToComponent(&inSlider, false);
    addAndMakeVisible(inSliderLabel);
    inSliderLabel.setText("input", dontSendNotification);

    inSlider.addListener(this);

    // outSlider;
    outSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    outSlider.setRange(0.0f, 2.0f, 0.01f);
    outSlider.setValue(1.0f);

    outSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    outSlider.setColour(Slider::trackColourId, Colours::darkgrey);
    outSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(outSlider);

//    outSliderLabel.attachToComponent(&outSlider, false);
    addAndMakeVisible(outSliderLabel);
    outSliderLabel.setText("output", dontSendNotification);

    outSlider.addListener(this);

    // yawSlider;
    yawSlider.setSliderStyle(Slider::LinearBar);
    yawSlider.setRange(-180.0f, 180.0f, 0.1f);
    yawSlider.setValue(0.0f);

    yawSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    yawSlider.setColour(Slider::trackColourId, Colours::darkgrey);
    yawSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(yawSlider);

//    yawSliderLabel.attachToComponent(&yawSlider, false);
    addAndMakeVisible(yawSliderLabel);
    yawSliderLabel.setText("yaw", dontSendNotification);

    yawSlider.addListener(this);

    // pitchSlider;
    pitchSlider.setSliderStyle(Slider::LinearBarVertical);
    pitchSlider.setRange(0.0f, 2.0f, 0.01f);
    pitchSlider.setValue(1.0f);

    pitchSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    pitchSlider.setColour(Slider::trackColourId, Colours::darkgrey);
    pitchSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(pitchSlider);

    pitchSliderLabel.attachToComponent(&pitchSlider, true);
    addAndMakeVisible(pitchSliderLabel);
    pitchSliderLabel.setText("pitch", dontSendNotification);

    pitchSlider.addListener(this);

    // rollSlider
    rollSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag); // ROLLTOGGLE
    rollSlider.setRange(0.0f, 2.0f, 0.01f); // ROLLTOGGLE
    rollSlider.setValue(1.0f); // ROLLTOGGLE
//
    rollSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0); // ROLLTOGGLE
    rollSlider.setColour(Slider::trackColourId, Colours::darkgrey); // ROLLTOGGLE
    rollSlider.setPopupMenuEnabled(false); // ROLLTOGGLE
    addAndMakeVisible(rollSlider); // ROLLTOGGLE
//
    rollSliderLabel.attachToComponent(&rollSlider, false); // ROLLTOGGLE
    addAndMakeVisible(rollSliderLabel); // ROLLTOGGLE
    rollSliderLabel.setText("roll", dontSendNotification); // ROLLTOGGLE
//
    rollSlider.addListener(this); // ROLLTOGGLE

    distSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag); // DISTTOGGLE
    distSlider.setRange(0.0f, 2.0f, 0.01f); // DISTTOGGLE
    distSlider.setValue(1.0f); // DISTTOGGLE

    distSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0); // DISTTOGGLE
    distSlider.setColour(Slider::trackColourId, Colours::darkgrey); // DISTTOGGLE
    distSlider.setPopupMenuEnabled(false); // DISTTOGGLE
//    addAndMakeVisible(distSlider); // DISTTOGGLE

    distSliderLabel.attachToComponent(&distSlider, false); // DISTTOGGLE
    addAndMakeVisible(distSliderLabel); // DISTTOGGLE
    distSliderLabel.setText("distance", dontSendNotification); // DISTTOGGLE

    distSlider.addListener(this); // DISTTOGGLE


    // directSlider;
    directSlider.setSliderStyle(Slider::LinearBar);
    directSlider.setRange(0.0f, 2.0f, 0.01f);
    directSlider.setValue(1.0f, dontSendNotification);

    directSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    directSlider.setColour(Slider::trackColourId, Colours::darkgrey);
    directSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(directSlider);

    directSliderLabel.attachToComponent(&directSlider, false);
    addAndMakeVisible(directSliderLabel);
    directSliderLabel.setText("direct", dontSendNotification);

    directSlider.addListener(this);

    // earlySlider;
    earlySlider.setSliderStyle(Slider::LinearBar);
    earlySlider.setRange(0.0f, 2.0f, 0.01f);
    earlySlider.setValue(1.0f, dontSendNotification);

    earlySlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    earlySlider.setColour(Slider::trackColourId, Colours::darkgrey);
    earlySlider.setPopupMenuEnabled(false);
    addAndMakeVisible(earlySlider);

    earlySliderLabel.attachToComponent(&earlySlider, false);
    addAndMakeVisible(earlySliderLabel);
    earlySliderLabel.setText("early", dontSendNotification);

    earlySlider.addListener(this);

    // lateSlider;
    lateSlider.setSliderStyle(Slider::LinearBar);
    lateSlider.setRange(0.0f, 2.0f, 0.01f);
    lateSlider.setValue(1.0f, dontSendNotification);

    lateSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    lateSlider.setColour(Slider::trackColourId, Colours::darkgrey);
    lateSlider.setPopupMenuEnabled(false);
    addAndMakeVisible(lateSlider);

    lateSliderLabel.attachToComponent(&lateSlider, false);
    addAndMakeVisible(lateSliderLabel);
    lateSliderLabel.setText("late", dontSendNotification);

    lateSlider.addListener(this);

    PresetButton.setButtonText("Preset");
    addAndMakeVisible(PresetButton);
    PresetButton.onClick = [this]{ presetButtonClicked(); };





//    addAndMakeVisible(PresetsBox);
//    PresetsBox.onChange = [this] { changePreset(); };

}

AuralizerAudioProcessorEditor::~AuralizerAudioProcessorEditor()
{
}

//==============================================================================
void AuralizerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));


    g.fillAll (Colour(PixelARGB(240,60,60,70)));

    g.setColour (Colours::white);

    g.drawLine(0 * scalex, 140 * scaley, getWidth(), 140 * scaley);
    g.drawLine(0 * scalex, 40 * scaley, getWidth(), 40 * scaley);
    


    g.setFont (15.0f * scalex);
    g.drawFittedText("auralizer", 19 * scalex, 7.5 * scaley, 132 * scalex, 25 * scaley, Justification::centred, 1);

    g.setFont (11.0f);
    g.drawFittedText("alpha build 0.0.3", 20 * scalex, 380 * scaley, 60 * scalex, 16 * scaley, Justification::centred, 1);
//    g.drawFittedText("input", 251, 46, 47, 19, Justification::centred, 1);




}



void AuralizerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    // header
//    PresetsBox.setBounds(<#int x#>, <#int y#>, <#int width#>, <#int height#>)
//    PresetsBox.setBounds        (  187 * scalex,  15 * scaley,   93 * scalex,   17 * scaley);

    PresetButton.setBounds      (  187 * scalex, 15  * scaley,  93  * scalex,     17 * scaley);
    // input section
    directSlider.setBounds      (  20  * scalex, 60  * scaley,  140 * scalex,     10 * scaley);
    earlySlider.setBounds       (  20  * scalex, 85  * scaley,  140 * scalex,     10 * scaley);
    lateSlider.setBounds        (  20  * scalex, 110 * scaley,  140 * scalex,     10 * scaley);

    directSliderLabel.setBounds (  170 * scalex, 60  * scaley,  34.9 * scalex,    10 * scaley);
    earlySliderLabel.setBounds  (  170 * scalex, 85  * scaley,  30.1 * scalex,  12.6 * scaley);
    lateSliderLabel.setBounds   (  170 * scalex, 110 * scaley,  22.5 * scalex,    10 * scaley);

    inSlider.setBounds          (  235 * scalex, 75  * scaley,   30 * scalex,     30 * scaley);
    inSliderLabel.setBounds     (  225 * scalex, 45  * scaley,   47 * scalex,     19 * scaley);
    // rotate section
  rollSlider.setBounds        (  130 * scalex, 180 * scaley,   40 * scalex,     40 * scaley); // ROLLTOGGLE
    distSlider.setBounds        (  130 * scalex, 180 * scaley,   40 * scalex,     40 * scaley); // DISTTOGGLE
    yawSlider.setBounds         (  48  * scalex, 240 * scaley,  200 * scalex,     16 * scaley);
    pitchSlider.setBounds       (  255 * scalex, 165 * scaley,   20 * scalex,     91 * scaley);

  rollSliderLabel.setBounds   (141.5 * scalex, 165 * scaley, 16.9 * scalex,      9 * scaley); // ROLLTOGGLE
    distSliderLabel.setBounds   (141.5 * scalex, 165 * scaley, 16.9 * scalex,      9 * scaley); // DISTTOGGLE
    yawSliderLabel.setBounds    (141.5 * scalex, 260 * scaley,   22 * scalex,      9 * scaley);
    pitchSliderLabel.setBounds  (  252 * scalex, 148 * scaley,   26 * scalex,   11.4 * scaley);
    // output section
    wetSlider.setBounds         (   20 * scalex, 340 * scaley,  140 * scalex,     16 * scaley);
    drySlider.setBounds         (   20 * scalex, 296 * scaley,  140 * scalex,     16 * scaley);
    outSlider.setBounds         (  236 * scalex, 320 * scaley,   30 * scalex,     30 * scaley);
    outSliderLabel.setBounds    (  220 * scalex, 286 * scaley,   60 * scalex,     18 * scaley);



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
    else if (slider == &rollSlider){ // ROLLTOGGLE
        processor.setSliderValue("rollSlider", rollSlider.getValue()); // ROLLTOGGLE
    } // ROLLTOGGLE
    else if (slider == &distSlider){ // DISTTOGGLE
        processor.setSliderValue("distSlider", distSlider.getValue()); // DISTTOGGLE
    } // DISTTOGGLE
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

void AuralizerAudioProcessorEditor::presetButtonClicked(){
    FileChooser chooser("Select a .xml auralizer preset.", {}, "*.xml");
    if (chooser.browseForFileToOpen()){
        juce::File presetFile = chooser.getResult();
        if (! presetFile.exists()){
            throw std::invalid_argument("The chosen file does not exist");
        }
        else if (! presetFile.existsAsFile()){
            throw std::invalid_argument("The chosen file is a directory, not a file.");
        }
        else if (! presetFile.hasFileExtension(".xml")){
            throw std::invalid_argument("The chosen file does not have \".xml\" extension");
        }
        PresetButton.setButtonText(presetFile.getFileNameWithoutExtension());
        processor.setXmlFileToLoad(presetFile);
        processor.loadPreset();
    }
}
