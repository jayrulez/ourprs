#include "Services.h"
#include <iostream>

#include "../Menu/Menus/Extended/About.h"
#include "../Menu/Menus/Extended/Help.h"
#include "../Tools/Frame.h"
#include "../Tools/Colour.h"
#include "../Screen/Screen.h"
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
#endif

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
    ConsoleObj.xyCoord(50,1);
    cout<<"SSN Payroll Management System";
}
void Services::SystemClearScreen()
{
    ScreenObj.ClearScreen();
    FrameObj.ResetScreenFrame();
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    ConsoleObj.xyCoord(50,1);
    cout<<"SSN Payroll Management System";
}
void Services::BasicRunLevel()
{

    ConsoleObj.CenterConsole(680,680);
    ScreenObj.SetScreenColour(DefaultBgColour);
    ScreenObj.SetScreenTextColour(DefaultTextColour);

    FrameObj.ResetScreenFrame();

    SystemTitle();

    HelpObj.ShowHelpMenu();
    AboutObj.ShowAboutMenu();

    ConsoleObj.xyCoord(0,0);
}
