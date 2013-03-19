#ifndef ADMINPAGE
#define ADMINPAGE
#include <gtk/gtk.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "AdminManager.h"
#include "AdminWindow.h"

using namespace std;
class Control;
class WindowApp;
class AdminManager;
class AdminPage{
	public:
		friend class AdminManager;
		void adminPage(AdminWindow*);

		
	private:
		static GtkWidget *admin_window,*admin_combo, *admin_frame, *admin_cancel , *admin_viewSummary, *admin_login, 
			*summary_combo, *adminTest;
		static void cleanup(GtkWidget *, AdminWindow *);
		AdminWindow *window;
		

};
#endif