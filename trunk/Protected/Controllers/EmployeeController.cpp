#ifndef _EMPLOYEECONTROLLER_H
#include "./EmployeeController.h"
#endif

EmployeeController::EmployeeController()
{
}

EmployeeController::EmployeeController(Component * component)
{
    this->setComponent(component);
}

EmployeeController::~EmployeeController()
{
}

int EmployeeController::getDefaultActionCode()
{
    return EMPLOYEE_CODE;
}

int EmployeeController::actionIndex()
{
    this->getServicesObj()->BasicRunLevel();
    return this->getMenuObj()->EmployeeMenu();
}

int EmployeeController::actionAdd()
{
	int actionCode;
	MasterFormMenuController *menuInstance = this->getMenuObj(true);

    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->AddEmployeeMenu();
	Field * data = menuInstance->GetAllFieldData();
	
	if(actionCode == MAIN_CODE || actionCode == EMPLOYEE_CODE || actionCode == EMPLOYEE_ADD_CODE)
	{
		return this->run(actionCode);
	}
	if(actionCode == EMPLOYEE_ADD_SAVE_CODE)
	{
        return this->run(menuInstance->AddEmployeeAfterSaveMenu());
	}
	return MAIN_CODE;
}

int EmployeeController::run(int actionCode)
{
    int call;
    switch(actionCode)
    {
		case EMPLOYEE_ADD_CODE:
			call = this->actionAdd();
		break;
        case EMPLOYEE_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}
