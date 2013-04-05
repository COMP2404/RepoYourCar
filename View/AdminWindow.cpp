#include "AdminWindow.h"

void AdminWindow::draw(){
	admin_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(admin_window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(admin_window), 400, 300);
	gtk_window_set_title(GTK_WINDOW(admin_window), "Admin Window");

	admin_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(admin_window), admin_frame);

	admin_viewSummary = gtk_button_new_with_label("View Summary Of Pending Applications");
	gtk_widget_set_size_request(admin_viewSummary, 150, 35);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_viewSummary , 100, 50);

	admin_assigned = gtk_button_new_with_label("View Summary Of Assigned Applications");
	gtk_widget_set_size_request(admin_assigned, 150, 35);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_assigned , 100, 110);

	viewApp = gtk_button_new_with_label("View an Application");
	gtk_widget_set_size_request(viewApp, 150, 35);
	gtk_fixed_put(GTK_FIXED(admin_frame), viewApp , 100, 170);

	admin_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(admin_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_cancel , 50, 250);
	
	gtk_widget_show_all(admin_window);

}

void AdminWindow::showSummary(){

	gtk_widget_destroy(admin_frame);
	admin_frame = gtk_fixed_new();
	
	//create a combo box that will hold the queue of application summaries


	admin_combo =  gtk_combo_box_text_new();
	
	admin_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(admin_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_cancel , 100, 150);
	gtk_fixed_put(GTK_FIXED(admin_frame), admin_combo, 50, 50);
	summary_combo =  gtk_combo_box_text_new();
	gtk_fixed_put(GTK_FIXED(admin_frame), summary_combo, 50, 100);
	
	gtk_container_add(GTK_CONTAINER(admin_window), admin_frame);
	
	gtk_widget_show_all(admin_window);

	

	char text[800];
	string courses[800];



	ifstream inFile("courses.txt", ios::in);
	if (!inFile) {
		cout<<"Could not open file"<<endl;
		exit(1);
	}	
	while (!inFile.eof()) {
		inFile.getline(text, 800);
		
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(admin_combo), text);   //append each summary to the combo box
	}
}


void AdminWindow::showSummaryChoice(GtkWidget *widget, AdminWindow *window){

	//allow the user to choose which summary type they would like to view

	window->sum = new SummaryChoiceWindow();

	window->sum->draw();
	if(widget == window->admin_viewSummary){
		window->pending = true;
		
		cout << "Pending eh" << endl;

	}
	else{
		window->pending = false;
		cout << "Assigned" << endl;
	}
	window->appSelected = false;
	g_signal_connect(window->sum->btnOneCourse, "clicked", G_CALLBACK (AdminWindow::closeSummaryChoice), window);
	g_signal_connect(window->sum->btnAllCourses, "clicked", G_CALLBACK   (AdminWindow::closeSummaryChoice), window);
	
}

void AdminWindow::closeSummaryChoice(GtkWidget *widget, AdminWindow *window){
	if(widget == window->sum->btnOneCourse)
		window->allCourses = false;
	else{
		window->allCourses = true;
		
	}
		
	gtk_widget_destroy(window->sum->summary_choice_window);
	AdminPage::viewSummary(widget,window);
}



void AdminWindow::chooseApp(GtkWidget* widget, AdminWindow *window){
	//called when the user wants to find an application to view



	gtk_widget_destroy(window->admin_frame);
	window->admin_frame = gtk_fixed_new();

	window->firstName = gtk_entry_new();
	window->lastName = gtk_entry_new();
	window->stuNum = gtk_entry_new();
	window->appNum = gtk_entry_new();
	window->appCombo =  gtk_combo_box_text_new();
	window->btnFind = gtk_button_new_with_label("Find Apps");
	window->lblFirst = gtk_label_new("First Name :");
	window->lblLast = gtk_label_new("Last Name :");
	window->lblAppNum = gtk_label_new("App Number :");
	window->lblStuNum = gtk_label_new("Student Number :");
	

	gtk_widget_set_size_request(window->firstName, 80, 35);
	gtk_widget_set_size_request(window->lastName, 80, 35);
	gtk_widget_set_size_request(window->appNum, 80, 35);
	gtk_widget_set_size_request(window->stuNum, 80, 35);
	gtk_widget_set_size_request(window->btnFind, 80, 35);

	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->btnFind , 250, 75);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->firstName , 50, 50);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->lastName , 50, 100);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->stuNum , 50, 150);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->appNum , 50, 200);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->lblFirst , 50, 35);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->lblLast , 50, 85);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->lblStuNum , 50, 135);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->lblAppNum , 50, 185);
	gtk_fixed_put(GTK_FIXED(window->admin_frame), window->appCombo , 50, 250);

	g_signal_connect(window->btnFind, "clicked", G_CALLBACK(AdminWindow::updateAppCombo), window);

	gtk_container_add(GTK_CONTAINER(window->admin_window), window->admin_frame);
	gtk_widget_show_all(window->admin_window);
}


void AdminWindow::updateAppCombo(GtkWidget* widget, AdminWindow* window){
	//this will update the combo box which will allow the user to click on an app to view



	cout << "Updating admin find combo" << endl;
	const gchar *sfname, *slname, *sStuNum, *sAppNum;
	string first, last, stuNum, appNum="-1";



	sfname = gtk_entry_get_text(GTK_ENTRY(window->firstName));
	slname = gtk_entry_get_text(GTK_ENTRY(window->lastName));
	sStuNum = gtk_entry_get_text(GTK_ENTRY(window->stuNum));
	sAppNum = gtk_entry_get_text(GTK_ENTRY(window->appNum));
	first = (sfname);
	last =(slname);
	stuNum =(sStuNum);
	appNum =(sAppNum);
	window->theFName = first;
	window->theLName = last;
	window->theAppNum = atoi(appNum.c_str());
	if(appNum == "")
		window->theAppNum = -1;
	window->theStuNum = sStuNum;
	Queue<Application> *temp;

	cout << "this is the app num " + window->theAppNum <<endl;
	if(window->theFName != ""){
		if(window->theLName != ""){
			//if first and last name are non-empty

			window->qCopy  = new Queue<Application>(*(window->theApp->appQueue.getAppsByName(window->theFName,window->theLName)));
			cout << "both names" <<endl;
			//if stuNum is not empty
			if(window->theStuNum != ""){
				window->qCopy = new Queue<Application>(*(window->qCopy->getAppsByStuNum(window->theStuNum)));
				cout << "stu Num" <<endl;
			}

			//if app num is not empty
			if(window->theAppNum != -1){

				window->qCopy = new Queue<Application>(*(window->qCopy->getAppsByAppNum(window->theAppNum)));
				cout << "App num" + window->theAppNum <<endl;
			}


		}else{
			//if first is non-empty but last is empty


			window->qCopy  = new Queue<Application>(*(window->theApp->appQueue.getAppsByFirst(window->theFName)));
			cout << "first name" <<endl;


			if(window->theStuNum != ""){
				window->qCopy = new Queue<Application>(*(window->qCopy->getAppsByStuNum(window->theStuNum)));
				cout << "stu num" <<endl;
			}
			if(window->theAppNum != -1){
				window->qCopy = new Queue<Application>(*(window->qCopy->getAppsByAppNum(window->theAppNum)));
				cout << "app num" <<endl;
			}


		}



	}


	//if first name is empty
	else if(window->theFName == ""){

		//if first name is empty and last name is empty
		if(window->theLName == ""){



			//if they are both empty, then get queue from main appqueue
			if(window->theStuNum != ""){
				window->qCopy = new Queue<Application>(*(window->theApp->appQueue.getAppsByStuNum(window->theStuNum)));
				cout << "stu num" <<endl;

				if(window->theAppNum != -1){
					window->qCopy = new Queue<Application>(*(window->qCopy->getAppsByAppNum(window->theAppNum)));
					cout << "app num" <<endl;
				}


			}

			else {

				//if stunum is empty then get appnum queue from main
				window->qCopy = new Queue<Application>(*(window->theApp->appQueue.getAppsByAppNum(window->theAppNum)));
				cout << "app num" <<endl;
			}

		}else{
			//last name is non-empty


			window->qCopy  = new Queue<Application>(*(window->theApp->appQueue.getAppsByLast(window->theLName)));
			cout << "last name" <<endl;

			if(window->theStuNum != ""){
				window->qCopy = new Queue<Application>(*(window->qCopy->getAppsByStuNum(window->theStuNum)));
				cout << "stu num" <<endl;
			}
			if(window->theAppNum != -1){
				window->qCopy = new Queue<Application>(*(window->qCopy->getAppsByAppNum(window->theAppNum)));
				cout << "app num" <<endl;
			}
		}
	}
	window->qCombo = new Queue<Application>(*(window->qCopy));

	



	temp = window->qCopy;

	
	char theInput[200];
	string input[100];//string array for each Application
	Application* tmpApp = NULL;
	Application* app;


	if(temp != NULL){
		app = (window->qCopy->popFront());
		cout << "Popped Front" << endl;	
	}
	
	 int i = 0;

	while(app != NULL){
		input[i] = app->getSummaryString();
		strcpy(theInput,input[i].c_str());
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(window->appCombo), theInput);
		i++;
		app = temp->popFront();		
	}
	g_signal_connect(GTK_COMBO_BOX(window->appCombo), "changed", G_CALLBACK (AdminWindow::showApp), window);
}

void AdminWindow::showApp(GtkWidget *widget, AdminWindow *window){
	int theIndex = 0;
	gchar *s1,s2,s3,s4;
	bool type[100];
	string checkSummary = "";
	int cycleIndex = 0;
	string stringToFind1("Undergrad");
	
	Queue<Application> *temp, *cycle, *tempCycle;

	temp = window->qCombo;
	cycle = new Queue<Application>(*(window->qCombo));
	tempCycle = new Queue<Application>(*(window->qCombo));
	Application *checkApp;
	
	if(tempCycle != NULL){
		checkApp = (tempCycle->popFront());
	}
	
	int tempIndex = 0;
	
	while(checkApp != NULL){
		checkSummary = checkApp->getSummaryString();
		unsigned validChars1 = (checkSummary).find(stringToFind1);
		if (validChars1 == string::npos) {
			window->theApp->cyclerTypes[tempIndex] = true;    //an array of booleans that hold the type of the applications in the queue
		}
		else if(validChars1 != string::npos){
			window->theApp->cyclerTypes[tempIndex] = false;
		}
		tempIndex++;
		checkApp = tempCycle->popFront();	
		
	}
	if(tempIndex >0){
		window->theApp->canCycle = true;
		cout << "CAN CYCLE THAT SHIT" << endl;
	}else{
		window->theApp->canCycle = false;
	}
	theIndex = gtk_combo_box_get_active(GTK_COMBO_BOX(window->appCombo));
	Application *app = (*temp)[theIndex];
	gchar *appType = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
	
	string theType;
	theType = (appType);
	cout << theType << endl;
	
	unsigned validChars1 = (theType).find(stringToFind1);

	if (validChars1 == string::npos) {
			cout<< "Grad app clicked" <<endl;
			gtk_widget_destroy(window->admin_window);
			window->theApp->canEdit = false;                      //disallow the user from making edits to the app
			window->theApp->cycle = new Queue<Application>(*(cycle)); //pass through the queue of loaded apps matching the critera to cycle through
			window->theApp->cycler = 0;
			window->theApp->cyclerSize = tempIndex;
			AppManager *appMan = new AppManager(true, window->theApp); //view the new app
			appMan->fillInData(app, window->theApp);  //fill in the data
	}
	else if(validChars1 != string::npos){
			cout<< "UnderGrad app clicked" <<endl;
			gtk_widget_destroy(window->admin_window);
			window->theApp->canEdit = false;
			window->theApp->cycle = cycle;
			window->theApp->cycler = 0;
			window->theApp->cyclerSize = tempIndex;
			AppManager *appMan = new AppManager(false, window->theApp);		
			appMan->fillInUData(app, window->theApp);		
	}
	else{

	}

	
}
