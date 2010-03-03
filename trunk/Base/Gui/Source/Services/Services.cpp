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
    FrameObj.ResetScreenFrame();
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    ConsoleObj.xyCoord(2,1);
    cout<<"SSN Payroll Management System";
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
    ConsoleObj.SetConsoleBufferHeigth(STANDARD_FRAME_HEIGHT+2);
}
void Services::Title(string Title)
{
    ConsoleObj.SetCurrentConsoleTitle(Title);
}
void Services::BasicRunLevel()
{
    ScreenObj.SetScreenColour(DefaultBgColour);
    ScreenObj.SetScreenTextColour(DefaultTextColour);

    FrameObj.ResetScreenFrame();

    SystemTitle();

    HelpObj.ShowHelpMenu();
    AboutObj.ShowAboutMenu();

    ConsoleObj.xyCoord(0,0);
}
