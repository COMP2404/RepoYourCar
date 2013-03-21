#ifndef FORM
#define FORM
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
//#include "WindowApp.h"



using namespace std;
class WindowApp;
class Form;
class Form{
	public:
		friend class RelatedCoursesOneForm;
		friend class RelatedCoursesTwoForm;
		//friend class WorkExperienceForm;
		friend class GradAppPage;
		friend class UnderGradAppPage;
		
		bool null();
		virtual string getTheType()=0;
		
	protected:
		
		GtkWidget *grad_research, *grad_research_combo, *grad_sup, *grad_program_combo, *grad_apply, *lbl_grad_sup,
			*label, *info_label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, 
			*major, *lblMajor, *gpa, *lblGpa, *cgpa, *lblCgpa, *stuNum,*lblstuNum, *email, *lblEmail, *year, *lblYear, 
			*submit, *cancel, *combo,  *ei_relatedCourse1, *ei_relatedCourse2, *ei_term1, *ei_term2, *ei_year1, 
			*ei_year2, *ei_finalGrade, *ei_supervisor, *ei_relevantWork, *ei_responsabilities, *ei_duration, 
			*ei_startDate, *ei_endDate, *ei_continue, *ei_continue2, *ei_repeat, *ei_repeat2, *ei_repeat3, *ei_finish, 
			*ei_lblRelatedCourse, *ei_lblTerm, *ei_lblYear, *ei_lblFinalGrade, *ei_lblSupervisor, *ei_lblRelevantWork, 
			*ei_lblDuration, *ei_lblStartDate, *ei_lblEndDate, *ei_lblResponsabilities,
			*lblpickCourse, *lblpickArea, *lblpickProgram;
		virtual void draw();
		
		
};
#endif