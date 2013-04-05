#ifndef APPLICATION_H
#define APPLICATION_H

#include "Course.h"
#include "Job.h"
#include "Student.h"
#include "GradStudent.h"
#include "UndergradStudent.h"
#include <string>
#include <iostream>
#include <fstream>

//#include "AppQueue.h"
#define APP_MAX_BUF 1000

#define INCLUDED
using namespace std;
//#include "Queue.h"
//#include "JobQueue.h"
//class Queue<Course>;
//class Queue<Job>;
template<typename T>//FORWARD DECLERATION
class Queue;//---------------------------

class Application{

	friend   ostream& operator<<(ostream&, Application&);
public:
	//VARIABLES---------------------	
	//------------------------------
	//FUNCTIONS---------------------
	
	
	int      getApplicationNumber(void);
	string   getCourse(void);
	string   getStatus();
	string	 getStuName();
	string   getStuFirst();
	string   getStuLast();
	string   getStuEmail();
	string 	 getType();
	
	string   getStuID();
	
	void	 setRelatedTAPositions(Queue<Course>*);
	void	 setRelatedWorkEXP(Queue<Job>*);
	//bool 	 saveSummary();

	//virtual string getStuName();
	virtual bool printApp(bool) = 0;
	virtual bool printModifiedApp(ofstream&) = 0;
	virtual Application* getCopy() = 0; //returns value from copy constructor
	virtual string 	 getSummaryString() = 0;//returns the string for the summary output
	virtual string   compareValue() = 0;//returns the comparison value so all can be compared
	//virtual bool compare(GradApp*) = 0;//returns true based on sorting specifications of the app
	//virtual bool compare(UndergradApp*) = 0;
	Application(int, string="unknown", string="pending", string="grad");
	~Application();
	//Application(Application&);//COPY CONSTRUCTOR!
	Queue<Course>	*relatedCourses;
	Queue<Course>	*relatedTAPositions;
	Queue<Job>	*relatedWorkEXP;
	//------------------------------

	Application& operator-();//unary '-' changes status of application to "closed"
    Application& operator+();//unary '+' changes status to "assigned"
    bool 		 operator==(Application&);

protected:
	//VARIABLES---------------------

	int     applicationNumber;
	string  course;
	
	
	string  applicationStatus;
	
	string stuFirst;
	string stuLast;
	string stuEmail;
	
	string stuID;
	string stuType;
	
	//------------------------------
};


#endif

