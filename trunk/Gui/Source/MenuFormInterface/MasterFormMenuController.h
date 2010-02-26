#ifndef MASTERFORMCONTROLLER_H
#define MASTERFORMCONTROLLER_H

#include "../Menu/MenuController.h"
#include "../Form/FormController.h"
#include "../Menu/Menus/MenuSet.h"
#include "../Form/FormController.h"
#include "../Form/FormSet/FormSet.h"
#include "../List/List.h"
#include "../Menu/Menus/Extended/ExtendedMenuController.h"

class MasterFormMenuController
{
private:
    MenuController MenuControllerObj;
    MenuSet MenuSetObj;
    FormController FormControllerObj;
    ExtendedMenuController ExtendedMenuControllerObj;
    FormSet FormSetObj;
    List ListObj;
public:
	MasterFormMenuController();
	~MasterFormMenuController();
	int MainMenu();

	int DepartmentMenu();
	int AddDepartmentMenu();
	int SearchDepartmentMenu();
    int UpdateDepartmentMenu();
    int ViewDepartmentMenu();
    int ViewAllDepartmentMenu();

	int EmployeeMenu();
	int AddEmployeeMenu();
	int SearchEmployeeMenu();
    int UpdateEmployeeMenu();
    int ViewEmployeeMenu();
    int ViewSortedEmployeeMenu();

	int PayrollMenu();
	int ProcessPayrollMenu();
	int ViewPayrollMenu();
    int ViewSortedPayrollMenu();

	int ExitMenu();
};
#endif
