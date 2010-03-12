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
#include "../Item.h"
#include "MenuSet.h"
#include "../../Tools/Frame.h"
#include "../../Tools/Colour.h"
#include <string>
#include <iostream>
using namespace std;

MenuSet::MenuSet()
{
}
MenuSet::~MenuSet()
{
}
int MenuSet::GetMenuSize(Item* menu)
{
    return this->MenuSize;
}
int MenuSet::GetMenuCode(Item* menu)
{
    return this->MenuCode;
}
string MenuSet::GetMenuTitle()
{
    return this->MenuTitle;
}
void MenuSet::SetYRelativeSystemFrame(int y)
{
    this->YRelativeSystemFrame=y;
}
void MenuSet::ShowMenuTitle(int status)
{
    if(!status)
        ScreenObj.SetScreenTextColour(DefaultBgColour);
    else
        ScreenObj.SetScreenTextColour(DefaultTextColour);
    int TitleLength=MenuTitle.length();
    int x1=(STANDARD_FRAME_WIDTH/2)-(TitleLength/2);
    int x2=(STANDARD_FRAME_WIDTH/2)+(TitleLength/2);
    if(FrameObj.SetFrame(x1-1,x2+1,2,4,NORMAL_FRAME))
    {
        FrameObj.sFraming();
        ConsoleObj.xyCoord(x1-1,2);
        cout<<(unsigned char)MENU_TITLE_JOINT;
        ConsoleObj.xyCoord(x2+1,2);
        cout<<(unsigned char)MENU_TITLE_JOINT;
        ConsoleObj.xyCoord(x1,3);
        cout<<MenuTitle;
    }
     ScreenObj.SetScreenTextColour(DefaultTextColour);
}
void MenuSet::SetMenuTitle(string MenuTitle)
{
    this->MenuTitle=MenuTitle;
}



//main menu
Item* MenuSet::MainMenu()
{
    this->MenuCode = MAIN_CODE;
    this->MenuSize = 4;
    MenuTitle="MAIN MENU";
    static Item MainItem[4];
    MainItem[0].SetItem(17,23,DEPARTMENT_CODE,"Department");
    MainItem[1].SetItem(37,23,EMPLOYEE_CODE,"Employee");
    MainItem[2].SetItem(54,23,PAYROLL_CODE,"Payroll");
    MainItem[3].SetItem(39,27,EXIT_CODE,"Exit");
    return &MainItem[0];
}




//Employee Menu
Item* MenuSet::EmployeeMenu()
{
    this->MenuCode = EMPLOYEE_CODE;
    this->MenuSize = 6;
    MenuTitle="Employee Menu";
    static Item EmployeeItem[6];
    EmployeeItem[0].SetItem(15,24,EMPLOYEE_ADD_CODE,"Add");
    EmployeeItem[1].SetItem(28,24,EMPLOYEE_UPDATE_CODE,"Update");
    EmployeeItem[2].SetItem(43,24,EMPLOYEE_VIEW_CODE,"View");
    EmployeeItem[3].SetItem(55,24,EMPLOYEE_VIEW_SORTED_CODE,"View Sorted");
    EmployeeItem[4].SetItem(28,29,EMPLOYEE_DELETE_CODE,"Delete");
    EmployeeItem[5].SetItem(43,29,MAIN_CODE,"Main Menu");
    return &EmployeeItem[0];
}
Item* MenuSet::AddEmployeeAfterSaveMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 3;
    MenuTitle="Add Employee - Success";
    static Item AddEmployeeAfterSaveMenuItem[3];
    AddEmployeeAfterSaveMenuItem[0].SetItem(15,32,EMPLOYEE_ADD_CODE,"Add More");
    AddEmployeeAfterSaveMenuItem[1].SetItem(32,32,EMPLOYEE_CODE,"<--Employee");
    AddEmployeeAfterSaveMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return AddEmployeeAfterSaveMenuItem;
}
Item* MenuSet::AddEmployeeFailSaveMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 3;
    MenuTitle="Add Employee - Failed";
    static Item AddEmployeeFailSaveMenuItem[3];
    AddEmployeeFailSaveMenuItem[0].SetItem(15,32,EMPLOYEE_ADD_CODE,"<--Add Form");
    AddEmployeeFailSaveMenuItem[1].SetItem(32,32,EMPLOYEE_CODE,"Employee");
    AddEmployeeFailSaveMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return AddEmployeeFailSaveMenuItem;
}
Item* MenuSet::SearchEmployeeFormMenu()
{
    this->MenuCode = EMPLOYEE_SEARCH_CODE;
    this->MenuSize = 2;
    MenuTitle="Employee Menu - Search";
    static Item UpdateSearchEmployeeFormMenuItem[2];
    UpdateSearchEmployeeFormMenuItem[0].SetItem(30,28,EMPLOYEE_SEARCH_SUBMIT_CODE,"Search");
    UpdateSearchEmployeeFormMenuItem[1].SetItem(43,28,MAIN_CODE,"Main Menu");
    return UpdateSearchEmployeeFormMenuItem;
}
void MenuSet::SearchEmployeeFormMenuExtension(int state)
{
        if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(27,29,26);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,39);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,53);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::UpdateEmployeeAfterSaveMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 3;
    MenuTitle="Update Employee - Success";
    static Item UpdateEmployeeAfterSaveMenuItem[3];
    UpdateEmployeeAfterSaveMenuItem[0].SetItem(15,32,EMPLOYEE_UPDATE_CODE,"Update More");
    UpdateEmployeeAfterSaveMenuItem[1].SetItem(32,32,EMPLOYEE_CODE,"<--Employee");
    UpdateEmployeeAfterSaveMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return UpdateEmployeeAfterSaveMenuItem;
}
Item* MenuSet::UpdateEmployeeFailSaveMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 3;
    MenuTitle="Update Employee - Failed";
    static Item UpdateEmployeeFailSaveMenuItem[3];
    UpdateEmployeeFailSaveMenuItem[0].SetItem(15,32,EMPLOYEE_UPDATE_CODE,"<--Update Form");
    UpdateEmployeeFailSaveMenuItem[1].SetItem(32,32,EMPLOYEE_CODE,"Employee");
    UpdateEmployeeFailSaveMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return UpdateEmployeeFailSaveMenuItem;
}

void MenuSet::ViewEmployeeMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(27,29,22);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,40);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,55);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::EmployeeAfterViewMenu()
{
    this->MenuCode = EMPLOYEE_VIEW_CODE;
    this->MenuSize = 3;
    MenuTitle="View Employee - success";
    static Item EmployeeAfterViewMenuItem[2];
    EmployeeAfterViewMenuItem[0].SetItem(15,32,EMPLOYEE_SEARCH_SUBMIT_CODE,"View More");
    EmployeeAfterViewMenuItem[1].SetItem(32,32,EMPLOYEE_CODE,"<--Employee");
    EmployeeAfterViewMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return EmployeeAfterViewMenuItem;
}
Item* MenuSet::ViewSortedEmployeeMenu()
{
    this->MenuCode = EMPLOYEE_VIEW_SORTED_CODE;
    this->MenuSize = 7;
    MenuTitle="Employee Menu - View Sorted";
    static Item ViewSortedEmployeeItem[7];
    ViewSortedEmployeeItem[0].SetItem(9,22,1,"ID. No");
    ViewSortedEmployeeItem[1].SetItem(20,22,2,"Last Name");
    ViewSortedEmployeeItem[2].SetItem(34,22,3,"Dept. Code");
    ViewSortedEmployeeItem[3].SetItem(48,22,4,"Position");
    ViewSortedEmployeeItem[4].SetItem(60,22,4,"Hours Worked");
    ViewSortedEmployeeItem[5].SetItem(25,32,PAYROLL_CODE,"<--Employee");
    ViewSortedEmployeeItem[6].SetItem(45,32,MAIN_CODE,"Main Menu");
    return ViewSortedEmployeeItem;
}
void MenuSet::ViewSortedEmployeeMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(21,23,5);
    LineObj.vSLine();
    LineObj.setVCoord(21,23,17);
    LineObj.vSLine();
    LineObj.setVCoord(21,23,31);
    LineObj.vSLine();
    LineObj.setVCoord(21,23,45);
    LineObj.vSLine();
    LineObj.setVCoord(21,23,57);
    LineObj.vSLine();
    LineObj.setVCoord(21,23,73);
    LineObj.vSLine();
    if(FrameObj.SetFrame(2,76,16,28,NORMAL_FRAME))
    {
        FrameObj.sFraming();
        ConsoleObj.xyCoord(5,16);
        cout<<"Sort Employee by:";
    }
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::EmployeeAfterViewSortedMenu()
{
    this->MenuCode = EMPLOYEE_VIEW_CODE;
    this->MenuSize = 3;
    MenuTitle="View Employee - success";
    static Item EmployeeAfterViewSortedMenuItem[2];
    EmployeeAfterViewSortedMenuItem[0].SetItem(15,32,EMPLOYEE_VIEW_SORTED_CODE,"<--View Sorted");
    EmployeeAfterViewSortedMenuItem[1].SetItem(32,32,EMPLOYEE_CODE,"Employee");
    EmployeeAfterViewSortedMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return EmployeeAfterViewSortedMenuItem;
}






//Payroll Menu
Item* MenuSet::PayrollMenu()
{
    this->MenuCode = PAYROLL_CODE;
    this->MenuSize = 4;
    MenuTitle="Payroll Menu";
    static Item PayrollItem[4];
    PayrollItem[0].SetItem(10,23,1,"Process Payroll");
    PayrollItem[1].SetItem(34,23,2,"View Payroll");
    PayrollItem[2].SetItem(52,23,3,"View Sorted Payroll");
    PayrollItem[3].SetItem(36,27,MAIN_CODE,"Main Menu");
    return &PayrollItem[0];
}
Item* MenuSet::ViewSortedPayrollMenu()
{
    this->MenuCode = 6;
    this->MenuSize = 6;
    MenuTitle="Payroll Menu - View Sorted";
    static Item ViewSortedPayrollItem[6];
    ViewSortedPayrollItem[0].SetItem(13,22,1,"ID. No");
    ViewSortedPayrollItem[1].SetItem(26,22,2,"Last Name");
    ViewSortedPayrollItem[2].SetItem(41,22,3,"Dept. Code");
    ViewSortedPayrollItem[3].SetItem(58,22,4,"Position");
    ViewSortedPayrollItem[4].SetItem(25,32,PAYROLL_CODE,"<--Payroll");
    ViewSortedPayrollItem[5].SetItem(45,32,MAIN_CODE,"Main Menu");
    return &ViewSortedPayrollItem[0];
}
void MenuSet::ViewSortedPayrollMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(21,23,9);
    LineObj.vSLine();
    LineObj.setVCoord(21,23,22);
    LineObj.vSLine();
    LineObj.setVCoord(21,23,37);
    LineObj.vSLine();
    LineObj.setVCoord(21,23,54);
    LineObj.vSLine();
    LineObj.setVCoord(21,23,69);
    LineObj.vSLine();
    if(FrameObj.SetFrame(6,72,16,28,NORMAL_FRAME))
    {
        FrameObj.sFraming();
        ConsoleObj.xyCoord(9,16);
        cout<<"Sort Payroll by:";
    }
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::ViewPayrollMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="View Employee";
    static Item ViewPayrollMenuItem[2];
    ViewPayrollMenuItem[0].SetItem(25,28,PAYROLL_CODE,"<--Payroll");
    ViewPayrollMenuItem[1].SetItem(45,28,MAIN_CODE,"Main Menu");
    return ViewPayrollMenuItem;
}
void MenuSet::ViewPayrollMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(27,29,22);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,41);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,55);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}







//Form Menu
Item* MenuSet::AddDepartmentFormMenu()
{
    this->MenuCode = DEPARTMENT_ADD_CODE;
    this->MenuSize = 4;
    MenuTitle="Add Department Menu";
    static Item AddDepartmentFormItem[4];
    AddDepartmentFormItem[0].SetItem(13,35,DEPARTMENT_ADD_SAVE_CODE,"Save");
    AddDepartmentFormItem[1].SetItem(26,35,DEPARTMENT_ADD_CODE,"Reset Fields");
    AddDepartmentFormItem[2].SetItem(45,35,DEPARTMENT_CODE,"Cancel");
    AddDepartmentFormItem[3].SetItem(58,35,MAIN_CODE,"Main Menu");
    return AddDepartmentFormItem;
}
void MenuSet::AddDepartmentFormMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(34,36,9);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,22);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,41);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,54);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,69);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::UpdateDepartmentFormMenu()
{
    this->MenuCode = DEPARTMENT_UPDATE_FORM_MENU_CODE;
    this->MenuSize = 4;
    MenuTitle="Update Department Menu";
    static Item UpdateDepartmentFormItem[4];
    UpdateDepartmentFormItem[0].SetItem(13,35,DEPARTMENT_UPDATE_SAVE_CODE,"Save");
    UpdateDepartmentFormItem[1].SetItem(26,35,DEPARTMENT_UPDATE_FORM_RESET_CODE,"Reset Fields");
    UpdateDepartmentFormItem[2].SetItem(45,35,DEPARTMENT_CODE,"Cancel");
    UpdateDepartmentFormItem[3].SetItem(58,35,MAIN_CODE,"Main Menu");
    return UpdateDepartmentFormItem;
}
void MenuSet::UpdateDepartmentFormMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(34,36,9);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,22);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,41);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,54);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,69);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::AddEmployeeFormMenu()
{
    this->MenuCode = EMPLOYEE_ADD_CODE;
    this->MenuSize = 4;
    MenuTitle="Add Employee Menu";
    static Item AddEmployeeFormMenuItem[4];
    AddEmployeeFormMenuItem[0].SetItem(13,35,EMPLOYEE_ADD_SAVE_CODE,"Save");
    AddEmployeeFormMenuItem[1].SetItem(26,35,EMPLOYEE_UPDATE_FORM_RESET_CODE,"Reset Fields");
    AddEmployeeFormMenuItem[2].SetItem(45,35,EMPLOYEE_CODE,"Cancel");
    AddEmployeeFormMenuItem[3].SetItem(58,35,MAIN_CODE,"Main Menu");
    return AddEmployeeFormMenuItem;
}
void MenuSet::AddEmployeeFormMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(34,36,9);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,22);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,41);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,54);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,69);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::UpdateEmployeeFormMenu()
{
    this->MenuCode = DEPARTMENT_UPDATE_FORM_MENU_CODE;
    this->MenuSize = 4;
    MenuTitle="Update Employee Menu";
    static Item UpdateEmployeeFormItem[4];
    UpdateEmployeeFormItem[0].SetItem(13,35,EMPLOYEE_UPDATE_SAVE_CODE,"Save");
    UpdateEmployeeFormItem[1].SetItem(26,35,1,"Reset Fields");
    UpdateEmployeeFormItem[2].SetItem(45,35,EMPLOYEE_CODE,"Cancel");
    UpdateEmployeeFormItem[3].SetItem(58,35,MAIN_CODE,"Main Menu");
    return UpdateEmployeeFormItem;
}
void MenuSet::UpdateEmployeeFormMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(34,36,9);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,22);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,41);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,54);
    LineObj.vSLine();
    LineObj.setVCoord(34,36,69);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}






//Department Menu
Item* MenuSet::DepartmentMenu()
{
    this->MenuCode = DEPARTMENT_CODE;
    this->MenuSize = 5;
    MenuTitle="Department Menu";
    static Item DepartmentItem[5];
    DepartmentItem[0].SetItem(15,24,DEPARTMENT_ADD_CODE,"Add");
    DepartmentItem[1].SetItem(28,24,DEPARTMENT_UPDATE_CODE,"Update");
    DepartmentItem[2].SetItem(43,24,DEPARTMENT_VIEW_CODE,"View");
    DepartmentItem[3].SetItem(55,24,DEPARTMENT_LIST_CODE,"View All");
    DepartmentItem[4].SetItem(35,29,MAIN_CODE,"Main Menu");
    return &DepartmentItem[0];
}
Item* MenuSet::ViewSearchDepartmentFormMenu()
{
    this->MenuCode = DEPARTMENT_VIEW_CODE;
    this->MenuSize = 3;
    MenuTitle="View Department";
    static Item ViewSearchDepartmentFormMenuItem[3];
    ViewSearchDepartmentFormMenuItem[0].SetItem(15,28,DEPARTMENT_SEARCH_CODE,"Search");
    ViewSearchDepartmentFormMenuItem[1].SetItem(32,28,DEPARTMENT_CODE,"<--Department");
    ViewSearchDepartmentFormMenuItem[2].SetItem(55,28,MAIN_CODE,"Main Menu");
    return ViewSearchDepartmentFormMenuItem;
}
Item* MenuSet::DepartmentAfterViewMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 3;
    MenuTitle="View Department - Success";
    static Item DepartmentAfterViewMenuItem[3];
    DepartmentAfterViewMenuItem[0].SetItem(15,32,DEPARTMENT_VIEW_CODE,"View More");
    DepartmentAfterViewMenuItem[1].SetItem(32,32,DEPARTMENT_CODE,"<--Department");
    DepartmentAfterViewMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return DepartmentAfterViewMenuItem;
}
Item* MenuSet::ViewAllDepartmentMenu()
{
    this->MenuCode = DEPARTMENT_LIST_CODE;
    this->MenuSize = 2;
    MenuTitle="View all Departments";
    static Item ViewAllDepartmentMenuItem[2];
    ViewAllDepartmentMenuItem[0].SetItem(25,this->YRelativeSystemFrame-4,DEPARTMENT_CODE,"<--Department");
    ViewAllDepartmentMenuItem[1].SetItem(45,this->YRelativeSystemFrame-4,MAIN_CODE,"Main Menu");
    return ViewAllDepartmentMenuItem;
}
void MenuSet::ViewAllDepartmentMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(YRelativeSystemFrame-4-1,YRelativeSystemFrame-4+1,22);
    LineObj.vSLine();
    LineObj.setVCoord(YRelativeSystemFrame-4-1,YRelativeSystemFrame-4+1,41);
    LineObj.vSLine();
    LineObj.setVCoord(YRelativeSystemFrame-4-1,YRelativeSystemFrame-4+1,55);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}
void MenuSet::ViewDepartmentMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(27,29,22);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,41);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,55);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::UpdateSearchDepartmentFormMenu()
{
    this->MenuCode = DEPARTMENT_UPDATE_CODE;
    this->MenuSize = 3;
    MenuTitle="Update Department";
    static Item UpdateDepartmentFormMenuItem[3];
    UpdateDepartmentFormMenuItem[0].SetItem(15,28,DEPARTMENT_SEARCH_CODE,"Search");
    UpdateDepartmentFormMenuItem[1].SetItem(32,28,DEPARTMENT_CODE,"<--Department");
    UpdateDepartmentFormMenuItem[2].SetItem(55,28,MAIN_CODE,"Main Menu");
    return UpdateDepartmentFormMenuItem;
}
void MenuSet::SearchDepartmentFormMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(27,29,11);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,26);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,50);
    LineObj.vSLine();
    LineObj.setVCoord(27,29,67);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::AddDepartmentAfterSaveMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 3;
    MenuTitle="Add Department - Success";
    static Item AddDepartmentAfterSaveMenuItem[3];
    AddDepartmentAfterSaveMenuItem[0].SetItem(15,32,DEPARTMENT_ADD_CODE,"Add More");
    AddDepartmentAfterSaveMenuItem[1].SetItem(32,32,DEPARTMENT_CODE,"<--Department");
    AddDepartmentAfterSaveMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return AddDepartmentAfterSaveMenuItem;
}
Item* MenuSet::AddDepartmentFailSaveMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 3;
    MenuTitle="Add Department - Failed";
    static Item AddDepartmentFailSaveMenuItem[3];
    AddDepartmentFailSaveMenuItem[0].SetItem(15,32,DEPARTMENT_ADD_CODE,"<--Add Form");
    AddDepartmentFailSaveMenuItem[1].SetItem(32,32,DEPARTMENT_CODE,"Department");
    AddDepartmentFailSaveMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return AddDepartmentFailSaveMenuItem;
}
Item* MenuSet::UpdateDepartmentAfterSaveMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 3;
    MenuTitle="Update Department - Success";
    static Item UpdateDepartmentAfterSaveMenuItem[3];
    UpdateDepartmentAfterSaveMenuItem[0].SetItem(15,32,DEPARTMENT_SEARCH_CODE,"Update More");
    UpdateDepartmentAfterSaveMenuItem[1].SetItem(34,32,DEPARTMENT_CODE,"<--Department");
    UpdateDepartmentAfterSaveMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return UpdateDepartmentAfterSaveMenuItem;
}
Item* MenuSet::UpdateDepartmentFailSaveMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 3;
    MenuTitle="Update Department - Failed";
    static Item UpdateDepartmentFailSaveMenuItem[3];
    UpdateDepartmentFailSaveMenuItem[0].SetItem(15,32,DEPARTMENT_UPDATE_FORM_MENU_CODE,"<--Update Form");
    UpdateDepartmentFailSaveMenuItem[1].SetItem(32,32,DEPARTMENT_CODE,"Department");
    UpdateDepartmentFailSaveMenuItem[2].SetItem(50,32,MAIN_CODE,"Main Menu");
    return UpdateDepartmentFailSaveMenuItem;
}





//Delete menu
Item* MenuSet::DeleteConfirmEmployeeMenu()
{
    this->MenuCode = EMPLOYEE_DELETE_CONFIRM_MENU_CODE;
    this->MenuSize = 4;
    MenuTitle="Delete Employee Menu - Confirmation";
    static Item DeleteConfirmEmployeeMenuItem[4];
    DeleteConfirmEmployeeMenuItem[0].SetItem(32,28,EMPLOYEE_DELETE_CODE,"Yes");
    DeleteConfirmEmployeeMenuItem[1].SetItem(40,28,EMPLOYEE_SEARCH_CODE,"No");
    DeleteConfirmEmployeeMenuItem[2].SetItem(25,32,EMPLOYEE_CODE,"Employee");
    DeleteConfirmEmployeeMenuItem[3].SetItem(45,32,MAIN_CODE,"Main Menu");
    return DeleteConfirmEmployeeMenuItem;
}

Item* MenuSet::EmployeeAfterDeleteMenu()
{
    this->MenuCode = EMPLOYEE_VIEW_CODE;
    this->MenuSize = 3;
    MenuTitle="Delete Employee - success";
    static Item EmployeeAfterViewMenuItem[2];
    EmployeeAfterViewMenuItem[0].SetItem(15,32,EMPLOYEE_SEARCH_CODE,"Delete More");
    EmployeeAfterViewMenuItem[1].SetItem(32,32,EMPLOYEE_CODE,"Employee");
    EmployeeAfterViewMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return EmployeeAfterViewMenuItem;
}
Item* MenuSet::EmployeeFailDeleteMenu()
{
    this->MenuCode = EMPLOYEE_VIEW_CODE;
    this->MenuSize = 3;
    MenuTitle="Delete Employee - Failed";
    static Item EmployeeAfterViewMenuItem[2];
    EmployeeAfterViewMenuItem[0].SetItem(15,32,EMPLOYEE_DELETE_CODE,"Retry");
    EmployeeAfterViewMenuItem[1].SetItem(32,32,EMPLOYEE_CODE,"Employee");
    EmployeeAfterViewMenuItem[2].SetItem(55,32,MAIN_CODE,"Main Menu");
    return EmployeeAfterViewMenuItem;
}



//List Menu
Item* MenuSet::ListMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    static Item ListMenuItem[2];
    ListMenuItem[0].SetItem(3,46,1,"[<--Prev]");
    ListMenuItem[1].SetItem(69,46,1,"[Next-->]");
    return ListMenuItem;
}
void MenuSet::DimPrevious()
{
    ScreenObj.SetScreenTextColour(WhiteColour);
    ConsoleObj.xyCoord(3,46);
    cout<<"[<--Previous]";
    ScreenObj.SetScreenTextColour(DefaultTextColour);

}
void MenuSet::DimNext()
{
    ScreenObj.SetScreenTextColour(WhiteColour);
    ConsoleObj.xyCoord(69,46);
    cout<<"[Next-->]";
    ScreenObj.SetScreenTextColour(DefaultTextColour);
}






