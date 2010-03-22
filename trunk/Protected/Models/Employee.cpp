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
#include <iomanip>

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
    cout<<"Hours Worked    : "<< fixed << setprecision (1) << this->hoursWorked;
    //creates and displays a frame around the employee data
    if(FrameObj.SetFrame(5,STANDARD_FRAME_WIDTH-5,y,y+14,NORMAL_FRAME))
    {
        FrameObj.sFraming();
    }
}
/*
 * Checks if a Employee with id == keyCode exists
 * @ param int keyCode
 * @ return bool
 */
bool Employee::recordExists(int keyCode)
{
	ifstream streamObj(this->getFilename()); //attempts to open "Employee Payroll Data.txt" for reading
	string line;
    //checks if stream to "Employee Payroll Data.txt" is open
	if(streamObj.is_open())
	{
	    //Primary contruct an employee object
		Employee employee(0,"","",0,"",0);
		//get header row from file
	    std::getline( streamObj, line );
	    //read employee records(line by line) from file
		while(streamObj >> employee.id >> employee.firstname >> employee.lastname >> employee.deptCode >> employee.position >> employee.hoursWorked)
		{
			if(employee.id == keyCode)
			{
			    //close stream when record if found
			    streamObj.close();
			    //found record
				return true;
			}
		}
		streamObj.close();
	}
	//when record is not found or file was not opended
	return false;
}
/*
 * Checks if a Employee with id == keyCode exists by ignoring a certain id
 * @ param int keyCode, int ignore
 * @ return bool
 */
bool Employee::recordExists(int keyCode, int ignore)
{
	ifstream streamObj(this->getFilename());//attempts to open "Employee Payroll Data.txt" for reading
	string line;
	//checks if stream to "Employee Payroll Data.txt" is open
	if(streamObj.is_open())
	{
	    //Primary contruct an employee object
		Employee employee(0,"","",0,"",0);
		//get header row from file
	    std::getline( streamObj, line );
	    //read employee records(line by line) from file
		while(streamObj >> employee.id >> employee.firstname >> employee.lastname >> employee.deptCode >> employee.position >> employee.hoursWorked)
		{
			if(employee.id != ignore)
			{
				if(employee.id == keyCode)
				{
				    //close stream when record if found
					streamObj.close();
					//found record
					return true;
				}
			}
		}
		streamObj.close();
	}
	//when record is not found or file was not opended
	return false;
}
/*
 * Searches "Employee Payroll Data.txt" by id
 * @ param int keyCode
 * @ return Employee*
 */
Employee* Employee::findById(int keyCode)
{
	ifstream streamObj(this->getFilename());//attempts to open "Employee Payroll Data.txt" for reading
	string line;
	//checks if stream to "Employee Payroll Data.txt" is open
	if(streamObj.is_open())
	{
	    //Primary contruct an employee object
		Employee employee(0,"","",0,"",0);
		//get header row from file
	    std::getline( streamObj, line );
	    //read employee records(line by line) from file
		while(streamObj >> employee.id >> employee.firstname >> employee.lastname >> employee.deptCode >> employee.position >> employee.hoursWorked)
		{
			if(employee.id == keyCode)
			{
			    //close stream when record if found
			    streamObj.close();
			    Employee * record = new Employee(employee.id, employee.firstname, employee.lastname, employee.deptCode, employee.position, employee.hoursWorked);
				//pointer to record found is returned
				return record;
			}
		}
		streamObj.close();
	}
	//return NULL when record is not found or file was not opened
	return NULL;
}
/*
 * Saves Employee record to file
 * @ param int keyCode
 * @ return void
 */
void Employee::save(Employee * listHead)
{
	ifstream iStreamObj(this->getFilename());//attempts to open "Employee Payroll Data.txt" for overwriting
	Employee * tempEmployee = listHead;

	ofstream oStreamObj(this->getFilename(), ios::trunc);
	if(oStreamObj.is_open())
	{
	    //writes column headings to file
		oStreamObj << this->getFileHeader();
		do
		{
		    //if not at the end of the list
			if(tempEmployee != NULL)
			{
			    //write record to file
				oStreamObj << tempEmployee->getId() << "\t" << tempEmployee->getFirstname() << "\t" << tempEmployee->getLastname() << "\t" << tempEmployee->getDeptCode() << "\t" << tempEmployee->getPosition() << "\t" << fixed << setprecision(1) << tempEmployee->getHoursWorked() << "\n";
				//traverse list to next node
				tempEmployee = tempEmployee->getNext();
			}
        //loop while not at th end of list
		}while(tempEmployee!=NULL);
        //close stream
		oStreamObj.close();
	}
	Employee * record = Employee::model()->findById(this->getId());
	if(record != NULL && (*this == *record))
	{
		this->setOperationState(OPERATIONSTATE_SUCCESS);//saved successfully
	}else{
		this->setOperationState(OPERATIONSTATE_FAILURE);//save failed
	}
}
/*
 * Save for updating an employee record
 * @ param Employee * listHead, Employee * oldEmployee
 * @ return void
 */
void Employee::save(Employee * listHead, Employee * oldEmployee)
{
	if(*this == *oldEmployee)
	{
		this->setOperationState(OPERATIONSTATE_DEFAULT);
	}else{
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
					oStreamObj << tempEmployee->getId() << "\t" << tempEmployee->getFirstname() << "\t" << tempEmployee->getLastname() << "\t" << tempEmployee->getDeptCode() << "\t" << tempEmployee->getPosition() << "\t" << fixed << setprecision(1) << tempEmployee->getHoursWorked() << "\n";
					tempEmployee = tempEmployee->getNext();
				}
			}while(tempEmployee!=NULL);
			oStreamObj.close();
		}
		Employee * record = Employee::model()->findById(this->getId());
		if(record != NULL && (*this == *record))
		{
			this->setOperationState(OPERATIONSTATE_SUCCESS);
		}else{
			this->setOperationState(OPERATIONSTATE_FAILURE);
		}
	}
}
/*
 * Deletes a record from file
 * @ param Employee* listHead
 * @ return void
 */
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
/*
 * Gets coloumn headings/header row from file
 * @ param Employee* listHead
 * @ return void
 */
string Employee::getFileHeaderFromFile()
{
	ifstream streamObj(this->getFilename());
	string line = NULL;
	if(streamObj.is_open())
	{
	    std::getline( streamObj, line );
		streamObj.close();
	}
	return line;
}
