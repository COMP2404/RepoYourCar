#ifndef APP_PAGE
#define APP_PAGE
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
//#include "RelatedCoursesTwoForm.h"
//#include "WorkExperienceForm.h"
//
//#include <String.h>

using namespace std;
//class AppPage;
//class RelatedCoursesOneForm;
//class RelatedCoursesTwoForm;
//class WorkExperienceForm;


class AppPage{
	public:
		friend class RelatedCoursesOneForm;
		friend class RelatedCoursesTwoForm;
		friend class WorkExperienceForm;
		//AppPage();
	protected:
		
		Form *form;
		//RelatedCoursesOneForm *relatedCourses1;
		//RelatedCoursesTwoForm *relatedCourses2;
		//WorkExperienceForm *workExp;
		virtual void draw(AppPage*);
		//static void close(GtkWidget*,AppPage*);
		
		
		
		
};
#endif