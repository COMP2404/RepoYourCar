#include "SummaryChoiceWindow.h"

void SummaryChoiceWindow::draw(){
	
	summary_choice_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(summary_choice_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(summary_choice_window), 400, 200);
	//gtk_window_resize(GTK_WINDOW(window), 600,300);
	gtk_window_set_title(GTK_WINDOW(summary_choice_window), "Make a Choice!");
	
	summary_choice_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(summary_choice_window), summary_choice_frame);

	btnOneCourse = gtk_button_new_with_label("One Course");
	gtk_widget_set_size_request(btnOneCourse , 80, 35);
	gtk_fixed_put(GTK_FIXED(summary_choice_frame), btnOneCourse , 50, 100);	


	btnAllCourses = gtk_button_new_with_label("All Courses");
	gtk_widget_set_size_request(btnAllCourses , 80, 35);
	gtk_fixed_put(GTK_FIXED(summary_choice_frame), btnAllCourses , 150, 100);	
	
	const gchar* message;
	

	
	gtk_widget_show_all(summary_choice_window);
}