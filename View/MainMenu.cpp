#include "MainMenu.h"

void MainMenu::draw(){
	/////////////////////////////////////////////////////
	//-----------Create the window ------------------////
	/////////////////////////////////////////////////////
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//loadApplications(theApp);
	//cout << "app loaded" << endl;
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
	
	gtk_window_set_title(GTK_WINDOW(window), "Main Menu");
	
	

	


	/////////////////////////////////////////////////////
	//-----------Add frame onto window---------------////
	/////////////////////////////////////////////////////
	appFrame = gtk_fixed_new();
	//admin_frame = gtk_fixed_new();

	gtk_container_add(GTK_CONTAINER(window), appFrame);


	/////////////////////////////////////////////////////
	//Make the application button and add to frame---////
	/////////////////////////////////////////////////////

	btnStudent = gtk_button_new_with_label("Student");
	gtk_widget_set_size_request(btnStudent, 80, 35);
	gtk_fixed_put(GTK_FIXED(appFrame), btnStudent, 50, 20);	

	apply = gtk_button_new_with_label("Apply");
	gtk_widget_set_size_request(apply, 80, 35);


	/////////////////////////////////////////////////////
	//------Make the login button and add to frame---////
	/////////////////////////////////////////////////////
	login = gtk_button_new_with_label("Admin");
	gtk_widget_set_size_request(login, 80, 35);
	gtk_fixed_put(GTK_FIXED(appFrame), login, 50, 80);


	
	
	/////////////////////////////////////////////////////
	//------Make the Prompt Label and add to frame---////
	/////////////////////////////////////////////////////
	label = gtk_label_new("Choose a Menu Option");
	gtk_fixed_put(GTK_FIXED(appFrame), label, 150, 58); 



	/////////////////////////////////////////////////////
	//----------Show all the widgets on the window---////
	/////////////////////////////////////////////////////
	//moveOn = false;
	//extra = false;
	gtk_widget_show_all(window);
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);


	/////////////////////////////////////////////////////
	//Connect signals with each button as well as close////
	/////////////////////////////////////////////////////
	//g_signal_connect(window, "destroy", G_CALLBACK (Control::cancel), theApp);

	//g_signal_connect(btnStudent, "clicked", G_CALLBACK(WindowApp::studentPage), theApp);

	
	//g_signal_connect(login, "clicked", G_CALLBACK(WindowApp::adminPage), theApp);

}