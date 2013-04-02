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
		windowApp->uGradAppPage->form->ei_lblYear = gtk_label_new("Year (1990-present):");
		windowApp->uGradAppPage->form->ei_lblSupervisor = gtk_label_new("Supervisor :");


		windowApp->uGradAppPage->form->ei_relatedCourse2 = gtk_entry_new();
		windowApp->uGradAppPage->form->ei_term2= gtk_entry_new();
		windowApp->uGradAppPage->form->ei_year2 = gtk_entry_new();
		windowApp->uGradAppPage->form->ei_supervisor = gtk_entry_new();


		/////////////////////////////////////////////////////
		//-----------New Buttons, labels and entries------////
		/////////////////////////////////////////////////////
		if(windowApp->editUMode){
			windowApp->uGradAppPage->form->ei_repeat2 = gtk_button_new_with_label("Edit/Add Another");
		}else{
			windowApp->uGradAppPage->form->ei_repeat2 = gtk_button_new_with_label("Add Another");
		}
		
		
		
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

		windowApp->uGradAppPage->form->chkExperience = gtk_check_button_new_with_label("No Experience");
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->chkExperience, 450, 480);

		//gtk_widget_set_sensitive(ei_continue2, FALSE);
		//gtk_widget_set_sensitive(ei_repeat2, FALSE);
		gtk_widget_set_sensitive(windowApp->uGradAppPage->form->submit, FALSE);
		

		if(!windowApp->canEdit){
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_relatedCourse2, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_term2, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_year2, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_supervisor, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_continue2, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_repeat2, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->chkExperience, FALSE);

			windowApp->uGradAppPage->form->nextApp = gtk_button_new_with_label("Next App");
			windowApp->uGradAppPage->form->prevApp = gtk_button_new_with_label("Prev App");
			windowApp->uGradAppPage->form->nextSection = gtk_button_new_with_label("Next Section");
			windowApp->uGradAppPage->form->nextPage = gtk_button_new_with_label("Next Page");
			windowApp->uGradAppPage->form->prevSection = gtk_button_new_with_label("Prev Section");
			windowApp->uGradAppPage->form->prevPage = gtk_button_new_with_label("Prev Page");

			gtk_widget_set_size_request(windowApp->uGradAppPage->form->nextApp, 80, 35);
			gtk_widget_set_size_request(windowApp->uGradAppPage->form->prevApp, 80, 35);
			gtk_widget_set_size_request(windowApp->uGradAppPage->form->nextSection, 80, 35);
			gtk_widget_set_size_request(windowApp->uGradAppPage->form->nextPage, 80, 35);
			gtk_widget_set_size_request(windowApp->uGradAppPage->form->prevSection, 80, 35);
			gtk_widget_set_size_request(windowApp->uGradAppPage->form->prevPage, 80, 35);

			gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->nextApp, 460, 550);
			gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->prevApp, 545, 550);
			gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->nextSection, 550, 500);
			gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->nextPage, 640, 500);
			gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->prevSection, 465, 500);
			gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->prevPage, 380, 500);
	
		}
		gtk_widget_show_all(windowApp->uGradAppPage->form->appFrame);
		
	}
	else{
		gtk_window_resize(GTK_WINDOW(windowApp->gradAppPage->form->window), 800,600);
		
		windowApp->gradAppPage->form->ei_lblRelatedCourse = gtk_label_new("Related Course :");
		
		windowApp->gradAppPage->form->ei_lblTerm = gtk_label_new("Term :");
		windowApp->gradAppPage->form->ei_lblYear = gtk_label_new("Year (1990-Present) :");
		windowApp->gradAppPage->form->ei_lblSupervisor = gtk_label_new("Supervisor :");


		windowApp->gradAppPage->form->ei_relatedCourse2 = gtk_entry_new();
		windowApp->gradAppPage->form->ei_term2= gtk_entry_new();
		windowApp->gradAppPage->form->ei_year2 = gtk_entry_new();
		windowApp->gradAppPage->form->ei_supervisor = gtk_entry_new();


		/////////////////////////////////////////////////////
		//-----------New Buttons, labels and entries------////
		/////////////////////////////////////////////////////
		
		if(windowApp->editGMode){
			windowApp->gradAppPage->form->ei_repeat2 = gtk_button_new_with_label("Edit/Add Another");
		}else{
			windowApp->gradAppPage->form->ei_repeat2 = gtk_button_new_with_label("Add Another");
		}
		
		
		
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

		windowApp->gradAppPage->form->chkExperience = gtk_check_button_new_with_label("No Experience");
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->chkExperience, 450, 480);

		gtk_widget_set_sensitive(windowApp->gradAppPage->form->submit, FALSE);
		//gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_repeat2, FALSE);
		if(windowApp->gradAppPage->edit){
			//windowApp->gradAppPage->form->btnCycle = gtk_button_new_with_label("Edit Next");
			//gtk_widget_set_size_request(windowApp->gradAppPage->form->btnCycle, 80, 35);
			//gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->btnCycle, 500, 500);

		}
		if(!windowApp->canEdit){
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_relatedCourse2, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_term2, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_year2, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_supervisor, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_continue2, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_repeat2, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->chkExperience, FALSE);


			windowApp->gradAppPage->form->nextApp = gtk_button_new_with_label("Next App");
			windowApp->gradAppPage->form->prevApp = gtk_button_new_with_label("Prev App");
			windowApp->gradAppPage->form->nextSection = gtk_button_new_with_label("Next Section");
			windowApp->gradAppPage->form->nextPage = gtk_button_new_with_label("Next Page");
			windowApp->gradAppPage->form->prevSection = gtk_button_new_with_label("Prev Section");
			windowApp->gradAppPage->form->prevPage = gtk_button_new_with_label("Prev Page");

			gtk_widget_set_size_request(windowApp->gradAppPage->form->nextApp, 80, 35);
			gtk_widget_set_size_request(windowApp->gradAppPage->form->prevApp, 80, 35);
			gtk_widget_set_size_request(windowApp->gradAppPage->form->nextSection, 80, 35);
			gtk_widget_set_size_request(windowApp->gradAppPage->form->nextPage, 80, 35);
			gtk_widget_set_size_request(windowApp->gradAppPage->form->prevSection, 80, 35);
			gtk_widget_set_size_request(windowApp->gradAppPage->form->prevPage, 80, 35);

			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->nextApp, 460, 550);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->prevApp, 545, 550);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->nextSection, 550, 500);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->nextPage, 640, 500);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->prevSection, 465, 500);
			//gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->prevPage, 380, 500);
	
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
		theApp->uGradAppPage->form->rTA = true;
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
		Course* cor = new Course(string1, yr, string3, string4, "N/A");
		theApp->cQTa->pushBack(cor);
		theApp->gradAppPage->form->rTA = true;
		RelatedCoursesTwoForm::cleanupGrad(theApp);
		GradAppPage::workExp(theApp);
	}
	else{

	}

}

void RelatedCoursesTwoForm::viewNextUPage(GtkWidget* widget,WindowApp* theApp){
	RelatedCoursesTwoForm::cleanupUGrad(theApp);
 	UnderGradAppPage::workExp(theApp);
 	UnderGradAppPage::fillInWorkExp(theApp);
}
void RelatedCoursesTwoForm::viewPrevUPage(GtkWidget* widget,WindowApp* theApp){
	RelatedCoursesTwoForm::cleanupUGrad(theApp);
 	UnderGradAppPage::related1(widget,theApp);
 	UnderGradAppPage::fillInRelated(theApp);
}
void RelatedCoursesTwoForm::viewNextGPage(GtkWidget* widget,WindowApp* theApp){
	RelatedCoursesTwoForm::cleanupGrad(theApp);
 	GradAppPage::workExp(theApp);
 	GradAppPage::fillInWorkExp(theApp);
}

void RelatedCoursesTwoForm::viewNextUSection(GtkWidget* widget,WindowApp* theApp){
	
}
void RelatedCoursesTwoForm::viewPrevUSection(GtkWidget* widget,WindowApp* theApp){
	
}
void RelatedCoursesTwoForm::viewNextGSection(GtkWidget* widget,WindowApp* theApp){
	
}
void RelatedCoursesTwoForm::viewPrevGSection(GtkWidget* widget,WindowApp* theApp){
	
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
		if(theApp->editUMode)
			UnderGradAppPage::editNextRelated(theApp);
			
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
		Course* cor = new Course(string1, yr, string3, string4, "N/A");
		theApp->cQTa->pushBack(cor);

		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_relatedCourse2), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_year2), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_term2), "");
		gtk_entry_set_text(GTK_ENTRY(theApp->gradAppPage->form->ei_supervisor), "");
		if(theApp->editGMode)
			GradAppPage::editNextRelated(theApp);
			
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
				RelatedCoursesTwoForm::popWindow("You entered an invalid character in Related Courses");
				//theApp->checkGood = false;
				//theApp->moveOn = false;
				return false;
		   	}
			
  
			else if (validterm2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm2];
				cout << ", at position " << validterm2 << endl;
				RelatedCoursesTwoForm::popWindow("You entered a non-alphabetical character in term");
				//theApp->checkGood = false;
				//theApp->moveOn = false;
				return false;
		   	}

			
			else if (supervisor != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[supervisor];
				cout << ", at position " << supervisor << endl;
				RelatedCoursesTwoForm::popWindow("You entered a non-alphabetical character in supervisor");
				//theApp->checkGood = false;
				//theApp->moveOn = false;
				return false;
				
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				RelatedCoursesTwoForm::popWindow("Year must be between 1990 and 2013");
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
				RelatedCoursesTwoForm::popWindow("You entered an invalid character in Related Courses");
				//theApp->gradAppPage->form->checkGood = false;
				//theApp->gradAppPage->form->moveOn = false;
				return false;
		   	}
			
  
			else if (validterm2 != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string3)[validterm2];
				cout << ", at position " << validterm2 << endl;
				RelatedCoursesTwoForm::popWindow("You entered a non-alphabetical character in term");
				//theApp->gradAppPage->form->checkGood = false;
				//theApp->gradAppPage->form->moveOn = false;
				return false;
		   	}

			
			else if (supervisor != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[supervisor];
				cout << ", at position " << supervisor << endl;
				RelatedCoursesTwoForm::popWindow("You entered a non-alphabetical character in supervisor");
				//theApp->gradAppPage->form->checkGood = false;
				//theApp->gradAppPage->form->moveOn = false;
				return false;
				
		   	}


			else if (yr < 1990 || yr > 2013) {
				cout << "Year must be between 1990 and 2013" << endl; 
				RelatedCoursesTwoForm::popWindow("Year must be between 1990 and 2013");
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
	gtk_widget_destroy(app->gradAppPage->form->chkExperience);
	if(!app->canEdit){
		gtk_widget_destroy(app->gradAppPage->form->nextApp);
		gtk_widget_destroy(app->gradAppPage->form->prevApp);
		gtk_widget_destroy(app->gradAppPage->form->nextSection);
		gtk_widget_destroy(app->gradAppPage->form->nextPage);
		gtk_widget_destroy(app->gradAppPage->form->prevSection);
		gtk_widget_destroy(app->gradAppPage->form->prevPage);
		
	}
		

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
	gtk_widget_destroy(app->uGradAppPage->form->chkExperience);
	if(!app->canEdit){
		gtk_widget_destroy(app->uGradAppPage->form->nextApp);
		gtk_widget_destroy(app->uGradAppPage->form->prevApp);
		gtk_widget_destroy(app->uGradAppPage->form->nextSection);
		gtk_widget_destroy(app->uGradAppPage->form->nextPage);
		gtk_widget_destroy(app->uGradAppPage->form->prevSection);
		gtk_widget_destroy(app->uGradAppPage->form->prevPage);
		
	}
}
void RelatedCoursesTwoForm::closeU(GtkWidget* widget, WindowApp* app){
	app->uGradAppPage->form->rTA = false;
	//gtk_window_resize(GTK_WINDOW(app->uGradAppPage->form->window), 400,600);
	//gtk_widget_set_sensitive(app->uGradAppPage->form->submit, TRUE);
	RelatedCoursesTwoForm::cleanupUGrad(app);
	UnderGradAppPage::workExp(app);

}
void RelatedCoursesTwoForm::closeG(GtkWidget* widget, WindowApp* app){
	app->gradAppPage->form->rTA = false;
	//gtk_window_resize(GTK_WINDOW(app->gradAppPage->form->window), 400,600);
	//gtk_widget_set_sensitive(app->gradAppPage->form->submit, TRUE);
	RelatedCoursesTwoForm::cleanupGrad(app);
	GradAppPage::workExp(app);
}
void RelatedCoursesTwoForm::popWindow(string s){
	GtkWidget* error_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(error_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(error_window), 400, 200);
	
	gtk_window_set_title(GTK_WINDOW(error_window), "ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	
	GtkWidget* error_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(error_window), error_frame);

	GtkWidget* error_dismiss = gtk_button_new_with_label("Dismiss");
	gtk_widget_set_size_request(error_dismiss , 80, 35);
	gtk_fixed_put(GTK_FIXED(error_frame), error_dismiss , 100, 100);	
	const gchar* message;
	message = s.c_str();
	GtkWidget* error_message = gtk_label_new(message);
	gtk_fixed_put(GTK_FIXED(error_frame), error_message, 10, 10); 


	gtk_widget_show_all(error_window);

	g_signal_connect(error_dismiss, "clicked", G_CALLBACK (RelatedCoursesTwoForm::closePopWindow), error_window);
	
}

void RelatedCoursesTwoForm::closePopWindow(GtkWidget *widget, GtkWidget *window){
	gtk_widget_destroy(window);
}