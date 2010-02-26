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
#ifndef EXTENDEDMENUCONTROLLER_H
#define EXTENDEDMENUCONTROLLER_H

#ifdef _WIN32
	#include "../../../../Win32/Core/Console.h"
#endif
#include "../../../Tools/Frame.h"
#include "../../../Screen/Screen.h"
#include "../../../Services/Services.h"
#include "Help.h"
#include "About.h"
#include "Cancel.h"

class ExtendedMenuController
{
private:
    Console ConsoleObj;
    Screen ScreenObj;
    Frame FrameObj;
    Services ServicesObj;
    Help HelpObj;
    About AboutObj;
    Cancel CancelObj;
    int Key;
    int CurrentCode;
public:
    ExtendedMenuController();
    ~ExtendedMenuController();
    bool SetExtendedMenu(int, int);
    int ExtendedMenuBrowser();
    bool ExtendedMenuParser();
	bool ExtendedMenuCalls(int,int);
};
#endif
