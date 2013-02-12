#ifndef APPLICATION_H
#define APPLICATION_H

#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Queue.h"
#define APP_MAX_BUF 32

#define INCLUDED
using namespace std;

class Application{
public:
	//VARIABLES---------------------	
	//------------------------------
	//FUNCTIONS---------------------
	
//Student* getApplicant(void);
	int      getApplicationNumber(void);
	string   getCourse(void);
	string   getStatus();

	int      getStuCGPA();
	int      getStuMGPA();
	string   getStuFirst();
	string   getStuLast();
	string   getStuEmail();
	string   getStuMajor();
	int      getStuYrStanding();
	string   getStuID();
	
	bool printApp();
	Application(Student*, int, string="unknown", string="pending");
	~Application();
	//------------------------------

private:
	//VARIABLES---------------------
//Student *applicant;
	int     applicationNumber;
	string  course;
	Queue	relatedCourses;
	Queue	relatedTAPositions;
	Queue	relatedWorkEXP;
	string  applicationStatus;
	//Student members:
	int    stuCGPA;
	int    stuMGPA;
	string stuFirst;
	string stuLast;
	string stuEmail;
	string stuMajor;
	int    stuYearStanding;
	string stuID;
	//------------------------------
};


#endif
