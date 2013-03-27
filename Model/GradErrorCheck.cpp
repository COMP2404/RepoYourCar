#include "GradErrorCheck.h"
GradErrorCheck::GradErrorCheck(){
	
}
bool GradErrorCheck::check(GradAppData* data){
	string first,last,email,stunum,course,areas,program,supervisor;
	first = data->first;
	last = data->last;
	areas = data->areas;
	program = data->program;
	stunum = data->stuNum;
	course = data->course;
	email = data->email;
	supervisor = data->supervisor;


	bool good = true;
	
	unsigned invalidF = (first).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	unsigned invalidL = (last).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	unsigned invalidSup = (supervisor).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	string stringToFind1("@carleton.ca");
	unsigned validChars1 = (email).find(stringToFind1);
	unsigned validStu = (stunum).find_first_not_of("0123456789");
	
	

	

	//string* areas, string* program, string* supervisor
	if(areas.length() == 0){
		cout << "Study Area is empty" <<endl;
		popWindow("Choose a main study area");
		return !good;
	
	}
	else if(program.length() == 0){
		cout << "Program is empty" <<endl;
		popWindow("Choose a program");
		return !good;
		
	}



	
	

	if(course.length() == 0){
		cout << "Course is empty" <<endl;
		popWindow("Choose a course");
		return !good;
		
	}
		
	else if(first.length() == 0){
		cout << "First name is empty" <<endl;
		popWindow("First name is empty");
		return !good;
	}
                
		
	else if(last.length() == 0){
		cout << "Last Name is Empty" <<endl;
		popWindow("Last Name is Empty");
		return !good;
	}
                
	
                
	else if(email.length() == 0){
		cout << "Email is Empty" <<endl;
		popWindow("Email is Empty");
		return !good;
	}
                	
	
                
	else if(stunum.length() == 0){
		cout << "Student Number is Empty" <<endl;
		popWindow("Student Number is Empty");
		return !good;
	}

	
	
	
  
	else if (invalidF != string::npos) {
		cout << "You entered a non-alphabetical character, " << (first)[invalidF];
		cout << ", at position " << invalidF << endl;
			
		popWindow("You entered a non-alphabetical character in first name");
		return !good;
		
   	}


	
  
	else if (invalidL != string::npos) {
		cout << "You entered a non-alphabetical character, " << (last)[invalidL];
		cout << ", at position " << invalidL << endl;
		popWindow("You entered a non-alphabetical character in last name");
		return !good;
   	}

   	else if (invalidSup != string::npos) {
		cout << "You entered a non-alphabetical character, " << (supervisor)[invalidSup];
		cout << ", at position " << invalidSup << endl;
		popWindow("You entered a non-alphabetical character in supervisor");
		return !good;
   	}


	

	else if (validChars1 == string::npos) {
		cout << "Invalid e-mail address. Please enter your Carleton e-mail address (yourname@carleton.ca) to register." << endl;
		popWindow("Invalid e-mail address. Please enter your Carleton e-mail address (yourname@carleton.ca) to register.");
		return !good;
	}

	
  
	


	
	else if (validStu != string::npos) {
		cout << "You entered a character which is not a number between 0-9: " << (stunum)[validStu];
		cout << ", at position " << validStu << "Please re-enter your student number." << endl;
		popWindow("Your student number contains invalid characters");
		return !good;
    }

	else if ((stunum).length() != 9) {
		cout << "A valid student number has exactly 9 characters. Please re-enter your student number." << endl;
		popWindow("A valid student number has exactly 9 characters.");
		return !good;
	}
	



		

	

	return good;
}

void GradErrorCheck::popWindow(string s){
	error_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(error_window), GTK_WIN_POS_CENTER);	
	gtk_window_set_default_size(GTK_WINDOW(error_window), 400, 200);
	
	gtk_window_set_title(GTK_WINDOW(error_window), "ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	
	error_frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(error_window), error_frame);

	error_dismiss = gtk_button_new_with_label("Dismiss");
	gtk_widget_set_size_request(error_dismiss , 80, 35);
	gtk_fixed_put(GTK_FIXED(error_frame), error_dismiss , 100, 100);	
	const gchar* message;
	message = s.c_str();
	error_message = gtk_label_new(message);
	gtk_fixed_put(GTK_FIXED(error_frame), error_message, 10, 10); 


	gtk_widget_show_all(error_window);

	g_signal_connect(error_dismiss, "clicked", G_CALLBACK (GradErrorCheck::closePopWindow), error_window);
	
}

void GradErrorCheck::closePopWindow(GtkWidget *widget, GtkWidget *window){
	gtk_widget_destroy(window);
}