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
Item* MenuSet::MainMenu()
{
    this->MenuCode = 1;
    this->MenuSize = 4;
    MenuTitle="MAIN MENU";
    static Item MainItem[4];
    MainItem[0].SetItem(17,23,1,"DEPARTMENT");
    MainItem[1].SetItem(37,23,2,"EMPLOYEE");
    MainItem[2].SetItem(54,23,3,"PAYROLL");
    MainItem[3].SetItem(39,27,4,"EXIT");
    return &MainItem[0];
}

Item* MenuSet::DepartmentMenu()
{
    this->MenuCode = 2;
    this->MenuSize = 5;
    MenuTitle="Department Menu";
    static Item DepartmentItem[5];
    DepartmentItem[0].SetItem(15,24,1,"ADD");
    DepartmentItem[1].SetItem(28,24,2,"UPDATE");
    DepartmentItem[2].SetItem(43,24,3,"VIEW");
    DepartmentItem[3].SetItem(55,24,4,"VIEW ALL");
    DepartmentItem[4].SetItem(35,29,4,"MAIN MENU");
    return &DepartmentItem[0];
}
Item* MenuSet::EmployeeMenu()
{
    this->MenuCode = 3;
    this->MenuSize = 6;
    MenuTitle="Employee Menu";
    static Item EmployeeItem[6];
    EmployeeItem[0].SetItem(15,24,1,"ADD");
    EmployeeItem[1].SetItem(28,24,2,"UPDATE");
    EmployeeItem[2].SetItem(43,24,3,"VIEW");
    EmployeeItem[3].SetItem(55,24,4,"VIEW SORTED");
    EmployeeItem[4].SetItem(28,29,4,"DELETE");
    EmployeeItem[5].SetItem(43,29,4,"MAIN MENU");
    return &EmployeeItem[0];
}
Item* MenuSet::UpdateEmployeeFormMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="Update Department";
    static Item UpdateEmployeeFormMenuItem[2];
    UpdateEmployeeFormMenuItem[0].SetItem(25,28,1,"SUBMIT");
    UpdateEmployeeFormMenuItem[1].SetItem(45,28,1,"MAINMENU");
    return UpdateEmployeeFormMenuItem;
}
Item* MenuSet::ViewEmployeeMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="View Employee";
    static Item ViewEmployeeMenuItem[2];
    ViewEmployeeMenuItem[0].SetItem(25,28,1,"<--EMPLOYEE");
    ViewEmployeeMenuItem[1].SetItem(45,28,1,"MAINMENU");
    return ViewEmployeeMenuItem;
}
Item* MenuSet::ViewAllEmployeeMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="View all Employees";
    static Item ViewAllEmployeeMenuItem[2];
    ViewAllEmployeeMenuItem[0].SetItem(25,48,1,"<--EMPLOYEE");
    ViewAllEmployeeMenuItem[1].SetItem(45,48,1,"MAINMENU");
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
    ViewSortedEmployeeItem[5].SetItem(25,29,4,"<--EMPLOYEE");
    ViewSortedEmployeeItem[6].SetItem(45,29,4,"MAIN MENU");
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
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::PayrollMenu()
{
    this->MenuCode = 5;
    this->MenuSize = 4;
    MenuTitle="Payroll Menu";
    static Item PayrollItem[4];
    PayrollItem[0].SetItem(10,23,1,"PROCESS PAYROLL");
    PayrollItem[1].SetItem(34,23,2,"VIEW PAYROLL");
    PayrollItem[2].SetItem(52,23,3,"VIEW SORTED PAYROLL");
    PayrollItem[3].SetItem(36,27,2,"MAIN MENU");
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
    ViewSortedPayrollItem[4].SetItem(25,29,4,"<--PAYROLL");
    ViewSortedPayrollItem[5].SetItem(45,29,4,"MAIN MENU");
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
    ScreenObj.SetScreenTextColour(48);
}
Item* MenuSet::GeneralFormMenu()
{
    this->MenuCode = 7;
    this->MenuSize = 4;
    MenuTitle="Add Member Menu";
    static Item GeneralFormMenuItem[4];
    GeneralFormMenuItem[0].SetItem(13,35,1,"SUBMIT");
    GeneralFormMenuItem[1].SetItem(26,35,1,"CLEAR FIELDS");
    GeneralFormMenuItem[2].SetItem(45,35,1,"CANCEL");
    GeneralFormMenuItem[3].SetItem(58,35,1,"MAIN MENU");
    return GeneralFormMenuItem;
}
Item* MenuSet::EditFormMenu()
{
    this->MenuCode = 7;
    this->MenuSize = 3;
    MenuTitle="Add Member Menu";
    static Item EditFormMenuItem[3];
    EditFormMenuItem[0].SetItem(25,35,1,"SUBMIT");
    EditFormMenuItem[1].SetItem(45,35,1,"CANCEL");
    EditFormMenuItem[2].SetItem(58,35,1,"MAIN MENU");
    return EditFormMenuItem;
}
Item* MenuSet::ViewDepartmentMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="View Department";
    static Item ViewDepartmentMenuItem[2];
    ViewDepartmentMenuItem[0].SetItem(25,28,1,"<--DEPARTMENT");
    ViewDepartmentMenuItem[1].SetItem(45,28,1,"MAINMENU");
    return ViewDepartmentMenuItem;
}
Item* MenuSet::ViewAllDepartmentMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="View all Departments";
    static Item ViewAllDepartmentMenuItem[2];
    ViewAllDepartmentMenuItem[0].SetItem(25,48,1,"<--DEPARTMENT");
    ViewAllDepartmentMenuItem[1].SetItem(45,48,1,"MAINMENU");
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
Item* MenuSet::UpdateDepartmentFormMenu()
{
    this->MenuCode = 8;
    this->MenuSize = 2;
    MenuTitle="Update Department";
    static Item UpdateDepartmentFormMenuItem[2];
    UpdateDepartmentFormMenuItem[0].SetItem(25,28,1,"SUBMIT");
    UpdateDepartmentFormMenuItem[1].SetItem(45,28,1,"MAINMENU");
    return UpdateDepartmentFormMenuItem;
}
void MenuSet::UpdateDepartmentFormMenuExtension(int state)
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
    cout<<"[<--PREVIOUS]";
    ScreenObj.SetScreenTextColour(DefaultTextColour);

}
void MenuSet::DimNext()
{
    ScreenObj.SetScreenTextColour(WhiteColour);
    ConsoleObj.xyCoord(69,46);
    cout<<"[NEXT-->]";
    ScreenObj.SetScreenTextColour(DefaultTextColour);
}
void MenuSet::GeneralFormMenuExtension(int state)
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
