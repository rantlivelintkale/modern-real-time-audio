#pragma once

#include "PluginProcessor.h"

class MidiHandlerAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    MidiHandlerAudioProcessorEditor(MidiHandlerAudioProcessor&);
    ~MidiHandlerAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    MidiHandlerAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiHandlerAudioProcessorEditor)
};