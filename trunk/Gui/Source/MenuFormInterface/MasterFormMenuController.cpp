#include "MasterFormMenuController.h"

#include "../Menu/MenuController.h"
#include "../Form/FormController.h"
#include "../Menu/Menus/MenuSet.h"
#include "../Form/FormController.h"
#include "../Form/FormSet/FormSet.h"
#include "../Menu/Menus/Extended/ExtendedMenuController.h"

MasterFormMenuController::MasterFormMenuController()
{
}
MasterFormMenuController::~MasterFormMenuController()
{
}
/*
 * Main Menu
*/
int MasterFormMenuController::MainMenu()
{
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.MainMenu(),MenuSetObj.GetMenuSize(MenuSetObj.MainMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.MainMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuControllerObj.BrowseMenu(),MenuControllerObj.GetMenuCode()))
                {
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuControllerObj.ShowMenu();
                    Flag=true;
                }
            }while(Flag);
        }while(true);
    }
    return 0;
}
/*
 * Department Menu
*/
int MasterFormMenuController::DepartmentMenu()
{
    if(MenuControllerObj.SetMenu(MenuSetObj.MainMenu(),MenuSetObj.GetMenuSize(MenuSetObj.MainMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.MainMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuControllerObj.BrowseMenu();
    }
    return 0;
}
int MasterFormMenuController::AddDepartmentMenu()
{
    return 0;
}
int MasterFormMenuController::UpdateDepartmentMenu()
{
    return 0;
}
int MasterFormMenuController::ViewDepartmentMenu()
{
    return 0;
}
int MasterFormMenuController::ViewAllDepartmentMenu()
{
    return 0;
}
/*
 *Employee Menu
*/
int MasterFormMenuController::EmployeeMenu()
{
    if(MenuControllerObj.SetMenu(MenuSetObj.EmployeeMenu(),MenuSetObj.GetMenuSize(MenuSetObj.EmployeeMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.EmployeeMenu())))
    {
        MenuControllerObj.ShowMenu();
        do
        {
            MenuControllerObj.BrowseMenu();
        }while(true);
    }
    return 0;
}
int MasterFormMenuController::AddEmployeeMenu()
{
    bool Flag;
    if(FormControllerObj.SetForm(FormSetObj.AddEmployeeForm(),FormSetObj.GetFormSize(FormSetObj.AddEmployeeForm()),
    FormSetObj.GetFormCode(FormSetObj.AddEmployeeForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.GeneralFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.GeneralFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.GeneralFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(FormControllerObj.BrowseForm(),FormControllerObj.GetFormCode()))
                {
                    FormControllerObj.ShowForm();
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.GeneralFormMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
            do
            {
                Flag=false;
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuControllerObj.BrowseMenu(),MenuControllerObj.GetMenuCode()))
                {
                    FormControllerObj.ShowForm();
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.GeneralFormMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(true);
    }
    return 0;
}
int MasterFormMenuController::UpdateEmployeeMenu()
{
    return 0;
}
int MasterFormMenuController::ViewEmployeeMenu()
{
    return 0;
}
int MasterFormMenuController::ViewSortedEmployeeMenu()
{
    if(MenuControllerObj.SetMenu(MenuSetObj.ViewSortedEmployeeMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ViewSortedEmployeeMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ViewSortedEmployeeMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuControllerObj.BrowseMenu();
    }
    return 0;
}
/*
 * Payroll Menu
*/
int MasterFormMenuController::PayrollMenu()
{
    if(MenuControllerObj.SetMenu(MenuSetObj.PayrollMenu(),MenuSetObj.GetMenuSize(MenuSetObj.PayrollMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.PayrollMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuControllerObj.BrowseMenu();
    }
    return 0;
}
int MasterFormMenuController::ProcessPayrollMenu()
{
    return 0;
}
int MasterFormMenuController::ViewPayrollMenu()
{
    return 0;
}
int MasterFormMenuController::ViewSortedPayrollMenu()
{
    if(MenuControllerObj.SetMenu(MenuSetObj.ViewSortedPayrollMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ViewSortedPayrollMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ViewSortedPayrollMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuControllerObj.BrowseMenu();
    }
    return 0;
}
/*
 * Exit Menu
*/
int MasterFormMenuController::ExitMenu()
{
    return 0;
}
