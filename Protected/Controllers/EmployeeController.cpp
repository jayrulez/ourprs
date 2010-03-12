#ifndef _EMPLOYEECONTROLLER_H
#include "./EmployeeController.h"
#endif
#include <sstream>

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
    return this->run(this->getMenuObj()->EmployeeMenu());
}

int EmployeeController::actionAdd()
{
	int actionCode;
	MasterFormMenuController *menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->AddEmployeeMenu();
	Field * data = menuInstance->GetAllFieldData();

	if(actionCode == MAIN_CODE || actionCode == EMPLOYEE_CODE || actionCode == EMPLOYEE_ADD_CODE)
	{
		return this->run(actionCode);
	}
	if(actionCode == EMPLOYEE_ADD_SAVE_CODE)
	{
		istringstream idString((data)->GetFieldData());
		istringstream deptCodeString((data+3)->GetFieldData());
		istringstream hoursWorkedString((data+5)->GetFieldData());

		int id;
		int deptCode;
		int hoursWorked;
		string firstname;
		string lastname;
		string position;

		idString >> id;
		deptCodeString >> deptCode;
		hoursWorkedString >> hoursWorked;
		firstname = (data+1)->GetFieldData();
		lastname = (data+2)->GetFieldData();
		position = (data+4)->GetFieldData();

		Employee * employee = new Employee(id, firstname, lastname, deptCode, position, hoursWorked, NULL);

		employee->save();

		this->getServicesObj()->BasicRunLevel();
		if(employee->getOperationState() == OPERATIONSTATE_FAILURE)
		{
            ConsoleObj.xyCoord(20,9);
            ScreenObj.SetScreenTextColour(RedTextColour);
			cout << "Error: Could not save employee info to file" << endl;
			ScreenObj.SetScreenTextColour(DefaultTextColour);
			return this->run(menuInstance->AddDepartmentFailSaveMenu());
		}
		else
		{
            ConsoleObj.xyCoord(24,9);
            ScreenObj.SetScreenTextColour(GreenTextColour);
			cout << "Employee Added Successfuly" << endl;
			ScreenObj.SetScreenTextColour(DefaultTextColour);
			employee->show(14);
		}

        return this->run(menuInstance->AddEmployeeAfterSaveMenu());
	}
	return MAIN_CODE;
}

int EmployeeController::search()
{
	return MAIN_CODE;
}

int EmployeeController::actionUpdate()
{
	int actionCode;
	Employee * employee;
	MasterFormMenuController *menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->SearchEmployeeMenu();
	do
	{
		Field * data = menuInstance->GetAllFieldData();
		istringstream idString((data)->GetFieldData());
		int idInt;
		idString >> idInt;
		if(actionCode == EMPLOYEE_SEARCH_SUBMIT_CODE)
		{
			employee = Employee::model()->findById(idInt);

			if(employee != NULL)
			{

			}else{

			}
		}
		else
			break;
	}while(employee != NULL);
	return this->run(actionCode);
}

int EmployeeController::actionView()
{
	system("pause");
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
		case EMPLOYEE_UPDATE_CODE:
			call = this->actionUpdate();
		break;
		case EMPLOYEE_VIEW_CODE:
			call = this->actionView();
		break;
        case EMPLOYEE_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}
