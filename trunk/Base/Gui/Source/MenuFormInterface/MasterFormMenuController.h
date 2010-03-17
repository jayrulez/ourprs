#ifndef MASTERFORMCONTROLLER_H
#define MASTERFORMCONTROLLER_H
#include "../Form/Field.h"
#include "../Menu/MenuController.h"
#include "../Form/FormController.h"
#include "../Menu/Menus/MenuSet.h"
#include "../Form/FormController.h"
#include "../Form/FormSet/FormSet.h"
#include "../List/List.h"
#include "../Menu/Menus/Extended/ExtendedMenuController.h"
#include "../Services/Services.h"

class MasterFormMenuController
{
private:
    Services ServicesObj;
    MenuController MenuControllerObj;
    MenuSet MenuSetObj;
    FormController FormControllerObj;
    ExtendedMenuController ExtendedMenuControllerObj;
    FormSet FormSetObj;
    List ListObj;
    Field* FieldObj;
    int FormSize;
    int YRelativeSystemFrame;
public:
	MasterFormMenuController();
	~MasterFormMenuController();
	int GetFormSize();
    Field* GetAllFieldData();
    void ClearAllFieldData();
    void SetAllFieldData(Field*);
    void SetYRelativeSystemFrame(int);

	//Main Menu
	int MainMenu();

    //Department
	int DepartmentMenu();
	int AddDepartmentMenu();
	int UpdateSearchDepartmentMenu();
    int UpdateDepartmentMenu();
    int ViewSearchDepartmentMenu();
    int ViewAllDepartmentMenu();
    int DepartmentAfterViewMenu();
	int AddDepartmentAfterSaveMenu();
	int AddDepartmentFailSaveMenu();
	int UpdateDepartmentAfterSaveMenu();
	int UpdateDepartmentFailSaveMenu();

    //Employee
	int EmployeeMenu();
	int AddEmployeeMenu();
	int AddEmployeeAfterSaveMenu();
	int AddEmployeeFailSaveMenu();
	int SearchEmployeeMenu();
    int UpdateEmployeeMenu();
    int UpdateEmployeeAfterSaveMenu();
	int UpdateEmployeeFailSaveMenu();
    int ViewEmployeeMenu();
    int EmployeeAfterViewMenu();
    int ViewSortedEmployeeMenu();
    int EmployeeAfterViewSortedMenu();
    int EmployeeDeleteConfirmMenu();
    int EmployeeAfterDeleteMenu();
    int EmployeeFailDeleteMenu();

    //Payroll
	int PayrollMenu();
	int PayrollAfterProcessMenu();
	int PayrollFailProcessMenu();
	int SearchPayrollMenu();
	void SearchPayrollFormMenuExtension(int);
	int ViewPayrollMenu();
    int ViewSortedPayrollMenu();
    int PayrollAfterViewSortedMenu();
    int PayrollFailViewSortedMenu();

    //Exit
	int ExitMenu();
};
#endif
