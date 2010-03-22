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

#ifndef _PAYROLLCONTROLLER_H
#include "./PayrollController.h"
#endif
#ifndef _DEFAULTCONTROLLER_H
#include "./DefaultController.h"
#endif
#ifndef _PAYROLLLIST_H
#include "../Models/PayrollList.h"
#endif
#ifndef _PAYROLL_H
#include "../Models/Payroll.h"
#endif
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Screen/Screen.h"
#include "../../Base/Gui/Source/Tools/Colour.h"
#include <sstream>

/*
 * @ constructor
 * @ return int
 */
PayrollController::PayrollController()
{
}

/*
 * @ destructor
 * @ return int
 */
PayrollController::~PayrollController()
{
}

/*
 * @ return int
 */
int PayrollController::getDefaultActionCode()
{
    return PAYROLL_CODE;
}

/*
 * @ displays payroll menu
 * @ return int
 */
int PayrollController::actionIndex()
{
    this->getServicesObj()->BasicRunLevel();
    return this->run(this->getMenuObj()->PayrollMenu());
}
int PayrollController::actionProcess()
{
    this->getServicesObj()->BasicRunLevel();
    PayrollList PayrollListObj;
    PayrollListObj.ProcessPayroll();
    if(PayrollListObj.BuildFileFromList())
    {
        return this->run(this->getMenuObj()->PayrollAfterProcessMenu());
    }
    else
    {
        ConsoleObj.xyCoord(14,15);
        ScreenObj.SetScreenTextColour(RedTextColour);
        cout << "Error: Payroll File could not be opened for writing" << endl;
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return this->run(this->getMenuObj()->PayrollFailProcessMenu());
    }
    return MAIN_CODE;
}

/*
 * @ finds and displays a payroll record
 * @ return int
 */
int PayrollController::actionView()
{
    int actionCode;
    int id;
    Payroll *payroll;
	MasterFormMenuController* menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
	do
	{
        actionCode = menuInstance->SearchPayrollMenu();

        Field * data = menuInstance->GetAllFieldData();
        istringstream deptCodeString((data)->GetFieldData());
        deptCodeString >> id;

        payroll = Payroll::model()->findById(id);
        if(actionCode==PAYROLL_SEARCH_SUBMIT_CODE)
        {
            if(payroll!=NULL)
            {
                this->getServicesObj()->BasicRunLevel();
                payroll->show(9);
                return this->run(this->getMenuObj()->ViewPayrollMenu());
            }
            else
            {
                this->getServicesObj()->BasicRunLevel();
                ConsoleObj.xyCoord(20,9);
                ScreenObj.SetScreenTextColour(RedTextColour);
                cout << "Error: Could not find Payroll record" << endl;
                ScreenObj.SetScreenTextColour(DefaultTextColour);
            }
        }
        else
            break;
	}while(payroll==NULL);
    return this->run(actionCode);
}

/*
 * @ displays options to sort payroll list by
 * @ return int
 */
int PayrollController::actionViewSorted()
{
	MasterFormMenuController* menuInstance = this->getMenuObj();

    this->getServicesObj()->BasicRunLevel();
    PayrollList ListObj;
    ListObj.BuildListFromFile();

	int actionCode;
	string by;

    actionCode = menuInstance->ViewSortedPayrollMenu();
    switch(actionCode)
    {
        case PAYROLL_VIEW_SORTED_CODE_BY_ID:
        {
            ListObj.SortList("id");
			by = "Id. No";
        }
        break;
        case PAYROLL_VIEW_SORTED_CODE_BY_LASTNAME:
        {
            ListObj.SortList("lastname");
			by = "Lastname";
        }
        break;
        case PAYROLL_VIEW_SORTED_CODE_BY_DEPTCODE:
        {
            ListObj.SortList("deptCode");
			by = "Department Code";
        }
        break;
        case PAYROLL_VIEW_SORTED_CODE_BY_POSITION:
        {
            ListObj.SortList("position");
			by = "Position";
        }
        break;
    }
    if(actionCode == PAYROLL_CODE || actionCode == MAIN_CODE)
        return this->run(actionCode);
    else
        return this->actionViewSortedList(ListObj.GetHead(), by);
}

/*
 * @ displays a sorted list of payroll records
 * @ param Payroll * listHead
 * @ return int
 */
int PayrollController::actionViewSortedList(Payroll* listHead, string by)
{
	MasterFormMenuController* menuInstance = this->getMenuObj();
    Console ConsoleObj;

    this->getServicesObj()->SystemClearScreen();
    this->getServicesObj()->MaximumScreenBufferSize();

    PayrollList ListObj;
    ListObj.Show(listHead);
    if(listHead!=NULL)
    {
        ConsoleObj.xyCoord(30,6);
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        cout << "Sorted by: " << by;
    }
    menuInstance->SetYRelativeSystemFrame(this->getServicesObj()->DynamicRunLevel());
    return this->run(menuInstance->PayrollAfterViewSortedMenu());
}

/*
 * @ param int actionCode
 * @ calls various "class::method"s based on param
 * @ return int
 */
int PayrollController::run(int actionCode)
{
    int call;

    if(actionCode == MAIN_CODE)
        return DefaultController::getInstance()->actionIndex();

    switch(actionCode)
    {
        case PAYROLL_PROCESS_CODE:
        call = this->actionProcess();
        break;
        case PAYROLL_VIEW_CODE:
        call = this->actionView();
        break;
        case PAYROLL_VIEW_SORTED_CODE:
        call = this->actionViewSorted();
        break;
        case PAYROLL_CODE:
        default:
            call = this->run(this->actionIndex());
        break;
    }
    return call;
}
