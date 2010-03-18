#include "MasterFormMenuController.h"
#include "../Form/Field.h"
#include "../Menu/MenuController.h"
#include "../Form/FormController.h"
#include "../Menu/Menus/MenuSet.h"
#include "../Form/FormController.h"
#include "../Form/FormSet/FormSet.h"
#include "../Menu/Menus/Extended/ExtendedMenuController.h"
#include "../Services/Services.h"

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
void MasterFormMenuController::SetYRelativeSystemFrame(int y)
{
    this->YRelativeSystemFrame=y;
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
            FormControllerObj.BrowseForm();
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==DEPARTMENT_ADD_SAVE_CODE&&FormControllerObj.GetFormCompletionState()==_FAIL)
                {
                    Flag=true;
                }
                if(MenuCall==DEPARTMENT_CODE||MenuCall==MAIN_CODE)
                {
                    this->ClearAllFieldData();
                }
                if(MenuCall==DEPARTMENT_ADD_RESET_CODE)
                {
                    this->ClearAllFieldData();
                    ServicesObj.BasicRunLevel();
                    FormControllerObj.ShowForm();
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.AddDepartmentFormMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    this->FieldObj=FormControllerObj.GetAllFieldInfo();
    this->FormSize=FormControllerObj.GetFormSize();
    return MenuCall;
}
int MasterFormMenuController::UpdateSearchDepartmentMenu()
{
    bool Flag;
    int MenuCall;
    if(FormControllerObj.SetForm(FormSetObj.SearchDepartmentForm(),FormSetObj.GetFormSize(FormSetObj.SearchDepartmentForm()),
    FormSetObj.GetFormCode(FormSetObj.SearchDepartmentForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.UpdateSearchDepartmentFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.UpdateSearchDepartmentFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.UpdateSearchDepartmentFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.SearchDepartmentFormMenuExtension(ON);
        do
        {
            FormControllerObj.BrowseForm();
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==DEPARTMENT_CODE||MenuCall==MAIN_CODE)
                {
                    this->ClearAllFieldData();
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

            FormControllerObj.BrowseForm();
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==DEPARTMENT_UPDATE_SAVE_CODE&&FormControllerObj.GetFormCompletionState()==_FAIL)
                {
                    Flag=true;
                }
                if(MenuCall==MAIN_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchDepartmentForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    this->FieldObj=FormControllerObj.GetAllFieldInfo();
    this->FormSize=FormControllerObj.GetFormSize();
    return MenuCall;
}
int MasterFormMenuController::ViewSearchDepartmentMenu()
{
    bool Flag;
    int MenuCall;
    if(FormControllerObj.SetForm(FormSetObj.SearchDepartmentForm(),FormSetObj.GetFormSize(FormSetObj.SearchDepartmentForm()),
    FormSetObj.GetFormCode(FormSetObj.SearchDepartmentForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.ViewSearchDepartmentFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.ViewSearchDepartmentFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.ViewSearchDepartmentFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.SearchDepartmentFormMenuExtension(ON);
        do
        {

            FormControllerObj.BrowseForm();
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==DEPARTMENT_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchDepartmentForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    this->FieldObj=FormControllerObj.GetAllFieldInfo();
    this->FormSize=FormControllerObj.GetFormSize();
    return MenuCall;
}
int MasterFormMenuController::DepartmentAfterViewMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.DepartmentAfterViewMenu(),MenuSetObj.GetMenuSize(MenuSetObj.DepartmentAfterViewMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.DepartmentAfterViewMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
            }while(Flag);
        }while(MenuCall==0);
    }
    FormSetObj.FlushFieldData(FormSetObj.SearchDepartmentForm());
    return MenuCall;
}
int MasterFormMenuController::ViewAllDepartmentMenu()
{
    int MenuCall;
    bool Flag;
    MenuSetObj.SetYRelativeSystemFrame(YRelativeSystemFrame);
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
                MenuCall=MenuControllerObj.BrowseMenu();
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
                if(MenuCall==MAIN_CODE || MenuCall==DEPARTMENT_CODE || MenuCall==DEPARTMENT_ADD_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.AddDepartmentForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::AddDepartmentFailSaveMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.AddDepartmentFailSaveMenu(),MenuSetObj.GetMenuSize(MenuSetObj.AddDepartmentFailSaveMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.AddDepartmentFailSaveMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==DEPARTMENT_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.AddDepartmentForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::UpdateDepartmentAfterSaveMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.UpdateDepartmentAfterSaveMenu(),MenuSetObj.GetMenuSize(MenuSetObj.UpdateDepartmentAfterSaveMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.UpdateDepartmentAfterSaveMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::UpdateDepartmentFailSaveMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.UpdateDepartmentFailSaveMenu(),MenuSetObj.GetMenuSize(MenuSetObj.UpdateDepartmentFailSaveMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.UpdateDepartmentFailSaveMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==DEPARTMENT_CODE || MenuCall==MAIN_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchDepartmentForm());
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
            FormControllerObj.BrowseForm();
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==EMPLOYEE_ADD_SAVE_CODE&&FormControllerObj.GetFormCompletionState()==_FAIL)
                {
                    Flag=true;
                }
                if(MenuCall==EMPLOYEE_ADD_RESET_CODE)
                {
                    this->ClearAllFieldData();
                    ServicesObj.BasicRunLevel();
                    FormControllerObj.ShowForm();
                    MenuControllerObj.ShowMenu();
                    MenuSetObj.ShowMenuTitle(ON);
                    MenuSetObj.AddEmployeeFormMenuExtension(ON);
                    Flag=true;
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    if(MenuCall==EMPLOYEE_CODE || MenuCall==MAIN_CODE)
    {
        FormSetObj.FlushFieldData(FormSetObj.AddEmployeeForm());
    }
    this->FieldObj=FormControllerObj.GetAllFieldInfo();
    this->FormSize=FormControllerObj.GetFormSize();
    return MenuCall;
}
int MasterFormMenuController::AddEmployeeAfterSaveMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.AddEmployeeAfterSaveMenu(),MenuSetObj.GetMenuSize(MenuSetObj.AddEmployeeAfterSaveMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.AddEmployeeAfterSaveMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==EMPLOYEE_CODE || MenuCall==EMPLOYEE_ADD_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.AddEmployeeForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::AddEmployeeFailSaveMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.AddEmployeeFailSaveMenu(),MenuSetObj.GetMenuSize(MenuSetObj.AddEmployeeFailSaveMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.AddEmployeeFailSaveMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==EMPLOYEE_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.AddEmployeeForm());
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
    MenuControllerObj.SetMenu(MenuSetObj.SearchEmployeeFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.SearchEmployeeFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.SearchEmployeeFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.SearchEmployeeFormMenuExtension(ON);
        do
        {

            FormControllerObj.BrowseForm();
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==EMPLOYEE_CODE)
                {
                    this->ClearAllFieldData();
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    this->FieldObj=FormControllerObj.GetAllFieldInfo();
    this->FormSize=FormControllerObj.GetFormSize();
    return MenuCall;
}
int MasterFormMenuController::UpdateEmployeeMenu()
{
    bool Flag;
    int MenuCall;
    if(FormControllerObj.SetForm(FormSetObj.UpdateEmployeeForm(),FormSetObj.GetFormSize(FormSetObj.UpdateEmployeeForm()),
    FormSetObj.GetFormCode(FormSetObj.UpdateEmployeeForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.UpdateEmployeeFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.UpdateEmployeeFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.UpdateEmployeeFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.UpdateDepartmentFormMenuExtension(ON);
        do
        {
            FormControllerObj.BrowseForm();
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==EMPLOYEE_UPDATE_SAVE_CODE&&FormControllerObj.GetFormCompletionState()==_FAIL)
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
int MasterFormMenuController::UpdateEmployeeAfterSaveMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.UpdateEmployeeAfterSaveMenu(),MenuSetObj.GetMenuSize(MenuSetObj.UpdateEmployeeAfterSaveMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.UpdateEmployeeAfterSaveMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::UpdateEmployeeFailSaveMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.UpdateEmployeeFailSaveMenu(),MenuSetObj.GetMenuSize(MenuSetObj.UpdateEmployeeFailSaveMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.UpdateEmployeeFailSaveMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==EMPLOYEE_CODE || MenuCall==MAIN_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchEmployeeForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::EmployeeAfterViewMenu()
{
    int MenuCall;
    bool Flag;
    if(MenuControllerObj.SetMenu(MenuSetObj.EmployeeAfterViewMenu(),MenuSetObj.GetMenuSize(MenuSetObj.EmployeeAfterViewMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.EmployeeAfterViewMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==EMPLOYEE_VIEW_CODE ||MenuCall==EMPLOYEE_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchEmployeeForm());
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
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::EmployeeAfterViewSortedMenu()
{
    int MenuCall;
    bool Flag;
    MenuSetObj.SetYRelativeSystemFrame(YRelativeSystemFrame);
    if(MenuControllerObj.SetMenu(MenuSetObj.EmployeeAfterViewSortedMenu(),MenuSetObj.GetMenuSize(MenuSetObj.EmployeeAfterViewSortedMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.EmployeeAfterViewSortedMenu())))
    {
        MenuSetObj.ShowMenuTitle(ON);
        MenuControllerObj.ShowMenu();
        MenuSetObj.EmployeeAfterViewSortedMenuExtension(ON);
        do
        {
            do
            {
                Flag=false;
                MenuCall = MenuControllerObj.BrowseMenu();
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::EmployeeDeleteConfirmMenu()
{
    bool Flag;
    int MenuCall;
    if(MenuControllerObj.SetMenu(MenuSetObj.DeleteConfirmEmployeeMenu(),MenuSetObj.GetMenuSize(MenuSetObj.DeleteConfirmEmployeeMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.DeleteConfirmEmployeeMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.DeleteConfirmEmployeeMenuExtension(ON);
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==EMPLOYEE_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchEmployeeForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::EmployeeAfterDeleteMenu()
{
    bool Flag;
    int MenuCall;
    if(MenuControllerObj.SetMenu(MenuSetObj.EmployeeAfterDeleteMenu(),MenuSetObj.GetMenuSize(MenuSetObj.EmployeeAfterDeleteMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.EmployeeAfterDeleteMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        do
        {
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==EMPLOYEE_DELETE_CODE ||MenuCall==EMPLOYEE_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchEmployeeForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::EmployeeFailDeleteMenu()
{
    bool Flag;
    int MenuCall;
    if(MenuControllerObj.SetMenu(MenuSetObj.EmployeeFailDeleteMenu(),MenuSetObj.GetMenuSize(MenuSetObj.EmployeeFailDeleteMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.EmployeeFailDeleteMenu())))
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
                if(MenuCall==MAIN_CODE || MenuCall==EMPLOYEE_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchEmployeeForm());
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
int MasterFormMenuController::PayrollAfterProcessMenu()
{
    bool Flag;
    int MenuCall;
    if(MenuControllerObj.SetMenu(MenuSetObj.PayrollAfterGenerateMenu(),MenuSetObj.GetMenuSize(MenuSetObj.PayrollAfterGenerateMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.PayrollAfterGenerateMenu())))
    {
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        do
        {
            do
            {
                Flag=false;
                MenuCall = MenuControllerObj.BrowseMenu();
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::PayrollFailProcessMenu()
{
    bool Flag;
    int MenuCall;
    if(MenuControllerObj.SetMenu(MenuSetObj.PayrollFailGenerateMenu(),MenuSetObj.GetMenuSize(MenuSetObj.PayrollFailGenerateMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.PayrollFailGenerateMenu())))
    {MenuSetObj.SetYRelativeSystemFrame(YRelativeSystemFrame);
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        do
        {
            do
            {
                Flag=false;
                MenuCall = MenuControllerObj.BrowseMenu();
            }while(Flag);
        }while(MenuCall==0);
    }
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
        do
        {
            do
            {
                Flag=false;
                MenuCall= MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==PAYROLL_CODE || MenuCall==PAYROLL_VIEW_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchPayrollForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::SearchPayrollMenu()
{
    bool Flag;
    int MenuCall;
    if(FormControllerObj.SetForm(FormSetObj.SearchPayrollForm(),FormSetObj.GetFormSize(FormSetObj.SearchPayrollForm()),
    FormSetObj.GetFormCode(FormSetObj.SearchPayrollForm()))&&
    MenuControllerObj.SetMenu(MenuSetObj.SearchPayrollFormMenu(),MenuSetObj.GetMenuSize(MenuSetObj.SearchPayrollFormMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.SearchPayrollFormMenu())))
    {
        FormControllerObj.ShowForm();
        MenuControllerObj.ShowMenu();
        MenuSetObj.ShowMenuTitle(ON);
        MenuSetObj.SearchPayrollFormMenuExtension(ON);
        do
        {
            FormControllerObj.BrowseForm();
            do
            {
                Flag=false;
                MenuCall=MenuControllerObj.BrowseMenu();
                if(MenuCall==MAIN_CODE || MenuCall==PAYROLL_CODE)
                {
                    FormSetObj.FlushFieldData(FormSetObj.SearchPayrollForm());
                }
            }while(Flag);
        }while(MenuCall==0);
    }
    this->FieldObj=FormControllerObj.GetAllFieldInfo();
    this->FormSize=FormControllerObj.GetFormSize();
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
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::PayrollAfterViewSortedMenu()
{
    bool Flag;
    int MenuCall;
    MenuSetObj.SetYRelativeSystemFrame(YRelativeSystemFrame);
    if(MenuControllerObj.SetMenu(MenuSetObj.PayrollAfterViewSortedMenu(),MenuSetObj.GetMenuSize(MenuSetObj.PayrollAfterViewSortedMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.PayrollAfterViewSortedMenu())))
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
            }while(Flag);
        }while(MenuCall==0);
    }
    return MenuCall;
}
int MasterFormMenuController::PayrollFailViewSortedMenu()
{
    bool Flag;
    int MenuCall;
    if(MenuControllerObj.SetMenu(MenuSetObj.PayrollFailViewSortedMenu(),MenuSetObj.GetMenuSize(MenuSetObj.PayrollFailViewSortedMenu()),
    MenuSetObj.GetMenuCode(MenuSetObj.PayrollFailViewSortedMenu())))
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
