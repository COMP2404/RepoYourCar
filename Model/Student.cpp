#include "Student.h"
#include <string>
#include <iostream>

Student::Student(string f, string l, string e, string num,string type){
		//CGPA = cgpa;
      //  majorGPA = gpa;
        first = f;
        last = l;
        email = e;
      //  major = s;
      //  yearStanding = year;
        stuNumber = num;
	
}
//GETTERS===================================================
string Student::getStudentNumber(){ return stuNumber; }
string Student::getFirst(){ return first; }
string Student::getLast(){ return last; }
string Student::getEmail(){ return email; }
//string Student::getMajor(){ return major; }
//string Student::getSupervisor(){return supervisor;}
//string Student::getProgram(){ return program;}
//string Student::getArea(){return area;}
//int Student::getYearStanding(){ return yearStanding; }
//int Student::getMajorGPA(){ return majorGPA; }
//int Student::getCGPA(){ return CGPA; }


//==========================================================

//DESTRUCTOR:
Student::~Student(){
}
