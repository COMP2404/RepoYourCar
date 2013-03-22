#ifndef GRAD_APP_PAGE
#define GRAD_APP_PAGE
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "Form.h"
#include "AppPage.h"
//#include "RelatedCoursesOneForm.h"
class RelatedCoursesTwoForm;
#include "RelatedCoursesTwoForm.h"
#include "WorkExperienceForm.h"
#include "GradForm.h"
#include "../Model/GradAppData.h"
#include "../Model/GradErrorCheck.h"
#include "GradSubmitWindow.h"
#include "../Model/Application.h"
#include "../Model/JobQueue.h"
#include "../Model/CourseQueue.h"
#include "../Model/Job.h"
#include "../Model/Course.h"

using namespace std;

class WindowApp;

class GradAppPage : public AppPage{
	public:
		friend class WindowApp;
		friend class AppManager;
		friend class GradAppData;
		//friend class GradForm;
		friend class RelatedCoursesTwoForm;
		
		friend class WorkExperienceForm; 
		GradAppPage();
		bool edit;
	private:
		//GtkWidget *grad_research, *grad_research_combo, *grad_sup, *grad_program_combo, *grad_apply, *lbl_grad_sup;
		//GtkWidget *label, *info_label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *cgpa, *lblCgpa, *stuNum,*lblstuNum, *email, *lblEmail, *year, *lblYear, *submit, *cancel, *combo,  *ei_relatedCourse1, *ei_relatedCourse2, *ei_term1, *ei_term2, *ei_year1, *ei_year2, *ei_finalGrade, *ei_supervisor, *ei_relevantWork, *ei_responsabilities, *ei_duration, *ei_startDate, *ei_endDate, *ei_continue, *ei_continue2, *ei_repeat, *ei_repeat2, *ei_repeat3, *ei_finish, *ei_lblRelatedCourse, *ei_lblTerm, *ei_lblYear, *ei_lblFinalGrade, *ei_lblSupervisor, *ei_lblRelevantWork, *ei_lblDuration, *ei_lblStartDate, *ei_lblEndDate, *ei_lblResponsabilities
		//	,*lblpickCourse, *lblpickArea, *lblpickProgram;
		GradForm *form;
		RelatedCoursesTwoForm *relatedCourses2;
		//WorkExperienceForm *workExp;
		GradAppData *formData;
		WindowApp *theApp;
		JobQueue *workExpQueue;
		CourseQueue *relatedQueue;
		virtual void draw(WindowApp*);
		static void close(GtkWidget*,WindowApp*);
		static void related2(GtkWidget*,WindowApp*);
		static void workExp(WindowApp*);
		static void getInfo(GtkWidget*,WindowApp*);
		void errorCheck(WindowApp*);
		void submit(WindowApp*);
		static void fillInData(Application*, WindowApp*);
		static void fillInRelated(WindowApp*);
		static void fillInWorkExp(WindowApp*);
		static void editNextJob(WindowApp*);
		
		
		
};
#endif