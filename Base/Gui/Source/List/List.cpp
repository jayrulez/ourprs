#include "List.h"
#include "../Menu/MenuController.h"
#include "../Menu/Menus/MenuSet.h"
#include "../Menu/Menus/Extended/ExtendedMenuController.h"
#ifdef _WIN32
    #include "../../Win32/Core/Console.h"
#endif
#include <iostream>

using namespace std;

List::List()
{
}
List::~List()
{
}
bool List::SetList()
{
    if(MenuControllerObj.SetMenu(MenuSetObj.ListMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ListMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ListMenu())))
    {
        return true;
    }
    return false;
}
int List::BrowseList()
{
    if(SetList())
    {
        MenuControllerObj.ShowMenu();
        MenuControllerObj.BrowseMenu();
    }
    return 0;
}
