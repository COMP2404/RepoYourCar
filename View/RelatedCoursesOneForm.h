#ifndef RELATED_COURSES_ONE
#define RELATED_COURSES_ONE
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
class UnderGradAppPage;
class UnderGradForm;
#include <gtk/gtk.h>

#include "UnderGradAppPage.h"

#include "UnderGradForm.h"
#include "../Model/Course.h"


using namespace std;


class RelatedCoursesOneForm{
	public:
		
		//friend class GradForm;
		friend class UnderGradAppPage;
		
		
		
	private:
		GtkWidget *label, *info_label, *window, *frame, *apply, *login, *appFrame, *fName, *lblfName, *lName, *lbllName, *major, *lblMajor, *gpa, *lblGpa, *cgpa, *lblCgpa, *stuNum,*lblstuNum, *email, *lblEmail, *year, *lblYear, *submit, *cancel, *combo,  *ei_relatedCourse1, *ei_relatedCourse2, *ei_term1, *ei_term2, *ei_year1, *ei_year2, *ei_finalGrade, *ei_supervisor, *ei_relevantWork, *ei_responsabilities, *ei_duration, *ei_startDate, *ei_endDate, *ei_continue, *ei_continue2, *ei_repeat, *ei_repeat2, *ei_repeat3, *ei_finish, *ei_lblRelatedCourse, *ei_lblTerm, *ei_lblYear, *ei_lblFinalGrade, *ei_lblSupervisor, *ei_lblRelevantWork, *ei_lblDuration, *ei_lblStartDate, *ei_lblEndDate, *ei_lblResponsabilities
			,*lblpickCourse, *lblpickArea, *lblpickProgram;
		GtkWidget *error_window, *error_frame, *error_dismiss, *error_message;
		void create(WindowApp*);
		static bool errorCheck(WindowApp*);
		static void addAnother(GtkWidget*,WindowApp*);
		static void nextPage(GtkWidget*,WindowApp*);
		static void cleanup(WindowApp*);
		static void popWindow(string);
		static void closePopWindow(GtkWidget *, GtkWidget *);
		static void close(GtkWidget *, WindowApp*);
		//static void close(GtkWidget*,Form*);
		static void viewNextPage(GtkWidget*,WindowApp*);
		static void viewPrevPage(GtkWidget*,WindowApp*);
		static void viewNextSection(GtkWidget*,WindowApp*);
		static void viewPrevSection(GtkWidget*,WindowApp*);
		
		
};
#endif