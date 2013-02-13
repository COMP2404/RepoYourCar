#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
#include <string>
#define MAX_BUF 16
class Student{
public:
	//VARIABLES---------------------
	string TACourses[MAX_BUF];
	//------------------------------
	//FUNCTIONS---------------------
	Student(int=-1, int=-1, string="unknown", string ="", string="", string="unknown", int=-1, string="10000000");//Constructor
	~Student();//Destructor

	string getStudentNumber(void);	
	int    getCGPA(void);
	int    getMajorGPA(void);
	string getFirst(void);
	string getLast(void);
	string getEmail(void);
	string getMajor(void);
	int    getYearStanding(void);
	//-------------------------------

private:
	//VARIABLES----------------------
	int    CGPA;
	int    majorGPA;
	string first;
	string last;
	string email;
	string major;
	int    yearStanding;
	string stuNumber;
	
	//-------------------------------
};

#endif
