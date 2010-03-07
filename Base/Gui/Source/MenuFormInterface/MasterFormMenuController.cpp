#include "MasterFormMenuController.h"
#include "../Form/Field.h"
#include "../Menu/MenuController.h"
#include "../Form/FormController.h"
#include "../Menu/Menus/MenuSet.h"
#include "../Form/FormController.h"
#include "../Form/FormSet/FormSet.h"
#include "../Menu/Menus/Extended/ExtendedMenuController.h"

MasterFormMenuController::MasterFormMenuController()
{
    FormSize=0;
}
MasterFormMenuController::~MasterFormMenuController()
{
}
Field* MasterFormMenuController::GetAllFieldData()
{
    return FieldObj;
}
void MasterFormMenuController::SetAllFieldData(Field *NewField)
{
    FormControllerObj.UpdateAllFieldInfo(NewField);
}
int MasterFormMenuController::GetFormSize()
{
    return FormSize;
}
void MasterFormMenuController::ClearAllFieldData()
{
    FormControllerObj.ClearAllFieldData();
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
    int MenuCall;
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
int MasterFormMenuController::AddDepartmentMenu()
{
    bool Flag;
    int MenuCall;
    if(FormControllerObj.SetForm(FormSetObj.AddDepartmentForm(),FormSetObj.GetFormSize(FormSetObj.AddDepartmentForm()),
    FormSetObj.GetFormCode(FormSetObj.AddDepartmentForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.AddDepartmentFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.AddDepartmentFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.AddDepartmentFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.AddDepartmentFormMenuExtension(ON);
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
                    MenuSetObj.AddDepartmentFormMenuExtension(ON);
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
                    MenuSetObj.AddDepartmentFormMenuExtension(ON);
                    Flag=true;
                }
                if(MenuCall==DEPARTMENT_ADD_SAVE_CODE&&FormControllerObj.GetFormCompletionState()==_FAIL)
                {
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    this->FieldObj=FormControllerObj.GetAllFieldInfo();
    this->FormSize=FormControllerObj.GetFormSize();
    return MenuCall;
}
int MasterFormMenuController::SearchDepartmentMenu()
{
    bool Flag;
    int MenuCall;
    if(FormControllerObj.SetForm(FormSetObj.SearchDepartmentForm(),FormSetObj.GetFormSize(FormSetObj.SearchDepartmentForm()),
    FormSetObj.GetFormCode(FormSetObj.SearchDepartmentForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.SearchDepartmentFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.SearchDepartmentFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.SearchDepartmentFormMenu())))
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
                MenuCall=MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    FormControllerObj.ShowForm();
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    this->FieldObj=FormControllerObj.GetAllFieldInfo();
    this->FormSize=FormControllerObj.GetFormSize();
    return MenuCall;
}
int MasterFormMenuController::UpdateDepartmentMenu()
{
    bool Flag;
    int MenuCall;
    if(FormControllerObj.SetForm(FormSetObj.UpdateDepartmentForm(),FormSetObj.GetFormSize(FormSetObj.UpdateDepartmentForm()),
    FormSetObj.GetFormCode(FormSetObj.UpdateDepartmentForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.UpdateDepartmentFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.UpdateDepartmentFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.UpdateDepartmentFormMenu())))
    {
        /*
        Field *ptr=FormControllerObj.GetAllFieldInfo();
        cout<<"["<<(ptr+2)->GetFieldData()<<"]";
        system("pause");
        */
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.UpdateDepartmentFormMenuExtension(ON);
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
                    MenuSetObj.UpdateDepartmentFormMenuExtension(ON);
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
                    MenuSetObj.UpdateDepartmentFormMenuExtension(ON);
                    Flag=true;
                }
                if(MenuCall==DEPARTMENT_UPDATE_SAVE_CODE&&FormControllerObj.GetFormCompletionState()==_FAIL)
                {
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    this->FieldObj=FormControllerObj.GetAllFieldInfo();
    this->FormSize=FormControllerObj.GetFormSize();
    return MenuCall;
}
int MasterFormMenuController::ViewDepartmentMenu()
{
    bool Flag;
    int MenuCall;
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
                MenuCall = MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewDepartmentMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::ViewAllDepartmentMenu()
{
    bool Flag;
    int MenuCall;
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
                MenuCall=MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ViewAllDepartmentMenuExtension(ON);
                    MenuSetObj.ShowMenuTitle(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    return MenuCall;
}
int MasterFormMenuController::AddDepartmentAfterSaveMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.AddDepartmentAfterSaveMenu(),MenuSetObj.GetMenuSize(MenuSetObj.AddDepartmentAfterSaveMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.AddDepartmentAfterSaveMenu())))
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
 *Employee Menu
*/
int MasterFormMenuController::EmployeeMenu()
{
    bool Flag;
    int MenuCall;
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
int MasterFormMenuController::AddEmployeeMenu()
{
    bool Flag;
    int MenuCall;
    if(FormControllerObj.SetForm(FormSetObj.AddEmployeeForm(),FormSetObj.GetFormSize(FormSetObj.AddEmployeeForm()),
    FormSetObj.GetFormCode(FormSetObj.AddEmployeeForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.AddEmployeeFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.AddEmployeeFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.AddEmployeeFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.AddEmployeeFormMenuExtension(ON);
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
                    MenuSetObj.AddEmployeeFormMenuExtension(ON);
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
                    MenuSetObj.AddEmployeeFormMenuExtension(ON);
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
    int MenuCall;
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
                MenuCall=MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    FormControllerObj.ShowForm();
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::UpdateEmployeeMenu()
{
    int MenuCall;
    return MenuCall;
}
int MasterFormMenuController::ViewEmployeeMenu()
{
    bool Flag;
    int MenuCall;
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
                MenuCall=MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewEmployeeMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::ViewSortedEmployeeMenu()
{
    bool Flag;
    int MenuCall;
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
                MenuCall = MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewSortedEmployeeMenuExtension(ON);
                    MenuControllerObj.ShowMenu();
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
/*
 * Payroll Menu
*/
int MasterFormMenuController::PayrollMenu()
{
    bool Flag;
    int MenuCall;
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
int MasterFormMenuController::ProcessPayrollMenu()
{
    int MenuCall;
    return MenuCall;
}
int MasterFormMenuController::ViewPayrollMenu()
{
    bool Flag;
    int MenuCall;
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
                MenuCall= MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewDepartmentMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::ViewSortedPayrollMenu()
{
    bool Flag;
    int MenuCall;
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
                MenuCall=MenuControllerObj.BrowseMenu();
                if(ExtendedMenuControllerObj.ExtendedMenuCalls(MenuCall,MenuControllerObj.GetMenuCode()))
                {
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.ViewSortedPayrollMenuExtension(ON);
                    MenuControllerObj.ShowMenu();
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
/*
 * Exit Menu
*/
int MasterFormMenuController::ExitMenu()
{
    int MenuCall;
    return MenuCall;
}
