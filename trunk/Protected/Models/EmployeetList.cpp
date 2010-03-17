#include "./EmployeetList.h"
#include "../../config.h"
#include <fstream>
#include <sstream>
#include <iostream>

EmployeeList::EmployeeList()
{
    Head = NULL;
    ListSize = 0;
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


Employee* EmployeeList::GetHead()
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

    unsigned int listSize = 0;

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
            listSize++;
        }
        this->SetListSize(listSize);
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

void EmployeeList::UpdateNode(Employee* oldNode, Employee* newNode)
{
    // if list is not empty
    if(Head != NULL)
    {
        //
        Head->setPrev(NULL);
        // if record is found at the beginning of list
        if(*oldNode == *Head)
        {
            // if has more than one item
            Employee * hNext;
            hNext = Head->getNext();
            if(hNext!=NULL)
            {
                Head = newNode;
                Head->setNext(hNext);
                Head->getNext()->setPrev(NULL);
                Head->setPrev(NULL);
            }
        }else{
            Employee * temp = Head;
            while(temp != NULL)
            {
                // if not at the end of thelist
                if(temp->getNext()!=NULL)
                {
                    temp->getNext()->setPrev(temp);
                    // if item is between start and end of list
                    if(*oldNode == *temp)
                    {
                        Employee * tNext = temp->getNext();
                        Employee * tPrev = temp->getPrev();
                        newNode->setNext(tNext);
                        newNode->setPrev(tPrev);
                        newNode->getNext()->setPrev(newNode);
                        temp->getPrev()->setNext(newNode);
                    }
                }else{
                    // If record is found at end of list
                    if(*oldNode == *temp)
                    {
                        newNode->setPrev(temp->getPrev());
                        temp->getPrev()->setNext(newNode);
                    }
                }
                temp = temp->getNext();
            }
        }
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

unsigned int EmployeeList::GetListSize()
{
    return this->ListSize;
}

void EmployeeList::SetListSize(unsigned int size)
{
    this->ListSize = size;
}

void EmployeeList::SortList(string sortBy = "id")
{
	Employee * a = NULL;
	Employee * b = NULL;
	Employee * c = NULL;
	Employee * e = NULL;
	Employee * temp = NULL;
	while(e != Head->getNext())
	{
		c = a = Head;
		b = a->getNext();
		while(a != e)
		{
			if(this->CompareG(a,b,sortBy))
			{
				if(*a == *Head)
				{
					temp = b->getNext();
					b->setNext(a);
					a->setNext(temp);
					Head = b;
					c = b;
				}else{
					temp = b->getNext();
					b->setNext(a);
					a->setNext(temp);
					c->setNext(b);
					c = b;
				}
			}else{
				c = a;
				a = a->getNext();
			}
			b = a->getNext();
			if(b==e)
			{
				e = a;
			}
		}
	}
}

bool EmployeeList::CompareG(Employee* node1, Employee* node2, string compareBy)
{
	if(compareBy == "id")
	{
		return node1->getId() > node2->getId();
	}
	if(compareBy == "firstname")
	{
		return node1->getFirstname() > node2->getFirstname();
	}
	if(compareBy == "lastname")
	{
		return node1->getLastname() > node2->getLastname();
	}
	if(compareBy == "deptCode")
	{
		return node1->getDeptCode() > node2->getDeptCode();
	}
	if(compareBy == "position")
	{
		return node1->getPosition() > node2->getPosition();
	}
	if(compareBy == "hoursWorked")
	{
		return node1->getHoursWorked() > node2->getHoursWorked();
	}
	return false;
}
