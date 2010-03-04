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
    int MenuCall;
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
                MenuCall=MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuControllerObj.ShowMenu();
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
/*
 * Department Menu
*/
int MasterFormMenuController::DepartmentMenu()
{
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.DepartmentMenu(),MenuSetObj.GetMenuSize(MenuSetObj.DepartmentMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.DepartmentMenu())))
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
int MasterFormMenuController::AddDepartmentMenu()
{
    bool Flag;
    if(FormControllerObj.SetForm(FormSetObj.AddDepartmentForm(),FormSetObj.GetFormSize(FormSetObj.AddDepartmentForm()),
    FormSetObj.GetFormCode(FormSetObj.AddDepartmentForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.GeneralFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.GeneralFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.GeneralFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.GeneralFormMenuExtension(ON);
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
int MasterFormMenuController::SearchDepartmentMenu()
{
    bool Flag;
    if(FormControllerObj.SetForm(FormSetObj.SearchDepartmentForm(),FormSetObj.GetFormSize(FormSetObj.SearchDepartmentForm()),
    FormSetObj.GetFormCode(FormSetObj.SearchDepartmentForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.UpdateDepartmentFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.UpdateDepartmentFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.UpdateDepartmentFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
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
                    Flag=true;
                }
            }while(Flag);
        }while(true);
    }
    return 0;
}
int MasterFormMenuController::UpdateDepartmentMenu()
{
    return 0;
}
int MasterFormMenuController::ViewDepartmentMenu()
{
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.ViewDepartmentMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ViewDepartmentMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ViewDepartmentMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.ViewDepartmentMenuExtension(ON);
        do
        {
            do
            {
                Flag=false;
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuControllerObj.BrowseMenu(),MenuControllerObj.GetMenuCode()))
                {
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewDepartmentMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(true);
    }
    return 0;
}
int MasterFormMenuController::ViewAllDepartmentMenu()
{
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.ViewAllDepartmentMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ViewAllDepartmentMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ViewAllDepartmentMenu())))
        MenuControllerObj.ShowMenu();
        MenuSetObj.ViewAllDepartmentMenuExtension(ON);
        MenuSetObj.ShowMenuTitle(ON);
        do
        {
            do
            {
                Flag=false;
                ListObj.BrowseList();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuControllerObj.BrowseMenu(),MenuControllerObj.GetMenuCode()))
                {
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ViewAllDepartmentMenuExtension(ON);
                    MenuSetObj.ShowMenuTitle(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(true);
    return 0;
}
/*
 *Employee Menu
*/
int MasterFormMenuController::EmployeeMenu()
{
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.EmployeeMenu(),MenuSetObj.GetMenuSize(MenuSetObj.EmployeeMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.EmployeeMenu())))
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
int MasterFormMenuController::AddEmployeeMenu()
{
    bool Flag;
    int MenuCall;
    if(FormControllerObj.SetForm(FormSetObj.AddEmployeeForm(),FormSetObj.GetFormSize(FormSetObj.AddEmployeeForm()),
    FormSetObj.GetFormCode(FormSetObj.AddEmployeeForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.GeneralFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.GeneralFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.GeneralFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.GeneralFormMenuExtension(ON);
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
                MenuCall=MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    FormControllerObj.ShowForm();
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.GeneralFormMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::SearchEmployeeMenu()
{
    bool Flag;
    if(FormControllerObj.SetForm(FormSetObj.SearchEmployeeForm(),FormSetObj.GetFormSize(FormSetObj.SearchEmployeeForm()),
    FormSetObj.GetFormCode(FormSetObj.SearchEmployeeForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.UpdateEmployeeFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.UpdateEmployeeFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.UpdateEmployeeFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
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
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.ViewEmployeeMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ViewEmployeeMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ViewEmployeeMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.ViewEmployeeMenuExtension(ON);
        do
        {
            do
            {
                Flag=false;
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuControllerObj.BrowseMenu(),MenuControllerObj.GetMenuCode()))
                {
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewEmployeeMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(true);
    }
    return 0;
}
int MasterFormMenuController::ViewSortedEmployeeMenu()
{
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.ViewSortedEmployeeMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ViewSortedEmployeeMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ViewSortedEmployeeMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.ViewSortedEmployeeMenuExtension(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuControllerObj.BrowseMenu(),MenuControllerObj.GetMenuCode()))
                {
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewSortedEmployeeMenuExtension(ON);
                    MenuControllerObj.ShowMenu();
                    Flag=true;
                }
            }while(Flag);
        }while(true);
    }
    return 0;
}
/*
 * Payroll Menu
*/
int MasterFormMenuController::PayrollMenu()
{
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.PayrollMenu(),MenuSetObj.GetMenuSize(MenuSetObj.PayrollMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.PayrollMenu())))
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
int MasterFormMenuController::ProcessPayrollMenu()
{
    return 0;
}
int MasterFormMenuController::ViewPayrollMenu()
{
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.ViewPayrollMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ViewPayrollMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ViewPayrollMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.ViewDepartmentMenuExtension(ON);
        do
        {
            do
            {
                Flag=false;
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuControllerObj.BrowseMenu(),MenuControllerObj.GetMenuCode()))
                {
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewDepartmentMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(true);
    }
    return 0;
}
int MasterFormMenuController::ViewSortedPayrollMenu()
{
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.ViewSortedPayrollMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ViewSortedPayrollMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ViewSortedPayrollMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.ViewSortedPayrollMenuExtension(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuControllerObj.BrowseMenu(),MenuControllerObj.GetMenuCode()))
                {
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewSortedPayrollMenuExtension(ON);
                    MenuControllerObj.ShowMenu();
                    Flag=true;
                }
            }while(Flag);
        }while(true);
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
