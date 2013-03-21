#include "ErrorWindow.h"

void ErrorWindow::draw(string s){
	error_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(error_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(error_window), 400, 200);
	//gtk_window_resize(GTK_WINDOW(window), 600,300);
	gtk_window_set_title(GTK_WINDOW(error_window), "ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	
	error_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(error_window), error_frame);

	error_dismiss = gtk_button_new_with_label("Dismiss");
	gtk_widget_set_size_request(error_dismiss , 80, 35);
	gtk_fixed_put(GTK_FIXED(error_frame), error_dismiss , 100, 100);	
	const gchar* message;
	message = s.c_str();
	error_message = gtk_label_new(message);
	gtk_fixed_put(GTK_FIXED(error_frame), error_message, 10, 10); 


	gtk_widget_show_all(error_window);

	//g_signal_connect(error_dismiss, "clicked", G_CALLBACK (WindowApp::closePopWindow), theApp);
}

void ErrorWindow::close(){
	gtk_widget_destroy(error_window);
}