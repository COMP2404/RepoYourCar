#include "WorkExperienceForm.h"

void WorkExperienceForm::create(WindowApp *windowApp,bool grad){
	if(!grad){
		windowApp->uGradAppPage->form->ei_lblRelevantWork = gtk_label_new("Relevant Work :");
		windowApp->uGradAppPage->form->ei_lblDuration = gtk_label_new("Duration (#months):");
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
		windowApp->uGradAppPage->form->chkExperience = gtk_check_button_new_with_label("No Experience");
		gtk_fixed_put(GTK_FIXED(windowApp->uGradAppPage->form->appFrame), windowApp->uGradAppPage->form->chkExperience, 450, 480);


		if(!windowApp->canEdit){
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_relevantWork, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_responsabilities, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_startDate, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_endDate, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_duration, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_finish, FALSE);
			gtk_widget_set_sensitive(windowApp->uGradAppPage->form->ei_repeat3, FALSE);
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

		gtk_widget_set_sensitive(windowApp->uGradAppPage->form->submit, FALSE);
		gtk_widget_show_all(windowApp->uGradAppPage->form->appFrame);
	}
	else{
		windowApp->gradAppPage->form->ei_lblRelevantWork = gtk_label_new("Relevant Work :");
		windowApp->gradAppPage->form->ei_lblDuration = gtk_label_new("Duration (#months):");
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


		
		gtk_widget_set_size_request(windowApp->gradAppPage->form->ei_finish, 80, 35);
		gtk_widget_set_size_request(windowApp->gradAppPage->form->ei_repeat3, 80, 35);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_repeat3, 550, 430);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_finish, 450, 430);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_relevantWork, 550, 280);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_responsabilities, 550, 310);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_duration, 550, 340);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_startDate, 550, 370);
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->ei_endDate,550, 400);
		
		windowApp->gradAppPage->form->chkExperience = gtk_check_button_new_with_label("No Experience");
		gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->chkExperience, 450, 480);

		//gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_finish, FALSE);
		//gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_repeat3, FALSE);

		if(!windowApp->canEdit){
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_relevantWork, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_responsabilities, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_startDate, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_endDate, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_duration, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_finish, FALSE);
			gtk_widget_set_sensitive(windowApp->gradAppPage->form->ei_repeat3, FALSE);
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

			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->nextApp, 450, 430);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->prevApp, 450, 430);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->nextSection, 450, 430);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->nextPage, 450, 430);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->prevSection, 450, 430);
			gtk_fixed_put(GTK_FIXED(windowApp->gradAppPage->form->appFrame), windowApp->gradAppPage->form->prevPage, 450, 430);
	
		}


		gtk_widget_set_sensitive(windowApp->gradAppPage->form->submit, FALSE);
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
		if(windowApp->editGMode){
			GradAppPage::editNextJob(windowApp);
		}
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
		if(windowApp->editUMode){
			UnderGradAppPage::editNextJob(windowApp);
		}
		
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
		windowApp->uGradAppPage->form->rWorkExp = true;
		gtk_widget_set_sensitive(windowApp->uGradAppPage->form->submit, TRUE);
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
		windowApp->gradAppPage->form->rWorkExp = true;
		gtk_widget_set_sensitive(windowApp->gradAppPage->form->submit, TRUE);
		WorkExperienceForm::cleanupGrad(windowApp);
	}
	else{

	}
}


void WorkExperienceForm::viewNextUPage(GtkWidget* widget,WindowApp* theApp){

}
void WorkExperienceForm::viewPrevUPage(GtkWidget* widget,WindowApp* theApp){

}

void WorkExperienceForm::viewNextGPage(GtkWidget* widget,WindowApp* theApp){

}
void WorkExperienceForm::viewPrevGPage(GtkWidget* widget,WindowApp* theApp){

}

void WorkExperienceForm::viewPrevUSection(GtkWidget* widget,WindowApp* theApp){

}

void WorkExperienceForm::viewPrevGSection(GtkWidget* widget,WindowApp* theApp){

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
				WorkExperienceForm::popWindow("You entered a non-alphabetical character in related work");
				return false;
		   	}
			
  
			else if (validresp != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string2)[validresp];
				cout << ", at position " << validresp << endl;
				WorkExperienceForm::popWindow("You entered a non-alphabetical character in responsabilites");
				return false;
		   	}
			
			else if (validdur != string::npos) {
				cout << "Duration: enter a # for months" << (string3)[validdur];
				//cout << ", at position " << validdur << endl;
				WorkExperienceForm::popWindow("Please enter a number for months");
				return false;
		   	}

			
			else if (startDate != string::npos) {
				cout << "Start Date format is incorrect " << (string4)[startDate];
				cout << ", at position " << startDate << endl;
				WorkExperienceForm::popWindow("Wrong Format for Start Date");
				return false;
		   	}

			
			else if (endDate != string::npos) {
				cout << "End Date format is incorrect, " << (string5)[endDate];
				cout << ", at position " << endDate << endl;
				WorkExperienceForm::popWindow("Wrong Format for End Date");
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
				WorkExperienceForm::popWindow("You entered a non-alphabetical character in related work");
				return false;
		   	}
			
  
			else if (validresp != string::npos) {
				cout << "You entered a non-alphabetical character, " << (string2)[validresp];
				cout << ", at position " << validresp << endl;
				WorkExperienceForm::popWindow("You entered a non-alphabetical character");
				return false;
		   	}
			
			else if (validdur != string::npos) {
				cout << "Enter # of months" << (string3)[validdur];
				//cout << ", at position " << validdur << endl;
				WorkExperienceForm::popWindow("You entered a non-alphabetical character in responsabilites");
				return false;
		   	}

			
			else if (validdur != string::npos) {
				cout << "Duration: enter a # for months" << (string3)[validdur];
				//cout << ", at position " << validdur << endl;
				WorkExperienceForm::popWindow("Please enter a number for months");
				return false;
		   	}

			
			else if (startDate != string::npos) {
				cout << "Start Date format is incorrect " << (string4)[startDate];
				cout << ", at position " << startDate << endl;
				WorkExperienceForm::popWindow("Wrong Format for Start Date");
				return false;
		   	}

			
			else if (endDate != string::npos) {
				cout << "End Date format is incorrect, " << (string5)[endDate];
				cout << ", at position " << endDate << endl;
				WorkExperienceForm::popWindow("Wrong Format for End Date");
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
	gtk_widget_destroy(app->gradAppPage->form->chkExperience);
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
	gtk_widget_destroy(app->uGradAppPage->form->chkExperience);
	gtk_window_resize(GTK_WINDOW(app->uGradAppPage->form->window), 400,600);
}
void WorkExperienceForm::closeU(GtkWidget* widget, WindowApp* app){
	app->uGradAppPage->form->rWorkExp = false;
	gtk_widget_set_sensitive(app->uGradAppPage->form->submit, TRUE);
	//gtk_window_resize(GTK_WINDOW(app->uGradAppPage->form->window), 400,600);
	WorkExperienceForm::cleanupUGrad(app);
	
}
void WorkExperienceForm::closeG(GtkWidget* widget, WindowApp* app){
	app->gradAppPage->form->rWorkExp = false;
	gtk_widget_set_sensitive(app->gradAppPage->form->submit, TRUE);
	//gtk_window_resize(GTK_WINDOW(app->gradAppPage->form->window), 400,600);
	WorkExperienceForm::cleanupGrad(app);
}

void WorkExperienceForm::popWindow(string s){
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

	g_signal_connect(error_dismiss, "clicked", G_CALLBACK (WorkExperienceForm::closePopWindow), error_window);
	
}

void WorkExperienceForm::closePopWindow(GtkWidget *widget, GtkWidget *window){
	gtk_widget_destroy(window);
}