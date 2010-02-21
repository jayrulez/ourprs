#include "ExtendedMenuController.h"
#include "../../../Core/Console.h"
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
