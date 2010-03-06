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
        CompleteState=true;
        VerticalFormRangeCheck=IN_FORM_RANGE;
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
                ValidateField();
            break;
            case TAB_KEY:
            case DOWN_KEY:
            case ENTER_KEY:
                CurrentField=SearchField(_NEXT);
                ConsoleObj.xyCoord(PreviousField.GetFieldX(),PreviousField.GetFieldY()-1);
                ValidateField();
            break;
            case F1_KEY:
                return F1_KEY;
            break;
            case F3_KEY:
                return F3_KEY;
            break;
        }
        UpdateField();
        if(VerticalFormRangeCheck==OUT_OF_FORM_RANGE)
        {
            read=true;
            VerticalFormRangeCheck=IN_FORM_RANGE;
        }
    }
    ValidateForm();
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
bool FormController::ValidateField()
{
    if(!ValidatorObj.CheckDataExistence(PreviousField.GetFieldData()))
    {
        return false;
    }
    else if(PreviousField.GetFieldName()=="Dept. Code")
    {
        if(ValidatorObj.CheckDepartmentExistence(PreviousField.GetFieldData()))
        {
            return false;
        }
    }
	return true;
}
bool FormController::ValidateForm()
{
    int x;
    Field TempField;
    for(x=0;x<this->FormSize;x++)
    {
        TempField=*(fptr+x);
        ConsoleObj.xyCoord(TempField.GetFieldX(),TempField.GetFieldY()-1);
        if(ValidatorObj.CheckDataExistence(PreviousField.GetFieldData())==_FAIL||
        ValidatorObj.CheckDepartmentExistence(PreviousField.GetFieldData())==_FAIL)
        {
            CompleteState=false;
            return false;
        }
    }
    CompleteState=true;
    return true;
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
        ValidateField();
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
