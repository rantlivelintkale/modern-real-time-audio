#pragma once

#include <JuceHeader.h>

#include "Oscillator.h"
#include "Ramp.h"

namespace DSP
{

float convertMidiNoteToFreq(int MidiNote);

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }
};

class SynthVoice : public juce::SynthesiserVoice
{
public:
    SynthVoice();
    ~SynthVoice();

    SynthVoice(const SynthVoice&) = delete;
    SynthVoice(SynthVoice&&) = delete;
    const SynthVoice& operator=(const SynthVoice&) = delete;
    const SynthVoice& operator=(SynthVoice&&) = delete;

    bool canPlaySound(SynthesiserSound* ptr) override;
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound*, int) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void pitchWheelMoved(int) override;
    void controllerMoved(int, int) override;
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

private:
    double sampleRate { 48000.0 };

    Oscillator osc;
    Ramp<float> ramp;
};

}
