#include "GradForm.h"
void GradForm::draw(GradForm *form){

	/////////////////////////////////////////////////
	//--Creates new frame and adds it onto the window---//
	/////////////////////////////////////////////////
	cout << "in form draw" <<endl;
 	form->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//loadApplications(theApp);
	//cout << "app loaded" << endl;
	gtk_window_set_position(GTK_WINDOW(form->window), GTK_WIN_POS_CENTER);
	
	gtk_window_resize(GTK_WINDOW(form->window), 400,600);
	
	gtk_window_set_title(GTK_WINDOW(form->window), "Grad Form");
	
	

	


	/////////////////////////////////////////////////////
	//-----------Add frame onto window---------------////
	/////////////////////////////////////////////////////
	form->appFrame = gtk_fixed_new();
	//admin_frame = gtk_fixed_new();

	gtk_container_add(GTK_CONTAINER(form->window), form->appFrame);
	
//their general information, including student number, first and last names, email address, main research area
//(selected from a preconfigured list), program (MCS or PhD), and supervisor name
	form->combo =  gtk_combo_box_text_new();
	form->grad_research_combo =  gtk_combo_box_text_new();
	grad_program_combo =  gtk_combo_box_text_new();
	form->fName = gtk_entry_new();
	form->lName = gtk_entry_new();
	form->email = gtk_entry_new();
	form->grad_sup = gtk_entry_new();
	form->stuNum = gtk_entry_new();

	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(form->grad_program_combo), "MCS");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(form->grad_program_combo), "PHD");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->grad_program_combo, 200, 300);


	char text[800];
	string courses[800];

	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open courses file"<<endl;
		return;
	}	
	while (!inFile.eof()) {
		inFile.getline(text, 800);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(form->combo), text);
	}
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->combo, 200, 200);


	char text2[800];
	string areas[800];

	ifstream inFile2("gradResearch.txt", ios::in);

	if (!inFile2) {
		cout<<"Could not open Grad Research file"<<endl;
		return;
	}	
	while (!inFile2.eof()) {
		inFile2.getline(text2, 800);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(grad_research_combo), text2);
	}
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->grad_research_combo, 200, 250);
	



	/////////////////////////////////////////////////
	//--Creates text Boxes and submit\cancel buttons---//
	/////////////////////////////////////////////////
	//combo = combo;
	
	
	
	/////////////////////////////////////////////////
	//--Puts text boxes onto the new frame---------//
	/////////////////////////////////////////////////
	
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->fName, 150, 340);
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->lName, 150, 370);
	//gtk_fixed_put(GTK_FIXED(appFrame), major, 150, 340);
	//gtk_fixed_put(GTK_FIXED(appFrame), gpa, 150, 370);
	//gtk_fixed_put(GTK_FIXED(appFrame), cgpa, 150, 400);
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->email, 150, 400);
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->grad_sup, 150, 430);
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->stuNum, 150, 460);

	/////////////////////////////////////////////////
	//--Puts labels onto the new frame---------//
	/////////////////////////////////////////////////

	form->lblpickCourse = gtk_label_new("Pick Course :");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->lblpickCourse, 30, 200); 
	form->lblpickArea = gtk_label_new("Study Area :");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->lblpickArea, 30, 250);
	form->lblpickProgram = gtk_label_new("Grad Program:");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->lblpickProgram, 30, 300);
	
	form->lblfName = gtk_label_new("First Name :");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->lblfName, 30, 340); 
	form->lbllName = gtk_label_new("Last Name :");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->lbllName, 30, 370);
	form->lblEmail = gtk_label_new("Email Address:");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->lblEmail, 30, 400);
	//lblGpa = gtk_label_new("GPA :");
	//gtk_fixed_put(GTK_FIXED(appFrame), lblGpa, 30, 370);
	//lblCgpa = gtk_label_new("CGPA :");
	//gtk_fixed_put(GTK_FIXED(appFrame), lblCgpa, 30, 400);
	form->lbl_grad_sup = gtk_label_new("Supervisor :");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->lbl_grad_sup, 30, 430);
	//lblYear = gtk_label_new("Year :");
	//gtk_fixed_put(GTK_FIXED(appFrame), lblYear, 30, 460);
	form->lblstuNum = gtk_label_new("Student Number :");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->lblstuNum, 30, 460);

	

	/////////////////////////////////////////////////
	//--Puts buttons onto the new frame---------//
	/////////////////////////////////////////////////

	
	form->submit = gtk_button_new_with_label("Submit");
	form->cancel = gtk_button_new_with_label("Cancel");

	
	gtk_widget_set_size_request(form->submit, 80, 35);
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->submit, 50, 530);
	gtk_widget_set_size_request(form->cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->cancel, 200, 530);

	form->info_label = gtk_label_new("Please Enter Info Below");
	gtk_fixed_put(GTK_FIXED(form->appFrame), form->info_label, 150, 58);
	//gtk_container_add(GTK_CONTAINER(window), appFrame);
	/////////////////////////////////////////////////
	//--Show all widgets on new frame---------//
	/////////////////////////////////////////////////
	gtk_widget_show_all(form->window);
}
string GradForm::getTheType(){

	return "grad";
}