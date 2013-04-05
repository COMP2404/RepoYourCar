#include "UGradSubmitWindow.h"
void UGradSubmitWindow::draw(UGradSubmitWindow *theApp){
		theApp->submitWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_position(GTK_WINDOW(theApp->submitWindow), GTK_WIN_POS_CENTER);
	
		gtk_window_set_default_size(GTK_WINDOW(theApp->submitWindow), 250, 100);
		gtk_window_set_title(GTK_WINDOW(theApp->submitWindow), "Submit Page");
	
	

		/////////////////////////////////////////////////////
		//-----------Add frame onto window---------------////
		/////////////////////////////////////////////////////
		theApp->submitFrame = gtk_fixed_new();
	

		gtk_container_add(GTK_CONTAINER(theApp->submitWindow), theApp->submitFrame);

		//submission page
		theApp->submitFinish = gtk_button_new_with_label("Finish");
		theApp->submitRepeat = gtk_button_new_with_label("Make Another");

	
		gtk_widget_set_size_request(theApp->submitFinish, 80, 35);
		gtk_fixed_put(GTK_FIXED(theApp->submitFrame), theApp->submitFinish, 30, 20);

	
		gtk_widget_set_size_request(theApp->submitRepeat, 80, 35);
		gtk_fixed_put(GTK_FIXED(theApp->submitFrame), theApp->submitRepeat, 150, 20);

		gtk_widget_show_all(theApp->submitWindow);

		//g_signal_connect (theApp->submitFinish, "clicked", G_CALLBACK (Control::killSubmitWindow), theApp);
		//g_signal_connect (theApp->submitRepeat, "clicked", G_CALLBACK (Control::submitToRepeat), theApp);

		submit();
}

void UGradSubmitWindow::submit(){
	cout<<"submitted"<<endl;
	
}
void UGradSubmitWindow::close(GtkWidget *widget, WindowApp *page){
	cout<<"closing"<<endl;
	
	if(widget != page->uSubmitWindow->submitRepeat)
		UnderGradAppPage::close(widget,page);

	gtk_widget_destroy(page->uSubmitWindow->submitWindow);
}
