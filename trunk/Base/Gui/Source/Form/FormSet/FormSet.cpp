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
#include "FormSet.h"
#include "../Input/TextInput.h"
FormSet::FormSet()
{
}
FormSet::~FormSet()
{
}
FormSet::FormSet(int FormCode,int FormSize)
{
    if(FormSize>0)
    {
        this->FormSize = FormSize;
        this->FormCode = FormCode;
    }
    else
        throw INVALID_FORMSET;
}
int FormSet::GetFormCode(Field *FieldObj)
{
    return this->FormCode;
}
int FormSet::GetFormSize(Field *FieldObj)
{
    return this->FormSize;
}
Field* FormSet::AddDepartmentForm()
{
    this->FormCode=DEPARTMENT_ADD_FORM_CODE;
    this->FormSize=4;
    static Field AddDepartmentFormField[4];
    AddDepartmentFormField[0].SetField("Dept. Code",5,10,1,STRICTNUMERICTYPE,NO_SPACING,4);
    AddDepartmentFormField[1].SetField("Dept. Name",5,13,2,ALPHABETICALTYPE,SPACING,50);
    AddDepartmentFormField[2].SetField("Regular Rate ($)",5,16,3,CURRENCYTYPE,NO_SPACING,20);
    AddDepartmentFormField[3].SetField("Overtime Rate ($)",5,19,4,CURRENCYTYPE,NO_SPACING,20);
    return AddDepartmentFormField;
}
Field* FormSet::SearchDepartmentForm()
{
    this->FormCode=DEPARTMENT_SEARCH_FORM_CODE;
    this->FormSize=1;
    static Field SearchDepartmentFormField[1];
    SearchDepartmentFormField[0].SetField("Dept. Code",20,19,1,STRICTNUMERICTYPE,NO_SPACING,4);
    return SearchDepartmentFormField;
}
Field* FormSet::UpdateDepartmentForm()
{
    this->FormCode=DEPARTMENT_UPDATE_FORM_CODE;
    this->FormSize=4;
    static Field UpdateDepartmentFormField[4];
    UpdateDepartmentFormField[0].SetField("Dept. Code",5,10,1,STRICTNUMERICTYPE,NO_SPACING,4);
    UpdateDepartmentFormField[1].SetField("Dept. Name",5,13,2,ALPHABETICALTYPE,SPACING,50);
    UpdateDepartmentFormField[2].SetField("Regular Rate ($)",5,16,3,CURRENCYTYPE,NO_SPACING,20);
    UpdateDepartmentFormField[3].SetField("Overtime Rate ($)",5,19,4,CURRENCYTYPE,NO_SPACING,20);
    return UpdateDepartmentFormField;
}
Field* FormSet::AddEmployeeForm()
{
    this->FormCode=2;
    this->FormSize=6;
    static Field AddEmployeeFormField[6];
    AddEmployeeFormField[0].SetField("ID. No",5,10,5,STRICTNUMERICTYPE,NO_SPACING,4);
    AddEmployeeFormField[1].SetField("First Name",5,13,6,ALPHABETICALTYPE,SPACING,50);
    AddEmployeeFormField[2].SetField("Last Name",5,16,7,ALPHABETICALTYPE,SPACING,50);
    AddEmployeeFormField[3].SetField("Dept. Code",5,19,1,STRICTNUMERICTYPE,NO_SPACING,4);
    AddEmployeeFormField[4].SetField("Position",5,22,8,ALPHANUMERICTYPE,SPACING,50);
    AddEmployeeFormField[5].SetField("Hours Worked",5,25,9,FREENUMERICTYPE,NO_SPACING,20);
    return AddEmployeeFormField;
}
Field* FormSet::SearchEmployeeForm()
{
    this->FormCode=1;
    this->FormSize=1;
    static Field SearchEmployeeFormField[1];
    SearchEmployeeFormField[0].SetField("ID. No",20,19,1,STRICTNUMERICTYPE,NO_SPACING,4);
    return SearchEmployeeFormField;
}
