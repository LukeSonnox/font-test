/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

juce::Font getFont()
{
    // The crash is demonstrated here. If the typeface variable is declared
    // as static, the RX plug-ins will crash; removing the static keyword
    // will resolve the crash.
    //
    // An extra interesting piece of information:
    // Change to SourceSansProItalic below and the RX plug-ins WILL NOT crash.
    // Change to SourceSansProBold below and the RX plug-ins WILL crash.
    // I'm assuming this is because the RX plug-ins don't use the italic typeface,
    // but do use the bold and regular typefaces!
    
    static auto typeface = juce::Typeface::createSystemTypefaceFor (BinaryData::SourceSansProRegular_ttf,
                                                                    static_cast<size_t>(BinaryData::SourceSansProRegular_ttfSize));
    
    return typeface;

}

//==============================================================================
FontTestAudioProcessorEditor::FontTestAudioProcessorEditor (FontTestAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

FontTestAudioProcessorEditor::~FontTestAudioProcessorEditor()
{
}

//==============================================================================
void FontTestAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (getFont());
    
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void FontTestAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
