#include "Job.h"
#include "Course.h"
#include "Student.h"
#include "UndergradStudent.h"
#include "GradStudent.h"
#include "CourseQueue.h"
#include "JobQueue.h"
#include "GradApp.h"
#include "UndergradApp.h"
#include "Application.h"
#include "AppQueue.h"

#include <string>
#include <iostream>
using namespace std;
int main(){
	//=========================================TEMPLATES FOR OBJECT PARAMETERS===============================================
	//GradStudent(string first, string last, string email, string studentnum, string research, string program, string supervisor)
	//GradApp(GradStudent *gs, int appNum, string course, string status)

	//UndergradStudent(int cgpa, int gpa, string fisrt, string last, string email, string major, int year, string studentnum)
	//UndergradApp(UndergradStudent *ugs, int appNum, string course, string appstatus)
	//=======================================================================================================================

	/////////////////////STUDENTS/////////////////////////
	GradStudent bill("Bill", "OReily", "baba@carleton.ca", "100928374", "Physics", "super-Jim");
	UndergradStudent george(10, 11, "George", "Lamp", "lamp@carleton.ca", "InteriorLighting", 2, "100998877" );
	////////////////////APPLICATIONS//////////////////////
	GradApp billApp(&bill, 10231, "COMP2401", "pending");
	UndergradApp georgeApp(&george, 20394, "Comp2404", "pending");
	return 0;
}