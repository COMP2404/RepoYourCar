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
//#include "CourseQueue.h"
//#include "JobQueue.h"
#include "Queue.h"
class UndergradApp : public Application{
public:
	//Constructors
	UndergradApp(UndergradStudent *, int , string , string );
	~UndergradApp();
	//UndergradApp(UndergradApp&);//default member wise assignment is sufficient

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
	bool 	 printApp(bool,bool,bool,bool);
	bool     printApp(bool);
	bool     saveSummary();
	bool 	 printModifiedApp(ofstream&);
	Application* getCopy();//return value from copy ctor
	string 	 getSummaryString();
	string   compareValue();
	//bool     compare(GradApp*);
	//bool     compare(UndergradApp*);

	Application& operator-();//unary '-' changes status of application to "closed"
    Application& operator+();//unary '+' changes status to "assigned"
    bool operator==(Application&);

	//New from UndergradApp's
	int      getStuCGPA();
	int      getStuMGPA();
	string   getStuMajor();
	int      getStuYrStanding();

	void 	 setRelatedCourses(Queue<Course>*); 
	bool	 rCourses;
	bool     rTA;
	bool	 rWorkExp;

private:
	string stuMajor;
	int    stuYearStanding;
	int    stuCGPA;
	int    stuMGPA;
};
#endif
