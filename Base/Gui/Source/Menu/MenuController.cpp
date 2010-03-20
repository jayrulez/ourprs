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
#include "MenuController.h"
#include "../Tools/Frame.h"
#include "Item.h"
#include "../Tools/Colour.h"
#include "Menus/MenuSet.h"
#include <iostream>

using namespace std;

MenuController::MenuController()
{
}
MenuController::~MenuController()
{
}
MenuController::MenuController(Item *iptr, int size,int MenuCode)
{
    if(size>0)
    {
        this->iptr=iptr;
        this->size=size;
        this->MenuCode=MenuCode;
        this->CurrentItem=DefaultStartingItem();
        this->VerticalRangeCheck=true;
        this->HorizontalRangeCheck=true;
        this->NewInstance=true;
    }
}
/*
 *
*/
bool MenuController::SetMenu(Item *iptr, int size,int MenuCode)
{
    if(size>0)
    {
        this->iptr=iptr;
        this->size=size;
        this->MenuCode=MenuCode;
        this->CurrentItem=DefaultStartingItem();
        this->VerticalRangeCheck=true;
        this->HorizontalRangeCheck=true;
        this->NewInstance=true;
        return true;
    }
    return false;
}
int MenuController::GetMenuCode()
{
	return this->MenuCode;
}
/*
 *
*/
void MenuController::SetMenuControllerFrameObj(Frame FrameObj)
{
    this->FrameObj=FrameObj;
}
/*
 *
*/
int MenuController::BrowseMenu()
{
    bool read=false;
    ConsoleObj.SetCursor(false,1);
    while(!read)
    {
        if(HorizontalRangeCheck==IN_MENU_RANGE)
        {
            Browse();
        }
        switch(this->ValidKey())
        {
            case TAB_KEY:
            break;
            case LEFT_KEY:
                CurrentItem=ItemX(_PREV);
                if(HorizontalRangeCheck==IN_MENU_RANGE)
                {
                    MediaObj.PlayWav(MenuScrollSound);
                }
            break;
            case RIGHT_KEY:
                CurrentItem=ItemX(_NEXT);
                if(HorizontalRangeCheck==IN_MENU_RANGE)
                {
                    MediaObj.PlayWav(MenuScrollSound);
                }
            break;
            case UP_KEY:
                CurrentItem=ItemY(_PREV);
                if(VerticalRangeCheck==IN_MENU_RANGE)
                {
                    MediaObj.PlayWav(MenuScrollSound);
                }
            break;
            case DOWN_KEY:
                CurrentItem=ItemY(_NEXT);
                if(VerticalRangeCheck==IN_MENU_RANGE)
                {
                    MediaObj.PlayWav(MenuScrollSound);
                }
            break;
            case ENTER_KEY:
                //MediaObj.PlayWav(MenuSelectSound);
                return CurrentItem.GetItemCode();
            break;
            case F1_KEY:
                if(this->MenuCode==MAIN_CODE || this->MenuCode==DEPARTMENT_CODE || this->MenuCode==EMPLOYEE_CODE
                || this->MenuCode==PAYROLL_CODE)
                    return F1_KEY;
            break;
            case F3_KEY:
                if(this->MenuCode==MAIN_CODE || this->MenuCode==DEPARTMENT_CODE || this->MenuCode==EMPLOYEE_CODE
                || this->MenuCode==PAYROLL_CODE)
                    return F3_KEY;
            break;
        }
        if(VerticalRangeCheck==OUT_OF_MENU_RANGE)
        {
            read=true;
            VerticalRangeCheck=IN_MENU_RANGE;
            if(ScrollerObj.SetScroller(PreviousItem.GetItemX(),PreviousItem.GetItemY(),PreviousItem.GetItemLenght(),48))
            {
                ScrollerObj.KillScroll();
            }
        }
        if(HorizontalRangeCheck==OUT_OF_MENU_RANGE)
        {
            HorizontalRangeCheck=IN_MENU_RANGE;
        }

    }
    return 0;
}
/*
*
*/
int MenuController::ValidKey()
{
    int Key;
    do
    {
        Key=ConsoleObj.ReadConsoleVirtualKeyInput();
    }while(Key!=UP_KEY &&Key!=DOWN_KEY &&Key!=LEFT_KEY &&Key!=RIGHT_KEY &&Key!=F1_KEY &&Key!=F3_KEY &&Key!=ENTER_KEY);
    return Key;
}
void MenuController::Browse()
{
    if(!this->NewInstance)
    {
        if(ScrollerObj.SetScroller(PreviousItem.GetItemX(),PreviousItem.GetItemY(),PreviousItem.GetItemLenght(),48))
        {
            ScrollerObj.KillScroll();
        }
    }
    if(ScrollerObj.SetScroller(CurrentItem.GetItemX(),CurrentItem.GetItemY(),CurrentItem.GetItemLenght(),48))
    {
        ScrollerObj.scroll();
    }
    this->NewInstance=false;
}
/*
 *
*/
Item MenuController::DefaultStartingItem()
{
    Item TempItem;
    TempItem=*(iptr+0);
    for(int y=0;y<size;y++)
    {
        if((iptr+y)->GetItemY()<TempItem.GetItemY())
        {
            TempItem=*(iptr+y);
        }
    }
    for(int x=0;x<size;x++)
    {
        if((iptr+x)->GetItemX()<TempItem.GetItemX()&&(iptr+x)->GetItemY()==TempItem.GetItemY())
        {
            TempItem=*(iptr+x);
        }
    }
    return TempItem;
}
/*
 * This function is used to return the vertical range of any menu
*/
Item MenuController::ItemY(int type)
{
    PreviousItem=CurrentItem;
	switch(type)
	{
		case _NEXT:
            return SearchMenuY(_NEXT);
        break;
		case _PREV:
            return SearchMenuY(_PREV);
        break;
	}
	throw ITEM_Y_ERROR;
}
/*
 * This function is used to return the horizontal range of any menu
*/
Item MenuController::ItemX(int type)
{
    PreviousItem=CurrentItem;
	switch(type)
	{
		case _NEXT:
            return SearchMenuX(_NEXT);
        break;
		case _PREV:
            return SearchMenuX(_PREV);
        break;
	}
	throw ITEM_X_ERROR;
}
/*
 * This function is used to return the vertical range of any menu
*/
Item MenuController::SearchMenuY(int type)
{
    Item TempItem=CurrentItem;
    int x;
    int y;
    bool FoundInline=false;
	switch(type)
	{
		case _NEXT:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemY()>CurrentItem.GetItemY() && (iptr+x)->GetItemX()==CurrentItem.GetItemX())
                {
                    TempItem=*(iptr+x);
                    FoundInline=true;
                    for(y=0;y<size;y++)
                    {
                        if((iptr+y)->GetItemY()<TempItem.GetItemY() && (iptr+y)->GetItemY()>CurrentItem.GetItemY()&&
                        (iptr+y)->GetItemX()==CurrentItem.GetItemX())
                        {
                            TempItem=*(iptr+y);
                        }
                    }
                }
            }
            if(!FoundInline && RangeCheckY(_NEXT)==IN_MENU_RANGE)
                TempItem=ClosestItemY(_NEXT);
            else if(RangeCheckY(_NEXT)==OUT_OF_MENU_RANGE)
                VerticalRangeCheck=OUT_OF_MENU_RANGE;
            return TempItem;
        break;

		case _PREV:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemY()<CurrentItem.GetItemY() && (iptr+x)->GetItemX()==CurrentItem.GetItemX())
                {
                    TempItem=*(iptr+x);
                    FoundInline=true;
                    for(y=0;y<size;y++)
                    {
                        if((iptr+y)->GetItemY()>TempItem.GetItemY() &&(iptr+y)->GetItemY()<CurrentItem.GetItemY()&&
                        (iptr+y)->GetItemX()==CurrentItem.GetItemX())
                        {
                            TempItem=*(iptr+y);
                        }
                    }
                    break;
                }
            }
            if(!FoundInline && RangeCheckY(_PREV)==IN_MENU_RANGE)
                TempItem=ClosestItemY(_PREV);
            else if(RangeCheckY(_PREV)==OUT_OF_MENU_RANGE)
                VerticalRangeCheck=OUT_OF_MENU_RANGE;
            return TempItem;
        break;
	}
    throw SEARCH_MENU_Y_ERROR;
}
/*
 *
*/
Item MenuController::SearchMenuX(int type)
{
    int x;
    int y;
    bool FoundInline=false;
    Item TempItem=CurrentItem;
	switch(type)
	{
		case _NEXT:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemX()>CurrentItem.GetItemX() && (iptr+x)->GetItemY()==CurrentItem.GetItemY())
                {
                    TempItem=*(iptr+x);
                    FoundInline=true;
                    for(y=0;y<size;y++)
                    {
                        if((iptr+y)->GetItemX()<TempItem.GetItemX() && (iptr+y)->GetItemX()>CurrentItem.GetItemX()&&
                        (iptr+y)->GetItemY()==CurrentItem.GetItemY())
                        {
                            TempItem=*(iptr+y);
                        }
                    }
                    break;
                }
            }
            if(RangeCheckX(_NEXT)==OUT_OF_MENU_RANGE)
                HorizontalRangeCheck=OUT_OF_MENU_RANGE;
            else if(!FoundInline)
                HorizontalRangeCheck=OUT_OF_MENU_RANGE;
            return TempItem;
        break;

		case _PREV:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemX()<CurrentItem.GetItemX() && (iptr+x)->GetItemY()==CurrentItem.GetItemY())
                {
                    TempItem=*(iptr+x);
                    FoundInline=true;
                    for(y=0;y<size;y++)
                    {
                        if((iptr+y)->GetItemX()>TempItem.GetItemX() && (iptr+y)->GetItemX()<CurrentItem.GetItemX()&&
                        (iptr+y)->GetItemY()==CurrentItem.GetItemY())
                        {
                            TempItem=*(iptr+y);
                        }
                    }
                    break;
                }
            }
            if(RangeCheckX(_PREV)==OUT_OF_MENU_RANGE)
                HorizontalRangeCheck=OUT_OF_MENU_RANGE;
            else if(!FoundInline)
                HorizontalRangeCheck=OUT_OF_MENU_RANGE;
            return TempItem;
        break;
	}
    throw SEARCH_MENU_X_ERROR;
}
/*
 *
*/
Item MenuController::ClosestItemY(int type)
{
    int x;
    int y;
    Item TempItem;
    Item TempCacheItem;
    switch(type)
    {
        case _PREV:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemY()<CurrentItem.GetItemY())
                {
                    TempItem=*(iptr+x);
                    TempCacheItem=TempItem;
                    for(y=0;y<size;y++)
                    {
                        if((iptr+y)->GetItemY()>TempItem.GetItemY() && (iptr+y)->GetItemY()<CurrentItem.GetItemY())
                        {
                            TempItem=*(iptr+y);
                            TempCacheItem=TempItem;
                        }
                    }
                    for(x=0;x<size;x++)
                    {
                        if((iptr+x)->GetItemX()<CurrentItem.GetItemX()&&TempCacheItem.GetItemY()==(iptr+x)->GetItemY())
                        {
                            TempCacheItem=*(iptr+x);
                            for(y=0;y<size;y++)
                            {
                                if((iptr+y)->GetItemX()>=TempCacheItem.GetItemX() && (iptr+y)->GetItemX()<=CurrentItem.GetItemX()&&TempCacheItem.GetItemY()==(iptr+y)->GetItemY())
                                {
                                    TempCacheItem=*(iptr+y);
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            return TempCacheItem;
        break;
        case _NEXT:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemY()>CurrentItem.GetItemY())
                {
                    TempItem=*(iptr+x);
                    TempCacheItem=TempItem;
                    for(y=0;y<size;y++)
                    {
                        if((iptr+y)->GetItemY()<TempItem.GetItemY() && (iptr+y)->GetItemY()>CurrentItem.GetItemY())
                        {
                            TempItem=*(iptr+y);
                            TempCacheItem=TempItem;
                        }
                    }
                    for(x=0;x<size;x++)
                    {
                        if((iptr+x)->GetItemX()>CurrentItem.GetItemX()&&TempCacheItem.GetItemY()==(iptr+x)->GetItemY())
                        {
                            TempCacheItem=*(iptr+x);
                            for(y=0;y<size;y++)
                            {
                                if((iptr+y)->GetItemX()<=TempCacheItem.GetItemX() && (iptr+y)->GetItemX()>=CurrentItem.GetItemX()&&TempCacheItem.GetItemY()==(iptr+y)->GetItemY())
                                {
                                    TempCacheItem=*(iptr+y);
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            return TempCacheItem;
        break;
    }
    throw 1;
}
/*
 *
*/
bool MenuController::RangeCheckY(int type)
{
    int x;
    switch(type)
    {
        case _NEXT:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemY()>CurrentItem.GetItemY())
                {

                    return IN_MENU_RANGE;
                }
            }
        break;
        case _PREV:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemY()<CurrentItem.GetItemY())
                {

                    return IN_MENU_RANGE;
                }
            }
        break;
    }
    return OUT_OF_MENU_RANGE;
}
bool MenuController::RangeCheckX(int type)
{
    int x;
    switch(type)
    {
        case _NEXT:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemX()>CurrentItem.GetItemX())
                {

                    return IN_MENU_RANGE;
                }
            }
        break;
        case _PREV:
            for(x=0;x<size;x++)
            {
                if((iptr+x)->GetItemX()<CurrentItem.GetItemX())
                {

                    return IN_MENU_RANGE;
                }
            }
        break;
    }
    return OUT_OF_MENU_RANGE;
}
/*
 *
*/
void MenuController::ShowMenu()
{
    int x;
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    for (x=0;x<size;x++)
    {
        (iptr+x)->born();
    }
}
/*
 *
*/
void MenuController::KillMenu()
{
    int x;
    ScreenObj.SetScreenTextColour(DefaultBgColour);
    for (x=0;x<size;x++)
    {
        (iptr+x)->born();
    }
    ScreenObj.SetScreenTextColour(DefaultTextColour);
}
