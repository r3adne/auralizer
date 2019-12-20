/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AuralizerAudioProcessorEditor::AuralizerAudioProcessorEditor (AuralizerAudioProcessor& p, AudioProcessorValueTreeState& vts)
: AudioProcessorEditor (&p), processor (p), valueTreeState (vts)
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

    for (int i = 0; i < NUM_SLIDERS; i++){
        Sliders[i]->setColour(Slider::trackColourId, Colours::darkgrey);
        Sliders[i]->setColour(Slider::rotarySliderOutlineColourId, Colours::white);
        Sliders[i]->setColour(Slider::rotarySliderFillColourId, Colours::darkgrey);
        Sliders[i]->setColour(Slider::thumbColourId, Colours::white);
        Sliders[i]->setSliderStyle(Slider::LinearBar);
        Sliders[i]->setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
        Sliders[i]->setPopupMenuEnabled(false);

        Sliders[i]->setValue(*valueTreeState.getRawParameterValue(vstids[i]), sendNotification);
        Labels[i]->attachToComponent(Sliders[i], false);

        SliderAttachments[i].reset (new SliderAttachment(valueTreeState, Sliders[i]->getName(), *Sliders[i]));

        addAndMakeVisible(Sliders[i]);
        addAndMakeVisible(Labels[i]);

        Sliders[i]->addListener(this);
    }


    //////////// SLIDER PARAMETER OVERRIDES ////////////

    // wetSlider
    wetSliderLabel.setText("wet", dontSendNotification);

    // drySlider
    drySliderLabel.setText("dry", dontSendNotification);
//    dryAttachment.reset (new SliderAttachment()

    // inSlider
    inSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inSliderLabel.setText("input", dontSendNotification);

    // outSlider
    outSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    outSliderLabel.setText("output", dontSendNotification);

    // yawSlider
    yawSlider.setRange(-180.0f, 180.0f, 0.1f);
    yawSlider.setValue(0.0f, dontSendNotification);
    yawSliderLabel.setText("yaw", dontSendNotification);

    // pitchSlider
    pitchSlider.setSliderStyle(Slider::LinearBarVertical);
    pitchSliderLabel.setText("pitch", dontSendNotification);

    // rollSlider
    rollSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    rollSliderLabel.setText("roll", dontSendNotification);

    // distSlider
    distSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    distSlider.setRange(0.0f, 50.0f, 0.01f);
    distSliderLabel.setText("distance", dontSendNotification);

    // directSlider;
    directSlider.setSliderStyle(Slider::LinearBar);
    directSliderLabel.setText("direct", dontSendNotification);

    // earlySlider;
    earlySlider.setSliderStyle(Slider::LinearBar);
    earlySliderLabel.setText("early", dontSendNotification);

    // lateSlider;
    lateSliderLabel.setText("late", dontSendNotification);


    ////////////    ////////////

    PresetButton.setButtonText("Preset");
    presetAttachment.reset (new ButtonAttachment(valueTreeState, "Preset", PresetButton));
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

    wetSlider.setValue((double) processor.getSliderValue("wetSlider"));
    drySlider.setValue((double) processor.getSliderValue("drySlider"));
    inSlider.setValue((double) processor.getSliderValue("inSlider"));
    outSlider.setValue((double) processor.getSliderValue("outSlider"));
    rollSlider.setValue((double) processor.getSliderValue("rollSlider"));
    distSlider.setValue((double) processor.getSliderValue("distSlider"));
    pitchSlider.setValue((double) processor.getSliderValue("pitchSlider"));
    yawSlider.setValue((double) processor.getSliderValue("yawSlider"));
    directSlider.setValue((double) processor.getSliderValue("directSlider"));
    earlySlider.setValue((double) processor.getSliderValue("earlySlider"));
    lateSlider.setValue((double) processor.getSliderValue("lateSlider"));

    wetSlider.valueChanged();

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
  rollSlider.setBounds        (  110 * scalex, 180 * scaley,   40 * scalex,     40 * scaley); // ROLLTOGGLE
    distSlider.setBounds        (  150 * scalex, 180 * scaley,   40 * scalex,     40 * scaley); // DISTTOGGLE
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
