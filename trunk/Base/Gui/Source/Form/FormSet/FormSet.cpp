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
#include <string>
#include <iostream>
using namespace std;
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
void FormSet::FlushFieldData(Field *FieldObj)
{
    string Dummy;
    for(int x=0;x<this->FormSize;x++)
    {
        (FieldObj+x)->SetFieldData(Dummy.erase());
    }
}
Field* FormSet::AddDepartmentForm()
{
    this->FormCode=DEPARTMENT_ADD_FORM_CODE;
    this->FormSize=4;
    static Field AddDepartmentFormField[4];
    AddDepartmentFormField[0].SetField("Dept. Code",5,10,1,STRICTNUMERICTYPE,NO_SPACING,4,false);
    AddDepartmentFormField[1].SetField("Dept. Name",5,13,2,ALPHABETICALTYPE,SPACING,50,false);
    AddDepartmentFormField[2].SetField("Regular Rate ($)",5,16,3,CURRENCYTYPE,NO_SPACING,20,false);
    AddDepartmentFormField[3].SetField("Overtime Rate ($)",5,19,4,CURRENCYTYPE,NO_SPACING,20,false);
    return AddDepartmentFormField;
}
Field* FormSet::SearchDepartmentForm()
{
    this->FormCode=DEPARTMENT_SEARCH_FORM_CODE;
    this->FormSize=1;
    static Field SearchDepartmentFormField[1];
    SearchDepartmentFormField[0].SetField("Dept. Code",20,21,1,STRICTNUMERICTYPE,NO_SPACING,4,false);
    return SearchDepartmentFormField;
}
Field* FormSet::UpdateDepartmentForm()
{
    this->FormCode=DEPARTMENT_UPDATE_FORM_CODE;
    this->FormSize=4;
    static Field UpdateDepartmentFormField[4];
    UpdateDepartmentFormField[0].SetField("Dept. Code",5,10,1,STRICTNUMERICTYPE,NO_SPACING,4,true);
    UpdateDepartmentFormField[1].SetField("Dept. Name",5,13,2,ALPHABETICALTYPE,SPACING,50,true);
    UpdateDepartmentFormField[2].SetField("Regular Rate ($)",5,16,3,CURRENCYTYPE,NO_SPACING,20,true);
    UpdateDepartmentFormField[3].SetField("Overtime Rate ($)",5,19,4,CURRENCYTYPE,NO_SPACING,20,true);
    return UpdateDepartmentFormField;
}
Field* FormSet::AddEmployeeForm()
{
    this->FormCode=EMPLOYEE_ADD_FORM_CODE;
    this->FormSize=6;
    static Field AddEmployeeFormField[6];
    AddEmployeeFormField[0].SetField("ID. No",5,10,5,STRICTNUMERICTYPE,NO_SPACING,4,false);
    AddEmployeeFormField[1].SetField("First Name",5,13,6,ALPHABETICALTYPE,SPACING,50,false);
    AddEmployeeFormField[2].SetField("Last Name",5,16,7,ALPHABETICALTYPE,SPACING,50,false);
    AddEmployeeFormField[3].SetField("Dept. Code",5,19,1,STRICTNUMERICTYPE,NO_SPACING,4,false);
    AddEmployeeFormField[4].SetField("Position",5,22,8,ALPHANUMERICTYPE,SPACING,50,false);
    AddEmployeeFormField[5].SetField("Hours Worked",5,25,9,FREENUMERICTYPE,NO_SPACING,20,false);
    return AddEmployeeFormField;
}
Field* FormSet::UpdateEmployeeForm()
{
    this->FormCode=EMPLOYEE_UPDATE_FORM_CODE;
    this->FormSize=6;
    static Field UpdateEmployeeFormField[6];
    UpdateEmployeeFormField[0].SetField("ID. No",5,10,5,STRICTNUMERICTYPE,NO_SPACING,4,true);
    UpdateEmployeeFormField[1].SetField("First Name",5,13,6,ALPHABETICALTYPE,SPACING,50,true);
    UpdateEmployeeFormField[2].SetField("Last Name",5,16,7,ALPHABETICALTYPE,SPACING,50,true);
    UpdateEmployeeFormField[3].SetField("Dept. Code",5,19,1,STRICTNUMERICTYPE,NO_SPACING,4,true);
    UpdateEmployeeFormField[4].SetField("Position",5,22,8,ALPHANUMERICTYPE,SPACING,50,true);
    UpdateEmployeeFormField[5].SetField("Hours Worked",5,25,9,FREENUMERICTYPE,NO_SPACING,20,true);
    return UpdateEmployeeFormField;
}
Field* FormSet::SearchEmployeeForm()
{
    this->FormCode=EMPLOYEE_SEARCH_FORM_CODE;
    this->FormSize=1;
    static Field SearchEmployeeFormField[1];
    SearchEmployeeFormField[0].SetField("ID. No",20,19,EMPLOYEE_SEARCH_FORM_CODE,STRICTNUMERICTYPE,NO_SPACING,4,false);
    return SearchEmployeeFormField;
}
Field* FormSet::SearchPayrollForm()
{
    this->FormCode=PAYROLL_SEARCH_FORM_CODE;
    this->FormSize=1;
    static Field SearchPayrollFormField[1];
    SearchPayrollFormField[0].SetField("ID. No",20,19,EMPLOYEE_SEARCH_FORM_CODE,STRICTNUMERICTYPE,NO_SPACING,4,false);
    return SearchPayrollFormField;
}
