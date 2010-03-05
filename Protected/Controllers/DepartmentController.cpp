#ifndef _DEPARTMENTCONTROLLER_H
#include "./DepartmentController.h"
#endif
#ifndef _DEPARTMENT_H
#include "../Models/Department.h"
#endif

DepartmentController::DepartmentController()
{
}

DepartmentController::DepartmentController(Component * component)
{
    this->setComponent(component);
}

DepartmentController::~DepartmentController()
{
}

int DepartmentController::getDefaultActionCode()
{
    return DEPARTMENT_CODE;
}

int DepartmentController::actionIndex()
{
    this->getServicesObj()->BasicRunLevel();
	return this->run(this->getMenuObj()->DepartmentMenu());
}

int DepartmentController::actionAdd()
{
	int actionCode;
	MasterFormMenuController* menuInstance = this->getMenuObj();
    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->AddDepartmentMenu();
	Field * data = menuInstance->GetAllFieldData();
	int deptCode = atoi((data)->GetFieldData().c_str());
	string deptName = (data+1)->GetFieldData();
	float regularRate = atof((data+2)->GetFieldData().c_str());
	float overtimeRate = atof((data+3)->GetFieldData().c_str());
	Department * department = new Department(deptCode, deptName, regularRate, overtimeRate, NULL);
	// cout << actionCode; fgetc(stdin);
	if(actionCode == MAIN_CODE || actionCode == DEPARTMENT_CODE || actionCode == DEPARTMENT_ADD_CODE)
	{
		return this->run(actionCode);
	}
	return actionCode;
}

int DepartmentController::actionUpdate(int deptCode)
{
    return DEPARTMENT_CODE;
}

int DepartmentController::actionView(int deptCode)
{
	Department *department = Department::model()->find(deptCode);
	if(department!=NULL)
	{
		department->show();
	}
	// return this->getMenuObj()->afterDepartmentViewMenu();
    return DEPARTMENT_CODE;
}

int DepartmentController::actionList(int page = 0)
{
    return DEPARTMENT_CODE;
}

int DepartmentController::run(int actionCode)
{
    int call;
	if(actionCode == MAIN_CODE)
		return actionCode;
    switch(actionCode)
    {
		case DEPARTMENT_ADD_CODE:
			call = this->actionAdd();
		break;
        case DEPARTMENT_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}
