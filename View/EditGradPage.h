#ifndef EDIT_GRAD
#define EDIT_GRAD
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "Form.h"
#include "AppPage.h"
class RelatedCoursesOneForm;
class RelatedCoursesTwoForm;
class WorkExperienceForm;
#include "RelatedCoursesOneForm.h"
#include "RelatedCoursesTwoForm.h"
#include "WorkExperienceForm.h"
#include "UnderGradForm.h"
#include "../Model/UGradAppData.h"
#include "../Model/UGradErrorCheck.h"
#include "UGradSubmitWindow.h"


//
//#include <String.h>

using namespace std;

class WindowApp;
class EditGradPage{
	public:
		friend class WindowApp;
		friend class AppManager;
		friend class UGradAppData;
		//friend class UnderGradForm;
		friend class RelatedCoursesTwoForm;
		friend class RelatedCoursesOneForm;
		friend class WorkExperienceForm;
		UnderGradAppPage();
	private:
		UnderGradForm *form;
		RelatedCoursesOneForm *relatedCourses1;
		RelatedCoursesTwoForm *relatedCourses2;
		//WorkExperienceForm *workExp;
		UGradAppData *formData;
		WindowApp *theApp;
		virtual void draw(WindowApp*);
		static void close(GtkWidget*,WindowApp*);
		static void related1(GtkWidget*,WindowApp*);
		static void related2(GtkWidget*,WindowApp*);
		static void getInfo(GtkWidget*,WindowApp*);
		static void workExp(WindowApp*);
		void errorCheck(WindowApp*);
		void submit(WindowApp*);
		//static void workExperience(GtkWidget*,UnderGradAppPage*);
		
		
};
#endif