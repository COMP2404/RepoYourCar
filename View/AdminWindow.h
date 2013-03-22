#ifndef ADMIN_WINDOW
#define ADMIN_WINDOW
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
class WindowApp;
#include "AdminPage.h"
#include "SummaryChoiceWindow.h"
#include "WindowApp.h"
//
//#include <String.h>

using namespace std;
class Control;
class AdminPage;
class SummaryChoiceWindow;
class AdminWindow{
	public:
		friend class AdminPage;
		friend class AdminManager;
		bool allCourses;
		bool pending;
		bool appSelected;
		int selectedIndex;
		AppQueue *saveQueue;
		//AdminPage adminPage;
		

	private:
		GtkWidget *admin_window,*admin_combo, *admin_frame, *admin_cancel , *admin_viewSummary, *admin_assigned, *admin_login, 
			*summary_combo, *adminTest, *printSum;

		WindowApp *theApp;
		SummaryChoiceWindow *sum;
		//void viewSummaryClicked(GtkWidget* ,AdminManager &);
		void draw();
		void showSummary();
		static void showSummaryChoice(GtkWidget*,AdminWindow *);
		static void closeSummaryChoice(GtkWidget*,AdminWindow *);
		
		
};
#endif