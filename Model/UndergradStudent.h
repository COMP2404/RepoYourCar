#ifndef UNDERGRADSTUDENT_H
#define UNDERGRADSTUDENT_H

#include <string>
#include "Student.h"

class UndergradStudent: public Student{
	public:
		UndergradStudent(int=-1, int=-1, string="unknown", string ="", string="", string="unknown", int=-1, string="10000000");
		~UndergradStudent();
		int    getCGPA(void);
		int    getMajorGPA(void);
		string getMajor(void);
		int    getYearStanding(void);
	private:
		
		int    CGPA;
		int    majorGPA;
		string major;
		int    yearStanding;
};

#endif