#ifndef JOB_H
#define JOB_H
using namespace std;
#include <string>
//#define MAX_BUF 80

class Job{
public:
	//VARIABLES---------------------
	//------------------------------
	//FUNCTIONS---------------------

	Job(string="", string[]=NULL, string="", string="0/0/0", string="0/0/0", int=-1);
	~Job();

	string 	getJobTitle(void);
	string	getDuration(void);
	string	getStartDate(void);
	string	getEndDate(void);
	
	int getNumTasks(void);
	//-------------------------------

private:
	//VARIABLES----------------------
	string	jobTitle;
	string	tasks[];
	string	duration; // ie: "8 weeks",  "2 years"
	string	startDate;
	string	endDate;
	
	int r; //keeps track of how many tasks in the array

	//string courseCode;
	
	//-------------------------------
};

#endif
