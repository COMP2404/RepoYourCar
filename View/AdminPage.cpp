#include "AdminPage.h"

void AdminPage::adminPage(AdminWindow *window){
	//window = new AdminWindow();

	
	window->admin_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window->admin_window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window->admin_window), 400, 200);
	gtk_window_set_title(GTK_WINDOW(window->admin_window), "Admin Window");

	window->admin_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window->admin_window), window->admin_frame);

	window->admin_viewSummary = gtk_button_new_with_label("View Summary Of Pending Applications");
	gtk_widget_set_size_request(window->admin_viewSummary, 150, 35);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->admin_viewSummary , 100, 50);

	window->admin_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(window->admin_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->admin_cancel , 100, 150);
	
	gtk_widget_show_all(window->admin_window);


	/*
	if(theApp->appQueue.isEmpty()){
		gtk_widget_set_sensitive(admin_viewSummary, FALSE);
	}
	else{
		gtk_widget_set_sensitive(admin_viewSummary, TRUE);
	}





	/*
	
	
	
	
	

	

	
	*/
	//g_signal_connect(manager.admin_viewSummary, "clicked", G_CALLBACK (AdminManager::viewSummaryClicked), this);
	g_signal_connect(window->admin_cancel, "clicked", G_CALLBACK (AdminPage::cleanup), window);
	//g_signal_connect (manager.admin_window, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);
	//g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
}

void AdminPage::cleanup(GtkWidget *widget , AdminWindow *window){
	cout << "Clicked it" << endl;
	gtk_widget_destroy(window->admin_window);

}