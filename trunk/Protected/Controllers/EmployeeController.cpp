#ifndef _EMPLOYEECONTROLLER_H
#include "./EmployeeController.h"
#endif
#include <sstream>
#ifndef EMPLOYEELIST_H
#include "../Models/EmployeetList.h"
#endif
#include "../../Base/Gui/Source/Form/FormSet/FormSet.h"
#ifndef _DEFAULTCONTROLLER_H
#include "./DefaultController.h"
#endif
#include "../../Base/Gui/Source/Services/Services.h"

using namespace std;

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

		Employee * employee = new Employee(id, firstname, lastname, deptCode, position, hoursWorked);

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
                BackToForm:
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

                Employee * updatedEmployee = new Employee(_id,_firstname,_lastname,_deptCode,_position,_hoursWorked);
                if(actionCode == MAIN_CODE || actionCode == EMPLOYEE_CODE || actionCode == EMPLOYEE_UPDATE_CODE)
                {
                    return this->run(actionCode);
                }
                if(actionCode == EMPLOYEE_UPDATE_SAVE_CODE)
                {
					EmployeeList ListObj;
					ListObj.BuildListFromFile();
					ListObj.UpdateNode(employee, updatedEmployee);
                    updatedEmployee->update(ListObj.GetHead());

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
                            goto BackToForm;
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
                        actionCode=menuInstance->UpdateEmployeeAfterSaveMenu();

                        FormSet FormSetObj;
                        FormSetObj.FlushFieldData(FormSetObj.SearchEmployeeForm());

                        return this->run(actionCode);
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
    //Services ServicesObj;
	MasterFormMenuController* menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
    //ServicesObj.BasicRunLevel();
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
                //ServicesObj.BasicRunLevel();
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
int EmployeeController::actionViewSorted()
{
	MasterFormMenuController* menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
    EmployeeList ListObj;
    ListObj.BuildListFromFile();

	int actionCode;

    actionCode = menuInstance->ViewSortedEmployeeMenu();
    switch(actionCode)
    {
        case EMPLOYEE_VIEW_SORTED_CODE_BY_ID:
        {
            ListObj.SortList("id");
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_FIRSTNAME:
        {
            ListObj.SortList("firstname");
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_LASTNAME:
        {
            ListObj.SortList("lastname");
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_DEPTCODE:
        {
            ListObj.SortList("deptCode");
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_POSITION:
        {
            ListObj.SortList("position");
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_HOURSWORKED:
        {
            ListObj.SortList("hoursWorked");
        }
        break;
    }
    if(actionCode == EMPLOYEE_CODE || actionCode == MAIN_CODE)
        return actionCode;
    else
        return this->actionViewSortedList(ListObj.GetHead());
}

int EmployeeController::actionViewSortedList(Employee* listHead)
{
	MasterFormMenuController* menuInstance = this->getMenuObj();
    this->getServicesObj()->SystemClearScreen();
    this->getServicesObj()->MaximumScreenBufferSize();

    EmployeeList ListObj;
    ListObj.Show(listHead);
    menuInstance->SetYRelativeSystemFrame(this->getServicesObj()->DynamicRunLevel());
    //int x = menuInstance->EmployeeAfterViewSortedMenu();
    //cout <<x<<endl;system("pause");
    return this->run(menuInstance->EmployeeAfterViewSortedMenu());
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

                actionCode = this->getMenuObj()->EmployeeDeleteConfirmMenu();
                if(actionCode == EMPLOYEE_DELETE_CONFIRM_MENU_CODE)
                {
                    EmployeeList ListObj;
                    ListObj.BuildListFromFile();
                    ListObj.DeleteNode(employee);
                    employee->deleteRecord(ListObj.GetHead());
                    this->getServicesObj()->BasicRunLevel();
                    if(employee->getOperationState()==OPERATIONSTATE_SUCCESS)
                    {
                        ConsoleObj.xyCoord(32,16);
                        ScreenObj.SetScreenTextColour(GreenTextColour);
                        cout << "Employee deleted."<<endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                        actionCode = this->getMenuObj()->EmployeeAfterDeleteMenu();

                    }
                    if(employee->getOperationState()==OPERATIONSTATE_FAILURE)
                    {
                        ConsoleObj.xyCoord(25,16);
                        ScreenObj.SetScreenTextColour(RedTextColour);
                        cout << "Error: Employee not deleted."<<endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                        actionCode = this->getMenuObj()->EmployeeFailDeleteMenu();
                    }
                    return this->run(actionCode);
                }else{
                    return this->run(actionCode);
                }
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
    {
        return DefaultController::getInstance()->actionIndex();
    }else{
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
            case EMPLOYEE_VIEW_SORTED_CODE:
                call = this->actionViewSorted();
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
}
