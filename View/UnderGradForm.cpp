#include "UnderGradForm.h"

void UnderGradForm::draw(){

	cout << "ugrad draw" <<endl;
	/////////////////////////////////////////////////
	//--Creates new frame and adds it onto the window---//
	/////////////////////////////////////////////////
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//loadApplications(theApp);
	//cout << "app loaded" << endl;
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	gtk_window_resize(GTK_WINDOW(window), 400,600);
	
	gtk_window_set_title(GTK_WINDOW(window), "UnderGrad Form");
	
	

	


	/////////////////////////////////////////////////////
	//-----------Add frame onto window---------------////
	/////////////////////////////////////////////////////
	appFrame = gtk_fixed_new();
	//admin_frame = gtk_fixed_new();

	gtk_container_add(GTK_CONTAINER(window), appFrame);

	

	combo =  gtk_combo_box_text_new();
	fName = gtk_entry_new();
	lName = gtk_entry_new();
	major = gtk_entry_new();
	gpa = gtk_entry_new();
	email = gtk_entry_new();
	year = gtk_entry_new();
	cgpa = gtk_entry_new();
	stuNum = gtk_entry_new();


	
	char text[800];
	string courses[800];

	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open file"<<endl;
		return;
	}	
	while (!inFile.eof()) {
		inFile.getline(text, 800);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), text);
	}
	gtk_fixed_put(GTK_FIXED(appFrame), combo, 200, 200);
	/////////////////////////////////////////////////
	//--Creates text Boxes and submit\cancel buttons---//
	/////////////////////////////////////////////////
	//combo = combo;
	
	
	
	/////////////////////////////////////////////////
	//--Puts text boxes onto the new frame---------//
	/////////////////////////////////////////////////
	
	gtk_fixed_put(GTK_FIXED(appFrame), fName, 150, 280);
	gtk_fixed_put(GTK_FIXED(appFrame), lName, 150, 310);
	gtk_fixed_put(GTK_FIXED(appFrame), major, 150, 340);
	gtk_fixed_put(GTK_FIXED(appFrame), gpa, 150, 370);
	gtk_fixed_put(GTK_FIXED(appFrame), cgpa, 150, 400);
	gtk_fixed_put(GTK_FIXED(appFrame), email, 150, 430);
	gtk_fixed_put(GTK_FIXED(appFrame), year, 150, 460);
	gtk_fixed_put(GTK_FIXED(appFrame), stuNum, 150, 490);

	/////////////////////////////////////////////////
	//--Puts labels onto the new frame---------//
	/////////////////////////////////////////////////

	
	lblfName = gtk_label_new("First Name :");
	gtk_fixed_put(GTK_FIXED(appFrame), lblfName, 30, 280); 
	lbllName = gtk_label_new("Last Name :");
	gtk_fixed_put(GTK_FIXED(appFrame), lbllName, 30, 310);
	lblMajor = gtk_label_new("Major :");
	gtk_fixed_put(GTK_FIXED(appFrame), lblMajor, 30, 340);
	lblGpa = gtk_label_new("GPA :");
	gtk_fixed_put(GTK_FIXED(appFrame), lblGpa, 30, 370);
	lblCgpa = gtk_label_new("CGPA :");
	gtk_fixed_put(GTK_FIXED(appFrame), lblCgpa, 30, 400);
	lblEmail = gtk_label_new("Email Address :");
	gtk_fixed_put(GTK_FIXED(appFrame), lblEmail, 30, 430);
	lblYear = gtk_label_new("Year :");
	gtk_fixed_put(GTK_FIXED(appFrame), lblYear, 30, 460);
	lblstuNum = gtk_label_new("Student Number :");
	gtk_fixed_put(GTK_FIXED(appFrame), lblstuNum, 30, 490);

	

	/////////////////////////////////////////////////
	//--Puts buttons onto the new frame---------//
	/////////////////////////////////////////////////

	
	submit = gtk_button_new_with_label("Submit");
	cancel = gtk_button_new_with_label("Cancel");

	
	gtk_widget_set_size_request(submit, 80, 35);
	gtk_fixed_put(GTK_FIXED(appFrame), submit, 50, 530);
	gtk_widget_set_size_request(cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(appFrame), cancel, 200, 530);

	info_label = gtk_label_new("Please Enter Info Below");
	gtk_fixed_put(GTK_FIXED(appFrame), info_label, 150, 58);
	//gtk_container_add(GTK_CONTAINER(window), appFrame);
	/////////////////////////////////////////////////
	//--Show all widgets on new frame---------//
	/////////////////////////////////////////////////
	gtk_widget_show_all(window);

	
}

string UnderGradForm::getTheType(){
	return "under";
}