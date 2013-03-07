#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include <string>
#include "Student.h"

class GradStudent: public Student{
	public:
		GradStudent(int=-1, int=-1, string="unknown", string ="", string="", string="unknown", int=-1, string="10000000", string="Undeclared", string="MCS", string="Unknown");
		~GradStudent();
		string getSupervisor();
		string getProgram();
		string getArea();
		//either MCS or PhD 
	private:
		
		string stuArea;
		string stuProgram;
		string stuSupervisor;
};

#endif

