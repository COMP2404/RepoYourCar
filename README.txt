ACKNOWLEDGEMENTS AND WARNINGS:
--------------------------------------

Dear T.A.

We sincerely apologize in advance to you for the time it may take to understand some of the implementation. 
We realize it's horribly structured, not all implemented and generally confusing. So we would like to save you some time and explain some of the things you may find yourself questioning. 

In our previous assignment, we actually had all of the structure well put together, but the design of the program needed to be COMPLETELY overhauled to incorporate MVC. We went from about 10 classes to well over 50. Unfortunately, this took much much longer than expected, and introduced more problems than we physically had time to resolve. Even staying up until past 3 A.M. every single day for the better part of the last two weeks. As I'm writing this, it's 6:43 in the morning and I've been up for the better part of the last 48 hours, mostly working on this assignment. Just so you do not get overwhelmed with frustration, I will include a list of things that are confusing and just plain don't work.

1. When getting a summary in the admin page, you must click on the top Combo box first, then hover your mouse over the small one beneath it to load them. This is not at all intuitive, and we would chage it given more time.

2. The Edit an Application Feature is abysmal. We literally made negative progress on this one tonight, because of phantom Seg Faults. Sometimes, we would not even change the code, and we would get a seg fault, then comment out the block, and slowly uncomment it and it would disappear!! You can imagine how I feel as I'm writing this....
Most of the info is loaded into the app, and the form for making the app is re-used which is awesome, but we kept getting so many phantom seg faults, we just could not finish the implementation. It will not replace the old app, but push the new one onto the queue.

3. The Process is not killed when the X is clicked

4. The error checking has stopped working on the main form. It is still implemented, but the dialog boxes do not show up anymore. It will also seg fault if any field is left blank.

5. Having said this, the operators and the test file are beautiful. And if you can look past the subtle imperfections, all of the
functionality and assignment requirements are present and working (minus half of the edit an application feature).

Given the above map to the depths of our application, we hope that you can overcome the partial confusion and assess
the functionality and working features for what they are.







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
