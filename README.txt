TO DO:
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



marks to get back:
-2 report appears in a combo box
-2 tab sequence is weird
-5 summary choosing from grad or undergrad
-2 sorting not working correctly
-2 course names hard coded in AppQueue
-2 view all was from general information only










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
