#include "GradStudent.h"

#include <string>
#include <iostream>
using namespace std;

GradStudent::GradStudent(int cgpa, int gpa, string f, string l, string e, string s, int year, string num, string research, string prog, string super)
			:stuArea(research), stuProgram(prog), stuSupervisor(super), Student(f, l, e, num)
{
	//GradStudent Constructor
}

string GradStudent::getSupervisor(){
	return stuSupervisor;
}

string GradStudent::getProgram(){
	return stuProgram;
}

string GradStudent::getArea(){
	return stuArea;
}