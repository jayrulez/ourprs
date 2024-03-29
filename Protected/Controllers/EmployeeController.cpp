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

#ifndef _EMPLOYEECONTROLLER_H
#include "./EmployeeController.h"
#endif
#include <sstream>
#ifndef EMPLOYEELIST_H
#include "../Models/EmployeeList.h"
#endif
#include "../../Base/Gui/Source/Form/FormSet/FormSet.h"
#ifndef _DEFAULTCONTROLLER_H
#include "./DefaultController.h"
#endif
#include "../../Base/Gui/Source/Services/Services.h"

using namespace std;

/*
 * @ constructor
 * @ return int
 */
EmployeeController::EmployeeController()
{
}

/*
 * @ destructor
 * @ return int
 */
EmployeeController::~EmployeeController()
{
}

/*
 * @ return int
 */
int EmployeeController::getDefaultActionCode()
{
    return EMPLOYEE_CODE;
}

/*
 * @ displays employee menu
 * @ return int
 */
int EmployeeController::actionIndex()
{
    this->getServicesObj()->BasicRunLevel();
    return this->run(this->getMenuObj()->EmployeeMenu());
}

/*
 * @ adds an employee record
 * @ return int
 */
int EmployeeController::actionAdd()
{
	int actionCode;
	MasterFormMenuController *menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->AddEmployeeMenu();
	Field * data = menuInstance->GetAllFieldData();

	if(actionCode == MAIN_CODE || actionCode == EMPLOYEE_CODE || actionCode == EMPLOYEE_ADD_CODE)
	{
	    menuInstance->ClearAllFieldData();
		return this->run(actionCode);
	}
	if(actionCode == EMPLOYEE_ADD_SAVE_CODE)
	{
		istringstream idString((data)->GetFieldData());
		istringstream deptCodeString((data+3)->GetFieldData());
		istringstream hoursWorkedString((data+5)->GetFieldData());

		int id;
		int deptCode;
		float hoursWorked;
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
        EmployeeList ListObj;
        ListObj.BuildListFromFile();
        ListObj.AddEmployee(*employee);
        employee->save(ListObj.GetHead());

		this->getServicesObj()->BasicRunLevel();
		if(employee->getOperationState() == OPERATIONSTATE_FAILURE)
		{
            ConsoleObj.xyCoord(18,14);
            ScreenObj.SetScreenTextColour(RedTextColour);
			cout << "Error: Could not save employee info to file" << endl;
			ScreenObj.SetScreenTextColour(DefaultTextColour);
			return this->run(menuInstance->AddEmployeeFailSaveMenu());
		}
		else
		{
		    menuInstance->ClearAllFieldData();
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

/*
 * @ search for an employee record
 * @ return int
 */
int EmployeeController::search()
{
	return MAIN_CODE;
}

/*
 * @ finds and updates an employee record
 * @ return int
 */
int EmployeeController::actionUpdate()
{
    bool status=true;
	int actionCode;
	Employee * employee;
	MasterFormMenuController *menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	do
	{
	    actionCode = menuInstance->SearchEmployeeMenu();
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

                ConsoleObj.xyCoord(13,7);
                ScreenObj.SetScreenTextColour(SharpeWhiteTextColour);
                cout << "NB: Process Payroll to reflect changes in Payroll file." << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);

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
                    updatedEmployee->save(ListObj.GetHead(), employee);

                    this->getServicesObj()->BasicRunLevel();
                    if(updatedEmployee->getOperationState() == OPERATIONSTATE_DEFAULT)
                    {
                        ConsoleObj.xyCoord(18,15);
                        ScreenObj.SetScreenTextColour(RedTextColour);
                        cout << "Notice: The record was not changed" << endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                        actionCode=menuInstance->UpdateEmployeeFailSaveMenu();
                        if(actionCode==EMPLOYEE_SEARCH_SUBMIT_CODE)
                        {
                            return this->run(this->actionUpdate());
                        }
                        else
                            return this->run(actionCode);
                    }else if(updatedEmployee->getOperationState() == OPERATIONSTATE_FAILURE)
                    {
                        ConsoleObj.xyCoord(18,15);
                        ScreenObj.SetScreenTextColour(RedTextColour);
                        cout << "Error: Could not update employee record" << endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                        actionCode=menuInstance->UpdateEmployeeFailSaveMenu();
                        if(actionCode==EMPLOYEE_SEARCH_SUBMIT_CODE)
                        {
                            return this->run(this->actionUpdate());
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
	}while(status);
	return this->run(actionCode);
}

/*
 * @ finds and displays an employee record
 * @ return int
 */
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

/*
 * @ displays available options by which to sort employee records
 * @ return int
 */
int EmployeeController::actionViewSorted()
{
	MasterFormMenuController* menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
    EmployeeList ListObj;
    ListObj.BuildListFromFile();

	int actionCode;
	string by;

    actionCode = menuInstance->ViewSortedEmployeeMenu();
    switch(actionCode)
    {
        case EMPLOYEE_VIEW_SORTED_CODE_BY_ID:
        {
            ListObj.SortList("id");
			by = "Id. No";
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_FIRSTNAME:
        {
            ListObj.SortList("firstname");
			by = "Firstname";
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_LASTNAME:
        {
            ListObj.SortList("lastname");
			by = "Lastname";
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_DEPTCODE:
        {
            ListObj.SortList("deptCode");
			by = "Department Code";
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_POSITION:
        {
            ListObj.SortList("position");
			by = "Position";
        }
        break;
        case EMPLOYEE_VIEW_SORTED_CODE_BY_HOURSWORKED:
        {
            ListObj.SortList("hoursWorked");
			by = "Hours Worked";
        }
        break;
    }
    if(actionCode == EMPLOYEE_CODE || actionCode == MAIN_CODE)
        return this->run(actionCode);
    else
        return this->actionViewSortedList(ListObj.GetHead(), by);
}

/*
 * @ displays sorted list of employees
 * @ return int
 */
int EmployeeController::actionViewSortedList(Employee* listHead, string by)
{
	MasterFormMenuController* menuInstance = this->getMenuObj();
	Console ConsoleObj;
    this->getServicesObj()->SystemClearScreen();
    this->getServicesObj()->MaximumScreenBufferSize();

    if(listHead!=NULL)
    {
        ConsoleObj.xyCoord(30,6);
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        cout << "Sorted by: " << by;
    }

    EmployeeList ListObj;
    ListObj.Show(listHead);

    menuInstance->SetYRelativeSystemFrame(this->getServicesObj()->DynamicRunLevel());
    return this->run(menuInstance->EmployeeAfterViewSortedMenu());
}

/*
 * @ finds and deletes an employee record
 * @ return int
 */
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

                ConsoleObj.xyCoord(13,28);
                ScreenObj.SetScreenTextColour(SharpeWhiteTextColour);
                cout << "NB: Process Payroll to reflect changes in Payroll file." << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);

                ConsoleObj.xyCoord(25,32);
                ScreenObj.SetScreenTextColour(SharpeWhiteTextColour);
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
                        ConsoleObj.xyCoord(25,16);
                        ScreenObj.SetScreenTextColour(GreenTextColour);
                        cout << "Employee deleted successfully."<<endl;
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

/*
 * @ param int actionCode
 * @ calls various "class::method"s based on param
 * @ return int
 */
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
                call = this->run(this->actionIndex());
            break;
        }
        return call;
    }
}
