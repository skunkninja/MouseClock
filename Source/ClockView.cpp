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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "ClockView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#define CLOCK_POINT_SPEED_DIV  15.0f
#define CLOCK_POINT_ANGLE_MIN  0.6f
//[/MiscUserDefs]

//==============================================================================
CClockView::CClockView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	bDisplaySec = false;
	fMinPosDisplay = 90.f;
	fHourPosDisplay = -90.f;
	fSecPosDisplay = 180.f;
	startTimer(10);
	bDisNum = true;
	bShowDigitalClock = false;
	bAnimate = true;
	bUseSystemClock = false;
	SetTime(1, 0, 0, 0);
    //[/Constructor]
}

CClockView::~CClockView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CClockView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffffe9bd));

    //[UserPaint] Add your own custom painting code here..
	float sizeX = float(getWidth());
	float sizeY = float(getHeight());
	float clockSize = sizeX;
	if(clockSize > sizeY)
	{
		clockSize = sizeY;
	}
	float fOutLineWidth,fClockNumberSize,fClockGradWidth;
	fOutLineWidth = clockSize*0.01f;
	fClockGradWidth = clockSize*0.006f;
	fClockNumberSize = clockSize*0.06f;

	g.setColour(Colours::black);
	g.drawEllipse(fOutLineWidth/2,fOutLineWidth/2,clockSize-fOutLineWidth,clockSize-fOutLineWidth,fOutLineWidth);

	g.setFont(clockSize*0.08f);
	for(int i = 0;i < 12;i++)
	{
		float xBase = clockSize/2.f*sin(i*3.1415926f/6);
		float yBase = -clockSize/2.f*cos(i*3.1415926f/6);
		float tempWidth = fClockGradWidth;
		if (!bDisNum)
		{
			if ((i % 3) == 0)
			{
				tempWidth *= 3;
			}
		}
		g.drawLine(clockSize / 2 + xBase, clockSize / 2 + yBase, clockSize / 2 + xBase*0.90f, clockSize / 2 + yBase*0.90f, tempWidth);
		if(bDisNum)
		{
			Rectangle<int> tempRect;
			tempRect.setX(int(clockSize/2.0f+xBase*0.78f-clockSize*0.1f));
			tempRect.setY(int(clockSize / 2.0f + yBase*0.78f - clockSize*0.1f));
			tempRect.setWidth(int(clockSize*0.2f));
			tempRect.setHeight(int(clockSize*0.2f));
		//g.drawEllipse(temp,fClockGradWidth/2);
			String tempStr;
			if(i == 0)
			{
				tempStr = String(12);
			}
			else
			{
				tempStr = String(i);
			}
			g.drawFittedText(tempStr,tempRect,Justification::centred,1);
		}
	}

	for(int i = 0;i < 60;i++)
	{
		if((i % 5) == 0)
		{
			continue;
		}
		float xBase = clockSize/2.f*sin(i*3.1415926f/30);
		float yBase = -clockSize/2.f*cos(i*3.1415926f/30);
		g.drawLine(clockSize/2+xBase,clockSize/2+yBase,clockSize/2+xBase*0.93f,clockSize/2+yBase*0.93f,fClockGradWidth/2);
	}

	Path tempPath;
	AffineTransform tempTransform;

	g.setColour(Colour(uint8(255), 0, 0, uint8(128)));
	tempPath.startNewSubPath(clockSize / 2 - clockSize*0.04f, clockSize / 2);
	tempPath.lineTo(clockSize / 2, clockSize*0.15f);
	tempPath.lineTo(clockSize / 2 + clockSize*0.04f, clockSize / 2);
	tempPath.lineTo(clockSize / 2, clockSize*0.52f);
	tempPath.closeSubPath();
	g.fillPath(tempPath, tempTransform.rotated(fHourPosDisplay*3.1415926f / 180.0f, clockSize*0.5f, clockSize*0.5f));

	g.setColour(Colour(uint8(0), 128, 0, uint8(128)));
	tempPath.clear();
	tempPath.startNewSubPath(clockSize / 2 - clockSize*0.03f, clockSize / 2);
	tempPath.lineTo(clockSize / 2, clockSize*0.05f);
	tempPath.lineTo(clockSize / 2 + clockSize*0.03f, clockSize / 2);
	tempPath.lineTo(clockSize / 2, clockSize*0.52f);
	tempPath.closeSubPath();
	g.fillPath(tempPath, tempTransform.rotated(fMinPosDisplay*3.1415926f / 180.0f, clockSize*0.5f, clockSize*0.5f));

	g.setColour(Colour(uint8(0), 0, 255));
	g.fillEllipse(sizeX*(0.5f - 0.01f), sizeY*(0.5f - 0.01f), sizeX*0.02f, sizeY*0.02f);

	tempPath.clear();
	tempPath.startNewSubPath(clockSize / 2 + clockSize*0.006f, clockSize*0.55f);
	tempPath.addCentredArc(clockSize / 2, clockSize*0.55f, clockSize*0.006, clockSize*0.006, 0,
		3.141592f*0.5f, 3.1415926f*1.5f);
	tempPath.lineTo(clockSize * 0.494f, clockSize*0.03f);
	tempPath.addCentredArc(clockSize / 2, clockSize*0.03f, clockSize*0.006, clockSize*0.006, 0,
		3.141592f*1.5f, 3.1415926f*2.5f);
	tempPath.lineTo(clockSize * 0.506f, clockSize*0.55f);

	g.setColour(Colour(uint8(128), 0, 0, uint8(192)));
	g.fillPath(tempPath, tempTransform.rotated(fSecPosDisplay*3.1415926f / 180.0f, clockSize*0.5f, clockSize*0.5f));

	if (bShowDigitalClock)
	{
		String tempString = String::formatted(L"%02d:%02d", (iLocalHour != 0) ? iLocalHour:12, iLocalMin);
		g.setColour(Colours::black);
		g.drawFittedText(tempString, 0, 0, int(sizeX), int(sizeY), Justification::bottomRight, 1);
	}
    //[/UserPaint]
}

void CClockView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void CClockView::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
	CalClockChange(e.x, e.y);
	setFocusContainer(true);
    //[/UserCode_mouseDown]
}

void CClockView::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
	CalClockChange(e.x, e.y);
    //[/UserCode_mouseDrag]
}

void CClockView::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
	setFocusContainer(false);
    //[/UserCode_mouseUp]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ConvertAngle(float& angleTarget, float& angleCurrent)
{
	if(angleCurrent < 0)
	{
		angleCurrent += 360;
	}

	if(angleTarget > angleCurrent)
	{
		if((angleTarget - angleCurrent) < 180)
		{
		}
		else
		{
			angleTarget-=360;
		}
	}
	else
	{
		if((angleCurrent - angleTarget) < 180)
		{
		}
		else
		{
			angleCurrent -= 360;
		}
	}
}

void UpdateAngle(float& angleTarget, float& angleCurrent)
{
	if(angleTarget == angleCurrent)
	{
		return;
	}
	float fstep = abs(angleTarget-angleCurrent);
	fstep /= CLOCK_POINT_SPEED_DIV;
	if (fstep < CLOCK_POINT_ANGLE_MIN)
	{
		fstep = CLOCK_POINT_ANGLE_MIN;
	}

	if(angleTarget > angleCurrent)
	{
		angleCurrent += fstep;
		if(angleCurrent > angleTarget)
		{
			angleCurrent = angleTarget;
		}
	}
	else
	{
		angleCurrent -= fstep;
		if(angleCurrent < angleTarget)
		{
			angleCurrent = angleTarget;
		}
	}
}
void CClockView::SetTime(int hour, int min, int sec, int mSec)
{
	iLocalHour = hour;
	iLocalMin = min;
	hour %= 12;
	sec %= 60;
	fSecPosTarget = float(mSec);
	fSecPosTarget /= 1000;
	fSecPosTarget += sec;
	fMinPosTarget = fSecPosTarget;
	fSecPosTarget *= 6.f;
	fMinPosTarget /= 60.f;
	fMinPosTarget += min;
	fHourPosTarget = fMinPosTarget;
	fMinPosTarget *= 6.f;//0-360

	fHourPosTarget *= 0.5f;
	fHourPosTarget += hour*30;//0-360

	if (bAnimate)
	{
		ConvertAngle(fMinPosTarget, fMinPosDisplay);
		ConvertAngle(fHourPosTarget, fHourPosDisplay);
		ConvertAngle(fSecPosTarget, fSecPosDisplay);
	}
	else
	{
		fMinPosDisplay = fMinPosTarget;
		fHourPosDisplay = fHourPosTarget;
		fSecPosDisplay = fSecPosTarget;
		repaint();
	}
}
void CClockView::timerCallback(void)
{
	float hourPosSave = fHourPosDisplay;
	float minPosSave = fMinPosDisplay;
	float secPosSave = fSecPosDisplay;

	UpdateAngle(fMinPosTarget, fMinPosDisplay);
	UpdateAngle(fHourPosTarget, fHourPosDisplay);
	UpdateAngle(fSecPosTarget, fSecPosDisplay);

	if((hourPosSave != fHourPosDisplay)
		|| (minPosSave != fMinPosDisplay)
		|| (secPosSave != fSecPosDisplay))
	{
		repaint();
	}

	if (bUseSystemClock)
	{
		Time tempTime = Time::getCurrentTime();
		SetTime(tempTime.getHours(), tempTime.getMinutes(), tempTime.getSeconds(), tempTime.getMilliseconds());
	}
}

void CClockView::CalClockChange(int posX, int posY)
{
	float fMouseMinute;

	if (bUseSystemClock)
	{
		return;
	}

	posY -= (getWidth()/2);
	posX -= (getWidth() / 2);

	fMouseMinute = asin(posX/sqrt(float(posX*posX+posY*posY)))*30/3.1415926535f;
	if(fMouseMinute > 0)
	{
		if(posY < 0)
		{
		}
		else
		{
			fMouseMinute=30-fMouseMinute;
		}
	}
	else
	{
		if(posY < 0)
		{
			fMouseMinute = 60 + fMouseMinute;
		}
		else
		{
			fMouseMinute = 30 - fMouseMinute;
		}
	}

	int iMouseMinute = int(fMouseMinute);
	if (iMouseMinute == 60)
	{
		iMouseMinute = 0;
	}

	if (iMouseMinute > iLocalMin)
	{
		if ((iMouseMinute - iLocalMin) > 30)
		{
			iLocalHour--;
			iLocalHour %= 12;
			if (iLocalHour < 0)
			{
				iLocalHour += 12;
			}
		}
	}
	else
	{
		if ((iLocalMin - iMouseMinute) > 30)
		{
			iLocalHour++;
			iLocalHour %= 12;
		}
	}
	fMouseMinute -= float(iMouseMinute);
	SetTime(iLocalHour, iMouseMinute, int(fMouseMinute*60));
}

void CClockView::ShowClockNumber(bool bShow)
{
	bDisNum = bShow;
	repaint();
}

void CClockView::ShowDigitalClock(bool bShow)
{
	bShowDigitalClock = bShow;
	repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="CClockView" componentName=""
                 parentClasses="public Component, public Timer" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffe9bd"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
