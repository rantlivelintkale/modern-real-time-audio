#include "PluginProcessor.h"
#include "PluginEditor.h"

MidiHandlerAudioProcessor::MidiHandlerAudioProcessor()
{
    synth.addSound(new DSP::SynthSound());
    synth.addVoice(new DSP::SynthVoice());
}

MidiHandlerAudioProcessor::~MidiHandlerAudioProcessor()
{
}

void MidiHandlerAudioProcessor::prepareToPlay(double sampleRate, int /*samplesPerBlock*/)
{
    synth.setCurrentPlaybackSampleRate(sampleRate);
}

void MidiHandlerAudioProcessor::releaseResources()
{
}

void MidiHandlerAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

void MidiHandlerAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
}

void MidiHandlerAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
}

bool MidiHandlerAudioProcessor::acceptsMidi() const
{
    return true;
}

//==============================================================================
const juce::String MidiHandlerAudioProcessor::getName() const { return JucePlugin_Name; }
bool MidiHandlerAudioProcessor::producesMidi() const { return false; }
bool MidiHandlerAudioProcessor::isMidiEffect() const { return false; }
double MidiHandlerAudioProcessor::getTailLengthSeconds() const { return 0.0; }
int MidiHandlerAudioProcessor::getNumPrograms() { return 1; }
int MidiHandlerAudioProcessor::getCurrentProgram() { return 0; }
void MidiHandlerAudioProcessor::setCurrentProgram(int) { }
const juce::String MidiHandlerAudioProcessor::getProgramName(int) { return {}; }
void MidiHandlerAudioProcessor::changeProgramName(int, const juce::String&) { }
bool MidiHandlerAudioProcessor::hasEditor() const { return true; }
juce::AudioProcessorEditor* MidiHandlerAudioProcessor::createEditor() { return new MidiHandlerAudioProcessorEditor(*this); }
//==============================================================================

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MidiHandlerAudioProcessor();
}