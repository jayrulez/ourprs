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
#define DEPARTMENT_ADD_FORM_CODE 2001
#define DEPARTMENT_SEARCH_FORM_CODE 2002
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
    Field* AddEmployeeForm();
    Field* SearchEmployeeForm();

};
#endif
