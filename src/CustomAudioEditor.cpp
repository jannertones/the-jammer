#include "CustomAudioEditor.h"

CustomAudioEditor::CustomAudioEditor (RNBO::JuceAudioProcessor* const p, RNBO::CoreObject& rnboObject)
    : AudioProcessorEditor (p)
    , _rnboObject(rnboObject)
    , _audioProcessor(p)
{
    _audioProcessor->AudioProcessor::addListener(this);
    _rootComponent.setAudioProcessor(p);
    addAndMakeVisible(_rootComponent);
    setSize(_rootComponent.getWidth(), _rootComponent.getHeight());
}

CustomAudioEditor::~CustomAudioEditor()
{
    _audioProcessor->AudioProcessor::removeListener(this);
}

void CustomAudioEditor::paint (Graphics& g)
{
    g.fillAll(Colours::white);
}

void CustomAudioEditor::audioProcessorParameterChanged (AudioProcessor*, int parameterIndex, float value)
{
    _rootComponent.updateSliderForParam(parameterIndex, value);
}

