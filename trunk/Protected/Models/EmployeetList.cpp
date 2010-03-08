#include "Employee.h"
#include "EmployeeList.h"

EmployeeList::EmployeeList()
{
    Head=NULL;
}
EmployeeList::~EmployeeList()
{
}
void EmployeeList::AddEmployee(Employee NewEmployee)
{
    Employee *TempEmployee = new Employee;
    *TempEmployee = NewEmployee;
    if(TempEmployee!=NULL)
    {
        if(Head==NULL)
        {
            Head=TempEmployee;
        }
        else
        {
            Employee *CacheEmployee=Head;
            while(CacheEmployee->getNext()!=NULL)
            {
                CacheEmployee=CacheEmployee->getNext();
            }
            CacheEmployee->setNext(TempEmployee);
        }
    }
    else
        throw 1;
}
Employee* EmployeeList::GetEmployee(Employee Emp)
{
    return &Emp;
}
void EmployeeList::ShowEmployeeList()
{
    Employee *CacheEmployee = Head;
    while(CacheEmployee!=NULL)
    {
        //CacheEmployee->ShowEmployee();
        CacheEmployee=CacheEmployee->getNext();
    }
}
