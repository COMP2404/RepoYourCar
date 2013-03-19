#ifndef ADMIN_MANAGER
#define ADMIN_MANAGER
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "AdminPage.h"
#include "AdminWindow.h"
//
//#include <String.h>

using namespace std;
class Control;
class AdminPage;
class AdminManager{
	public:
		friend class AdminPage;

		//AdminPage adminPage;
		AdminManager();

	private:
		static void viewSummaryClicked(GtkWidget* ,AdminManager &);
		AdminPage *adminPage;
		AdminWindow *window;
		
};
#endif