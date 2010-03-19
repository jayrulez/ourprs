#include "Department.h"
#include "DepartmentList.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Screen/Screen.h"
#include "../../Base/Gui/Source/Tools/Colour.h"
#include <sstream>
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
    Screen ScreenObj;
    Department *CacheDepartment = Head;
    if(CacheDepartment!=NULL)
    {
        int x=5;
        int y=8;

        string headerText;
        Department* department = Department::model();
        ifstream iStreamObj(department->getFilename());
        if(iStreamObj.is_open())
        {
            std::getline( iStreamObj, headerText );
            iStreamObj.close();
        }
        if(headerText.empty())
            headerText = department->getFileHeader();

        istringstream header(headerText);
        string headers[4];
        string temp;
        int pos=0;
        while(pos < 4 )
        {
            getline(header, temp, '\t');
            headers[pos] = temp;
            pos++;
        }

        ConsoleObj.xyCoord(x,y);
        cout << setw(10) << left << headers[0] << "  " <<
        setw(20) << left << headers[1] << "  " << setw(15) << left << headers[2] << "($)" << "  " <<
        setw(15) << left << headers[3] << "($)" << endl;

        y+=2;

        while(CacheDepartment!=NULL)
        {

            ConsoleObj.xyCoord(x,y);
            cout << setw(10) << left << CacheDepartment->getDeptCode() << "  " <<
            setw(20) << left << CacheDepartment->getDeptName() << "  " << setw(15)
            << left << CacheDepartment->getRegularRate() << "  " <<
            setw(15) << left <<fixed << setprecision (2) << CacheDepartment->getOvertimeRate() << endl;
            CacheDepartment=CacheDepartment->getNext();
            y+=2;
        }
        ConsoleObj.xyCoord(x,y+6);
    }else{
        ConsoleObj.xyCoord(20,15);
        ScreenObj.SetScreenTextColour(WhiteColour);
        cout << "No Department(s) information is available" << endl;
        ScreenObj.SetScreenTextColour(DefaultTextColour);
    }
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
            Department * hNext = Head->getNext();
            Head = newNode;
            if(hNext!=NULL)
            {
                Head->setNext(hNext);
                Head->getNext()->setPrev(Head);
                Head->setPrev(NULL);
            }else{
                Head->setNext(NULL);
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
