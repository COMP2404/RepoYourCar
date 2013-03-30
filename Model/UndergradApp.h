#ifndef UNDERGRADAPP_H
#define UNDERGRADAPP_H

#include "Application.h"
#include <string>
#include <iostream>
#include <fstream>

//#include "AppQueue.h"
#define APP_MAX_BUF 1000

#define INCLUDED
using namespace std;
#include "CourseQueue.h"
#include "JobQueue.h"

class UndergradApp : public Application{
public:
	//Constructors
	UndergradApp(UndergradStudent *, int , string , string );
	virtual ~UndergradApp();

	//From base Application
	int      getApplicationNumber();
	string   getAppStatus();
	string   getStuFirst();
	string   getStuLast();
	string   getCourse();
	string   getStatus();
	string   getStuEmail();
	string   getStuID();
	string   getStuType();
	bool 	 printApp(bool);
	bool     saveSummary();
	bool 	 printModifiedApp(ofstream&);
	Application& operator-();//unary '-' changes status of application to "closed"
    	Application& operator+();//unary '+' changes status to "assigned"
    	bool operator==(Application&);

	//New from UndergradApp's
	int      getStuCGPA();
	int      getStuMGPA();
	string   getStuMajor();
	int      getStuYrStanding();

	void 	 setRelatedCourses(CourseQueue*); // ??


private:
	string stuMajor;
	int    stuYearStanding;
	int    stuCGPA;
	int    stuMGPA;
};
#endif
