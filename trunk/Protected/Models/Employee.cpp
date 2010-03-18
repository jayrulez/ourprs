#ifndef _EMPLOYEE_H
#include "./Employee.h"
#endif
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Tools/Frame.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Employee::Employee()
{
	this->next = NULL;
	this->prev = NULL;
	this->head = NULL;
	this->setFilename(EMPLOYEE_PAYROLL_DATA_FILE);
	this->setFileHeader("ID. No.\tFirst Name\tLast Name\tDept. Code\tPosition\tHours Worked\n");
}

Employee::~Employee()
{
}

Employee::Employee(int id = 0, string firstname = "", string lastname = "", int deptCode = 0, string position = "", float hoursWorked = 0)
{
	this->id = id;
	this->firstname = firstname;
	this->lastname = lastname;
	this->deptCode = deptCode;
	this->position = position;
	this->hoursWorked = hoursWorked;
	this->next = NULL;
	this->prev = NULL;
	this->head = NULL;
	this->setFilename(EMPLOYEE_PAYROLL_DATA_FILE);
	this->setFileHeader("ID. No.\tFirst Name\tLast Name\tDept. Code\tPosition\tHours Worked\n");
}

Employee* Employee::model()
{
    static Employee * instance = NULL;
    if(instance == NULL)
        instance = new Employee(0,"","",0,"",0);
    return instance;
}

Employee* Employee::getNext()
{
	return this->next;
}

void Employee::setNext(Employee * next = NULL)
{
	this->next = next;
}

int Employee::getId()
{
	return this->id;
}

string Employee::getFirstname()
{
	return this->firstname;
}

string Employee::getLastname()
{
	return this->lastname;
}

int Employee::getDeptCode()
{
	return this->deptCode;
}

string Employee::getPosition()
{
	return this->position;
}

float Employee::getHoursWorked()
{
	return this->hoursWorked;
}

void Employee::setId(int id)
{
	this->id = id;
}

void Employee::setFirstname(string firstname)
{
	this->firstname = firstname;
}

void Employee::setLastname(string lastname)
{
	this->lastname = lastname;
}

void Employee::setDeptCode(int deptCode)
{
	this->deptCode = deptCode;
}

void Employee::setPosition(string position)
{
	this->position = position;
}

void Employee::setHoursWorked(float hoursWorked)
{
	this->hoursWorked = hoursWorked;
}
void Employee::show(int y)
{
    Console ConsoleObj;
	Frame FrameObj;
    ConsoleObj.xyCoord(10,y+2);
    cout<<"Employee Id     : "<<this->id;
    ConsoleObj.xyCoord(10,y+4);
    cout<<"First Name      : "<<this->firstname;
    ConsoleObj.xyCoord(10,y+6);
    cout<<"Last Name       : "<<this->lastname;
    ConsoleObj.xyCoord(10,y+8);
    cout<<"Department Code : "<<this->deptCode;
    ConsoleObj.xyCoord(10,y+10);
    cout<<"Position        : "<<this->position;
    ConsoleObj.xyCoord(10,y+12);
    cout<<"Hours Worked    : "<<this->hoursWorked;
    if(FrameObj.SetFrame(5,STANDARD_FRAME_WIDTH-5,y,y+14,NORMAL_FRAME))
    {
        FrameObj.sFraming();
    }
}
void Employee::write()
{

}

void Employee::read()
{

}

bool Employee::recordExists(int keyCode)
{
	ifstream streamObj(this->getFilename());
	string line;
	if(streamObj.is_open())
	{
		Employee employee(0,"","",0,"",0);
	    std::getline( streamObj, line );
		while(streamObj >> employee.id >> employee.firstname >> employee.lastname >> employee.deptCode >> employee.position >> employee.hoursWorked)
		{
			if(employee.id == keyCode)
			{
			    streamObj.close();
				return true;
			}
		}
		streamObj.close();
	}
	return false;
}

bool Employee::recordExists(int keyCode, int ignore)
{
	ifstream streamObj(this->getFilename());
	string line;
	if(streamObj.is_open())
	{
		Employee employee(0,"","",0,"",0);
	    std::getline( streamObj, line );
		while(streamObj >> employee.id >> employee.firstname >> employee.lastname >> employee.deptCode >> employee.position >> employee.hoursWorked)
		{
			if(employee.id != ignore)
			{
				if(employee.id == keyCode)
				{
					streamObj.close();
					return true;
				}
			}
		}
		streamObj.close();
	}
	return false;
}

Employee* Employee::findById(int keyCode)
{
	ifstream streamObj(this->getFilename());
	string line;
	if(streamObj.is_open())
	{
		Employee employee(0,"","",0,"",0);
	    std::getline( streamObj, line );
		while(streamObj >> employee.id >> employee.firstname >> employee.lastname >> employee.deptCode >> employee.position >> employee.hoursWorked)
		{
			if(employee.id == keyCode)
			{
			    streamObj.close();
			    Employee * record = new Employee(employee.id, employee.firstname, employee.lastname, employee.deptCode, employee.position, employee.hoursWorked);
				return record;
			}
		}
		streamObj.close();
	}
	return NULL;
}

void Employee::save(Employee * listHead)
{
	ifstream iStreamObj(this->getFilename());
	Employee * tempEmployee = listHead;

    ofstream oStreamObj(this->getFilename(), ios::trunc);
    if(oStreamObj.is_open())
    {
        oStreamObj << this->getFileHeader();
        do
        {
            if(tempEmployee != NULL)
            {
				cout << tempEmployee->getId();system("pause");
                oStreamObj << tempEmployee->getId() << "\t" << tempEmployee->getFirstname() << "\t" << tempEmployee->getLastname() << "\t" << tempEmployee->getDeptCode() << "\t" << tempEmployee->getPosition() << "\t" << tempEmployee->getHoursWorked() << "\n";
                tempEmployee = tempEmployee->getNext();
            }
        }while(tempEmployee!=NULL);
        oStreamObj.close();
    }
    if(Employee::model()->recordExists(this->getId()))
    {
        this->setOperationState(OPERATIONSTATE_SUCCESS);
    }else{
        this->setOperationState(OPERATIONSTATE_FAILURE);
	}
}


void Employee::deleteRecord(Employee* listHead)
{
	ifstream iStreamObj(this->getFilename());
	Employee * tempEmployee = listHead;

    ofstream oStreamObj(this->getFilename(), ios::trunc);
    if(oStreamObj.is_open())
    {
        oStreamObj << this->getFileHeader();
        do
        {
            if(tempEmployee != NULL)
            {
                oStreamObj << tempEmployee->getId() << "\t" << tempEmployee->getFirstname() << "\t" << tempEmployee->getLastname() << "\t" << tempEmployee->getDeptCode() << "\t" << tempEmployee->getPosition() << "\t" << tempEmployee->getHoursWorked() << "\n";
                tempEmployee = tempEmployee->getNext();
            }
        }while(tempEmployee!=NULL);
        oStreamObj.close();
    }
    if(!Employee::model()->recordExists(this->id))
    {
        this->setOperationState(OPERATIONSTATE_SUCCESS);
    }else{
        this->setOperationState(OPERATIONSTATE_FAILURE);
	}
}

void Employee::setPrev(Employee* employee)
{
    this->prev = employee;
}

Employee* Employee::getPrev()
{
    return this->prev;
}

Employee* Employee::getHead()
{
    return this->head;
}
