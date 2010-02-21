#ifndef MENU_H
#define MENU_H
#include "item.h"

#define SEARCH_MENU_Y_ERROR 0x6000
#define NEXT_ITEM_X_ERROR 0x6001
#define NEXT_ITEM_Y_ERROR 0x6002

#define _NEXT 1
#define _PREV 0

class menu
{
private:
        /*
        * instantiating an handle data type
        * that will be able to store input handles
        */
        HANDLE hIn;
        /*
        * structure that stores information on the various
        * types of console inputs
        */
        INPUT_RECORD InRec;
        /*
        * will be used to store the amount of event read
        */
        DWORD AmtRead;
public:
        menu();
        ~menu();
        int MenuBrowser(item*,int);
        int NextItemY(item* ,int,int,int);
        int NextItemX(item*,int,int,int);
        item SearchMenuY(item*,int,item,int);
        int CoreMenuBrowser(item*,int,int);
        void MenuShow(item*,int);
};
#endif
