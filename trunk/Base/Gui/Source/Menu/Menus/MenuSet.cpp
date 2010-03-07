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
    EmployeeItem[0].SetItem(15,24,1,"Add");
    EmployeeItem[1].SetItem(28,24,2,"Update");
    EmployeeItem[2].SetItem(43,24,3,"View");
    EmployeeItem[3].SetItem(55,24,4,"View Sorted");
    EmployeeItem[4].SetItem(28,29,4,"Delete");
    EmployeeItem[5].SetItem(43,29,MAIN_CODE,"Main Menu");
    return &EmployeeItem[0];
}
Item* MenuSet::UpdateEmployeeFormMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="Update Department";
    static Item UpdateEmployeeFormMenuItem[2];
    UpdateEmployeeFormMenuItem[0].SetItem(25,28,1,"Submit");
    UpdateEmployeeFormMenuItem[1].SetItem(45,28,MAIN_CODE,"Main Menu");
    return UpdateEmployeeFormMenuItem;
}
Item* MenuSet::ViewEmployeeMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="View Employee";
    static Item ViewEmployeeMenuItem[2];
    ViewEmployeeMenuItem[0].SetItem(26,28,PAYROLL_CODE,"<--Employee");
    ViewEmployeeMenuItem[1].SetItem(44,28,MAIN_CODE,"Main Menu");
    return ViewEmployeeMenuItem;
}
Item* MenuSet::ViewAllEmployeeMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="View all Employees";
    static Item ViewAllEmployeeMenuItem[2];
    ViewAllEmployeeMenuItem[0].SetItem(25,48,PAYROLL_CODE,"<--Employee");
    ViewAllEmployeeMenuItem[1].SetItem(45,48,MAIN_CODE,"Main Menu");
    return ViewAllEmployeeMenuItem;
}
Item* MenuSet::ViewSortedEmployeeMenu()
{
    this->MenuCode = 4;
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
    return &ViewSortedEmployeeItem[0];
}
void MenuSet::ViewAllEmployeeMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(47,49,22);
    LineObj.vSLine();
    LineObj.setVCoord(47,49,41);
    LineObj.vSLine();
    LineObj.setVCoord(47,49,55);
    LineObj.vSLine();
    ScreenObj.SetScreenTextColour(48);
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
    MenuTitle="Add Member Menu";
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
    MenuTitle="Add Member Menu";
    static Item UpdateDepartmentFormItem[4];
    UpdateDepartmentFormItem[0].SetItem(13,35,DEPARTMENT_UPDATE_SAVE_CODE,"Save");
    UpdateDepartmentFormItem[1].SetItem(26,35,DEPARTMENT_UPDATE_FORM_MENU_CODE,"Reset Fields");
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
    MenuTitle="Add Member Menu";
    static Item AddEmployeeFormMenuItem[4];
    AddEmployeeFormMenuItem[0].SetItem(13,35,1,"Save");
    AddEmployeeFormMenuItem[1].SetItem(26,35,EMPLOYEE_ADD_CODE,"Reset Fields");
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
Item* MenuSet::EditFormMenu()
{
    this->MenuCode = 7;
    this->MenuSize = 3;
    MenuTitle="Add Member Menu";
    static Item EditFormMenuItem[3];
    EditFormMenuItem[0].SetItem(25,35,1,"Save");
    EditFormMenuItem[1].SetItem(45,35,1,"Cancel");
    EditFormMenuItem[2].SetItem(58,35,MAIN_CODE,"Main Menu");
    return EditFormMenuItem;
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
Item* MenuSet::ViewDepartmentMenu()
{
    this->MenuCode = DEPARTMENT_VIEW_CODE;
    this->MenuSize = 2;
    MenuTitle="View Department";
    static Item ViewDepartmentMenuItem[2];
    ViewDepartmentMenuItem[0].SetItem(25,28,DEPARTMENT_CODE,"<--Department");
    ViewDepartmentMenuItem[1].SetItem(45,28,MAIN_CODE,"Main Menu");
    return ViewDepartmentMenuItem;
}
Item* MenuSet::ViewAllDepartmentMenu()
{
    this->MenuCode = DEPARTMENT_LIST_CODE;
    this->MenuSize = 2;
    MenuTitle="View all Departments";
    static Item ViewAllDepartmentMenuItem[2];
    ViewAllDepartmentMenuItem[0].SetItem(25,48,DEPARTMENT_CODE,"<--Department");
    ViewAllDepartmentMenuItem[1].SetItem(45,48,MAIN_CODE,"Main Menu");
    return ViewAllDepartmentMenuItem;
}
void MenuSet::ViewAllDepartmentMenuExtension(int state)
{
    if(state==OFF)
    {
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    }
    LineObj.setVCoord(47,49,22);
    LineObj.vSLine();
    LineObj.setVCoord(47,49,41);
    LineObj.vSLine();
    LineObj.setVCoord(47,49,55);
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
Item* MenuSet::SearchDepartmentFormMenu()
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






