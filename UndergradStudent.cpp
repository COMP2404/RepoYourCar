#include "UndergradStudent.h"

#include <string>
#include <iostream>
using namespace std;

UndergradStudent::UndergradStudent(int cgpa, int gpa, string f, string l, string e, string s, int year, string num, string research, string prog, string super)
			:CGPA(cgpa), majorGPA(gpa), yearStanding(year), Student(cgpa, gpa, f, l, e, s, year, num)
{
	//UndergradStudent Constructor
}
