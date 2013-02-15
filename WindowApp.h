#ifndef WINDOWAPP_H
#define WINDOWAPP_H
#include <iostream>
#include <gtk/gtk.h>
#include "Student.h"
#include "Application.h"
#include "Course.h"
#include "AppQueue.h"
//#include <String.h>

using namespace std;
class WindowApp{
	public:
		GtkWidget *label, *window, *frame, *apply, *login, *appFrame, *admin_frame ,*fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *cgpa, *lblCgpa, *stuNum,*lblstuNum, *email, *lblEmail, *year, *lblYear, *submit, *cancel, *combo, *admin_combo, *ei_relatedCourse1, *ei_relatedCourse2, *ei_term1, *ei_term2, *ei_year1, *ei_year2, *ei_finalGrade, *ei_supervisor, *ei_relevantWork, *ei_responsabilities, *ei_duration, *ei_startDate, *ei_endDate, *ei_continue, *ei_continue2, *ei_repeat, *ei_repeat2, *ei_repeat3, *ei_finish, *ei_lblRelatedCourse, *ei_lblTerm, *ei_lblYear, *ei_lblFinalGrade, *ei_lblSupervisor, *ei_lblRelevantWork, *ei_lblDuration, *ei_lblStartDate, *ei_lblEndDate, *ei_lblResponsabilities, *admin_cancel;

		GtkWidget *submitWindow, *submitFrame, *submitRepeat, *submitFinish, *admin_login, *admin_viewSummary, *student_edit, *btnStudent, *error_window, *error_frame, *error_dismiss, *error_message;
		
		Application *studentApp;
		Course *studentCourse;
		CourseQueue *cQRelated, *cQTa;
		JobQueue *jQRelated;
		AppQueue appQueue;
		

		bool moveOn;
		bool checkGood;
		bool extra;
		int page;
		
		/*WindowApp();
		~WindowApp();*/
		void setfName(string);
		void setlName(string);
		void setMajor(string);
		void setGpa(string);
		void setEmail(string);
		void setYear(string);
		void setCgpa(string);
		void setStuNum(string);

		string getfName();
		string getlName();
		string getMajor();
		string getGpa();
		string getEmail();
		string getYear();
		string getStuNum();
		string getCgpa();
	private:
		string strfName, strlName, strMajor, strGpa, strCgpa, strEmail, strYear, strStuNum;
		
		
				
};

#endif
