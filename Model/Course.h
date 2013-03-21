#ifndef COURSE_H
#define COURSE_H
using namespace std;
#include <string>


class Course{
public:
	//VARIABLES---------------------
	//------------------------------
	//FUNCTIONS---------------------

	Course(string="Unknown", int=-1, string="Unknown", string="No one", string="N/A");
	~Course();

	int 	getYear(void);
	string 	getTerm(void);
	string	getSupervisor(void);
	string	getTitle(void);
	string   getFinal(void);

	void 	setYear(int);
	void 	setTerm(string);
	void	setSupervisor(string);
	void	setTitle(string);
	void    setFinal(string);
	//-------------------------------

private:
	//VARIABLES----------------------
	string	title;
	string	supervisor;
	string	term;
	int	year;
	string  final;
	//string courseCode;
	
	//-------------------------------
};

#endif
