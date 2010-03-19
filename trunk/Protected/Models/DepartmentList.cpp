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
    //set Head of list to null by default
    Head=NULL;
}
DepartmentList::~DepartmentList()
{
    //Free memory allocations from the heap when department list is destroyed
    this->DestroyList();
}
void DepartmentList::AddDepartment(Department NewDepartment)
{
    //dynamically allocate memory on the heap for linklist
    Department *TempDepartment = new Department;

    //store data of NewDepartment to area pointed to by TempDepartment
    *TempDepartment = NewDepartment;

    if(TempDepartment!=NULL)
    {
        if(Head==NULL)
        {
            //set Head to TempDepartment since Head is NULL
            Head=TempDepartment;
        }
        else
        {
            Department *CacheDepartment=Head;
            while(CacheDepartment->getNext()!=NULL)
            {
                //retrieve the next node
                CacheDepartment=CacheDepartment->getNext();
            }
            //point to a new node in list
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
    //Create an instance of Console
    Console ConsoleObj;
    //Create an instance of Screen
    Screen ScreenObj;

    Department *CacheDepartment = Head;

    if(CacheDepartment!=NULL)
    {
        int x=5;
        int y=8;

        //headerText will be used to get the header row from file
        string headerText;

        //allocate memory dynamically from the Heap
        Department* department = Department::model();

        //open input file stream to "Department Rates.txt"
        ifstream iStreamObj(department->getFilename());

        if(iStreamObj.is_open())
        {
            //get header row from file "Department Rates.txt" and store it in the string headerText
            std::getline( iStreamObj, headerText );
            //close stream
            iStreamObj.close();
        }
        if(headerText.empty())
            headerText = department->getFileHeader();

        istringstream header(headerText);
        //will store colums headings
        string headers[4];
        string temp;
        int pos=0;
        while(pos < 4 )
        {
            //extract column heading from header by tab delimiting
            getline(header, temp, '\t');

            headers[pos] = temp;
            pos++;
        }
        //set cursor to positions x and y on the screen
        ConsoleObj.xyCoord(x,y);
        //display column headings
		
		headers[2] = headers[2] + " ($)";
		headers[3] = headers[3] + " ($)";
		
        cout << setw(10) << left << headers[0] << "  " <<
        setw(20) << left << headers[1] << "  " << setw(16) << left << headers[2] << "  " <<
        setw(17) << left << headers[3] << endl;
        //display under cloumn headings
        ConsoleObj.xyCoord(1,y+1);
        cout<<"--------------------------------------------------------------------------------";
        y+=4;

        while(CacheDepartment!=NULL)
        {
            //display records
            ConsoleObj.xyCoord(x,y);
            cout << setw(10) << left << CacheDepartment->getDeptCode() << "  " <<
            setw(20) << left << CacheDepartment->getDeptName() << "  " << setw(16)
            << right << CacheDepartment->getRegularRate() << "  " <<
            setw(17) << right <<fixed << setprecision (2) << CacheDepartment->getOvertimeRate() << endl;
            CacheDepartment=CacheDepartment->getNext();
            //increment position of record on screen
            y+=4;
        }
        //placed at the end of records display
        ConsoleObj.xyCoord(1,y-2);
        cout<<"--------------------------------------------------------------------------------";
        ConsoleObj.xyCoord(x,y+6);
    }else{
        ConsoleObj.xyCoord(20,15);
        ScreenObj.SetScreenTextColour(WhiteColour);
        //display when no records are present
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
