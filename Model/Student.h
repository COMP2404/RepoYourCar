#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
#include <string>
#define MAX_BUF 200
class Student{
public:
	//VARIABLES---------------------
	string TACourses[MAX_BUF];
	//------------------------------
	//FUNCTIONS---------------------
	Student(string ="", string="", string="unknown", string="10000000", string="student");//Constructor
	~Student();//Destructor

	string getStudentNumber(void);	
	//int    getCGPA(void);
	//int    getMajorGPA(void);
	string getFirst(void);
	string getLast(void);
	string getEmail(void);
	//string getMajor(void);
	//string getSupervisor(void);
	//string getProgram(void);
	//string getArea(void);
	//int    getYearStanding(void);
	//-------------------------------

private:
	//VARIABLES----------------------
	//int    CGPA;
	//int    majorGPA;
	string first;
	string last;
	string email;
	//string major;
	//int    yearStanding;
	string stuNumber;
	//string stuProgram;
	//string stuArea;
	//string stuSuper;
	
	//-------------------------------
};

#endif
