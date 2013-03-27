#include "UGradErrorCheck.h"
UGradErrorCheck::UGradErrorCheck(){

}
bool UGradErrorCheck::check(UGradAppData* data){
	string first,last,email,major,stunum,gpa,mgpa,year,course;
	first = data->first;
	last = data->last;
	major = data->gmajor;
	stunum = data->stuNum;
	gpa = data->GPA;
	mgpa = data->CGPA;
	course = data->course;
	year = data->year;
	email = data->email;

	bool good = true;
	int mg;
	int cg;
	int yr;
	unsigned invalidF = (first).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	unsigned invalidL = (last).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'");
	
	string stringToFind1("@carleton.ca");
	unsigned validChars1 = (email).find(stringToFind1);
	unsigned invalidE = (major).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ- ");
	unsigned validStu = (stunum).find_first_not_of("0123456789");
	unsigned validGPA = (gpa).find_first_not_of("0123456789");
	unsigned validCGPA = (mgpa).find_first_not_of("0123456789");
	
	
		mg = atoi(mgpa.c_str());	
		cg = atoi(gpa.c_str());
		yr = atoi(year.c_str());

		if(mgpa.length() == 0){
			cout << "MGPA is empty" <<endl;
			popWindow("MGPA is empty");
			return !good;
		}
                
		else if(gpa.length() == 0){
			cout << "GPA is empty" <<endl;
			popWindow("GPA is empty");
			return !good;
		}

		else if(year.length() == 0){
			cout << "year is Empty" <<endl;
			popWindow("year is Empty");
			return !good;
		}
               
		else if(major.length() == 0){
			cout << "Major is Empty" <<endl;
			popWindow("Major is Empty");
			return !good;
		}
		else if (validGPA != string::npos) {
			cout << "You entered a non-alphabetical character, " << (gpa)[validGPA];
			cout << ", at position " << validGPA << endl;
			
			popWindow("Please Enter a valid GPA");
			return !good;
		
  		}
		else if (validCGPA != string::npos) {
			cout << "You entered a non-alphabetical character, " << (mgpa)[validCGPA];
			cout << ", at position " << validCGPA << endl;
				
			popWindow("Please Enter a valid CGPA");
			return !good;
			
	   	}
		
			
		else if(mg < 0 || mg > 12){
			popWindow("Enter a GPA between 0 and 12");
			return !good;
		}
		else if(cg < 0 || cg > 12){
			popWindow("Enter a CGPA between 0 and 12");
			return !good;
		}
		else if (yr < 1 || yr > 4) {
			cout << "Year standing must be either 1, 2, 3, or 4. Please try again" << endl; 
			popWindow("Year standing must be either 1, 2, 3, or 4.");
			return !good;
		}
		else if (invalidE != string::npos) {
			cout << "You entered a non-alphabetical character, " << (major)[invalidE];
			cout << ", at position " << invalidE << endl;
			popWindow("You entered a non-alphabetical character in major");
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
	
	cout << "Its getting to here" << endl;


		

	

	return good;
}



void UGradErrorCheck::popWindow(string s){
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

	g_signal_connect(error_dismiss, "clicked", G_CALLBACK (UGradErrorCheck::closePopWindow), error_window);
	
}

void UGradErrorCheck::closePopWindow(GtkWidget *widget, GtkWidget *window){
	gtk_widget_destroy(window);
}