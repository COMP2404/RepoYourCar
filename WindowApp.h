#ifndef WINDOWAPP_H
#define WINDOWAPP_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "Student.h"
#include "Application.h"
#include "Course.h"
#include "AppQueue.h"
//
//#include <String.h>

using namespace std;
class Control;
class WindowApp{
	public:
		friend class Control;
		//Control Control;
		GtkWidget *label, *info_label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *cgpa, *lblCgpa, *stuNum,*lblstuNum, *email, *lblEmail, *year, *lblYear, *submit, *cancel, *combo,  *ei_relatedCourse1, *ei_relatedCourse2, *ei_term1, *ei_term2, *ei_year1, *ei_year2, *ei_finalGrade, *ei_supervisor, *ei_relevantWork, *ei_responsabilities, *ei_duration, *ei_startDate, *ei_endDate, *ei_continue, *ei_continue2, *ei_repeat, *ei_repeat2, *ei_repeat3, *ei_finish, *ei_lblRelatedCourse, *ei_lblTerm, *ei_lblYear, *ei_lblFinalGrade, *ei_lblSupervisor, *ei_lblRelevantWork, *ei_lblDuration, *ei_lblStartDate, *ei_lblEndDate, *ei_lblResponsabilities;

		GtkWidget *submitWindow, *submitFrame, *submitRepeat, *error_window, *error_frame, *error_dismiss, *error_message;
		
		GtkWidget *student_window, *student_frame, *submitFinish, *student_edit, *student_cancel, *student_apply, *btnStudent,*admin_window,*admin_combo, *admin_frame, *admin_cancel , *admin_viewSummary, *admin_login, *summary_combo;
		
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
	protected:
		static void adminPage(GtkWidget*, WindowApp*);
		static void viewSummary(GtkWidget*, WindowApp*);
		static void mainMenu(GtkWidget*, WindowApp*);
		static void popWindow(string, WindowApp*);
		static void closePopWindow(GtkWidget*, WindowApp*);
		static void closeAdminPage(GtkWidget*, WindowApp*);
		static void closeStudentPage(GtkWidget*, WindowApp*);
		static void studentPage(GtkWidget*, WindowApp*);
		static int makeApplication(GtkWidget*, WindowApp*);	
		static void updateCombo(GtkWidget*, WindowApp*);

		static void workExperience(GtkWidget *, WindowApp *);
		static void relatedCourses1(GtkWidget *, WindowApp *);
		static void relatedCourses2(GtkWidget *, WindowApp *);
		
		static void finishExtra(GtkWidget*,WindowApp*);
				
};

#endif
