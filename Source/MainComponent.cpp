/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainContentComponent::MainContentComponent ()
{
    addAndMakeVisible (label5 = new Label ("new label",
                                           CharPointer_UTF8 ("\xe6\x95\xb0\xe5\xad\x97\xe6\x97\xb6\xe9\x92\x9f")));
    label5->setFont (Font ("Microsoft YaHei", 20.00f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_clockView = new CClockView());
    m_clockView->setName ("new component");

    addAndMakeVisible (m_HourSlider = new Slider ("new slider"));
    m_HourSlider->setRange (1, 12, 1);
    m_HourSlider->setSliderStyle (Slider::LinearHorizontal);
    m_HourSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_HourSlider->addListener (this);

    addAndMakeVisible (m_MinSlider = new Slider ("new slider"));
    m_MinSlider->setRange (0, 59, 1);
    m_MinSlider->setSliderStyle (Slider::LinearHorizontal);
    m_MinSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_MinSlider->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           CharPointer_UTF8 ("\xe6\x97\xb6:")));
    label2->setFont (Font ("Microsoft YaHei", 20.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           CharPointer_UTF8 ("\xe5\x88\x86:")));
    label3->setFont (Font ("Microsoft YaHei", 20.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_DigitalView = new ToggleButton ("new toggle button"));
    m_DigitalView->setButtonText (String::empty);
    m_DigitalView->addListener (this);

    addAndMakeVisible (label4 = new Label ("new label",
                                           CharPointer_UTF8 ("\xe8\xa1\xa8\xe7\x9b\x98\xe6\x95\xb0\xe5\xad\x97")));
    label4->setFont (Font ("Microsoft YaHei", 20.00f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ShowClkNumber = new ToggleButton ("new toggle button"));
    m_ShowClkNumber->setButtonText (String::empty);
    m_ShowClkNumber->addListener (this);
    m_ShowClkNumber->setToggleState (true, dontSendNotification);

    addAndMakeVisible (label6 = new Label ("new label",
                                           CharPointer_UTF8 ("\xe6\x8c\x87\xe9\x92\x88\xe5\x8a\xa8\xe7\x94\xbb")));
    label6->setFont (Font ("Microsoft YaHei", 20.00f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_AnimateShow = new ToggleButton ("new toggle button"));
    m_AnimateShow->setButtonText (String::empty);
    m_AnimateShow->addListener (this);
    m_AnimateShow->setToggleState (true, dontSendNotification);

    addAndMakeVisible (label7 = new Label ("new label",
                                           CharPointer_UTF8 ("\xe7\xb3\xbb\xe7\xbb\x9f\xe6\x97\xb6\xe9\x97\xb4")));
    label7->setFont (Font ("Microsoft YaHei", 20.00f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_SystemClock = new ToggleButton ("new toggle button"));
    m_SystemClock->setButtonText (String::empty);
    m_SystemClock->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainContentComponent::~MainContentComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label5 = nullptr;
    m_clockView = nullptr;
    m_HourSlider = nullptr;
    m_MinSlider = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    m_DigitalView = nullptr;
    label4 = nullptr;
    m_ShowClkNumber = nullptr;
    label6 = nullptr;
    m_AnimateShow = nullptr;
    label7 = nullptr;
    m_SystemClock = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainContentComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainContentComponent::resized()
{
    label5->setBounds (384, 344, 72, 24);
    m_clockView->setBounds (0, 0, 600, 320);
    m_HourSlider->setBounds (48, 344, 296, 24);
    m_MinSlider->setBounds (48, 368, 296, 24);
    label2->setBounds (8, 344, 32, 24);
    label3->setBounds (8, 368, 32, 24);
    m_DigitalView->setBounds (360, 344, 96, 24);
    label4->setBounds (384, 368, 72, 24);
    m_ShowClkNumber->setBounds (360, 368, 96, 24);
    label6->setBounds (384, 320, 72, 24);
    m_AnimateShow->setBounds (360, 320, 96, 24);
    label7->setBounds (40, 320, 72, 24);
    m_SystemClock->setBounds (16, 320, 96, 24);
    //[UserResized] Add your own custom resize handling here..
	int sizeX = getWidth();
	int sizeY = getHeight();
	int clockViewX = sizeX;
	int clockViewY = sizeY - 96;

	if (clockViewX > clockViewY)
	{
		m_clockView->setBounds((clockViewX - clockViewY) / 2, 0, clockViewY, clockViewY);
	}
	else
	{
		m_clockView->setBounds(0, (clockViewY - clockViewX) / 2, clockViewX, clockViewX);
	}

	m_DigitalView ->setBounds(sizeX - 104,sizeY-56,96,24);
    label5->setBounds (sizeX - 80, sizeY-56, 72, 24);

	m_ShowClkNumber->setBounds(sizeX - 104, sizeY - 32, 96, 24);
	label4->setBounds(sizeX - 80, sizeY - 32, 72, 24);

	m_AnimateShow->setBounds(sizeX - 104, sizeY - 80, 96, 24);
	label6->setBounds(sizeX - 80, sizeY - 80, 72, 24);


	label7->setBounds(40, sizeY - 80, 72, 24);
	m_SystemClock->setBounds(16, sizeY - 80, 96, 24);

    m_HourSlider->setBounds (40, sizeY-56, 296, 24);
    label2->setBounds (8, sizeY-56, 32, 24);
    m_MinSlider->setBounds (40, sizeY-32, 296, 24);
    label3->setBounds (8, sizeY-32, 32, 24);

    //[/UserResized]
}

void MainContentComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_HourSlider)
    {
        //[UserSliderCode_m_HourSlider] -- add your slider handling code here..
		m_clockView->SetTime(int(m_HourSlider->getValue()),int(m_MinSlider->getValue()), 0, 0);
        //[/UserSliderCode_m_HourSlider]
    }
    else if (sliderThatWasMoved == m_MinSlider)
    {
        //[UserSliderCode_m_MinSlider] -- add your slider handling code here..
		m_clockView->SetTime(int(m_HourSlider->getValue()), int(m_MinSlider->getValue()), 0, 0);
        //[/UserSliderCode_m_MinSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MainContentComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_DigitalView)
    {
        //[UserButtonCode_m_DigitalView] -- add your button handler code here..
		m_clockView->ShowDigitalClock(m_DigitalView->getToggleState());
        //[/UserButtonCode_m_DigitalView]
    }
    else if (buttonThatWasClicked == m_ShowClkNumber)
    {
        //[UserButtonCode_m_ShowClkNumber] -- add your button handler code here..
		m_clockView->ShowClockNumber(m_ShowClkNumber->getToggleState());
        //[/UserButtonCode_m_ShowClkNumber]
    }
    else if (buttonThatWasClicked == m_AnimateShow)
    {
        //[UserButtonCode_m_AnimateShow] -- add your button handler code here..
		m_clockView->EnableAnimate(m_AnimateShow->getToggleState());
        //[/UserButtonCode_m_AnimateShow]
    }
    else if (buttonThatWasClicked == m_SystemClock)
    {
        //[UserButtonCode_m_SystemClock] -- add your button handler code here..
		m_HourSlider->setEnabled(!m_SystemClock->getToggleState());
		m_MinSlider->setEnabled(!m_SystemClock->getToggleState());
		m_clockView->UseSystemClock(m_SystemClock->getToggleState());
        //[/UserButtonCode_m_SystemClock]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainContentComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <LABEL name="new label" id="da0a5f9712e1b313" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="384 344 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="&#25968;&#23383;&#26102;&#38047;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Microsoft YaHei"
         fontsize="20" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="new component" id="254fb6c70e710266" memberName="m_clockView"
                    virtualName="CClockView" explicitFocusOrder="0" pos="0 0 600 320"
                    class="Component" params=""/>
  <SLIDER name="new slider" id="c15d6c3d1cd1dda3" memberName="m_HourSlider"
          virtualName="" explicitFocusOrder="0" pos="48 344 296 24" min="1"
          max="12" int="1" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="e8e16b643f8c6210" memberName="m_MinSlider"
          virtualName="" explicitFocusOrder="0" pos="48 368 296 24" min="0"
          max="59" int="1" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="dd29328eb5758b22" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 344 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="&#26102;:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Microsoft YaHei" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="6faba1f110220501" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 368 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="&#20998;:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Microsoft YaHei" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="f268a52432afd634" memberName="m_DigitalView"
                virtualName="" explicitFocusOrder="0" pos="360 344 96 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="cbd4eb2f1afabf2" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="384 368 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="&#34920;&#30424;&#25968;&#23383;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Microsoft YaHei"
         fontsize="20" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="9a599059606ee762" memberName="m_ShowClkNumber"
                virtualName="" explicitFocusOrder="0" pos="360 368 96 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="new label" id="3b36d1b0b38633d2" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="384 320 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="&#25351;&#38024;&#21160;&#30011;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Microsoft YaHei"
         fontsize="20" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="c1c6b5fa7200507e" memberName="m_AnimateShow"
                virtualName="" explicitFocusOrder="0" pos="360 320 96 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="new label" id="1edaa39d94cd4a29" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="40 320 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="&#31995;&#32479;&#26102;&#38388;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Microsoft YaHei"
         fontsize="20" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="e7d9b3ec4dbbba11" memberName="m_SystemClock"
                virtualName="" explicitFocusOrder="0" pos="16 320 96 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
