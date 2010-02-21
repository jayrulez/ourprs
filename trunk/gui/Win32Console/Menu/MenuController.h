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
#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "Item.h"
#include "Scroller.h"
#include "../core/Console.h"
#include "../Tools/Frame.h"
#include "../Screen/Screen.h"
#include "Menus/Extended/ExtendedMenuController.h"
#include "../Form/FormController.h"

#define SEARCH_MENU_Y_ERROR 0x6000
#define SEARCH_MENU_X_ERROR 0x6001
#define ITEM_X_ERROR 0x6002
#define ITEM_Y_ERROR 0x6003
#define BROWSE_ERROR 0x6004

#define OUT_OF_MENU_RANGE 0
#define IN_MENU_RANGE 1

#define _NEXT 1
#define _PREV 0

class MenuController
{
private:
    Console ConsoleObj;
    Scroller ScrollerObj;
    Screen ScreenObj;
    Frame FrameObj;
    ExtendedMenuController ExtendedMenuControllerObj;
    Item *iptr;
    int size;
    int MenuCode;
    bool VerticalRangeCheck;
    Item CurrentItem;
    Item PreviousItem;
    FormController *FormControllerObj;
public:
    MenuController();
    MenuController(Item *,int,int);
    ~MenuController();
    bool SetMenu(Item*,int,int);
    void SetMenuControllerFrameObj(Frame);
    int MenuBrowser();
    Item ItemY(int);
    Item ItemX(int);
    Item SearchMenuY(int);
    Item SearchMenuX(int);
    Item ClosestItemY(int);
    void Browse();
    void ShowMenu();
    void KillMenu();
    bool RangeCheckY(int);
    Item DefaultStartingItem();
    int ExtendedMenuCalls(int,int);
    void SetMenuFormController(FormController*);
};
#endif
