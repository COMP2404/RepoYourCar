#include <ncurses.h>
#include <iostream>
#include "Student.h"
#include "Application.h"
#include <cstdlib>
#include <fstream>
using namespace std;
#define debug
bool errorCheck(string*, string*, string*, string*, string*, string*, string*, string*);
bool submit(string*, string*, string*, int, int, string*, int, string*);
bool printApp(Application*);

int main(){
	/*
	*/
	#ifdef debug
	string s1, s2, s3, s4, s5, s6, s7, s8;
	s1="COMP 2404";
	s2="Zach";
	s3="Renaud";
	s4=10.33;
	s5=10;
	s6="yoyo@hotmail.com";
	s7="fe2";
	s8="Comnputer Science";
	errorCheck(&s1,&s2,&s3,&s4,&s5,&s6,&s7,&s8);
	#endif
	return 0;
}

bool errorCheck(string* course, string* first, string* last, string* mgpa, string* gpa, string* email, string* year, string* major){

	bool good = true;
	int mg;
	int cg;
	int yr;
	if(course->length() == 0)
		good = false;
	if(first->length() == 0)
                good = false;
	if(last->length() == 0)
                good = false;
	if(mgpa->length() == 0)
                good = false;
	if(gpa->length() == 0)
                good = false;
	if(email->length() == 0)
                good = false;	
	if(year->length() == 0)
                good = false;
	if(major->length() == 0)
                good = false;
	
	mg = atoi(mgpa->c_str());	
	cg = atoi(gpa->c_str());
	yr = atoi(year->c_str());	

	if(mg < 0 || mg > 12)
		good = false;
	if(cg < 0 || cg > 12)
		good = false;
	if(yr < 0 )
		good = false;

	bool ok = false;
	if(good) 
		ok = submit(course, first, last, mg, cg, email, yr, major);
	return ok;
}

bool submit(string* course, string* first, string* last, int mgpa, int gpa, string* email, int year, string* major){
	static int applicationNum = 1;

	Student* s = new Student(gpa, gpa, *first, *last, *email, *major, year);
	Application* a = new Application(s, applicationNum++, *course);
	
	if(!printApp(a))
		return false;
	return true;
}

bool printApp(Application* app){
	ofstream outFile("Application.txt", ios::out);

  	if (!outFile) {
   		//ios::out<<"Could not open file"<<endl;
   		return false;
	}

	outFile << "\t\tAPPLICANTION FORM:\n" << endl;
	outFile << "Applying for TA for class: " << app->getCourse() << " Application id: " << app->getApplicationNumber() << endl;
	outFile << "======================APPLICANT INFORMATION======================="<<endl;
	outFile << "Applicant name: " << app->getApplicant()->getFirst() << " " << app->getApplicant()->getLast() << endl;
	outFile << "Applicant email: " << app->getApplicant()->getEmail() << endl;
	outFile << "Applicant student number: " << app->getApplicant()->getStudentNumber() << endl;
	
	return true;
}



/*
*/
