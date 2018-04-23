#pragma once
#ifndef student_h
#define student_h
#include "subject.h"

struct student		//Struktura listy jednokierunkowej studentów.
{
	string name;
	string surname;
	int idNumber;
	studentNode *subjects;
	student *next;
}; 

void addOrUpdateStudent(student* &head, const string& name, const string& surname, const int& idNumber, const string& teacher, const string& subject, const float& grade, const string& date);
void saveList(student* head);
void removeStudent(student* &head);

#endif