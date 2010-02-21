#ifndef EXTENDEDMENUCONTROLLER_H
#define EXTENDEDMENUCONTROLLER_H

#include "../../../Core/Console.h"
#include "../../../Tools/Frame.h"
#include "../../../Screen/Screen.h"
#include "Help.h"
#include "About.h"

class ExtendedMenuController
{
private:
    Console ConsoleObj;
    Screen ScreenObj;
    Help HelpObj;
    About AboutObj;
    int Key;
    int CurrentCode;
public:
    ExtendedMenuController();
    ~ExtendedMenuController();
    bool SetExtendedMenu(int, int);
    int ExtendedMenuBrowser();
    void ExtendedMenuParser();
};
#endif
