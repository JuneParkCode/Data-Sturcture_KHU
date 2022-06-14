#include "Student.h"
#include <cstring>


void Print(ostream& out, Student stu[], int numelement)
{
	for(int i=0; i<numelement; i++)
	{
		stu[i].Print(out);
	}
}
void Student::Print(ostream& out)
{
	out << id << "\t" << name << "\t" << gpa << endl;
}
void Student::InitValue(int _id, char* _name, float _gpa)
{
	id = _id;
	strlcpy(name, _name, sizeof(name));
	gpa = _gpa;
}
void Student::getValue(int& _id, char* _name, float& _gpa)
{
	_id = id;
	strlcpy(_name, name, sizeof(_name));
	_gpa = gpa;	
}
char* Student::getName()
{
	return name;
}
void Student::operator = (Student stu)
{
	id = stu.id;
	strlcpy(name, stu.name, sizeof(name));
	gpa = stu.gpa;
}

bool Student::operator < (const Student &stu)
{
	return (strcmp(this->name, stu.name) < 0);
}

bool Student::operator > (const Student &stu)
{
	return (strcmp(this->name, stu.name) > 0);
}

bool Student::operator <= (const Student &stu)
{
	return (strcmp(this->name, stu.name) <= 0);
}

bool Student::operator >= (const Student &stu)
{
	return (strcmp(this->name, stu.name) >= 0);
}

bool operator < (const Student &lhs, const Student &rhs)
{
	return (strcmp(lhs.name, rhs.name) < 0);
}

bool operator > (const Student &lhs, const Student &rhs)
{
	return (strcmp(lhs.name, rhs.name) > 0);
}

bool operator <= (const Student &lhs, const Student &rhs)
{
	return (strcmp(lhs.name, rhs.name) <= 0);
}

bool operator >= (const Student &lhs, const Student &rhs)
{
	return (strcmp(lhs.name, rhs.name) >= 0);
}

void PrintByPointer(ostream& out, Student* values[], int numValues)
{
	for(int i=0; i<numValues; i++)
	{
		(*values[i]).Print(out);
	}
}
