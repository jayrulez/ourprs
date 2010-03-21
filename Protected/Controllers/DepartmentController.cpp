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

#ifndef _DEPARTMENTCONTROLLER_H
#include "./DepartmentController.h"
#endif
#ifndef _DEPARTMENT_H
#include "../Models/Department.h"
#endif

#ifndef _EMPLOYEE_H
#include "../Models/Employee.h"
#endif

#ifndef DEPARTMENTLIST_H
#include "../Models/DepartmentList.h"
#endif

#ifndef EMPLOYEELIST_H
#include "../Models/EmployeeList.h"
#endif

#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Screen/Screen.h"
#include "../../Base/Gui/Source/Tools/Colour.h"
#include "../../Base/Gui/Source/Form/FormSet/FormSet.h"
#include <sstream>
#ifndef _DEFAULTCONTROLLER_H
#include "./DefaultController.h"
#endif

/*
 * @ constructor
 */
DepartmentController::DepartmentController()
{
}

/*
 * @ destructor
 */
DepartmentController::~DepartmentController()
{
}

/*
 * @ return int
 */
int DepartmentController::getDefaultActionCode()
{
    return DEPARTMENT_CODE;
}

/*
 * @ displays department menu
 * @ return int
 */
int DepartmentController::actionIndex()
{
    this->getServicesObj()->BasicRunLevel();
	return this->run(this->getMenuObj()->DepartmentMenu());
}

/*
 * @ adds a department record
 * @ return int
 */
int DepartmentController::actionAdd()
{
	int actionCode;
	MasterFormMenuController *menuInstance = this->getMenuObj(true);

    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->AddDepartmentMenu();
	Field * data = menuInstance->GetAllFieldData();
	
	if(actionCode == MAIN_CODE || actionCode == DEPARTMENT_CODE || actionCode == DEPARTMENT_ADD_CODE)
	{
	    menuInstance->ClearAllFieldData();
		return this->run(actionCode);
	}
	if(actionCode == DEPARTMENT_ADD_SAVE_CODE)
	{
        istringstream deptCodeString((data)->GetFieldData());
        istringstream regularRateString((data+2)->GetFieldData());
        istringstream overtimeRateString((data+3)->GetFieldData());

        int deptCode;
        string deptName;
        float regularRate;
        float overtimeRate;

        deptCodeString >> deptCode;
        deptName = (data+1)->GetFieldData();
        regularRateString >> regularRate;
        overtimeRateString >> overtimeRate;

        Department * department = new Department(deptCode, deptName, regularRate, overtimeRate);

        DepartmentList ListObj;
        ListObj.BuildListFromFile();
        ListObj.AddDepartment(*department);

        department->save(ListObj.getHead());

		this->getServicesObj()->BasicRunLevel();
		if(department->getOperationState() == OPERATIONSTATE_FAILURE)
		{
            ConsoleObj.xyCoord(18,14);
            ScreenObj.SetScreenTextColour(RedTextColour);
			cout << "Error: Could not save department info to file" << endl;
			ScreenObj.SetScreenTextColour(DefaultTextColour);
			return this->run(menuInstance->AddDepartmentFailSaveMenu());
		}
		else
		{
		    menuInstance->ClearAllFieldData();
            ConsoleObj.xyCoord(24,9);
            ScreenObj.SetScreenTextColour(GreenTextColour);
			cout << "Department Added Successfuly" << endl;
			ScreenObj.SetScreenTextColour(DefaultTextColour);
			department->show(14);
		}

        return this->run(menuInstance->AddDepartmentAfterSaveMenu());
	}
	return this->run(MAIN_CODE);
}

/*
 * @ updates a department record
 * @ return int
 */
int DepartmentController::actionUpdate()
{
	int actionCode;
	int deptCode;
	Department *department;

	MasterFormMenuController* menuInstance = this->getMenuObj(true);
    this->getServicesObj()->BasicRunLevel();
    do
    {
        actionCode = menuInstance->UpdateSearchDepartmentMenu();
        Field * data = menuInstance->GetAllFieldData();

        istringstream deptCodeString((data)->GetFieldData());
        deptCodeString >> deptCode;

        if(actionCode == DEPARTMENT_SEARCH_CODE)
        {
            department = Department::model()->findByCode(deptCode);
            if(department != NULL)
            {
                string deptCodeString;
                string regularRateString;
                string overtimeRateString;

                ostringstream deptCode;
                ostringstream regularRate;
                ostringstream overtimeRate;

                deptCode << department->getDeptCode();
                regularRate << department->getRegularRate();
                overtimeRate << department->getOvertimeRate();

                deptCodeString = deptCode.str();
                regularRateString = regularRate.str();
                overtimeRateString = overtimeRate.str();

                FormSet FormSetObj;
                Field *record=FormSetObj.UpdateDepartmentForm();

                (record+0)->SetFieldData(deptCodeString);
                (record+1)->SetFieldData(department->getDeptName());
                (record+2)->SetFieldData(regularRateString);
                (record+3)->SetFieldData(overtimeRateString);

                this->getServicesObj()->BasicRunLevel();

                menuInstance->SetAllFieldData(record);

                ConsoleObj.xyCoord(17,7);
                ScreenObj.SetScreenTextColour(YellowTextColour);
                cout << "Warning: Dependent Employee records will be updated" << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);

                actionCode = menuInstance->UpdateDepartmentMenu();
                Field * newData = menuInstance->GetAllFieldData();

                int _deptCodeInt;
                string _deptName;
                float _regularRateFloat;
                float _overtimeRateFloat;

                istringstream _deptCodeString((newData)->GetFieldData());
                istringstream _regularRateString((newData+2)->GetFieldData());
                istringstream _overtimeRateString((newData+3)->GetFieldData());

                _deptCodeString >> _deptCodeInt;
                _deptName = (newData+1)->GetFieldData();
                _regularRateString >> _regularRateFloat;
                _overtimeRateString >> _overtimeRateFloat;

                Department * updatedDepartment = new Department(_deptCodeInt,_deptName,_regularRateFloat,_overtimeRateFloat);
                if(actionCode == MAIN_CODE || actionCode == DEPARTMENT_CODE)
                {
                    //clear search field
                    FormSet FormSetObj;
                    FormSetObj.FlushFieldData(FormSetObj.SearchDepartmentForm());
                    return this->run(actionCode);
                }
                if(actionCode == DEPARTMENT_UPDATE_SAVE_CODE)
                {
                    //updatedDepartment->setOldDeptCode(department->getDeptCode());
					DepartmentList ListObj;
					ListObj.BuildListFromFile();
					ListObj.UpdateNode(department, updatedDepartment);
					//updatedDepartment->setList(ListObj.getHead());
                    updatedDepartment->save(ListObj.getHead(), department);

                    this->getServicesObj()->BasicRunLevel();
                    if(updatedDepartment->getOperationState() == OPERATIONSTATE_DEFAULT)
                    {
                        ConsoleObj.xyCoord(20,14);
                        ScreenObj.SetScreenTextColour(RedTextColour);
                        cout << "Notice: The record was not changed" << endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                        return this->run(menuInstance->UpdateDepartmentFailSaveMenu());
                    }else if(updatedDepartment->getOperationState() == OPERATIONSTATE_FAILURE)
                    {
                        ConsoleObj.xyCoord(20,14);
                        ScreenObj.SetScreenTextColour(RedTextColour);
                        cout << "Error: Could not update department record" << endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                        return this->run(menuInstance->UpdateDepartmentFailSaveMenu());
                    }
                    else if(updatedDepartment->getOperationState() == OPERATIONSTATE_SUCCESS)
                    {
						EmployeeList _list;
						_list.BuildListFromFile();
						_list.silentCascadeUpdateDeptRelation(department->getDeptCode(),updatedDepartment->getDeptCode(),_list.GetHead());
						_list.saveListToFile(_list.GetHead());
                        ConsoleObj.xyCoord(24,9);
                        ScreenObj.SetScreenTextColour(GreenTextColour);
                        cout << "Department Updated Successfuly" << endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                        updatedDepartment->show(14);

                        //clear search field
                        FormSet FormSetObj;
                        FormSetObj.FlushFieldData(FormSetObj.SearchDepartmentForm());

                        return this->run(menuInstance->UpdateDepartmentAfterSaveMenu());
                    }
                }
            }
            else
            {
                this->getServicesObj()->BasicRunLevel();
                ConsoleObj.xyCoord(20,9);
                ScreenObj.SetScreenTextColour(RedTextColour);
                cout << "Error: Could not find department record" << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);
            }
        }
        else
            break;
    }while(department==NULL);

    return this->run(actionCode);
}

/*
 * @ finds and displays a single department record
 * @ return int
 */
int DepartmentController::actionView()
{
    int actionCode;
    int deptCode;
    Department *department;
	MasterFormMenuController* menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	do
	{
        actionCode = menuInstance->ViewSearchDepartmentMenu();

        Field * data = menuInstance->GetAllFieldData();
        istringstream deptCodeString((data)->GetFieldData());
        deptCodeString >> deptCode;

        department = Department::model()->findByCode(deptCode);
        if(actionCode==DEPARTMENT_SEARCH_CODE)
        {
            if(department!=NULL)
            {
                this->getServicesObj()->BasicRunLevel();
                department->show(16);
                return this->run(this->getMenuObj()->DepartmentAfterViewMenu());
            }
            else
            {
                this->getServicesObj()->BasicRunLevel();
                ConsoleObj.xyCoord(20,9);
                ScreenObj.SetScreenTextColour(RedTextColour);
                cout << "Error: Could not find department record" << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);
            }
        }
        else
            break;
	}while(department==NULL);
    return this->run(actionCode);
}

/*
 * @ displays a list of all department records
 * @ return int
 */
int DepartmentController::actionList(int page = 0)
{
	MasterFormMenuController* menuInstance = this->getMenuObj();
    DepartmentList ListObj;
    this->getServicesObj()->SystemClearScreen();
    this->getServicesObj()->MaximumScreenBufferSize();
    ListObj.BuildListFromFile();
    ListObj.ShowDepartmentList();
    menuInstance->SetYRelativeSystemFrame(this->getServicesObj()->DynamicRunLevel());
    return this->run(menuInstance->ViewAllDepartmentMenu());
}

/*
 * @ param int actionCode
 * @ calls various "class::method"s based on param
 * @ return int
 */
int DepartmentController::run(int actionCode)
{
    int call;

	if(actionCode == MAIN_CODE)
		return DefaultController::getInstance()->actionIndex();

    switch(actionCode)
    {
		case DEPARTMENT_ADD_CODE:
			call = this->actionAdd();
		break;
		case DEPARTMENT_UPDATE_CODE:
            call = this->actionUpdate();
        break;
        case DEPARTMENT_VIEW_CODE:
            call = this->actionView();
        break;
        case DEPARTMENT_LIST_CODE:
            call = this->actionList();
        break;
        case DEPARTMENT_CODE:
        default:
            call = this->run(this->actionIndex());
        break;
    }
    return call;
}
