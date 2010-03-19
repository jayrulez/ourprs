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

#include "FormController.h"
#include "../Menu/MenuController.h"
#include "FormSet/FormSet.h"
#include "Field.h"
#include <iostream>
using namespace std;

FormController::FormController()
{
}

FormController::~FormController()
{
}
int FormController::GetFormCode()
{
	return this->FormCode;
}
int FormController::GetFormSize()
{
	return this->FormSize;
}
bool FormController::GetFormCompletionState()
{
    return CompleteState;
}
bool FormController::SetForm(Field* FormObj,int FormSize,int FormCode)
{
    if(FormSize>0)
    {
        this->FormSize=FormSize;
        this->fptr=FormObj;
        this->FormCode=FormCode;
        CurrentField=DefaultStartingField();
        PreviousField=CurrentField;
        CompleteState=true;
        VerticalFormRangeCheck=IN_FORM_RANGE;
        if(this->FormCode==DEPARTMENT_UPDATE_FORM_CODE)
        {
            this->UpdateFormOldKey=(this->fptr)->GetFieldData();
        }
        if(this->FormCode==EMPLOYEE_UPDATE_FORM_CODE)
        {
            this->UpdateFormOldKey=(this->fptr)->GetFieldData();
        }
        return true;
    }
    else
        return false;
}


int FormController::BrowseForm()
{
    bool read=false;
    ConsoleObj.SetCursor(true,20);
    while(!read)
    {
        Browse();
        FieldInput();
        switch(TextInputObj.GetVirtualKey())
        {
            case UP_KEY:
                CurrentField=SearchField(_PREV);
                ConsoleObj.xyCoord(PreviousField.GetFieldX(),PreviousField.GetFieldY()-1);
                ValidateDepartmentFields();
                ValidateEmployeeFields();
            break;
            case TAB_KEY:
            case DOWN_KEY:
            case ENTER_KEY:
                CurrentField=SearchField(_NEXT);
                ConsoleObj.xyCoord(PreviousField.GetFieldX(),PreviousField.GetFieldY()-1);
                ValidateDepartmentFields();
                ValidateEmployeeFields();
            break;
        }
        UpdateField();
        if(VerticalFormRangeCheck==OUT_OF_FORM_RANGE)
        {
            read=true;
            VerticalFormRangeCheck=IN_FORM_RANGE;
        }
    }
    this->ValidateForm();
    return 0;
}
void FormController::Browse()
{
    ConsoleObj.xyCoord(CurrentField.GetFieldX()+CurrentField.GetFieldNameLength()+FIELD_NAME_PAD+CurrentField.GetFieldDataLength(),CurrentField.GetFieldY());
}
Field FormController::DefaultStartingField()
{
    int x;
    Field TempField;
    TempField=*fptr;
    for(x=0;x<FormSize;x++)
    {
        if((fptr+x)->GetFieldY()<TempField.GetFieldY())
        {
            TempField=*(fptr+x);
        }
    }
    return TempField;
}
Field FormController::SearchField(int type)
{
    int x;
    int y;
    Field TempField;
    PreviousField=CurrentField;
    switch(type)
    {
        case _NEXT:
            for(x=0;x<FormSize;x++)
            {
                if((fptr+x)->GetFieldY()>CurrentField.GetFieldY())
                {
                    TempField=*(fptr+x);
                    for(y=0;y<FormSize;y++)
                    {
                        if((fptr+y)->GetFieldY()<TempField.GetFieldY()&&(fptr+y)->GetFieldY()>CurrentField.GetFieldY())
                        {
                            TempField=*(fptr+y);
                        }
                    }
                    break;
                }
            }
            if(FormRangeCheck(_NEXT)==OUT_OF_FORM_RANGE)
            {
                VerticalFormRangeCheck=OUT_OF_FORM_RANGE;
                return CurrentField;
            }
            return TempField;
        break;

        case _PREV:
            for(x=0;x<FormSize;x++)
            {
                if((fptr+x)->GetFieldY()<CurrentField.GetFieldY())
                {
                    TempField=*(fptr+x);
                    for(y=0;y<FormSize;y++)
                    {
                        if((fptr+y)->GetFieldY()>TempField.GetFieldY()&&(fptr+y)->GetFieldY()<CurrentField.GetFieldY())
                        {
                            TempField=*(fptr+y);
                        }
                    }
                    break;
                }
            }
            if(FormRangeCheck(_PREV)==OUT_OF_FORM_RANGE)
            {
                VerticalFormRangeCheck=OUT_OF_FORM_RANGE;
                return CurrentField;
            }
            return TempField;
        break;
    }
    throw 1;
}
bool FormController::FormRangeCheck(int type)
{
    int x;
    switch(type)
    {
        case _NEXT:
            for(x=0;x<FormSize;x++)
            {
                if((fptr+x)->GetFieldY()>CurrentField.GetFieldY())
                {
                    return IN_FORM_RANGE;
                }
            }
        break;
        case _PREV:
            for(x=0;x<FormSize;x++)
            {
                if((fptr+x)->GetFieldY()<CurrentField.GetFieldY())
                {

                    return IN_FORM_RANGE;
                }
            }
        break;
    }
    return OUT_OF_FORM_RANGE;
}
void FormController::UpdateField()
{
    int x;
    for(x=0;x<FormSize;x++)
    {
        if(PreviousField==*(fptr+x))
        {
            (fptr+x)->SetFieldData(PreviousField.GetFieldData());
            break;
        }
    }
}
void FormController::FieldInput()
{
    TextInputObj.SetFormTextInput(CurrentField.GetInputType(),CurrentField.GetInputLength(),CurrentField.GetSpaceType());
    CurrentField.SetFieldData(TextInputObj.FormTextInput(CurrentField.GetFieldData()));
}

bool FormController::ValidateEmployeeFields()
{
    if(FormCode==EMPLOYEE_ADD_FORM_CODE)
    {
        if(!ValidatorObj.CheckDataExistence(PreviousField.GetFieldData()))
        {
            SetFieldState(false);
            return false;
        }
        if(PreviousField.GetFieldName()=="Dept. Code")
        {
            if(ValidatorObj.CheckDepartmentExistenceInEmployeeForm(PreviousField.GetFieldData())==false)
            {
                SetFieldState(false);
                return false;
            }
        }
        if(PreviousField.GetFieldName()=="ID. No")
        {

            if(ValidatorObj.CheckEmployeeExistence(PreviousField.GetFieldData()))
            {
                SetFieldState(false);
                return false;
            }
        }
    }
    if(FormCode==EMPLOYEE_UPDATE_FORM_CODE)
    {
        if(!ValidatorObj.CheckDataExistence(PreviousField.GetFieldData()))
        {
            SetFieldState(false);
            return false;
        }
        if(PreviousField.GetFieldName()=="ID. No")
        {
            if(ValidatorObj.CheckOtherEmployeeExistence(PreviousField.GetFieldData(),UpdateFormOldKey)==true)
            {
                SetFieldState(false);
                return false;
            }
        }
        if(PreviousField.GetFieldName()=="Dept. Code")
        {
            if(!ValidatorObj.CheckDepartmentExistenceInEmployeeForm(PreviousField.GetFieldData()))
            {
                SetFieldState(false);
                return false;
            }
        }
    }
    if(FormCode==EMPLOYEE_SEARCH_FORM_CODE)
    {
        if(!ValidatorObj.CheckDataExistence(PreviousField.GetFieldData()))
        {
            SetFieldState(false);
            return false;
        }
    }
    SetFieldState(true);
    return true;
}
bool FormController::ValidatePayrollFields()
{
    if(FormCode==PAYROLL_SEARCH_FORM_CODE)
    {
        if(!ValidatorObj.CheckDataExistence(PreviousField.GetFieldData()))
        {
            SetFieldState(false);
            return false;
        }
    }
    SetFieldState(true);
    return true;
}
bool FormController::ValidateDepartmentFields()
{
    if(this->FormCode==DEPARTMENT_ADD_FORM_CODE)
    {
        if(!ValidatorObj.CheckDataExistence(PreviousField.GetFieldData()))
        {
            SetFieldState(false);
            return false;
        }
        if(PreviousField.GetFieldName()=="Dept. Code")
        {
            if(ValidatorObj.CheckDepartmentExistence(PreviousField.GetFieldData()))
            {
                SetFieldState(false);
                return false;
            }
        }
    }
    if(FormCode==DEPARTMENT_UPDATE_FORM_CODE)
    {
        if(!ValidatorObj.CheckDataExistence(PreviousField.GetFieldData()))
        {
            SetFieldState(false);
            return false;
        }
        if(PreviousField.GetFieldName()=="Dept. Code")
        {
            if(ValidatorObj.CheckOtherDepartmentExistence(PreviousField.GetFieldData(),UpdateFormOldKey)==true)
            {
                SetFieldState(false);
                return false;
            }
        }
    }
    if(FormCode==DEPARTMENT_SEARCH_FORM_CODE)
    {
        if(!ValidatorObj.CheckDataExistence(PreviousField.GetFieldData()))
        {
            SetFieldState(false);
            return false;
        }
    }
    SetFieldState(true);
    return true;
}
bool FormController::ValidateForm()
{
    int x;
    for(x=0;x<FormSize;x++)
    {
        if(!(fptr+x)->GetValidData())
        {
            //cout<<"["<<(fptr+x)->GetValidData()<<"]"<<endl;system("pause");
            CompleteState=false;
            return false;
        }
    }
    return true;
}
void FormController::SetFieldState(bool state)
{
    int x;
    for(x=0;x<FormSize;x++)
    {
        cout<<"["<<(fptr+x)->GetValidData()<<"]"<<endl;system("pause");
        if(PreviousField==*(fptr+x))
        {
            (fptr+x)->SetValidData(state);
        }
    }
}
void FormController::ShowForm()
{
    int x;
    Field TempField;
    for(x=0;x<this->FormSize;x++)
    {
        (fptr+x)->ShowField();
        TempField=*(fptr+x);
        ConsoleObj.xyCoord(TempField.GetFieldX(),TempField.GetFieldY()-1);
        ValidateEmployeeFields();
        ValidateDepartmentFields();
    }
}
Field* FormController::GetAllFieldInfo()
{
    return this->fptr;
}
void FormController::UpdateAllFieldInfo(Field *fptr)
{
    this->fptr=fptr;
}
void FormController::ClearAllFieldData()
{
    string Dummy;
    for(int x=0;x<FormSize;x++)
    {
        ((this->fptr)+x)->SetFieldData(Dummy.erase());
    }
    CurrentField.SetFieldData(Dummy.erase());
    PreviousField.SetFieldData(Dummy.erase());
}
