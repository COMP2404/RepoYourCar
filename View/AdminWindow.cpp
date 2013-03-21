#include "AdminWindow.h"

void AdminWindow::draw(){
	admin_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(admin_window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(admin_window), 400, 200);
	gtk_window_set_title(GTK_WINDOW(admin_window), "Admin Window");

	admin_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(admin_window), admin_frame);

	admin_viewSummary = gtk_button_new_with_label("View Summary Of Pending Applications");
	gtk_widget_set_size_request(admin_viewSummary, 150, 35);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_viewSummary , 100, 50);

	admin_assigned = gtk_button_new_with_label("View Summary Of Assigned Applications");
	gtk_widget_set_size_request(admin_assigned, 150, 35);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_assigned , 100, 110);


	admin_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(admin_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_cancel , 50, 150);
	
	gtk_widget_show_all(admin_window);

}

void AdminWindow::showSummary(){

	gtk_widget_destroy(admin_frame);
	admin_frame = gtk_fixed_new();
	
	
	admin_combo =  gtk_combo_box_text_new();
	
	admin_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(admin_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_cancel , 100, 150);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_combo, 50, 50);
	summary_combo =  gtk_combo_box_text_new();
	gtk_fixed_put(GTK_FIXED(admin_frame), summary_combo, 50, 100);
	
	gtk_container_add(GTK_CONTAINER(admin_window), admin_frame);
	
	gtk_widget_show_all(admin_window);

	

	char text[800];
	string courses[800];



	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open file"<<endl;
		exit(1);
	}	
	while (!inFile.eof()) {
		inFile.getline(text, 800);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(admin_combo), text);
	}
}


void AdminWindow::showSummaryChoice(GtkWidget *widget, AdminWindow *window){
	window->sum = new SummaryChoiceWindow();
	//cout<<""<<endl;
	window->sum->draw();
	if(widget == window->admin_viewSummary){
		window->pending = true;
		cout << "Pending" << endl;
	}
	else{
		window->pending = false;
		cout << "Assigned" << endl;
	}
	g_signal_connect(window->sum->btnOneCourse, "clicked", G_CALLBACK (AdminWindow::closeSummaryChoice), window);
	g_signal_connect(window->sum->btnAllCourses, "clicked", G_CALLBACK   (AdminWindow::closeSummaryChoice), window);
	
}

void AdminWindow::closeSummaryChoice(GtkWidget *widget, AdminWindow *window){
	if(widget == window->sum->btnOneCourse)
		window->allCourses = false;
	else{
		window->allCourses = true;
		
	}
		
	gtk_widget_destroy(window->sum->summary_choice_window);
	AdminPage::viewSummary(widget,window);
}