#include "AdminManager.h"
AdminManager::AdminManager(WindowApp *theApp){
	adminPage = new AdminPage();
	window = new AdminWindow();
	window->theApp = theApp;
	adminPage->adminPage(window);
	
}
void AdminManager::viewSummaryClicked(GtkWidget *widget, AdminManager &manager){

	cout << "Clicked it" << endl;
	//gtk_widget_destroy(manager->admin_window);
}
