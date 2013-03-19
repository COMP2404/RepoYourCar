#ifndef ADMIN_WINDOW
#define ADMIN_WINDOW
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "AdminPage.h"
//
//#include <String.h>

using namespace std;
class Control;
class AdminPage;
class AdminWindow{
	public:
		friend class AdminPage;

		//AdminPage adminPage;
		

	private:
		GtkWidget *admin_window,*admin_combo, *admin_frame, *admin_cancel , *admin_viewSummary, *admin_login, 
			*summary_combo, *adminTest;
		//void viewSummaryClicked(GtkWidget* ,AdminManager &);
		
		
};
#endif