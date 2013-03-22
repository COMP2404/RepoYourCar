#include "RelatedCoursesTwoForm.h"

void RelatedCoursesTwoForm::create(WindowApp *windowApp, bool grad){
	/////////////////////////////////////////////////////
	//-----------Put Labels on Entries---------------////
	/////////////////////////////////////////////////////
	
	if(!grad){
		cout << "creating form 2" << endl;
		gtk_window_resize(GTK_WINDOW(windowApp->uGradAppPage->form->window), 800,600);

		windowApp->uGradAppPage->form->ei_lblRelatedCourse = gtk_label_new("Related Course :");
		
		windowApp->uGradAppPage->form->ei_lblTerm = gtk_label_new("Term :");
		windowApp->uGradAppPage->form->ei_lblYear = gtk_label_new("Year (1993-present):");
		windowApp->uGradAppPage->form->ei_lblSupervisor = gtk_label_new("Supervisor :");


		windowApp->uGradAppPage->form->ei_relatedCourse2 = gtk_entry_new();
		windowApp->uGradAppPage->form->ei_term2= gtk_entry_new();
		windowApp->uGradAppPage->form->ei_year2 = gtk_entry_new();
		windowApp->uGradAppPage->form->ei_supervisor = gtk_entry_new();


		/////////////////////////////////////////////////////
		//-----------New Buttons, labels and entries------////
		/////////////////////////////////////////////////////
	
		windowApp->uGradAppPage->form->ei_repeat2 = gtk_button_new_with_label("Add Another");
		
		
		//part 2
		windowApp->uGradAppPage->form->ei_continue2 = gtk_button_new_with_label("Continue");

		

		
		gtk_widget_set_size_request(windowApp->uGradAppPage->form->ei_continue2, 80, 35);

		gtk_widget_set_size_request(windowApp->uGradAppPage->form->ei_repeat2, 80, 35);

		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_repeat2, 550, 430);
		
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_continue2, 450, 430);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_relatedCourse2, 550, 280);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_term2, 550, 310);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_year2, 550, 340);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_supervisor, 550, 370);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_lblRelatedCourse, 400, 280);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_lblTerm, 400, 310);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_lblYear, 400, 340);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_lblSupervisor, 400, 370);
		//gtk_widget_set_sensitive(ei_continue2, FALSE);
		//gtk_widget_set_sensitive(ei_repeat2, FALSE);
		gtk_widget_set_sensitive(windowApp->uGradAppPage->form->submit, FALSE);
		gtk_widget_show_all(windowApp->uGradAppPage->form->appFrame);
		
	}
	else{
		gtk_window_resize(GTK_WINDOW(windowApp->gradAppPage->form->window), 800,600);
		
		windowApp->gradAppPage->form->ei_lblRelatedCourse = gtk_label_new("Related Course :");
		
		windowApp->gradAppPage->form->ei_lblTerm = gtk_label_new("Term :");
		windowApp->gradAppPage->form->ei_lblYear = gtk_label_new("Year (1993-Present) :");
		windowApp->gradAppPage->form->ei_lblSupervisor = gtk_label_new("Supervisor :");


		windowApp->gradAppPage->form->ei_relatedCourse2 = gtk_entry_new();
		windowApp->gradAppPage->form->ei_term2= gtk_entry_new();
		windowApp->gradAppPage->form->ei_year2 = gtk_entry_new();
		windowApp->gradAppPage->form->ei_supervisor = gtk_entry_new();


		/////////////////////////////////////////////////////
		//-----------New Buttons, labels and entries------////
		/////////////////////////////////////////////////////
		

		windowApp->gradAppPage->form->ei_repeat2 = gtk_button_new_with_label("Add Another");
		
		
		//part 2
		windowApp->gradAppPage->form->ei_continue2 = gtk_button_new_with_label("Continue");

		
		
		
		gtk_widget_set_size_request(windowApp->gradAppPage->form->ei_continue2, 80, 35);

		gtk_widget_set_size_request(windowApp->gradAppPage->form->ei_repeat2, 80, 35);

		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_repeat2, 550, 430);
		
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_continue2, 450, 430);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_relatedCourse2, 550, 280);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_term2, 550, 310);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_year2, 550, 340);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_supervisor, 550, 370);

		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_lblRelatedCourse, 400, 280);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_lblTerm, 400, 310);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_lblYear, 400, 340);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_lblSupervisor, 400, 370);
		
		gtk_widget_set_sensitive(windowApp->gradAppPage->form->submit, FALSE);
		//gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_repeat2, FALSE);
		if(windowApp->gradAppPage->edit){
			//windowApp->gradAppPage->form->btnCycle = gtk_button_new_with_label("Edit Next");
			//gtk_widget_set_size_request(windowApp->gradAppPage->form->btnCycle, 80, 35);
			//gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->btnCycle, 500, 500);

		}
		
		gtk_widget_show_all(windowApp->gradAppPage->form->appFrame);
		//if(windowApp->gradAppPage->edit)
		//	GradAppPage::fillInRelated(windowApp);
	}
	

}
void RelatedCoursesTwoForm::nextPageUGrad(GtkWidget* widget, WindowApp *theApp){
	
	if(errorCheckUGrad(theApp)){

		const gchar *s1, *s2, *s3, *s4, *s5;
		string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
		s1 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse2));
		
		s2 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year2));
		s3 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term2));
		s4 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_supervisor));        
	      
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);


		int yr = atoi(string2.c_str());
		Course* cor = new Course(string1, yr, string3, "N/A", string4);
		theApp->cQTa->pushBack(cor);
		
		RelatedCoursesTwoForm::cleanupUGrad(theApp);
		UnderGradAppPage::workExp(theApp);
	}
	else{

	}
	
	
}

void RelatedCoursesTwoForm::nextPageGrad(GtkWidget* widget, WindowApp *theApp){
	
	if(errorCheckGrad(theApp)){
		const gchar *s1, *s2, *s3, *s4, *s5;
		string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
		s1 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_relatedCourse2));
		
		s2 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_year2));
		s3 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_term2));
		s4 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_supervisor));        
	      
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);


		int yr = atoi(string2.c_str());
		Course* cor = new Course(string1, yr, string3, "N/A", string4);
		theApp->cQTa->pushBack(cor);

		RelatedCoursesTwoForm::cleanupGrad(theApp);
		GradAppPage::workExp(theApp);
	}
	else{

	}

}

void RelatedCoursesTwoForm::addAnotherUGrad(GtkWidget* widget, WindowApp *theApp){
	if(errorCheckUGrad(theApp)){
		const gchar *s1, *s2, *s3, *s4, *s5;
		string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
		s1 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse2));
		
		s2 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year2));
		s3 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term2));
		s4 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_supervisor));        
	      
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);


		int yr = atoi(string2.c_str());
		Course* cor = new Course(string1, yr, string3, "N/A", string4);
		theApp->cQTa->pushBack(cor);

		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse2), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year2), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term2), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_supervisor), "");
		
			
	}
	else{

	}
}

void RelatedCoursesTwoForm::addAnotherGrad(GtkWidget* widget, WindowApp *theApp){
	if(errorCheckGrad(theApp)){
		const gchar *s1, *s2, *s3, *s4, *s5;
		string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
		s1 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_relatedCourse2));
		
		s2 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_year2));
		s3 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_term2));
		s4 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_supervisor));        
	      
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);


		int yr = atoi(string2.c_str());
		Course* cor = new Course(string1, yr, string3, "N/A", string4);
		theApp->cQTa->pushBack(cor);

		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_relatedCourse2), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_year2), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_term2), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_supervisor), "");
		
			
	}
	else{

	}
}

bool RelatedCoursesTwoForm::errorCheckUGrad(WindowApp* theApp){

	

	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
	
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_relatedCourse2));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_year2));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_term2));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->uGradAppPage->form->ei_supervisor));        
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""){
		//theApp->checkGood = true;
		gtk_widget_set_sensitive(theApp->uGradAppPage->form->ei_continue2, TRUE);
		gtk_widget_set_sensitive(theApp->uGradAppPage->form->ei_repeat2, TRUE);
		
			int yr = atoi(string2.c_str());


			unsigned validRC2 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
			unsigned validterm2 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned supervisor = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  
			if (validRC2 != string::npos) {
				cout << "You entered an invalidcharacter, " << (string1)[validRC2];
				cout << ", at position " << validRC2 << endl;
				//WindowApp::popWindow("You entered an invalid character in Related Courses", theApp);
				//theApp->checkGood = false;
				//theApp->moveOn = false;
				return false;
		   	}
			
  
			else if (validterm2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm2];
				cout << ", at position " << validterm2 << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character in term", theApp);
				//theApp->checkGood = false;
				//theApp->moveOn = false;
				return false;
		   	}

			
			else if (supervisor != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[supervisor];
				cout << ", at position " << supervisor << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character in supervisor", theApp);
				//theApp->checkGood = false;
				//theApp->moveOn = false;
				return false;
				
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				//WindowApp::popWindow("Year must be between 1990 and 2013", theApp);
				//theApp->checkGood = false;
				//theApp->moveOn = false;
				return false;
				
			}

			
		return true;
		
		
	}
	else{
		return false;
	}
	
}
bool RelatedCoursesTwoForm::errorCheckGrad(WindowApp* theApp){

	

	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="", string6="", string7="", string8="", string9="";
	
	
	s1 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_relatedCourse2));
	
	s2 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_year2));
	s3 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_term2));
	s4 = gtk_entry_get_text(GTK_ENTRY(theApp->gradAppPage->form->ei_supervisor));        
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""){
		//theApp->gradAppPage->form->checkGood = true;
		gtk_widget_set_sensitive(theApp->gradAppPage->form->ei_continue2, TRUE);
		gtk_widget_set_sensitive(theApp->gradAppPage->form->ei_repeat2, TRUE);
		
			int yr = atoi(string2.c_str());


			unsigned validRC2 = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
			unsigned validterm2 = (string3).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned supervisor = (string4).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  
			if (validRC2 != string::npos) {
				cout << "You entered an invalidcharacter, " << (string1)[validRC2];
				cout << ", at position " << validRC2 << endl;
				//WindowApp::popWindow("You entered an invalid character in Related Courses", theApp->gradAppPage->form);
				//theApp->gradAppPage->form->checkGood = false;
				//theApp->gradAppPage->form->moveOn = false;
				return false;
		   	}
			
  
			else if (validterm2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm2];
				cout << ", at position " << validterm2 << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character in term", theApp->gradAppPage->form);
				//theApp->gradAppPage->form->checkGood = false;
				//theApp->gradAppPage->form->moveOn = false;
				return false;
		   	}

			
			else if (supervisor != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[supervisor];
				cout << ", at position " << supervisor << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character in supervisor", theApp->gradAppPage->form);
				//theApp->gradAppPage->form->checkGood = false;
				//theApp->gradAppPage->form->moveOn = false;
				return false;
				
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				//WindowApp::popWindow("Year must be between 1990 and 2013", theApp->gradAppPage->form);
				//theApp->gradAppPage->form->checkGood = false;
				//theApp->gradAppPage->form->moveOn = false;
				return false;
				
			}

			
		return true;
		
		
	}
	else{
		return false;
	}
	
}
void RelatedCoursesTwoForm::cleanupGrad(WindowApp* app){
	gtk_widget_destroy(app->gradAppPage->form->ei_repeat2);
	gtk_widget_destroy(app->gradAppPage->form->ei_continue2);
	gtk_widget_destroy(app->gradAppPage->form->ei_relatedCourse2);
	gtk_widget_destroy(app->gradAppPage->form->ei_term2);
	gtk_widget_destroy(app->gradAppPage->form->ei_year2);
	gtk_widget_destroy(app->gradAppPage->form->ei_supervisor);
	gtk_widget_destroy(app->gradAppPage->form->ei_lblRelatedCourse);
	gtk_widget_destroy(app->gradAppPage->form->ei_lblTerm);
	gtk_widget_destroy(app->gradAppPage->form->ei_lblYear);
	gtk_widget_destroy(app->gradAppPage->form->ei_lblSupervisor);
		

}
void RelatedCoursesTwoForm::cleanupUGrad(WindowApp *app){
	gtk_widget_destroy(app->uGradAppPage->form->ei_repeat2);
	gtk_widget_destroy(app->uGradAppPage->form->ei_continue2);
	gtk_widget_destroy(app->uGradAppPage->form->ei_relatedCourse2);
	gtk_widget_destroy(app->uGradAppPage->form->ei_term2);
	gtk_widget_destroy(app->uGradAppPage->form->ei_year2);
	gtk_widget_destroy(app->uGradAppPage->form->ei_supervisor);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblRelatedCourse);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblTerm);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblYear);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblSupervisor);
}