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
			//WindowApp::popWindow("MGPA is empty", theApp);
			return !good;
		}
                
		else if(gpa.length() == 0){
			cout << "GPA is empty" <<endl;
			//WindowApp::popWindow("GPA is empty", theApp);
			return !good;
		}

		else if(year.length() == 0){
			cout << "year is Empty" <<endl;
			//WindowApp::popWindow("year is Empty", theApp);
			return !good;
		}
               
		else if(major.length() == 0){
			cout << "Major is Empty" <<endl;
			//WindowApp::popWindow("Major is Empty", theApp);
			return !good;
		}
		else if (validGPA != string::npos) {
			cout << "You entered a non-alphabetical character, " << (gpa)[validGPA];
			cout << ", at position " << validGPA << endl;
			
			//WindowApp::popWindow("Please Enter a valid GPA", theApp);
			return !good;
		
  		}
		else if (validCGPA != string::npos) {
			cout << "You entered a non-alphabetical character, " << (mgpa)[validCGPA];
			cout << ", at position " << validCGPA << endl;
				
			//WindowApp::popWindow("Please Enter a valid CGPA", theApp);
			return !good;
			
	   	}
		
			
		else if(mg < 0 || mg > 12){
			//WindowApp::popWindow("Enter a GPA between 0 and 12", theApp);
			return !good;
		}
		else if(cg < 0 || cg > 12){
			//WindowApp::popWindow("Enter a CGPA between 0 and 12", theApp);
			return !good;
		}
		else if (yr < 1 || yr > 4) {
			cout << "Year standing must be either 1, 2, 3, or 4. Please try again" << endl; 
			//WindowApp::popWindow("Year standing must be either 1, 2, 3, or 4.", theApp);
			return !good;
		}
		else if (invalidE != string::npos) {
			cout << "You entered a non-alphabetical character, " << (major)[invalidE];
			cout << ", at position " << invalidE << endl;
			//WindowApp::popWindow("You entered a non-alphabetical character in major", theApp);
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
	
	cout << "Its getting to here" << endl;


		

	

	return good;
}