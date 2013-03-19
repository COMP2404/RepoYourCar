#include "AdminManager.h"
AdminManager::AdminManager(){
	adminPage = new AdminPage();
	window = new AdminWindow();
	adminPage->adminPage(window);
	
}
void AdminManager::viewSummaryClicked(GtkWidget *widget, AdminManager &manager){

	cout << "Clicked it" << endl;
	//gtk_widget_destroy(manager->admin_window);
}
