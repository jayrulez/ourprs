#ifndef _EMPLOYEE_H
#include "./Employee.h"
#endif
#include <fstream>

Employee::Employee()
{
	this->next = NULL;
	this->setFilename(EMPLOYEE_PAYROLL_DATA_FILE);
}

Employee::~Employee()
{
}

Employee::Employee(int id = 0, string firstname = "", string lastname = "", int deptCode = 0, string position = "", float hoursWorked = 0, Employee * next = NULL)
{
	this->id = id;
	this->firstname = firstname;
	this->lastname = lastname;
	this->deptCode = deptCode;
	this->position = position;
	this->hoursWorked = hoursWorked;
	this->next = next;
	this->setFilename(EMPLOYEE_PAYROLL_DATA_FILE);
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
		Employee employee(0,"","",0,"",0,NULL);
	    //std::getline( streamObj, line );
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
		Employee employee(0,"","",0,"",0,NULL);
	    //std::getline( streamObj, line );
		while(streamObj >> employee.id >> employee.firstname >> employee.lastname >> employee.deptCode >> employee.position >> employee.hoursWorked)
		{
			if(employee.id == ignore)
			{
				break;
			}
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

Employee* Employee::findById(int keyCode)
{
	ifstream streamObj(this->getFilename());
	string line;
	if(streamObj.is_open())
	{
		Employee employee(0,"","",0,"",0,NULL);
	    //std::getline( streamObj, line );
		while(streamObj >> employee.id >> employee.firstname >> employee.lastname >> employee.deptCode >> employee.position >> employee.hoursWorked)
		{
			if(employee.id == keyCode)
			{
			    streamObj.close();
			    Employee * record = new Employee(employee.id, employee.firstname, employee.lastname, employee.deptCode, employee.position, employee.hoursWorked, NULL);
				return record;
			}
		}
		streamObj.close();
	}
	return NULL;
}

void Employee::save()
{
	ofstream streamObj(this->getFilename(),ios::app);
	if(streamObj.is_open())
	{
		if(streamObj << this->id << "\t" << this->firstname << "\t" << this->lastname << "\t" << this->deptCode << "\t" << this->position << "\t" << this->hoursWorked << "\n")
			this->setOperationState(OPERATIONSTATE_SUCCESS);
		else
			this->setOperationState(OPERATIONSTATE_FAILURE);
		streamObj.close();
	}
}
