TO DO:

FIXES--------------

** Seperate Window App into smaller classes
	- these classes should be small atomic units of forms and windows that can be resued across the application

** The View needs a manager class that takes care of which classes and functions to call. The WindowApp
	should not be the one to take care of calling functions in order. The functions should return, and the
	manager should decide which functions to call based on that.

**The Control class should not have any knowledge of the nitty gritty of the UI. The get info function should
be able to take in data from any location. To solve this, the View should pass through an object containing the data.

**Seperate the control class functions such as error checking and loading into seperate classes. The control class should
not have any main functionality.

** make sure that there is an option for the TA to have no experience necessary

** fix up error checking feedback, allow related courses to accept "comp1001" for instance

** error checking should be FORM specific as well as FORMAT specific

ASSIGNMENT 4 IMPLEMENTATIONS---------

----Edit Application Feature----

-only pending ones(could use get pending for all courses like in sortAll)
-only their own application
  -must enter personal info and create a getAppByName or something similar
  -we are aloud to trust the user to enter their own name (no credentials require)
-cancel application option
  -changes the application.status to "closed" (using Application::operator-() )
-submit changes option
  -will call a function that replaces the aplication at a specified location, 
   using the queues operator[]
-cancel button
  -aborts changes

----View Summary Feature----

-must be able to select a specific app and save it to permanent storage
  -this will save all information in the application (not just basic info)

----Assign Succesful Candidate Option----

-will be accessed through the admin window
-sets the selected applications status to "assigned"
  -using the Application::operator+() 
-gets the rest of the applications from that person and sets their status to "closed"

----Operator Testing File----

-finish the functions for testing each of AppQueue's overloaded operators

MARKS TO GET BACK---------------------------

-2 UML does not show model / view disconnection
-2 report appears in a combo box
-2 tab sequence is weird
-5 summary choosing from grad or undergrad
-2 sorting not working correctly
-2 course names hard coded in AppQueue
-2 view all was from general information only
--------------
-17

best possible mark of 74%










======READ ME========
(Read-Only)
=====================
-program graphics built on GTKmm library
-packaged using `pkg-config gtkmm-3.0 --cflags --libs`
-compile using Makefile's "make" command
-to run the executable:./cuTaes
or  "make run" command in shell		

The program will load applications from 
file. If the file is missing it will simply start
a new one. 

The UML provided illustrates the implementation of
inheritance/composition and other features/functions.

To create an application, launch the program (following 
instructions above), select 'Student' and follow the 
steps(input the application information).

To view applications, select "Admin" from the main menu.
You will be prompted for a course for which you would like to view the applicants or
an option to view all applications.


<OperatorTestFile>
compile all objects with
	'make' command

compile the main with:
	'make test' command

run the tests with
	./test || 'make runtest' command

</OperatorTestFile>
		
*
*
*
*
*
*
*
</readme>
