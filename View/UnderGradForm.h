#ifndef UNDERGRAD_FORM
#define UNDERGRAD_FORM
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "Form.h"

//
//#include <String.h>

using namespace std;
class Control;
class WindowApp;
class GradAppPage;
class UnderGradAppPage;

class UnderGradForm : public Form{
	public:
		friend class WindowApp;
		friend class GradAppPage;
		friend class UnderGradAppPage;
		friend class AppManager;
		friend class RelatedCoursesTwoForm;
		friend class RelatedCoursesOneForm;
		friend class WorkExperienceForm;
		
	private:
		virtual string getTheType();
		GtkWidget *grad_research, *grad_research_combo, *grad_sup, *grad_program_combo, *grad_apply, *lbl_grad_sup;
		GtkWidget *label, *info_label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *cgpa, *lblCgpa, *stuNum,*lblstuNum, *email, *lblEmail, *year, *lblYear, *submit, *cancel, *combo,  *ei_relatedCourse1, *ei_relatedCourse2, *ei_term1, *ei_term2, *ei_year1, *ei_year2, *ei_finalGrade, *ei_supervisor, *ei_relevantWork, *ei_responsabilities, *ei_duration, *ei_startDate, *ei_endDate, *ei_continue, *ei_continue2, *ei_repeat, *ei_repeat2, *ei_repeat3, *ei_finish, *ei_lblRelatedCourse, *ei_lblTerm, *ei_lblYear, *ei_lblFinalGrade, *ei_lblSupervisor, *ei_lblRelevantWork, *ei_lblDuration, *ei_lblStartDate, *ei_lblEndDate, *ei_lblResponsabilities
			,*lblpickCourse, *lblpickArea, *lblpickProgram;

		virtual void draw();
		
		
};
#endif