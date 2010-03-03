#ifndef LIST_H
#define LIST_H
#include "../Menu/MenuController.h"
#include "../Menu/Menus/MenuSet.h"
#include "../Menu/Menus/Extended/ExtendedMenuController.h"
#ifdef _WIN32
    #include "../../Win32/Core/Console.h"
#endif
class List
{
private:
    MenuSet MenuSetObj;
    MenuController MenuControllerObj;
    ExtendedMenuController ExtendedMenuControllerObj;
    Console ConsoleObj;
public:
    List();
    ~List();
    bool SetList();
    int BrowseList();
};
#endif
