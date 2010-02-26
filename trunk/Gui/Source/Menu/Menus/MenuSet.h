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
#ifndef MENUSET_H
#define MENUSET_H
#include "../Item.h"
#include "../../Tools/Line.h"
#include "../../Tools/Frame.h"
#include "../../Screen/Screen.h"
#ifdef _WIN32
	#include "../../../Win32/Core/Console.h"
#endif
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
