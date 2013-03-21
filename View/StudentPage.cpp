#include "StudentPage.h"

void StudentPage::draw(){
	student_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(student_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(student_window), 550, 200);
	
	gtk_window_set_title(GTK_WINDOW(student_window), "Student Window");
	
	student_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(student_window), student_frame);

	student_edit = gtk_button_new_with_label("Edit Application");
	gtk_widget_set_size_request(student_edit , 80, 35);
	gtk_fixed_put(GTK_FIXED(student_frame), student_edit  , 20, 50);

	student_apply = gtk_button_new_with_label("New Undergrad Application");
	gtk_widget_set_size_request(student_apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(student_frame), student_apply , 150, 50);

	grad_apply = gtk_button_new_with_label("New Graduate Application");
	gtk_widget_set_size_request(grad_apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(student_frame), grad_apply , 350, 50);

	student_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(student_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(student_frame), student_cancel , 60, 150);
	
	gtk_widget_show_all(student_window);

	//g_signal_connect(student_apply, "clicked", G_CALLBACK (WindowApp::makeApplication), theApp);
	//g_signal_connect(grad_apply, "clicked", G_CALLBACK (WindowApp::makeGradApplication), theApp);
	//g_signal_connect(student_cancel, "clicked", G_CALLBACK (WindowApp::closeStudentPage), theApp);
}

void StudentPage::close(){
	gtk_widget_destroy(student_window);
}