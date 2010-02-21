#ifndef MENUSET_H
#define MENUSET_H
#include "../Item.h"
#include "../../Tools/Line.h"
#include "../../Tools/Frame.h"
#include "../../Screen/Screen.h"
#include "../../Core/Console.h"
#define ON 1
#define OFF 2
#include <string>
#define MENU_TITLE_JOINT 194
using namespace std;

class MenuSet
{
private:
    int MenuCode;
    int MenuSize;
    string MenuTitle;
    Line LineObj;
    Screen ScreenObj;
    Console ConsoleObj;
    Frame FrameObj;
public:
    MenuSet();
    ~MenuSet();
    int GetMenuSize(Item*);
    int GetMenuCode(Item*);
    string GetMenuTitle();
    void ShowMenuTitle(int);
    void SetMenuTitle(string);
    Item* MainMenu();
    Item* DepartmentMenu();
    Item* EmployeeMenu();
    Item* PayrollMenu();
    Item* ViewSortedEmployeeMenu();
    void ViewSortedEmployeeMenuExtension(int);
    Item* ViewSortedPayrollMenu();
    void ViewSortedPayrollMenuExtension(int);
    Item* GeneralFormMenu();
    void GeneralFormMenuExtension(int);
};
#endif // MENUSET_H
