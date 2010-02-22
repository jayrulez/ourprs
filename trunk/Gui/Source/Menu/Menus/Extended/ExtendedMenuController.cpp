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
void ExtendedMenuController::ExtendedMenuParser()
{
    ScreenObj.ClearScreen();
    switch(Key)
    {
        case F1_KEY:
            HelpObj.ShowHelpMenuTitle(ON);
            HelpObj.ShowHelpInfo();
        break;

        case F3_KEY:
            AboutObj.ShowAboutMenuTitle(ON);
            AboutObj.ShowAboutInfo();
        break;
    }
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
                read=true;
            break;
        }
    }
    return 0;
}
