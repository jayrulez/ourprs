#ifndef FORMSET_H
#define FORMSET_H
#include "../Field.h"
#define INVALID_FORMSET 0x8001

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
    Field* AddEmployeeForm();

};
#endif
