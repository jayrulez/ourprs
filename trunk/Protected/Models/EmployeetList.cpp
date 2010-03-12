#include "./EmployeetList.h"

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


Employee* EmployeeList::getHead()
{
	return Head;
}

void EmployeeList::BuildListFromFile()
{
    int id;
    string firstname;
	string lastname;
	int deptCode;
	string position;
	float hoursWorked;
	
	ifstream iStreamObj(Employee::model()->getFilename());

    Employee EmployeeObj(0,"","",0,"",0,NULL);

	if(iStreamObj.is_open())
	{
		/*while(iStreamObj >> deptCode >> deptName >> regularRate >> overtimeRate)
		{
		    EmployeeObj.setDeptCode(deptCode);
		    EmployeeObj.setDeptName(deptName);
		    EmployeeObj.setRegularRate(regularRate);
		    EmployeeObj.setOvertimeRate(overtimeRate);
            this->AddEmployee(EmployeeObj);
        }*/
        iStreamObj.close();
	}
}