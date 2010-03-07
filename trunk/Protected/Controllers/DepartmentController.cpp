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
	MasterFormMenuController *menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->AddDepartmentMenu();
	Field * data = menuInstance->GetAllFieldData();
	this->getMenuObj(true);

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
	MasterFormMenuController* menuInstance = this->getMenuObj();



    this->getServicesObj()->BasicRunLevel();
	actionCode = menuInstance->SearchDepartmentMenu();
	Field * data = menuInstance->GetAllFieldData();
	int deptCode;
	istringstream deptCodeString((data)->GetFieldData());
	deptCodeString >> deptCode;

	if(actionCode == DEPARTMENT_SEARCH_CODE)
	{
	    Department *department = Department::model()->findByCode(deptCode);
		if(department!= NULL)
		{
			cout << "found";
		}
	}
	fgetc(stdin);

    return DEPARTMENT_CODE;
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
