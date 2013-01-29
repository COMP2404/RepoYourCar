#include <gtk/gtk.h>
#include "main.h"
//`pkg-config gtkmm-3.0 --cflags --libs`

using namespace std;
char buf[5];
void application(GtkWidget *widget, GtkWidget *frame)
{
	int cont = 0;
	GtkWidget *entry = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(frame), entry, 50, 120);
	gtk_widget_show_all(frame);
	/*while(cont == 0){

	
		if(errorCheck() == 1){
			
			cont = 1;
		}
		else if (errorCheck() == 0){
			cout << "You fucked up bro!";
	
		}
  
	}*/
  
}

void admin(GtkWidget *widget, gpointer label)
{
  //count--;

  //sprintf(buf, "%d", count);
 //gtk_label_set_text(GTK_LABEL(label), buf);
}

int errorCheck(){

}
void callback()
{
	/*const gchar * s1 = gtk_entry_get_text(GTK_ENTRY(num1));
	const gchar * s2 = gtk_entry_get_text(GTK_ENTRY(num2));
	int n1 = atoi(s1), n2=atoi(s2);
	n1=abs(n1), n2=abs(n2); // GCD defined to return non-negative value
	int i; for ( i=(n1>n2?n1:n2); i>=1; i-- ) if ( n1/i*i==n1 && n2/i*i==n2 ) break;
	char s3[32]; snprintf(s3,32,"%d",i);
	gtk_entry_set_text(GTK_ENTRY(mcdt),s3);*/
}

int main(int argc, char** argv) {

	/////////////////////////////////////////////////////
	//-----------Declaration of all the widgets------////
	/////////////////////////////////////////////////////
	GtkWidget *label;
	GtkWidget *window, *theApp;
	GtkWidget *frame;
	GtkWidget *apply;
	GtkWidget *login;
	
	// initialize GTK+
	gtk_init(&argc, &argv);
	

	/////////////////////////////////////////////////////
	//-----------Create the window ------------------////
	/////////////////////////////////////////////////////
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
	gtk_window_set_title(GTK_WINDOW(window), "Application Center");
	

	/////////////////////////////////////////////////////
	//-----------Add frame onto window---------------////
	/////////////////////////////////////////////////////
	frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), frame);
	

	/////////////////////////////////////////////////////
	//Make the application button and add to frame---////
	/////////////////////////////////////////////////////
	apply = gtk_button_new_with_label("Apply");
	gtk_widget_set_size_request(apply, 80, 35);
	gtk_fixed_put(GTK_FIXED(frame), apply, 50, 20);
	
	/////////////////////////////////////////////////////
	//------Make the login button and add to frame---////
	/////////////////////////////////////////////////////
	login = gtk_button_new_with_label("Login");
	gtk_widget_set_size_request(login, 80, 35);
	gtk_fixed_put(GTK_FIXED(frame), login, 50, 80);

	/////////////////////////////////////////////////////
	//------Make the Prompt Label and add to frame---////
	/////////////////////////////////////////////////////
	label = gtk_label_new("Click Apply to Choose Your Courses");
	gtk_fixed_put(GTK_FIXED(frame), label, 190, 58); 
	
	/////////////////////////////////////////////////////
	//----------Show all the widgets on the window---////
	/////////////////////////////////////////////////////
	gtk_widget_show_all(window);
	


	/////////////////////////////////////////////////////
	//Connect signals with each button as well as close////
	/////////////////////////////////////////////////////
	g_signal_connect(window, "destroy",
	G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect(apply, "clicked", 
	G_CALLBACK(application), frame);

	g_signal_connect(login, "clicked", 
	G_CALLBACK(admin), frame);

	gtk_main();

	return 0;
}



 
