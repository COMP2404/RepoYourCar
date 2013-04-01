#ifndef UNDERGRAD_APP_PAGE
#define UNDERGRAD_APP_PAGE
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
#include "../Model/Application.h"


//
//#include <String.h>

using namespace std;

class WindowApp;
class UnderGradAppPage : public AppPage{
	public:
		friend class WindowApp;
		friend class AppManager;
		friend class UGradAppData;
		friend class UGradSubmitWindow;
		
		friend class RelatedCoursesTwoForm;
		friend class RelatedCoursesOneForm;
		friend class WorkExperienceForm;
		UnderGradAppPage();
		bool edit;
		bool experience;
	private:
		UnderGradForm *form;
		RelatedCoursesOneForm *relatedCourses1;
		RelatedCoursesTwoForm *relatedCourses2;
		//WorkExperienceForm *workExp;
		UGradAppData *formData;
		WindowApp *theApp;
		Queue<Job> *workExpQueue;
		Queue<Course> *relatedTA;
		Queue<Course> *relatedCourse;

		virtual void draw(WindowApp*);
		static void close(GtkWidget*,WindowApp*);
		static void related1(GtkWidget*,WindowApp*);
		static void related2(GtkWidget*,WindowApp*);
		static void getInfo(GtkWidget*,WindowApp*);
		static void workExp(WindowApp*);
		void errorCheck(WindowApp*);
		void submit(WindowApp*);
		static void fillInData(Application*,WindowApp*);
		static void fillInRelated(WindowApp*);
		static void fillInTA(WindowApp*);
		static void fillInWorkExp(WindowApp*);

		static void editNextCourse(WindowApp*);
		static void editNextRelated(WindowApp*);
		static void editNextJob(WindowApp*);
		//static void workExperience(GtkWidget*,UnderGradAppPage*);
		
		
};
#endif