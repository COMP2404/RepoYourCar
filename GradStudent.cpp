#include "GradStudent.h"

#include <string>
#include <iostream>
using namespace std;

GradStudent::GradStudent(int cgpa, int gpa, string f, string l, string e, string s, int year, string num, string research, string prog, string super)
			:researchArea(research), program(prog), supervisor(super), Student(cgpa, gpa, f, l, e, s, year, num)
{
	//GradStudent Constructor
}
