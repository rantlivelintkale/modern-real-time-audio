#include "PluginEditor.h"

MidiHandlerAudioProcessorEditor::MidiHandlerAudioProcessorEditor(MidiHandlerAudioProcessor& p) :
    juce::AudioProcessorEditor(p), audioProcessor(p)
{
    setSize(300, 300);
}


MidiHandlerAudioProcessorEditor::~MidiHandlerAudioProcessorEditor()
{
}

//==============================================================================
void MidiHandlerAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MidiHandlerAudioProcessorEditor::resized()
{
}