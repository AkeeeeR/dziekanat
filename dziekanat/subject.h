#pragma once
#ifndef subject_h
#define subject_h
#include "library.h"

struct studentNode		//Struktura drzewka przedmiotów i ocen.
{
	string teacher;
	string subject;
	float grade;
	string date;
	studentNode *left, *right;
};

void addSubject(studentNode* &root, const string& teacher, const string& subject, const float& grade, const string& date);
void printSubject(ofstream *file, studentNode* root);
void removeNode(studentNode* &root);

#endif
