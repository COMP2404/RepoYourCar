#include "StudentPage.h"

void StudentPage::draw(){
	student_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(student_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(student_window), 550, 200);
	
	gtk_window_set_title(GTK_WINDOW(student_window), "Student Window");
	
	student_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(student_window), student_frame);

	student_edit = gtk_button_new_with_label("Edit Application");
	gtk_widget_set_size_request(student_edit , 80, 35);
	gtk_fixed_put(GTK_FIXED(student_frame), student_edit  , 20, 50);

	student_apply = gtk_button_new_with_label("New Undergrad Application");
	gtk_widget_set_size_request(student_apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(student_frame), student_apply , 150, 50);

	grad_apply = gtk_button_new_with_label("New Graduate Application");
	gtk_widget_set_size_request(grad_apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(student_frame), grad_apply , 350, 50);

	student_cancel = gtk_button_new_with_label("Cancel");
	gtk_widget_set_size_request(student_cancel, 80, 35);
	gtk_fixed_put(GTK_FIXED(student_frame), student_cancel , 60, 150);
	
	gtk_widget_show_all(student_window);

	//g_signal_connect(student_apply, "clicked", G_CALLBACK (WindowApp::makeApplication), theApp);
	//g_signal_connect(grad_apply, "clicked", G_CALLBACK (WindowApp::makeGradApplication), theApp);
	//g_signal_connect(student_cancel, "clicked", G_CALLBACK (WindowApp::closeStudentPage), theApp);
}

void StudentPage::close(){
	gtk_widget_destroy(student_window);
}

void StudentPage::chooseApp(WindowApp *theApp){
	firstName = gtk_entry_new();
	lastName = gtk_entry_new();
	appCombo =  gtk_combo_box_text_new();
	btnFind = gtk_button_new_with_label("Find Apps");
	lblFirst = gtk_label_new("First Name :");
	lblLast = gtk_label_new("Last Name :");
	student_frame = gtk_fixed_new();

	gtk_widget_set_size_request(firstName, 80, 35);
	gtk_widget_set_size_request(lastName, 80, 35);
	gtk_widget_set_size_request(btnFind, 80, 35);

	gtk_fixed_put(GTK_FIXED(student_frame), btnFind , 250, 75);
	gtk_fixed_put(GTK_FIXED(student_frame), firstName , 50, 50);
	gtk_fixed_put(GTK_FIXED(student_frame), lastName , 50, 100);
	gtk_fixed_put(GTK_FIXED(student_frame), lblFirst , 50, 35);
	gtk_fixed_put(GTK_FIXED(student_frame), lblLast , 50, 85);
	gtk_fixed_put(GTK_FIXED(student_frame), appCombo , 50, 175);

	
	
	//qCopy->getAppsByName();
	//Application *app = theApp->appQueue->getOriginal(Application*);
	//qCopy->getOriginal(Application*);
	g_signal_connect(btnFind, "clicked", G_CALLBACK(StudentPage::updateCombo), theApp);

	gtk_container_add(GTK_CONTAINER(student_window), student_frame);
	gtk_widget_show_all(student_window);
}

void StudentPage::updateCombo(GtkWidget* widget, WindowApp* theApp){
	const gchar *sfname, *slname;
	string first, last;
	sfname = gtk_entry_get_text(GTK_ENTRY(theApp->stuPage->firstName));
	slname = gtk_entry_get_text(GTK_ENTRY(theApp->stuPage->lastName));
	first = (sfname);
	last =(slname);
	theApp->stuPage->theFName = first;
	theApp->stuPage->theLName = last;

	Queue<Application> *temp;
	//
	theApp->stuPage->qCopy  = new Queue<Application>(*(theApp->appQueue.getAppsByName(first,last)));
	//theApp->stuPage->qCopy = new AppQueue(theApp->stuPage->qCopy.getAppsByName(first,last));


	temp = theApp->stuPage->qCopy;
	string s1,s2,s3,s4,s5,s6,s7 ,s8,s9,s10,s11;
	
	//int length = qCopy->size();
	
	char theInput[200];
	string input[100];//string array for each Application
	Application* tmpApp = NULL;
	Application* app;
    
	GradApp* ga = NULL;
	UndergradApp *uga = NULL;
	
	if(temp != NULL){
		app = (theApp->stuPage->qCopy->popFront());
		cout << "Popped Front" << endl;
		
		
	}
	
	 int i = 0;
	//for(int i=0; i<length; i++){
	while(app != NULL){

		input[i] = app->getSummaryString();//polymorphic method for getting the application summary		
		 
		
		//theInput = input[i];
		strcpy(theInput,input[i].c_str());
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theApp->stuPage->appCombo), theInput);
		i++;
		app = temp->popFront();	
		
	}




	
	
	g_signal_connect(GTK_COMBO_BOX(theApp->stuPage->appCombo), "changed", G_CALLBACK (StudentPage::editApp), theApp);
}
void StudentPage::editApp(GtkWidget *widget, WindowApp *theApp){
	int index;

	Queue<Application> *temp;
	temp = new Queue<Application>(*(theApp->appQueue.getAppsByName(theApp->stuPage->theFName,theApp->stuPage->theLName)));
	index = gtk_combo_box_get_active (GTK_COMBO_BOX(widget));
	
	Application *app = (*temp)[index];
	
	//app = theApp->appQueue.getOriginal(app);
	
	//cout << app->getType() << endl;
	if(app->getType() == "grad"){
		cout << "got type" <<endl;
		AppManager *appMan = new AppManager(true, theApp);
		appMan->fillInData(app, theApp);
	}
	else{
		AppManager *appMan = new AppManager(false, theApp);
		appMan->fillInUData(app, theApp);
	}
	
}