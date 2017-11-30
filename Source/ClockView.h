/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class CClockView  : public Component,
                    public Timer
{
public:
    //==============================================================================
    CClockView ();
    ~CClockView();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void SetTime(int hour, int min, int sec = 0, int mSec = 0);
	void ShowClockNumber(bool bShow);
	void ShowDigitalClock(bool bShow);
	void UseSystemClock(bool bEnable)
	{
		bUseSystemClock = bEnable;
	}
	void EnableAnimate(bool bEnable)
	{
		bAnimate = bEnable;
	}
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void mouseDown (const MouseEvent& e) override;
    void mouseDrag (const MouseEvent& e) override;
    void mouseUp (const MouseEvent& e) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	float fMinPosDisplay,fHourPosDisplay;//
	float fMinPosTarget, fHourPosTarget;
	float fSecPosDisplay, fSecPosTarget;

	int iLocalHour, iLocalMin;
    bool bDisplaySec;
	bool bDisNum;
	bool bAnimate;
	bool bShowDigitalClock;
	bool bUseSystemClock;
	void timerCallback(void);
	void CalClockChange(int posX, int posY);
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CClockView)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
