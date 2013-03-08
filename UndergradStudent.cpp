#include "UndergradStudent.h"

#include <string>
#include <iostream>
using namespace std;

UndergradStudent::UndergradStudent(int cgpa, int gpa, string f, string l, string e, string s, int year, string num)
			:CGPA(cgpa), majorGPA(gpa), yearStanding(year), major(s), Student(f, l, e, num,"undergrad")
{
	//UndergradStudent Constructor
}

int UndergradStudent::getCGPA(){
	return CGPA;
}

int UndergradStudent::getMajorGPA(){
	return majorGPA;
}

string UndergradStudent::getMajor(){
	return major;
}

int UndergradStudent::getYearStanding(){
	return yearStanding;
}