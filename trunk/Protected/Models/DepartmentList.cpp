#include "Department.h"
#include "DepartmentList.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
using namespace std;

DepartmentList::DepartmentList()
{
    Head=NULL;
}
DepartmentList::~DepartmentList()
{
    this->DestroyList();
}
void DepartmentList::AddDepartment(Department NewDepartment)
{
    Department *TempDepartment = new Department;
    *TempDepartment = NewDepartment;
    if(TempDepartment!=NULL)
    {
        if(Head==NULL)
        {
            Head=TempDepartment;
        }
        else
        {
            Department *CacheDepartment=Head;
            while(CacheDepartment->getNext()!=NULL)
            {
                CacheDepartment=CacheDepartment->getNext();
            }
            CacheDepartment->setNext(TempDepartment);
        }
    }
}
Department* DepartmentList::GetDepartment(Department Dept)
{
    return &Dept;
}
void DepartmentList::ShowDepartmentList()
{
    Console ConsoleObj;
    Department *CacheDepartment = Head;

    int count=0;
    int x=5;
    int y=8;
    Department* department = Department::model();
    //department->setColumnHeaders();
    while(CacheDepartment!=NULL)
    {

        ConsoleObj.xyCoord(x,y);
        cout << setw(3) << ++count<<". "<< setw(4) << CacheDepartment->getDeptCode() << "\t" <<
        setw(30) << CacheDepartment->getDeptName() << "\t" << setw(10) << CacheDepartment->getRegularRate() << "\t" <<
        setw(10) << CacheDepartment->getOvertimeRate() << endl;
        CacheDepartment=CacheDepartment->getNext();
        y+=2;
    }
    ConsoleObj.xyCoord(x,y+6);
}

Department* DepartmentList::getHead()
{
	return Head;
}

void DepartmentList::BuildListFromFile()
{
    int deptCode;
    string deptName;
    float regularRate;
    float overtimeRate;
    string line;
	ifstream iStreamObj(Department::model()->getFilename());

    Department DepartmentObj(0,"",0,0);

	if(iStreamObj.is_open())
	{
	    std::getline( iStreamObj, line );
		while(iStreamObj >> deptCode >> deptName >> regularRate >> overtimeRate)
		{
		    DepartmentObj.setDeptCode(deptCode);
		    DepartmentObj.setDeptName(deptName);
		    DepartmentObj.setRegularRate(regularRate);
		    DepartmentObj.setOvertimeRate(overtimeRate);
            this->AddDepartment(DepartmentObj);
        }
        iStreamObj.close();
	}
}
void DepartmentList::DestroyList()
{
	Department *CacheDepartment;
	while (Head != NULL)
	{
		CacheDepartment = this->Head;
		CacheDepartment = (this->Head)->getNext();
		delete CacheDepartment;
	}
}

void DepartmentList::UpdateNode(Department* oldNode, Department* newNode)
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
            Department * hNext;
            hNext = Head->getNext();
            if(hNext!=NULL)
            {
                Head = newNode;
                Head->setNext(hNext);
                Head->getNext()->setPrev(NULL);
                Head->setPrev(NULL);
            }
        }else{
            Department * temp = Head;
            while(temp != NULL)
            {
                // if not at the end of thelist
                if(temp->getNext()!=NULL)
                {
                    temp->getNext()->setPrev(temp);
                    // if item is between start and end of list
                    if(*oldNode == *temp)
                    {
                        Department * tNext = temp->getNext();
                        Department * tPrev = temp->getPrev();
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
