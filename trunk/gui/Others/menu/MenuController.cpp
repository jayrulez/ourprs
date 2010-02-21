#include "menu.h"

menu::menu()
{
}
menu::~menu()
{
}
int menu::MenuBrowser(item *iptr,int size)
{
    bool read=false;
    /*
    * gets the console input handle and stores it
    */
    hIn=GetStdHandle(STD_INPUT_HANDLE);
    while(!read)
    {
        /*
        * This funtion reads the console input, both
        * keyboard and mouse
        */
        ReadConsoleInput(hIn,&InRec,1,&AmtRead);
        /*
        * case used to render the type of input,
        * wether KEY or MOUSE
        */
        switch(InRec.EventType)
        {
            case KEY_EVENT:
                /*
                * checks for a key being pressed
                * (going down)
                */
                if(InRec.Event.KeyEvent.bKeyDown)
                {
                    /*
                    * filters the type of key being pressed
                    */
                    switch(InRec.Event.KeyEvent.wVirtualKeyCode)
                    {
                        /*
                        * Tab key
                        */
                        case VK_TAB:
                        /*
                        * Left arrow key
                        */
                        case VK_LEFT:

                        /*
                        * Right arrow key
                        */
                        case VK_RIGHT:
                        /*
                        * Up arrow key
                        */
                        case VK_UP:
                        /*
                        * Down arrow key
                        */
                        case VK_DOWN:
                        /*
                        * Enter key
                        */
                        break;
                        case VK_RETURN:

                        break;
                    }
                }
            break;
        }
    }
    return 0;
}
/*
* This function is used to return the vertical range of any menu
*/
int menu::NextItemY(item *iptr,int size,int CurrentItemCode,int type)
{
    item CurrentItem;
    for(int x=0;x<size;x++)
    {
        if((iptr+x)->GetItemCode()==CurrentItemCode)
        {
            CurrentItem=*(iptr+x);
            break;
        }
    }
	switch(type)
	{
		case _NEXT:
            SearchMenuY(iptr,size,CurrentItem,_NEXT);
            //CurrentItem.
        break;
		case _PREV:
            SearchMenuY(iptr,size,CurrentItem,_PREV);
        break;
	}
	throw NEXT_ITEM_Y_ERROR;
	return 0;
}
/*
* This function is used to return the vertical range of any menu
*/
item menu::SearchMenuY(item *iptr,int size,item CurrentItem,int type)
{
    item TempItem;
    TempItem=CurrentItem;
	switch(type)
	{
		case _NEXT:
            for(int x=0;x<size;x++)
            {
                if(TempItem.GetItemY()<(iptr+x)->GetItemY())
                {
                    TempItem=*(iptr+x);
                    for(int y=x;y<size;y++)
                    {
                        if((iptr+y)->GetItemY()<TempItem.GetItemY()&&(iptr+y)->GetItemY()>CurrentItem.GetItemY())
                        {
                            TempItem=*(iptr+y);
                        }
                    }
                }
            }
            return TempItem;
        break;

		case _PREV:
            for(int x=0;x<size;x++)
            {
                if(TempItem.GetItemY()>(iptr+x)->GetItemY())
                {
                    TempItem=*(iptr+x);
                    for(int y=x;y<size;y++)
                    {
                        if((iptr+y)->GetItemY()>TempItem.GetItemY()&&(iptr+y)->GetItemY()<CurrentItem.GetItemY())
                        {
                            TempItem=*(iptr+y);
                        }
                    }
                }
            }
            return TempItem;
        break;
	}
    throw SEARCH_MENU_Y_ERROR;
}
/*
* This function is used to return the horizontal range of any menu
*/
int menu::NextItemX(item *iptr,int size,int CurrentItemCode,int type)
{
	switch(type)
	{
		case _NEXT:
        break;
		case _PREV:
        break;
	}
	throw NEXT_ITEM_X_ERROR;
}
int menu::CoreMenuBrowser(item *iptr,int size,int KeyEvent)
{
    return 0;
}
void menu::MenuShow(item *iptr,int size)
{
    int x;
    for (x=0;x<size;x++)
    {
        (iptr+x)->born();
    }
}

