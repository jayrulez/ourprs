#ifndef _EMPLOYEE_H
#include "./Employee.h"
#endif

Employee::Employee()
{
	this->next = NULL;
	this->setFilename("Employee Payroll Data.txt");
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
	this->setFilename("Employee Payroll Data.txt");
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
