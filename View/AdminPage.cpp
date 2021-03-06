#include "AdminPage.h"

void AdminPage::adminPage(AdminWindow *window){

	window->draw(); //draw the admin form where the user can fill in data

	g_signal_connect(window->admin_cancel, "clicked", G_CALLBACK (AdminPage::cleanup), window);
	g_signal_connect(window->admin_viewSummary, "clicked", G_CALLBACK (AdminPage::viewSummaryChoice), window);
	g_signal_connect(window->admin_assigned, "clicked", G_CALLBACK (AdminPage::viewSummaryChoice), window);
	g_signal_connect(window->viewApp, "clicked", G_CALLBACK (AdminPage::viewAnApp), window);

}

void AdminPage::cleanup(GtkWidget *widget , AdminWindow *window){
	cout << "Clicked it" << endl;
	gtk_widget_destroy(window->admin_window); //close the page

}
void AdminPage::viewSummary(GtkWidget *widget, AdminWindow *window){
	gtk_widget_destroy(window->admin_frame);
	window->admin_frame = gtk_fixed_new();
	window->admin_combo =  gtk_combo_box_text_new(); 			//summary of apps in a combo box
	window->admin_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(window->admin_cancel, 80, 35);

	window->printSum = gtk_button_new_with_label("Save Summary");
	gtk_widget_set_size_request(window->printSum, 80, 35);

	window->admin_assigned = gtk_button_new_with_label("Assign App to Successful");
	gtk_widget_set_size_request(window->admin_assigned, 80, 35);

	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->admin_cancel , 120, 150);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->admin_combo, 50, 50);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->printSum, 10, 150);
	if(window->pending)
		gtk_fixed_put(GTK_FIXED(window->admin_frame), window->admin_assigned, 200, 150);  //if the app is pending 
	window->summary_combo =  gtk_combo_box_text_new();
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->summary_combo, 50, 100);
	
	gtk_widget_set_sensitive(window->admin_assigned, FALSE);
	gtk_widget_set_sensitive(window->printSum, FALSE);
	gtk_container_add(GTK_CONTAINER(window->admin_window), window->admin_frame);	
	gtk_widget_show_all(window->admin_window);

	
	if(!window->allCourses){
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
	}else{

		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(window->admin_combo), "All Courses");
	}
	g_signal_connect(window->admin_assigned, "clicked", G_CALLBACK (AdminPage::setAppSuccess), window);
	g_signal_connect(window->printSum, "clicked", G_CALLBACK (AdminPage::saveTheSum), window);
	g_signal_connect(GTK_COMBO_BOX(window->admin_combo), "changed", G_CALLBACK   (AdminPage::updateCombo), window);
	g_signal_connect(GTK_COMBO_BOX(window->summary_combo), "changed", G_CALLBACK   (AdminPage::setAppSelected), window);
	g_signal_connect(window->admin_cancel, "clicked", G_CALLBACK (AdminPage::cleanup), window);
}

//show the window to make a choice of which type of summary
void AdminPage::viewSummaryChoice(GtkWidget *widget, AdminWindow *window){
	window->showSummaryChoice(widget, window);
	
}

//view an application feature
void AdminPage::viewAnApp(GtkWidget *widget, AdminWindow *window){
	cout <<"choosing app" <<endl;
	window->chooseApp(widget, window);
}


//when clicking on an app, this will assign it successful
void AdminPage::setAppSelected(GtkWidget *widget, AdminWindow *window){
	if(window->pending){
		window->appSelected = true;
		gtk_widget_set_sensitive(window->admin_assigned, TRUE);
		gtk_widget_set_sensitive(window->printSum, TRUE);//sensitive on wrong combo box
		window->selectedIndex = gtk_combo_box_get_active (GTK_COMBO_BOX(window->summary_combo));
	}
	else{
		window->appSelected = true;
		gtk_widget_set_sensitive(window->printSum, TRUE);//sensitive on wrong combo box
		window->selectedIndex = gtk_combo_box_get_active (GTK_COMBO_BOX(window->summary_combo));
	}
}

void AdminPage::setAppSuccess(GtkWidget *widget, AdminWindow *window){
	Queue<Application>* qCopy = new Queue<Application>(window->theApp->appQueue);
	if(window->allCourses){
		qCopy = qCopy->getPendingList("all");
		qCopy = qCopy->sortAll();
		window->theApp->appQueue.assignSuccesfulCandidate((*qCopy)[window->selectedIndex]);
		window->theApp->appQueue.writeToFile();//re-wrte the text file with changes
		//REFRESH THE LIST OF PENDING APPLICANTS
		AdminPage::updateCombo(widget, window);
		//cout << *qCopy;
	}
	else{
		const gchar* theCourse;
		theCourse = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(window->admin_combo));
		qCopy = qCopy->getPendingList(theCourse);
		qCopy = qCopy->sortAll();
		window->theApp->appQueue.assignSuccesfulCandidate((*qCopy)[window->selectedIndex]);
		window->theApp->appQueue.writeToFile();//re-write the text file with changes
		//REFRESH THE LIST OF PENDING APPLICANTS
		AdminPage::updateCombo(widget, window);
		//cout << *qCopy;
	}
}

void AdminPage::updateCombo(GtkWidget* widget, AdminWindow *window){
	
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(window->summary_combo));
    //SET BOTH BUTTONS TO FALSE INCASE CHOOSING A COURSE WITHOUT APPLICATIONS
    gtk_widget_set_sensitive(window->admin_assigned, FALSE);
	gtk_widget_set_sensitive(window->printSum, FALSE);//sensitive on wrong combo box
	//gtk_widget_set_sensitive(window->printSum, TRUE);
 
	Queue<Application>* qCopy = new Queue<Application>(window->theApp->appQueue);
	//cout << *qCopy;
	if(window->pending){
		if(window->allCourses){
			cout << "Pending all courses" <<endl;
			qCopy = qCopy->getPendingList("all");

			qCopy = qCopy->sortAll();

			//qCopy->saveSummaries();//TESTING THE FUNCTION (WORKS...need a place to put this now)
			
			gtk_widget_set_sensitive(window->admin_combo, FALSE);
		}
		else{
			cout << "Pending one course" <<endl;
			const gchar* theCourse;
		 	theCourse = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(window->admin_combo));
			string courseString;
			courseString = (theCourse);
			cout << "-The course is: " << theCourse << endl;
			qCopy = qCopy->getPendingList(courseString);

			qCopy = qCopy->sortAll();
			cout << "-Here is the queue thats getting appended\n" << *qCopy;
		}
	}else{
		if(window->allCourses){
			cout << "Assigned all courses" <<endl;
			qCopy = qCopy->getAssignedList();
			qCopy = qCopy->sortAll();

		}else{
			cout << "Assigned one courses" <<endl;
			const gchar* theCourse;
		 	theCourse = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(window->admin_combo));
			string courseString;
			courseString = (theCourse);
			qCopy = qCopy->getAppsByCourse(courseString);//subset the queue to only for one course
			qCopy = qCopy->getAssignedList();//further subset the queue to only have "assigned"
			qCopy = qCopy->sortAll();//sort all

		}
		
	}
	window->saveQueue = new Queue<Application>(*qCopy);

	string s1,s2,s3,s4,s5,s6,s7 ,s8,s9,s10,s11;

	char theInput[200];
	string input[100];//string array for each Application
	Application* tmpApp = NULL;
	Application* app;
    
	
	if(qCopy != NULL){
		app = (qCopy->popFront());
		cout << "Popped Front" << endl;
		
		
	}
	
	 int i = 0;

	while(app != NULL){
		input[i] = app->getSummaryString();
		strcpy(theInput,input[i].c_str());
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(window->summary_combo), input[i].c_str());
		i++;
		app = qCopy->popFront();		
	}
	gtk_widget_show_all(window->admin_window);
}



//save the summary of apps to a file


void AdminPage::saveTheSum(GtkWidget *widget, AdminWindow *window){
	
	Queue<Application> tQ; //this si the queue that will hold the selected application
	Queue<Application>* qCopy = new Queue<Application>(window->theApp->appQueue);
	if(window->allCourses){
		cout << "summary for all\n";

		if(window->pending)//currently viewing pending applications
			qCopy = qCopy->getPendingList("all");//restrict qCopy to those that are loaded in pending
		else{
			//filter out those that are closed or pending
			qCopy = qCopy->getAssignedList();
		}

		//sort them to match the box
		qCopy = qCopy->sortAll();
		cout << "Here is the sorted queue: \n" << *qCopy <<endl;
		tQ.pushBack((*qCopy)[window->selectedIndex]);
		cout << "Here is tQ: " << tQ <<endl;
		tQ.saveSummaries();

		cout << "SUMMARY SAVED\n";
	}
	else{
		cout << "summary for one\n";
		const gchar* theCourse;
		theCourse = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(window->admin_combo));

		if(window->pending)//currently viewing pending applications
			qCopy = qCopy->getPendingList(theCourse);
		else{
			qCopy = qCopy->getAppsByCourse(theCourse);
			//filter out those that are closed or pending
			qCopy = qCopy->getAssignedList();
		}

		qCopy = qCopy->sortAll();
		cout << "Here is the sorted queue: \n" << *qCopy <<endl;
		tQ.pushBack((*qCopy)[window->selectedIndex]);
		cout << "Here is tQ: " << tQ <<endl;
		tQ.saveSummaries();
		
		cout << "SUMMARY SAVED\n";
	}
}

