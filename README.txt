ACKNOWLEDGEMENTS AND WARNINGS:
--------------------------------------

Dear T.A.

=======================Things to be aware of with regards to our implementation:=========================

When viewing all applications you must select 'ALL' in the combo_box for selecting the course.

In all cases, the combo_box with the list of queried applications will be filled upon hovering the mouse over it.

this run-time error: "(cuTaes:5249): GLib-GObject-CRITICAL **: g_object_notify: assertion `G_IS_OBJECT (object)' failed"
despite its appearence, is not harmful to our implementation. GTK just likes to throw a fit when it's told what to do.

A weird tab sequence exists IFF you click on the select a course combo box more than once in a single creation of an application
The version of gtk that we are using is known for having many quirky imperfections. The tab sequence is properly resolved upon finishing (or cancelling) the application in which it was changed.

When saving the summary of a selected application, it is logged (appended) to the Summaries.txt file.

====================================================UML:==================================================

We apologize for the lack of clearity as we have many classes.

It was not possible to italisize the Application class with the program that we used, so instead it is clearly
listed as Abstract

================================================OTHER NOTES===============================================

everything (including uml and Summaries.txt) is better understood/appreciated in fullscreen

We are extremely pleased with the outcome of this assignment, we hope you find all the information you need
here and enjoy grading it. Thanks!

=============================================READ ME===============================================
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~(Read-Only)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
===================================================================================================
*
*
*
*
*
*
*
*
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
=============================================</readme>===============================================
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
=====================================================================================================
