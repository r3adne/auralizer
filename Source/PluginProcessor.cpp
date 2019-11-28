/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <stdexcept>

//==============================================================================


AuralizerAudioProcessor::~AuralizerAudioProcessor()
{
    
}

//==============================================================================
const String AuralizerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AuralizerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AuralizerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AuralizerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AuralizerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AuralizerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AuralizerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AuralizerAudioProcessor::setCurrentProgram (int index)
{
}

const String AuralizerAudioProcessor::getProgramName (int index)
{
    return {};
}

void AuralizerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AuralizerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

    _block_size = samplesPerBlock;
    _sample_rate = sampleRate;


    Ambi_block.setSize(getOrder[AMBISONIC_ORDER_NUMBER], samplesPerBlock);

    position.fAzimuth = *yawAmt;
    position.fDistance = *distAmt;
    position.fElevation = *pitchAmt;
    Encoder.Configure(AMBISONIC_ORDER_NUMBER, true, 0);
//    Processor.Configure(AMBISONIC_ORDER_NUMBER, true, _block_size, 0);
    Decoder.Configure(AMBISONIC_ORDER_NUMBER, true, kAmblib_Stereo);

    ambi_buffer.Configure(AMBISONIC_ORDER_NUMBER, true, _block_size);

    
}

void AuralizerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AuralizerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AuralizerAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.





    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);



        // ..do something to the data...
    }
}

//==============================================================================
bool AuralizerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AuralizerAudioProcessor::createEditor()
{
    return new AuralizerAudioProcessorEditor (*this);
}

//==============================================================================
void AuralizerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    std::unique_ptr<XmlElement> xml (new XmlElement ("auralizerParam_0"));
    xml->setAttribute("name", new_preset_name);
    xml->setAttribute("IRDir", IR_directory);

    xml->setAttribute("wetAmt", (double) *wetAmt);
    xml->setAttribute("dryAmt", (double) *dryAmt);

    xml->setAttribute("inAmt", (double) *inAmt);
    xml->setAttribute("outAmt", (double) *outAmt);

    xml->setAttribute("yawAmt", (double) *yawAmt);
    xml->setAttribute("pitchAmt", (double) *pitchAmt);
//    xml->setAttribute("rollAmt", (double) *rollAmt);
    xml->setAttribute("distAmt", (double) *distAmt);

    xml->setAttribute("dirAmt", (double) *dirAmt);
    xml->setAttribute("earlyAmt", (double) *earlyAmt);
    xml->setAttribute("lateAmt", (double) *lateAmt);
    copyXmlToBinary(*xml, destData);

}

void AuralizerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState.get() != nullptr){
        if (xmlState->hasTagName("auralizerParam_0")){
            new_preset_name = xmlState->getStringAttribute("name");
            IR_directory = xmlState->getStringAttribute("IRDir");

            *wetAmt = (float) xmlState->getDoubleAttribute("wetAmt");
            *dryAmt = (float) xmlState->getDoubleAttribute("dryAmt");

            *inAmt = (float) xmlState->getDoubleAttribute("inAmt");
            *outAmt = (float) xmlState->getDoubleAttribute("outAmt");

            *yawAmt = (float) xmlState->getDoubleAttribute("yawAmt");
            *pitchAmt = (float) xmlState->getDoubleAttribute("pitchAmt");
//            *rollAmt = (float) xmlState->getDoubleAttribute("rollAmt"); // ROLLTOGGLE
            *distAmt = (float) xmlState->getDoubleAttribute("distAmt"); // DISTTOGGLE

            *dirAmt = (float) xmlState->getDoubleAttribute("dirAmt");
            *earlyAmt = (float) xmlState->getDoubleAttribute("earlyAmt");
            *lateAmt = (float) xmlState->getDoubleAttribute("lateAmt");

//            load_irs();
        }

    }
}


void AuralizerAudioProcessor::setSliderValue(String name, float value){
    if (name == "wetSlider"){
        *wetAmt = value;
    }
    else if (name == "drySlider"){
        *dryAmt = value;
    }
    else if (name == "inSlider"){
        *inAmt = value;
    }
    else if (name == "outSlider"){
        *outAmt = value;
    }
    else if (name == "yawSlider"){
        *yawAmt = value;
    }
    else if (name == "pitchSlider"){
        *pitchAmt = value;
    }
//    else if (name == "rollSlider"){ // ROLLTOGGLE
//        *rollAmt = value; // ROLLTOGGLE
//    } // ROLLTOGGLE
    else if (name == "distSlider"){ // DISTTOGGLE
        *distAmt = value; // DISTTOGGLE
    } // DISTTOGGLE
    else if (name == "directSlider"){
        *dirAmt = value;
    }
    else if (name == "earlySlider"){
        *earlyAmt = value;
    }
    else if (name == "lateSlider"){
        *lateAmt = value;
    }
    else { // error
        throw std::invalid_argument("received invalid slider name argument");
    }

}









//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AuralizerAudioProcessor();
}

