#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include <string>
#include "Student.h"

class GradStudent: public Student{
	public:
		GradStudent(int=-1, int=-1, string="unknown", string ="", string="", string="unknown", int=-1, string="10000000", string="Undeclared", string="MCS", string="Unknown");
		~GradStudent();
		
	private:
		string researchArea;
		string program;//either MCS or PhD 
		string supervisor;
};

#endif

