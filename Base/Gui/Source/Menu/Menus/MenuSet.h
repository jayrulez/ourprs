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


//Department
    //add
#define DEPARTMENT_CODE 2000
#define DEPARTMENT_ADD_CODE 2100
#define DEPARTMENT_ADD_SAVE_CODE 2110
#define DEPARTMENT_ADD_RESET_CODE 2220
    //update
#define DEPARTMENT_UPDATE_CODE 2200
#define DEPARTMENT_UPDATE_FORM_MENU_CODE 2210
#define DEPARTMENT_UPDATE_RESET_CODE 2220
#define DEPARTMENT_UPDATE_SAVE_CODE 2230
    //view
#define DEPARTMENT_VIEW_CODE 2300
#define DEPARTMENT_LIST_CODE 2400
#define DEPARTMENT_SEARCH_CODE 2500


//Employee
    //add
#define EMPLOYEE_CODE 3000
#define EMPLOYEE_ADD_CODE 3100
#define EMPLOYEE_ADD_SAVE_CODE 3110
#define EMPLOYEE_ADD_RESET_CODE 3120
    //update
#define EMPLOYEE_UPDATE_CODE 3200
#define EMPLOYEE_UPDATE_FORM_RESET_CODE 3210
#define EMPLOYEE_UPDATE_SAVE_CODE 3220
    //view
#define EMPLOYEE_VIEW_CODE 3300
    //view sorted
#define EMPLOYEE_VIEW_SORTED_CODE 3400
	#define EMPLOYEE_VIEW_SORTED_CODE_BY_ID 3401
	#define EMPLOYEE_VIEW_SORTED_CODE_BY_FIRSTNAME 3402
	#define EMPLOYEE_VIEW_SORTED_CODE_BY_LASTNAME 3403
	#define EMPLOYEE_VIEW_SORTED_CODE_BY_DEPTCODE 3404
	#define EMPLOYEE_VIEW_SORTED_CODE_BY_POSITION 3405
	#define EMPLOYEE_VIEW_SORTED_CODE_BY_HOURSWORKED 3406
    //delete
#define EMPLOYEE_DELETE_CODE 3500
#define EMPLOYEE_DELETE_CONFIRM_MENU_CODE 3510
    //search
#define EMPLOYEE_SEARCH_CODE 3600
#define EMPLOYEE_SEARCH_SUBMIT_CODE 3610


//Payroll
#define PAYROLL_CODE 4000
    //process
#define PAYROLL_PROCESS_CODE 4100
#define PAYROLL_PRINT_CODE 4110
    //view
#define PAYROLL_VIEW_CODE 4200
    //view sorted
#define PAYROLL_VIEW_SORTED_CODE 4300
	#define PAYROLL_VIEW_SORTED_CODE_BY_ID 4301
	#define PAYROLL_VIEW_SORTED_CODE_BY_FIRSTNAME 4302
	#define PAYROLL_VIEW_SORTED_CODE_BY_LASTNAME 4303
	#define PAYROLL_VIEW_SORTED_CODE_BY_DEPTCODE 4304
	#define PAYROLL_VIEW_SORTED_CODE_BY_POSITION 4305
	#define PAYROLL_VIEW_SORTED_CODE_BY_HOURSWORKED 4306
    //search
#define PAYROLL_SEARCH_SUBMIT_CODE 4400

//exit
#define EXIT_CODE 5000
//End Codes

using namespace std;

class MenuSet
{
private:
    int MenuCode;
    int MenuSize;
    int YRelativeSystemFrame;
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
    void SetMenuTitle(string);
    void ShowMenuTitle(int);
    void SetYRelativeSystemFrame(int);

    Item* MainMenu();

    //Department Menu Set
    Item* DepartmentMenu();
    Item* UpdateSearchDepartmentFormMenu();
    void SearchDepartmentFormMenuExtension(int);
    Item* ViewSearchDepartmentFormMenu();
    Item* DepartmentAfterViewMenu();
    Item* ViewAllDepartmentMenu();
    void ViewAllDepartmentMenuExtension(int);
    void ViewDepartmentMenuExtension(int);
    Item* AddDepartmentFailSaveMenu();
    Item* UpdateDepartmentFailSaveMenu();

    //Employee Menu Set
    Item* EmployeeMenu();
    Item* AddEmployeeAfterSaveMenu();
    Item* AddEmployeeFailSaveMenu();
    Item* SearchEmployeeFormMenu();
    void SearchEmployeeFormMenuExtension(int);
    Item* UpdateEmployeeAfterSaveMenu();
    Item* UpdateEmployeeFailSaveMenu();
    void ViewEmployeeMenuExtension(int);
    Item* EmployeeAfterViewMenu();
    Item* ViewSortedEmployeeMenu();
    void ViewSortedEmployeeMenuExtension(int);
    void EmployeeAfterViewSortedMenuExtension(int);
    Item* EmployeeAfterViewSortedMenu();
    Item* DeleteConfirmEmployeeMenu();
    void DeleteConfirmEmployeeMenuExtension(int);
    Item* EmployeeAfterDeleteMenu();
    Item* EmployeeFailDeleteMenu();


    //Payroll Menu Set
    Item* PayrollMenu();
    Item* PayrollAfterGenerateMenu();
    Item* PayrollFailGenerateMenu();
    Item* SearchPayrollFormMenu();
    void SearchPayrollFormMenuExtension(int);
    Item* ViewSortedPayrollMenu();
    void ViewSortedPayrollMenuExtension(int);
    Item* PayrollAfterViewSortedMenu();
    Item* PayrollFailViewSortedMenu();
    Item* ViewPayrollMenu();
    void ViewPayrollMenuExtension(int);
    Item* AddDepartmentAfterSaveMenu();
    Item* UpdateDepartmentAfterSaveMenu();

    //General Forms Menu Set
    Item* AddDepartmentFormMenu();
    void AddDepartmentFormMenuExtension(int);
    Item* UpdateDepartmentFormMenu();
    void UpdateDepartmentFormMenuExtension(int);
    Item* AddEmployeeFormMenu();
    void AddEmployeeFormMenuExtension(int);
    Item* UpdateEmployeeFormMenu();
    void UpdateEmployeeFormMenuExtension(int);


    //List Menu Set
    Item* ListMenu();
    void DimPrevious();
    void DimNext();
};
#endif // MENUSET_H
