/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
	</ul>
@
*/
#include "ExtendedMenuController.h"
#ifdef _WIN32
	#include "../../../../Win32/Core/Console.h"
#endif
#include "../../../Tools/Colour.h"
#include "Help.h"
#include "About.h"

ExtendedMenuController::ExtendedMenuController()
{
}

ExtendedMenuController::~ExtendedMenuController()
{
}
bool ExtendedMenuController::SetExtendedMenu(int Key, int CurrentCode)
{
    this->Key=Key;
    this->CurrentCode=CurrentCode;
    return true;
}
bool ExtendedMenuController::ExtendedMenuParser()
{
    switch(Key)
    {
        case F1_KEY:
            ServicesObj.SystemClearScreen();
            HelpObj.ShowHelpMenuTitle(ON);
            HelpObj.ShowHelpInfo();
            CancelObj.ShowCancelMenu();
			return true;
        break;

        case F3_KEY:
            ServicesObj.SystemClearScreen();
            AboutObj.ShowAboutMenuTitle(ON);
            AboutObj.ShowAboutInfo();
            CancelObj.ShowCancelMenu();
			return true;
        break;
    }
	return false;
}
int ExtendedMenuController::ExtendedMenuBrowser()
{
    bool read=false;
    ConsoleObj.SetCursor(false,1);
    while(!read)
    {
        switch(ConsoleObj.ReadConsoleVirtualKeyInput())
        {
            case ESC_KEY:
                ScreenObj.ClearScreen();
                ServicesObj.BasicRunLevel();
                read=true;
            break;
        }
    }
    return 0;
}
/*
 *
*/
bool ExtendedMenuController::ExtendedMenuCalls(int Key,int CurrentCode)
{
    if(SetExtendedMenu(Key,CurrentCode))
    {
        if(ExtendedMenuParser())
		{
			ExtendedMenuBrowser();
			return true;
		}
    }
    return false;
}
