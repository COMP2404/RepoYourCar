#ifndef COURSE_H
#define COURSE_H
using namespace std;
#include <string>

class Course{
public:
	//VARIABLES---------------------
	//------------------------------
	//FUNCTIONS---------------------

	Course(string="Unknown", int=-1, int=-1, string="No one");
	~Course();

	int 	getYear(void);
	int 	getTerm(void);
	string	getSupervisor(void);
	string	getTitle(void);
	
	//-------------------------------

private:
	//VARIABLES----------------------
	string	title;
	string	supervisor;
	int	term;
	int	year;

	//string courseCode;
	
	//-------------------------------
};

#endif
