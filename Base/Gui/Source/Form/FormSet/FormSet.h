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
#ifndef FORMSET_H
#define FORMSET_H
#include "../Field.h"
#define INVALID_FORMSET 0x8001
#define DEPARTMENT_ADD_FORM_CODE 2010
#define DEPARTMENT_UPDATE_FORM_CODE 2220
#define DEPARTMENT_SEARCH_FORM_CODE 2030

#define EMPLOYEE_ADD_FORM_CODE 3010
#define EMPLOYEE_UPDATE_FORM_CODE 3010

#define EMPLOYEE_SEARCH_FORM_CODE 5000
class FormSet
{
private:
    int FormCode;
    int FormSize;
    Field FieldObj;
public:
    FormSet();
    ~FormSet();
    FormSet(int,int);
    int GetFormCode(Field*);
    int GetFormSize(Field*);
    Field* AddDepartmentForm();
    Field* SearchDepartmentForm();
    Field* UpdateDepartmentForm();
    Field* AddEmployeeForm();
    Field* UpdateEmployeeForm();
    Field* SearchEmployeeForm();

};
#endif
