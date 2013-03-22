#include "WorkExperienceForm.h"

void WorkExperienceForm::create(WindowApp *windowApp,bool grad){
	if(!grad){
		windowApp->uGradAppPage->form->ei_lblRelevantWork = gtk_label_new("Relevant Work :");
		windowApp->uGradAppPage->form->ei_lblDuration = gtk_label_new("Duration :");
		windowApp->uGradAppPage->form->ei_lblStartDate = gtk_label_new("Start Date (dd/mm/yr) :");
		windowApp->uGradAppPage->form->ei_lblEndDate = gtk_label_new("End Date (dd/mm/yr) :");
		windowApp->uGradAppPage->form->ei_lblResponsabilities = gtk_label_new("Responsabilities :");
		
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_lblRelevantWork, 400, 280);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_lblResponsabilities, 400, 310);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_lblDuration, 400,340);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_lblStartDate, 400, 370);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_lblEndDate, 400, 400);

		//part 3
		windowApp->uGradAppPage->form->ei_relevantWork = gtk_entry_new();
		windowApp->uGradAppPage->form->ei_responsabilities = gtk_entry_new();
		windowApp->uGradAppPage->form->ei_duration= gtk_entry_new();
		windowApp->uGradAppPage->form->ei_startDate = gtk_entry_new();
		windowApp->uGradAppPage->form->ei_endDate = gtk_entry_new();

		//part 3
		windowApp->uGradAppPage->form->ei_finish = gtk_button_new_with_label("Finish");
		windowApp->uGradAppPage->form->ei_repeat3 = gtk_button_new_with_label("Add Another");
		
		gtk_widget_set_size_request(windowApp->uGradAppPage->form->ei_finish, 80, 35);
		gtk_widget_set_size_request(windowApp->uGradAppPage->form->ei_repeat3, 80, 35);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_repeat3, 550, 430);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_finish, 450, 430);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_relevantWork, 550, 280);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_responsabilities, 550, 310);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_duration, 550, 340);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_startDate, 550, 370);
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->ei_endDate,550, 400);
		//gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_finish, FALSE);
		//gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_repeat3, FALSE);*/
		gtk_widget_show_all(windowApp->uGradAppPage->form->appFrame);
	}
	else{
		windowApp->gradAppPage->form->ei_lblRelevantWork = gtk_label_new("Relevant Work :");
		windowApp->gradAppPage->form->ei_lblDuration = gtk_label_new("Duration :");
		windowApp->gradAppPage->form->ei_lblStartDate = gtk_label_new("Start Date (dd/mm/yr) :");
		windowApp->gradAppPage->form->ei_lblEndDate = gtk_label_new("End Date (dd/mm/yr) :");
		windowApp->gradAppPage->form->ei_lblResponsabilities = gtk_label_new("Responsabilities :");
		
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_lblRelevantWork, 400, 280);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_lblResponsabilities, 400, 310);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_lblDuration, 400,340);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_lblStartDate, 400, 370);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_lblEndDate, 400, 400);

		//part 3
		windowApp->gradAppPage->form->ei_relevantWork = gtk_entry_new();
		windowApp->gradAppPage->form->ei_responsabilities = gtk_entry_new();
		windowApp->gradAppPage->form->ei_duration= gtk_entry_new();
		windowApp->gradAppPage->form->ei_startDate = gtk_entry_new();
		windowApp->gradAppPage->form->ei_endDate = gtk_entry_new();

		//part 3
		windowApp->gradAppPage->form->ei_finish = gtk_button_new_with_label("Finish");
		windowApp->gradAppPage->form->ei_repeat3 = gtk_button_new_with_label("Add Another");

		if(windowApp->gradAppPage->edit){
			windowApp->gradAppPage->form->btnCycle = gtk_button_new_with_label("Edit Next");
			gtk_widget_set_size_request(windowApp->gradAppPage->form->btnCycle, 80, 35);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->btnCycle, 500, 500);
			//GradAppPage::fillInWorkExp(windowApp);
		}

		
		gtk_widget_set_size_request(windowApp->gradAppPage->form->ei_finish, 80, 35);
		gtk_widget_set_size_request(windowApp->gradAppPage->form->ei_repeat3, 80, 35);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_repeat3, 550, 430);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_finish, 450, 430);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_relevantWork, 550, 280);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_responsabilities, 550, 310);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_duration, 550, 340);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_startDate, 550, 370);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_endDate,550, 400);
		
		//gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_finish, FALSE);
		//gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_repeat3, FALSE);
		gtk_widget_show_all(windowApp->gradAppPage->form->appFrame);
	}
}

void WorkExperienceForm::addAnotherGrad(GtkWidget* widget,WindowApp* windowApp){
	if(errorCheckGrad(windowApp)){
		const gchar *s1, *s2, *s3, *s4, *s5;
		char *c1;
		string string1 = "", string2= "", string3="", string4="", string5="";

		s1 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_relevantWork));
		s2 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_responsabilities));
		s3 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_duration)); 
		s4 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_startDate));
		s5 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_endDate));
		       
		  
		  
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);
		string5 = (s5);
		Job* job = new Job(s1, s2, s3, s4, s5);
		windowApp->jQRelated->pushBack(job);
		
		gtk_entry_set_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_relevantWork), "");
		gtk_entry_set_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_responsabilities), "");
		gtk_entry_set_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_duration), "");
		gtk_entry_set_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_startDate), "");
		gtk_entry_set_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_endDate), "");
		
	}
	else{

	}
}

void WorkExperienceForm::addAnotherUGrad(GtkWidget* widget,WindowApp* windowApp){
	if(errorCheckUGrad(windowApp)){
		const gchar *s1, *s2, *s3, *s4, *s5;
		char *c1;
		string string1 = "", string2= "", string3="", string4="", string5="";

		s1 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_relevantWork));
		s2 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_responsabilities));
		s3 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_duration)); 
		s4 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_startDate));
		s5 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_endDate));
		       
		  
		  
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);
		string5 = (s5);
		Job* job = new Job(s1, s2, s3, s4, s5);
		windowApp->jQRelated->pushBack(job);
		
		gtk_entry_set_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_relevantWork), "");
		gtk_entry_set_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_responsabilities), "");
		gtk_entry_set_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_duration), "");
		gtk_entry_set_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_startDate), "");
		gtk_entry_set_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_endDate), "");

		
	}else{

	}
}


void WorkExperienceForm::finishUGrad(GtkWidget* widget, WindowApp* windowApp){
	if(errorCheckUGrad(windowApp)){
		const gchar *s1, *s2, *s3, *s4, *s5;
		char *c1;
		string string1 = "", string2= "", string3="", string4="", string5="";

		s1 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_relevantWork));
		s2 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_responsabilities));
		s3 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_duration)); 
		s4 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_startDate));
		s5 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_endDate));
		       
		  
		  
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);
		string5 = (s5);
		Job* job = new Job(s1, s2, s3, s4, s5);
		windowApp->jQRelated->pushBack(job);

		WorkExperienceForm::cleanupUGrad(windowApp);
	}else{

	}
}

void WorkExperienceForm::finishGrad(GtkWidget*widget,WindowApp* windowApp){
	if(errorCheckGrad(windowApp)){
		const gchar *s1, *s2, *s3, *s4, *s5;
		char *c1;
		string string1 = "", string2= "", string3="", string4="", string5="";

		s1 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_relevantWork));
		s2 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_responsabilities));
		s3 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_duration)); 
		s4 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_startDate));
		s5 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_endDate));
		       
		  
		  
		string1 = (s1);
		string2 = (s2);
		string3 = (s3);
		string4 = (s4);
		string5 = (s5);
		Job* job = new Job(s1, s2, s3, s4, s5);
		windowApp->jQRelated->pushBack(job);

		WorkExperienceForm::cleanupGrad(windowApp);
	}
	else{

	}
}


bool WorkExperienceForm::errorCheckGrad(WindowApp* windowApp){
	cout <<"errorcheckgrad" <<endl;
	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_relevantWork));
	s2 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_responsabilities));
	s3 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_duration)); 
	s4 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_startDate));
	s5 = gtk_entry_get_text(GTK_ENTRY(windowApp->gradAppPage->form->ei_endDate));
	       
	  
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	string5 = (s5);

	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""&& string5 != ""){
		

			unsigned validRW = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validresp = (string2).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validdur = (string3).find_first_not_of("0123456789");
			unsigned startDate = (string4).find_first_not_of("0123456789/");
			unsigned endDate = (string5).find_first_not_of("0123456789/");
			//string startYear = "00";
  
			if (validRW != string::npos) {
				
				cout << "You entered a non-alphabetical character, " << (string1)[validRW];
				cout << ", at position " << validRW << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character in related work", windowApp);
				return false;
		   	}
			
  
			else if (validresp != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string2)[validresp];
				cout << ", at position " << validresp << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character in responsabilites", windowApp);
				return false;
		   	}
			
			else if (validdur != string::npos) {
				cout << "Duration: enter a # for months" << (string3)[validdur];
				//cout << ", at position " << validdur << endl;
				//WindowApp::popWindow("Please enter a number for months", windowApp);
				return false;
		   	}

			
			else if (startDate != string::npos) {
				cout << "Start Date format is incorrect " << (string4)[startDate];
				cout << ", at position " << startDate << endl;
				//WindowApp::popWindow("Wrong Format for Start Date", windowApp);
				return false;
		   	}

			
			else if (endDate != string::npos) {
				cout << "End Date format is incorrect, " << (string5)[endDate];
				cout << ", at position " << endDate << endl;
				//WindowApp::popWindow("Wrong Format for End Date", windowApp);
				return false;
		   	}

			
		
		return true;
	}else{
		
		return false;
	}
}

bool WorkExperienceForm::errorCheckUGrad(WindowApp *windowApp){
	const gchar *s1, *s2, *s3, *s4, *s5;
	char *c1;
	string string1 = "", string2= "", string3="", string4="", string5="";
	
	s1 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_relevantWork));
	s2 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_responsabilities));
	s3 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_duration)); 
	s4 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_startDate));
	s5 = gtk_entry_get_text(GTK_ENTRY(windowApp->uGradAppPage->form->ei_endDate));
	       
	  
      
	string1 = (s1);
	string2 = (s2);
	string3 = (s3);
	string4 = (s4);
	string5 = (s5);

	if(string1 != "" && string2 != "" && string3 != "" && string4 != ""&& string5 != ""){
		
			unsigned validRW = (string1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validresp = (string2).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
			unsigned validdur = (string3).find_first_not_of("0123456789");
			unsigned startDate = (string4).find_first_not_of("0123456789/");
			unsigned endDate = (string5).find_first_not_of("0123456789/");
			//string startYear = "00";
  
			if (validRW != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string1)[validRW];
				cout << ", at position " << validRW << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character", windowApp);
				return false;
		   	}
			
  
			else if (validresp != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string2)[validresp];
				cout << ", at position " << validresp << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character", windowApp);
				return false;
		   	}
			
			else if (validdur != string::npos) {
				cout << "Enter # of months" << (string3)[validdur];
				//cout << ", at position " << validdur << endl;
				//WindowApp::popWindow("You entered a non-alphabetical character", windowApp);
				return false;
		   	}

			
			else if (startDate != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string4)[startDate];
				cout << ", at position " << startDate << endl;
				//WindowApp::popWindow("Wrong Format for Start Date", windowApp);
				return false;
		   	}

			
			else if (endDate != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string5)[endDate];
				cout << ", at position " << endDate << endl;
				//WindowApp::popWindow("Wrong Format for End Date", windowApp);
				return false;
		   	}

		
		return true;
	}else{
		return false;
	}
}
void WorkExperienceForm::cleanupGrad(WindowApp* app){
	gtk_widget_destroy(app->gradAppPage->form->ei_repeat3);
	gtk_widget_destroy(app->gradAppPage->form->ei_finish);
	gtk_widget_destroy(app->gradAppPage->form->ei_relevantWork);
	gtk_widget_destroy(app->gradAppPage->form->ei_responsabilities);
	gtk_widget_destroy(app->gradAppPage->form->ei_duration);
	gtk_widget_destroy(app->gradAppPage->form->ei_startDate);
	gtk_widget_destroy(app->gradAppPage->form->ei_endDate);
	gtk_widget_destroy(app->gradAppPage->form->ei_lblRelevantWork);
	gtk_widget_destroy(app->gradAppPage->form->ei_lblResponsabilities);
	gtk_widget_destroy(app->gradAppPage->form->ei_lblDuration);
	gtk_widget_destroy(app->gradAppPage->form->ei_lblStartDate);
	gtk_widget_destroy(app->gradAppPage->form->ei_lblEndDate);
	gtk_window_resize(GTK_WINDOW(app->gradAppPage->form->window), 400,600);
	
}
void WorkExperienceForm::cleanupUGrad(WindowApp* app){
	gtk_widget_destroy(app->uGradAppPage->form->ei_repeat3);
	gtk_widget_destroy(app->uGradAppPage->form->ei_finish);
	gtk_widget_destroy(app->uGradAppPage->form->ei_relevantWork);
	gtk_widget_destroy(app->uGradAppPage->form->ei_responsabilities);
	gtk_widget_destroy(app->uGradAppPage->form->ei_duration);
	gtk_widget_destroy(app->uGradAppPage->form->ei_startDate);
	gtk_widget_destroy(app->uGradAppPage->form->ei_endDate);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblRelevantWork);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblResponsabilities);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblDuration);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblStartDate);
	gtk_widget_destroy(app->uGradAppPage->form->ei_lblEndDate);
	gtk_window_resize(GTK_WINDOW(app->uGradAppPage->form->window), 400,600);
}

