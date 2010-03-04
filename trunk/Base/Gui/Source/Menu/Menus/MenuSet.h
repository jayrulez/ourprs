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

/*
 *Menu Codes
*/
#define MAIN_CODE 1000
#define DEPARTMENT_CODE 2000
#define EMPLOYEE_CODE 3000
#define PAYROLL_CODE 4000
#define EXIT_CODE 5000
//End Codes

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

    //Department Menu Set
    Item* DepartmentMenu();
    Item* UpdateDepartmentFormMenu();
    void UpdateDepartmentFormMenuExtension(int);
    Item* ViewDepartmentMenu();
    Item* ViewAllDepartmentMenu();
    void ViewAllDepartmentMenuExtension(int);
    void ViewDepartmentMenuExtension(int);

    //Employee Menu Set
    Item* EmployeeMenu();
    Item* UpdateEmployeeFormMenu();
    Item* ViewEmployeeMenu();
    Item* ViewAllEmployeeMenu();
    void ViewAllEmployeeMenuExtension(int);
    void ViewEmployeeMenuExtension(int);
    Item* ViewSortedEmployeeMenu();
    void ViewSortedEmployeeMenuExtension(int);

    //Payroll Menu Set
    Item* PayrollMenu();
    Item* ViewSortedPayrollMenu();
    void ViewSortedPayrollMenuExtension(int);
    Item* ViewPayrollMenu();
    void ViewPayrollMenuExtension(int);

    //General Forms Menu Set
    Item* GeneralFormMenu();
    void GeneralFormMenuExtension(int);
    Item* EditFormMenu();

    //List Menu Set
    Item* ListMenu();
    void DimPrevious();
    void DimNext();
};
#endif // MENUSET_H
