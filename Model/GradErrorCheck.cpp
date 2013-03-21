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
		//WindowApp::popWindow("Choose a main study area", theApp);
		return !good;
	
	}
	else if(program.length() == 0){
		cout << "Program is empty" <<endl;
		//WindowApp::popWindow("Choose a program", theApp);
		return !good;
		
	}



	
	

	if(course.length() == 0){
		cout << "Course is empty" <<endl;
		//WindowApp::popWindow("Choose a course", theApp);
		return !good;
		
	}
		
	else if(first.length() == 0){
		cout << "First name is empty" <<endl;
		//WindowApp::popWindow("First name is empty", theApp);
		return !good;
	}
                
		
	else if(last.length() == 0){
		cout << "Last Name is Empty" <<endl;
		//WindowApp::popWindow("Last Name is Empty", theApp);
		return !good;
	}
                
	
                
	else if(email.length() == 0){
		cout << "Email is Empty" <<endl;
		//WindowApp::popWindow("Email is Empty", theApp);
		return !good;
	}
                	
	
                
	else if(stunum.length() == 0){
		cout << "Student Number is Empty" <<endl;
		//WindowApp::popWindow("Student Number is Empty", theApp);
		return !good;
	}

	
	
	
  
	else if (invalidF != string::npos) {
		cout << "You entered a non-alphabetical character, " << (first)[invalidF];
		cout << ", at position " << invalidF << endl;
			
		//WindowApp::popWindow("You entered a non-alphabetical character in first name", theApp);
		return !good;
		
   	}


	
  
	else if (invalidL != string::npos) {
		cout << "You entered a non-alphabetical character, " << (last)[invalidL];
		cout << ", at position " << invalidL << endl;
		//WindowApp::popWindow("You entered a non-alphabetical character in last name", theApp);
		return !good;
   	}

   	else if (invalidSup != string::npos) {
		cout << "You entered a non-alphabetical character, " << (supervisor)[invalidSup];
		cout << ", at position " << invalidSup << endl;
		//WindowApp::popWindow("You entered a non-alphabetical character in supervisor", theApp);
		return !good;
   	}


	

	else if (validChars1 == string::npos) {
		cout << "Invalid e-mail address. Please enter your Carleton e-mail address (yourname@carleton.ca) to register." << endl;
		//WindowApp::popWindow("Invalid e-mail address. Please enter your Carleton e-mail address (yourname@carleton.ca) to register.", theApp);
		return !good;
	}

	
  
	


	
	else if (validStu != string::npos) {
		cout << "You entered a character which is not a number between 0-9: " << (stunum)[validStu];
		cout << ", at position " << validStu << "Please re-enter your student number." << endl;
		//WindowApp::popWindow("Your student number contains invalid characters", theApp);
		return !good;
    }

	else if ((stunum).length() != 9) {
		cout << "A valid student number has exactly 9 characters. Please re-enter your student number." << endl;
		//WindowApp::popWindow("A valid student number has exactly 9 characters.", theApp);
		return !good;
	}
	



		

	

	return good;
}