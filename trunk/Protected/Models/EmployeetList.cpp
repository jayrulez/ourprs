#include "./EmployeetList.h"
#include "../../config.h"
#include <fstream>
#include <sstream>
#include <iostream>

EmployeeList::EmployeeList()
{
    Head=NULL;
    //Head->setPrev(NULL);
}
EmployeeList::~EmployeeList()
{
    this->DestroyList();
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

    Employee EmployeeObj(0,"","",0,"",0);

	if(iStreamObj.is_open())
	{
		while(iStreamObj >> id >> firstname >> lastname >> deptCode >> position >> hoursWorked)
		{
		    EmployeeObj.setId(id);
		    EmployeeObj.setFirstname(firstname);
		    EmployeeObj.setLastname(lastname);
		    EmployeeObj.setDeptCode(deptCode);
		    EmployeeObj.setPosition(position);
		    EmployeeObj.setHoursWorked(hoursWorked);
            this->AddEmployee(EmployeeObj);
        }
        iStreamObj.close();
	}
}
void EmployeeList::DestroyList()
{
	Employee *CacheEmployee;
	while (Head != NULL)
	{
		CacheEmployee = this->Head;
		CacheEmployee = (this->Head)->getNext();
		delete CacheEmployee;
	}
}

void EmployeeList::DeleteNode(Employee * employee)
{
    // if list is not empty
    if(Head != NULL)
    {
        //
        Head->setPrev(NULL);
        // if record is found at the beginning of list
        if(employee->getId() == Head->getId())
        {
            // if has more than one item
            if(Head->getNext() != NULL)
                Head = Head->getNext();
            else
                Head = NULL;
        }else{
            Employee * temp = Head;
            while(temp != NULL)
            {
                // if not at the end of thelist
                if(temp->getNext()!=NULL)
                {
                    temp->getNext()->setPrev(temp);
                    // if item is between start and end of list
                    if(employee->getId() == temp->getId())
                    {
                        temp->getPrev()->setNext(temp->getNext());
                    }
                }else{
                    // If record is found at end of list
                    if(employee->getId() == temp->getId())
                    {
                        temp->getPrev()->setNext(NULL);
                    }
                }
                temp = temp->getNext();
            }
        }
    }
}

void EmployeeList::SortList(string sortBy = "id", int direction = SORT_DIRECTION_ASC)
{

}
