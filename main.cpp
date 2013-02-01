#include "main.h"
//`pkg-config gtkmm-3.0 --cflags --libs`

using namespace std;
char buf[5];


void getInfo(WindowApp *theApp){
	//const gchar * s1 = gtk_entry_get_text(GTK_ENTRY(theApp->lName));
	//theApp->setfName("Hello");
	//const gchar *s2 = (theApp->getfName()).c_str();
	
	//gtk_entry_set_text(GTK_ENTRY(theApp->lName), s2);

	const gchar *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8;
	
	double c, g;
	int num;
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->fName));
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->lName));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->major));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->gpa));
	s5 = s4;        
        s6 = gtk_entry_get_text(GTK_ENTRY(theApp->email));
        s7 = gtk_entry_get_text(GTK_ENTRY(theApp->year));
	string string1(s1);
	string string2(s2);
	string string3(s3);
	string string4(s4);
	//string string5(s5);
	string string6(s6);
	string string7(s7);
	string string8(s8);
	
	//s8 will be student number
	//s8 = s7;
        /*
	
    	if (errorCheck(&s1,&s2,&s3,&s4,&s5,&s6,&s7, &s8))
	{
		//Create a new student
		c = atof(s4.c_str());
		g = atof(s5.c_str());
		num = atoi(s7.c_str());

//		Student joe(c,g,s1,s2,s6,s3,num,s8);
		Student *newStu = new Student(c, g, s1, s2, s6, s3, num, s8);
		
	//Use it to make an application
	Application *newApp = new Application(newStu, 1007, "CompSci", "Pending");
	}*/
}



int main(int argc, char** argv) {

	/////////////////////////////////////////////////////
	//-----------Declaration of all the widgets------////
	/////////////////////////////////////////////////////
	
	WindowApp *theApp = new WindowApp();
	Control utility;
	utility.createWindow(argc, argv);
	// initialize GTK+
	//gtk_init(&argc, &argv);

	/*
	/////////////////////////////////////////////////////
	//-----------Create the window ------------------////
	/////////////////////////////////////////////////////
	



	theApp->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(theApp->window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(theApp->window), 400, 200);
	gtk_window_set_title(GTK_WINDOW(theApp->window), "Application Center");
	

	/////////////////////////////////////////////////////
	//-----------Add frame onto window---------------////
	/////////////////////////////////////////////////////
	theApp->frame = gtk_fixed_new();

	gtk_container_add(GTK_CONTAINER(theApp->window), theApp->frame);


	/////////////////////////////////////////////////////
	//Make the application button and add to frame---////
	/////////////////////////////////////////////////////
	theApp->apply = gtk_button_new_with_label("Apply");
	gtk_widget_set_size_request(theApp->apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->frame), theApp->apply, 50, 20);

	/////////////////////////////////////////////////////
	//------Make the login button and add to frame---////
	/////////////////////////////////////////////////////
	theApp->login = gtk_button_new_with_label("Login");
	gtk_widget_set_size_request(theApp->login, 80, 35);
	gtk_fixed_put(GTK_FIXED(theApp->frame), theApp->login, 50, 80);

	/////////////////////////////////////////////////////
	//------Make the Prompt Label and add to frame---////
	/////////////////////////////////////////////////////
	theApp->label = gtk_label_new("Click Apply to Choose Your Courses");
	gtk_fixed_put(GTK_FIXED(theApp->frame), theApp->label, 150, 58); 

	/////////////////////////////////////////////////////
	//----------Show all the widgets on the window---////
	/////////////////////////////////////////////////////
	gtk_widget_show_all(theApp->window);



	/////////////////////////////////////////////////////
	//Connect signals with each button as well as close////
	/////////////////////////////////////////////////////
	g_signal_connect(theApp->window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect(theApp->apply, "clicked", G_CALLBACK(application), theApp);

	g_signal_connect(theApp->login, "clicked", G_CALLBACK(admin), theApp);*/

	gtk_main();

	return 0;
}
