#ifndef _DEPARTMENTCONTROLLER_H
#include "./DepartmentController.h"
#endif
#ifndef _DEPARTMENT_H
#include "../Models/Department.h"
#endif
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Screen/Screen.h"
#include "../../Base/Gui/Source/Tools/Colour.h"
#include "../../Base/Gui/Source/Form/FormSet/FormSet.h"
#include <sstream>

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
	MasterFormMenuController *menuInstance = this->getMenuObj(true);

    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->AddDepartmentMenu();
	Field * data = menuInstance->GetAllFieldData();

	// cout << actionCode; fgetc(stdin);
	if(actionCode == MAIN_CODE || actionCode == DEPARTMENT_CODE || actionCode == DEPARTMENT_ADD_CODE)
	{
	    // menuInstance->ClearAllFieldData();
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

        Department * department = new Department(deptCode, deptName, regularRate, overtimeRate, NULL);

        department->save();
        menuInstance->ClearAllFieldData();

		this->getServicesObj()->BasicRunLevel();
		if(department->getOperationState() == OPERATIONSTATE_FAILURE)
		{
            ConsoleObj.xyCoord(20,9);
            ScreenObj.SetScreenTextColour(RedTextColour);
			cout << "Error: Could not save department info to file" << endl;
			ScreenObj.SetScreenTextColour(DefaultTextColour);
			return this->run(menuInstance->AddDepartmentFailSaveMenu());
		}
		else
		{
            ConsoleObj.xyCoord(24,9);
            ScreenObj.SetScreenTextColour(GreenTextColour);
			cout << "Department Added Successfuly" << endl;
			ScreenObj.SetScreenTextColour(DefaultTextColour);

		}
        department->show(14);

        return this->run(menuInstance->AddDepartmentAfterSaveMenu());
	}
	return MAIN_CODE;
}

int DepartmentController::actionUpdate()
{
	int actionCode;
	int deptCode;
	Department *department;

	MasterFormMenuController* menuInstance = this->getMenuObj(true);
    this->getServicesObj()->BasicRunLevel();
    do
    {
        actionCode = menuInstance->SearchDepartmentMenu();
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

                Department * updatedDepartment = new Department(_deptCodeInt,_deptName,_regularRateFloat,_overtimeRateFloat,NULL);
                if(actionCode == MAIN_CODE || actionCode == DEPARTMENT_CODE)
                {
                    return this->run(actionCode);
                }
                if(actionCode == DEPARTMENT_UPDATE_SAVE_CODE)
                {
                    //updatedDepartment->setOldDeptCode(department->getDeptCode());
                    updatedDepartment->update();
                    menuInstance->ClearAllFieldData();

                    this->getServicesObj()->BasicRunLevel();
                    if(updatedDepartment->getOperationState() == OPERATIONSTATE_FAILURE)
                    {
                        ConsoleObj.xyCoord(20,9);
                        ScreenObj.SetScreenTextColour(RedTextColour);
                        cout << "Error: Could not update department record" << endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                    }
                    else if(updatedDepartment->getOperationState() == OPERATIONSTATE_SUCCESS)
                    {
                        ConsoleObj.xyCoord(24,9);
                        ScreenObj.SetScreenTextColour(GreenTextColour);
                        cout << "Department Updated Successfuly" << endl;
                        ScreenObj.SetScreenTextColour(DefaultTextColour);
                    }
                    updatedDepartment->show(14);

                    return this->run(menuInstance->UpdateDepartmentAfterSaveMenu());
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

int DepartmentController::actionView()
{
    int actionCode;
	MasterFormMenuController* menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->SearchDepartmentMenu();
    /*
	Department *department = Department::model()->find(deptCode);
	if(department!=NULL)
	{
 		department->show(14);
	}
	// return this->getMenuObj()->afterDepartmentViewMenu();
	*/
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
		case DEPARTMENT_UPDATE_CODE:
            call = this->actionUpdate();
        break;
        case DEPARTMENT_VIEW_CODE:
            call = this->actionView();
        case DEPARTMENT_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}
