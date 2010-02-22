#include <iostream>
#include "Gui/Source/Menu/MenuController.h"
#include "Gui/Source/Menu/Menus/MenuSet.h"
#include "Gui/Source/Menu/Menus/Extended/About.h"
#include "Gui/Source/Menu/Menus/Extended/Help.h"
#include "Gui/Source/Tools/Frame.h"
#include "Gui/Source/Tools/Colour.h"
#include "Gui/Source/Screen/Screen.h"
#ifdef _WIN32
	#include "Gui/Win32/Core/Console.h"
#endif
#include "Gui/Source/Form/FormController.h"
#include "Gui/Source/Form/Field.h"
#include "Gui/Source/Form/FormSet/FormSet.h"

using namespace std;

void BasicRunLevel()
{
    Screen ScreenObj;
    Console ConsoleObj;
    Frame FrameObj;
    Help HelpObj;
    About AboutObj;

    ConsoleObj.CenterConsole(680,680);
    ScreenObj.SetScreenColour(DefaultBgColour);
    ScreenObj.SetScreenTextColour(DefaultTextColour);

    FrameObj.ResetScreenFrame();

    ConsoleObj.xyCoord(50,1);
    cout<<"SSN Payroll Management System";

    HelpObj.ShowHelpMenu();
    AboutObj.ShowAboutMenu();

    ConsoleObj.xyCoord(0,0);
}
int main()
{
    MenuController MenuControllerObj;
    MenuSet MenuSetObj;
    FormController FormControllerObj;
    FormSet FormSetObj;

    BasicRunLevel();
    if(FormControllerObj.SetForm(FormSetObj.AddEmployeeForm(),FormSetObj.GetFormSize(FormSetObj.AddEmployeeForm()),
    FormSetObj.GetFormCode(FormSetObj.AddEmployeeForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.GeneralFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.GeneralFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.GeneralFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
		
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.GeneralFormMenuExtension(ON);
        do
        {
            FormControllerObj.BrowseForm();
            MenuControllerObj.MenuBrowser();
        }while(true);
    }
    return 0;
}
