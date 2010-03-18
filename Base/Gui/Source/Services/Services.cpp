#include "Services.h"
#include <iostream>

#include "../Menu/Menus/Extended/About.h"
#include "../Menu/Menus/Extended/Help.h"
#include "../Tools/Frame.h"
#include "../Tools/Colour.h"
#include "../Screen/Screen.h"
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
	#include "../../Win32/Media/Media.h"
#endif
#include <string>

using namespace std;

Services::Services()
{

}
Services::~Services()
{

}
void Services::SystemTitle()
{
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    ConsoleObj.xyCoord(2,1);
    cout<<"SSN Payroll Management System";
}
void Services::SystemClearScreen()
{
    ScreenObj.ClearScreen();
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    this->SystemTitle();
}
void Services::SystemChangeScreenSound()
{
    MediaObj.PlayWav(ScreenChangeSound);
}
void Services::SystemChangeScreen()
{
    ScreenObj.ClearScreen();
    FrameObj.ResetScreenFrame();
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    ConsoleObj.xyCoord(2,1);
    cout<<"SSN Payroll Management System";
    SystemChangeScreenSound();
}
void Services::SizeConsoleWindow()
{
    ConsoleObj.CenterConsole(680,680);
    this->DefaultScreenBufferSize();
}
void Services::DefaultScreenBufferSize()
{
    ConsoleObj.SetConsoleBufferHeigth(STANDARD_FRAME_HEIGHT+2);
}
void Services::MaximumScreenBufferSize()
{
    ConsoleObj.SetConsoleBufferHeigth(MAX_SCREEN_BUFFER);
}
void Services::Title(string Title)
{
    ConsoleObj.SetCurrentConsoleTitle(Title);
}
void Services::BasicRunLevel()
{
    ScreenObj.SetScreenColour(DefaultBgColour);
    ScreenObj.SetScreenTextColour(DefaultTextColour);

    if(FrameObj.SetFrame(0,STANDARD_FRAME_WIDTH,0,STANDARD_FRAME_HEIGHT,SCREEN_FRAME))
    {
        FrameObj.dFraming();
    }

    SystemTitle();

    HelpObj.ShowHelpMenu();
    AboutObj.ShowAboutMenu();

    ConsoleObj.xyCoord(0,0);
}
int Services::DynamicRunLevel()
{
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    FrameObj.ResetScreenFrame();
    ConsoleObj.xyCoord(0,0);
    ConsoleObj.SetConsoleBufferHeigth(FrameObj.GetFrameHeigth()+1);
    return FrameObj.GetFrameHeigth();
}
