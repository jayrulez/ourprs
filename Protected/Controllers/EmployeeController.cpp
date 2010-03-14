#ifndef _EMPLOYEECONTROLLER_H
#include "./EmployeeController.h"
#endif
#include <sstream>
#ifndef EMPLOYEELIST_H
#include "../Models/EmployeetList.h"
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
				ostringstream id;
				ostringstream deptCode;
				ostringstream hoursWorked;

				id << employee->getId();
				string firstname = employee->getFirstname();
				string lastname = employee->getLastname();
				deptCode << employee->getDeptCode();
				string position = employee->getPosition();
				hoursWorked << employee->getHoursWorked();

				FormSet FormSetObj;
                Field *record=FormSetObj.UpdateEmployeeForm();

				(record+0)->SetFieldData(id.str());
				(record+1)->SetFieldData(firstname);
				(record+2)->SetFieldData(lastname);
				(record+3)->SetFieldData(deptCode.str());
				(record+4)->SetFieldData(position);
				(record+5)->SetFieldData(hoursWorked.str());

                this->getServicesObj()->BasicRunLevel();

                menuInstance->SetAllFieldData(record);

                actionCode = menuInstance->UpdateEmployeeMenu();
                Field * newData = menuInstance->GetAllFieldData();

				istringstream _idString((newData+0)->GetFieldData());
				istringstream _deptCodeString((newData+3)->GetFieldData());
				istringstream _hoursWorkedString((newData+5)->GetFieldData());

				int _id;
				int _deptCode;
				float _hoursWorked;

				_idString >> _id;
				string _firstname = (newData+1)->GetFieldData();
				string _lastname = (newData+2)->GetFieldData();
				_deptCodeString >> _deptCode;
				string _position = (newData+4)->GetFieldData();
				_hoursWorkedString >> _hoursWorked;

                Employee * updatedEmployee = new Employee(_id,_firstname,_lastname,_deptCode,_position,_hoursWorked, NULL);
                if(actionCode == MAIN_CODE || actionCode == EMPLOYEE_CODE)
                {
                    return this->run(actionCode);
                }
                if(actionCode == EMPLOYEE_UPDATE_SAVE_CODE)
                {
					EmployeeList ListObj;
					ListObj.BuildListFromFile();
                    updatedEmployee->update(ListObj.getHead());

                    this->getServicesObj()->BasicRunLevel();
                    if(updatedEmployee->getOperationState() == OPERATIONSTATE_FAILURE)
                    {
                        ConsoleObj.xyCoord(20,15);
                        ScreenObj.SetScreenTextColour(RedTextColour);
                        cout << "Error: Could not update employee record" << endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                        actionCode=menuInstance->UpdateEmployeeFailSaveMenu();
                        if(actionCode==EMPLOYEE_SEARCH_SUBMIT_CODE)
                        {
                            continue;
                        }
                        else
                            return this->run(actionCode);
                    }
                    else if(updatedEmployee->getOperationState() == OPERATIONSTATE_SUCCESS)
                    {
                        ConsoleObj.xyCoord(24,9);
                        ScreenObj.SetScreenTextColour(GreenTextColour);
                        cout << "Employee updated successfuly" << endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                        updatedEmployee->show(14);
                        return this->run(menuInstance->UpdateEmployeeAfterSaveMenu());
                    }
                }
			}else{
                this->getServicesObj()->BasicRunLevel();
                ConsoleObj.xyCoord(20,9);
                ScreenObj.SetScreenTextColour(RedTextColour);
                cout << "Error: Could not find employee record" << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);
			}
		}
		else
			break;
	}while(employee != NULL);
	return this->run(actionCode);
}

int EmployeeController::actionView()
{
    int actionCode;
    int id;
    Employee *employee;
	MasterFormMenuController* menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	do
	{
        actionCode = menuInstance->SearchEmployeeMenu();

        Field * data = menuInstance->GetAllFieldData();
        istringstream idString((data)->GetFieldData());
        idString >> id;

        employee = Employee::model()->findById(id);
        if(actionCode==EMPLOYEE_SEARCH_SUBMIT_CODE)
        {
            if(employee!=NULL)
            {
                this->getServicesObj()->BasicRunLevel();
                employee->show(14);
                return this->run(this->getMenuObj()->EmployeeAfterViewMenu());
            }
            else
            {
                this->getServicesObj()->BasicRunLevel();
                ConsoleObj.xyCoord(20,9);
                ScreenObj.SetScreenTextColour(RedTextColour);
                cout << "Error: Could not find employee record" << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);
            }
        }
        else
            break;
	}while(employee==NULL);
    return this->run(actionCode);
}
int EmployeeController::actionDelete()
{
    int actionCode;
    int id;
    Employee *employee;
	MasterFormMenuController* menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	do
	{
        actionCode = menuInstance->SearchEmployeeMenu();

        Field * data = menuInstance->GetAllFieldData();
        istringstream idString((data)->GetFieldData());
        idString >> id;

        employee = Employee::model()->findById(id);
        if(actionCode==EMPLOYEE_SEARCH_SUBMIT_CODE)
        {
            if(employee!=NULL)
            {
                this->getServicesObj()->BasicRunLevel();
                employee->show(9);
                ConsoleObj.xyCoord(25,30);
                ScreenObj.SetScreenTextColour(WhiteColour);
                cout << "Do you really want to delete?" << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);
                return this->run(this->getMenuObj()->EmployeeDeleteConfirmMenu());
            }
            else
            {
                this->getServicesObj()->BasicRunLevel();
                ConsoleObj.xyCoord(20,9);
                ScreenObj.SetScreenTextColour(RedTextColour);
                cout << "Error: Could not find employee record" << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);
            }
        }
        else
            break;
	}while(employee==NULL);
    return this->run(actionCode);
}

int EmployeeController::run(int actionCode)
{
    int call;

    if(actionCode == MAIN_CODE)
        return actionCode;

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
		case EMPLOYEE_DELETE_CODE:
			call = this->actionDelete();
		break;
        case EMPLOYEE_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}
