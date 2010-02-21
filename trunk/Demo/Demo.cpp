#include <iostream>
#include "../gui/Win32Console/Menu/MenuController.h"
#include "../gui/Win32Console/Menu/Menus/MenuSet.h"
#include "../gui/Win32Console/Menu/Menus/Extended/About.h"
#include "../gui/Win32Console/Menu/Menus/Extended/Help.h"
#include "../gui/Win32Console/Tools/Frame.h"
#include "../gui/Win32Console/Tools/Colour.h"
#include "../gui/Win32Console/Screen/Screen.h"
#include "../gui/Win32Console/core/Console.h"
#include "../gui/Win32Console/Form/FormController.h"
#include "../gui/Win32Console/Form/Field.h"
#include "../gui/Win32Console/Form/FormSet/FormSet.h"

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
        MenuControllerObj.SetMenuFormController(&FormControllerObj);
        FormControllerObj.SetFormMenuController(&MenuControllerObj);
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
