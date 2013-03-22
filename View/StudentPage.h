#ifndef STUDENT_PAGE
#define STUDENT_PAGE
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "WindowApp.h"
#include "AppManager.h"
//
//#include <String.h>

using namespace std;
class Control;
class WindowApp;
class StudentPage{
	public:
		friend class WindowApp;
		

	private:
		GtkWidget *student_window, *student_frame, *submitFinish, *student_edit, *student_cancel, *student_apply, *btnStudent,*admin_window,*admin_combo, *admin_frame, *admin_cancel , *admin_viewSummary, *admin_login, *summary_combo;
		GtkWidget *grad_research, *grad_research_combo, *grad_sup, *grad_program_combo, *grad_apply, *lbl_grad_sup;
		GtkWidget *firstName, *lastName, *lblFirst, *lblLast, *appCombo, *btnFind;
		
		void draw();
		void close();
		void chooseApp(WindowApp *theApp);
		static void editApp(GtkWidget* , WindowApp* );
		static void updateCombo(GtkWidget*, WindowApp* );
		AppQueue *qCopy;
		string theFName, theLName;
		
};
#endif