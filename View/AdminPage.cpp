#include "AdminPage.h"

void AdminPage::adminPage(AdminWindow *window){
	//window = new AdminWindow();
	window->draw();

	//g_signal_connect(manager.admin_viewSummary, "clicked", G_CALLBACK (AdminManager::viewSummaryClicked), this);
	//g_signal_connect(window->admin_cancel, "clicked", G_CALLBACK (AdminPage::cleanup), window);
	g_signal_connect(window->admin_viewSummary, "clicked", G_CALLBACK (AdminPage::viewSummaryChoice), window);
	g_signal_connect(window->admin_assigned, "clicked", G_CALLBACK (AdminPage::viewSummaryChoice), window);
	//g_signal_connect (manager.admin_window, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);
	//g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
}

void AdminPage::cleanup(GtkWidget *widget , AdminWindow *window){
	cout << "Clicked it" << endl;
	gtk_widget_destroy(window->admin_window);

}
void AdminPage::viewSummary(GtkWidget *widget, AdminWindow *window){
	gtk_widget_destroy(window->admin_frame);
	window->admin_frame = gtk_fixed_new();
	
	
	window->admin_combo =  gtk_combo_box_text_new();
	
	window->admin_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(window->admin_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->admin_cancel , 100, 150);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->admin_combo, 50, 50);
	window->summary_combo =  gtk_combo_box_text_new();
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->summary_combo, 50, 100);
	
	gtk_container_add(GTK_CONTAINER(window->admin_window), window->admin_frame);
	
	gtk_widget_show_all(window->admin_window);

	

	char text[800];
	string courses[800];



	ifstream inFile("courses.txt", ios::in);

	if (!inFile) {
		cout<<"Could not open file"<<endl;
		exit(1);
	}	
	while (!inFile.eof()) {
		inFile.getline(text, 800);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(window->admin_combo), text);
	}
	
	//g_signal_connect(window->admin_cancel, "clicked", G_CALLBACK (Control::submitToMain), theApp);
	g_signal_connect(GTK_COMBO_BOX(window->admin_combo), "changed", G_CALLBACK   (AdminPage::updateCombo), window);
	//if(window->allCourses)
	//	updateCombo(widget,theApp);
}
void AdminPage::viewSummaryChoice(GtkWidget *widget, AdminWindow *window){
	window->showSummaryChoice(widget, window);
	
}

void AdminPage::updateCombo(GtkWidget* widget, AdminWindow *window){
	
	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(window->summary_combo));
	
	
	AppQueue* qCopy = new AppQueue(window->theApp->appQueue);
	if(window->pending){
		if(window->allCourses){
			qCopy = qCopy->sortAll();
			
			gtk_widget_set_sensitive(window->admin_combo, FALSE);
		}
		else{
			const gchar* theCourse;
		 	theCourse = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(window->admin_combo));
			string courseString;
			courseString = (theCourse);
			cout << courseString << endl;
			qCopy = window->theApp->appQueue.getPendingList(courseString);
			qCopy = qCopy->sortAll();
		}
	}else{

	}
	
	
			
	cout << "Got Pending List" << endl;
	//char s1[100], s2[100], s3[100], s4[100], s5[100], s6[100], s7[100];
	string s1,s2,s3,s4,s5,s6,s7 ,s8,s9,s10,s11;
	
	//int length = qCopy->size();
	
	char theInput[200];
	string input[100];//string array for each Application
	Application* tmpApp = NULL;
	Application* app;
    
	GradApp* ga = NULL;
	UndergradApp *uga = NULL;
	
	if(qCopy != NULL){
		app = (qCopy->popFront());
		cout << "Popped Front" << endl;
		
		
	}
	
	 int i = 0;
	//for(int i=0; i<length; i++){
	while(app != NULL){
		std::stringstream ss1; 
		std::stringstream ss2; 
		std::stringstream ss3;
		if(app->getType() == "grad"){
			ga = static_cast<GradApp*>(app);
			s1 = ga->getStuFirst();
			//cout << s1 << endl;
			s2 = ga->getStuLast();
			s6 = ga->getStuEmail();
			s7 = ga->getStuID();
			s9 = ga->getStuArea();
			s10 = ga->getStuProgram();
			s11 = ga->getStuSuper();
			input[i] = "Course: " + ga->getCourse() +  "   Grad:   " + s1 + " " + s2 +  "   |  Email: " + s6 + "   |   ID: " + s7 + "    |   Area:  " + s9 + "   |   Program:  "  + s10 + "  |   Supervisor:  " + s11;
		}
		else{

			uga = static_cast<UndergradApp*>(app);	
			s1 = uga->getStuFirst();
			cout << s1 << endl;
			s2 = uga->getStuLast();
				 
			ss1 << uga->getStuYrStanding();
			s3 = ss1.str();
			s4 = uga->getStuMajor();
			ss2 << uga->getStuCGPA();
			s5 = ss2.str();
			s6 = uga->getStuEmail();
			s7 = uga->getStuID();
			ss3 << uga->getStuMGPA();
			s8 = ss3.str();
			input[i] = "Course:  " + uga->getCourse() + "   Undergrad: " + s1 + " " + s2 + "   in Year: " + s3 + "    |   Major: " + s4 + "  |  CGPA: " + s5  + "   |  GPA:  " + s8 + "   |  Email: " + s6 + "   |   ID: " + s7;
		}

			
		 
		
		//theInput = input[i];
		strcpy(theInput,input[i].c_str());
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(window->summary_combo), theInput);
		i++;
		app = qCopy->popFront();	
		if(app != NULL){
			if(app->getType() == "grad"){
				ga = static_cast<GradApp*>(app);
				

			}
			else{
				uga = dynamic_cast<UndergradApp*>(app);
			}
		}
		
	}
	
	
	gtk_widget_show_all(window->admin_window);
}