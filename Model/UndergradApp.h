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
	UndergradApp(UndergradStudent *, int , string , string );
	int      getStuCGPA();
	int      getStuMGPA();
	string   getStuMajor();
	int      getStuYrStanding();
	void 	 setRelatedCourses(CourseQueue*);
	bool 	 printApp();
	string   getStuName();
	bool     saveSummary();
	string   getStuLast();


private:
	string stuMajor;
	int    stuYearStanding;
	int    stuCGPA;
	int    stuMGPA;
};
#endif