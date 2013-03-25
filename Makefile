OBJECTS = main.o WindowApp.o Application.o Student.o Control.o AppQueue.o CourseQueue.o JobQueue.o Job.o Course.o GradStudent.o UndergradStudent.o GradApp.o UndergradApp.o AdminPage.o AdminManager.o AdminWindow.o SummaryChoiceWindow.o MainMenu.o ErrorWindow.o GradAppPage.o UnderGradAppPage.o StudentPage.o AppManager.o GradForm.o UnderGradForm.o RelatedCoursesOneForm.o RelatedCoursesTwoForm.o WorkExperienceForm.o Form.o AppPage.o GradErrorCheck.o UGradErrorCheck.o GradAppData.o UGradAppData.o GradSubmitWindow.o UGradSubmitWindow.o RelatedOneData.o RelatedTwoData.o WorkExperienceData.o
cuTaes: $(OBJECTS)
		g++ $(OBJECTS) -o cuTaes `pkg-config gtkmm-3.0 --cflags --libs` 

main.o:		main.cpp main.h
		g++ -c main.cpp  `pkg-config gtkmm-3.0 --cflags --libs`


WindowApp.o:	View/WindowApp.cpp View/WindowApp.h
		g++ -c View/WindowApp.cpp  `pkg-config gtkmm-3.0 --cflags --libs`

Control.o:	Control/Control.cpp Control/Control.h
		g++ -c Control/Control.cpp  `pkg-config gtkmm-3.0 --cflags --libs`

AppQueue.o:	Model/AppQueue.cpp Model/AppQueue.h
		g++ -c Model/AppQueue.cpp

AdminManager.o: View/AdminManager.cpp View/AdminManager.h
		g++ -c View/AdminManager.cpp `pkg-config gtkmm-3.0 --cflags --libs`

AppManager.o: View/AppManager.cpp View/AppManager.h
		g++ -c View/AppManager.cpp `pkg-config gtkmm-3.0 --cflags --libs`

AdminPage.o: View/AdminPage.cpp View/AdminPage.h
		g++ -c View/AdminPage.cpp `pkg-config gtkmm-3.0 --cflags --libs`

AdminWindow.o: View/AdminWindow.cpp View/AdminWindow.h
		g++ -c View/AdminWindow.cpp `pkg-config gtkmm-3.0 --cflags --libs`

AppPage.o: View/AppPage.cpp View/AppPage.h
		g++ -c View/AppPage.cpp `pkg-config gtkmm-3.0 --cflags --libs`

GradAppPage.o: View/GradAppPage.cpp View/GradAppPage.h
		g++ -c View/GradAppPage.cpp `pkg-config gtkmm-3.0 --cflags --libs`

UnderGradAppPage.o: View/UnderGradAppPage.cpp View/UnderGradAppPage.h
		g++ -c View/UnderGradAppPage.cpp `pkg-config gtkmm-3.0 --cflags --libs`

GradForm.o: View/GradForm.cpp View/GradForm.h
		g++ -c View/GradForm.cpp `pkg-config gtkmm-3.0 --cflags --libs`

UnderGradForm.o: View/UnderGradForm.cpp View/UnderGradForm.h
		g++ -c View/UnderGradForm.cpp `pkg-config gtkmm-3.0 --cflags --libs`

Form.o: View/Form.cpp View/Form.h
		g++ -c View/Form.cpp `pkg-config gtkmm-3.0 --cflags --libs`

StudentPage.o: View/StudentPage.cpp View/StudentPage.h
		g++ -c View/StudentPage.cpp `pkg-config gtkmm-3.0 --cflags --libs`

ErrorWindow.o: View/ErrorWindow.cpp View/ErrorWindow.h
		g++ -c View/ErrorWindow.cpp `pkg-config gtkmm-3.0 --cflags --libs`

MainMenu.o: View/MainMenu.cpp View/MainMenu.h
		g++ -c View/MainMenu.cpp `pkg-config gtkmm-3.0 --cflags --libs`

RelatedCoursesOneForm.o: View/RelatedCoursesOneForm.cpp View/RelatedCoursesOneForm.h
		g++ -c View/RelatedCoursesOneForm.cpp `pkg-config gtkmm-3.0 --cflags --libs`

RelatedCoursesTwoForm.o: View/RelatedCoursesTwoForm.cpp View/RelatedCoursesTwoForm.h
		g++ -c View/RelatedCoursesTwoForm.cpp `pkg-config gtkmm-3.0 --cflags --libs`

WorkExperienceForm.o: View/WorkExperienceForm.cpp View/WorkExperienceForm.h
		g++ -c View/WorkExperienceForm.cpp `pkg-config gtkmm-3.0 --cflags --libs`

GradSubmitWindow.o: View/GradSubmitWindow.cpp View/GradSubmitWindow.h
		g++ -c View/GradSubmitWindow.cpp `pkg-config gtkmm-3.0 --cflags --libs`

UGradSubmitWindow.o: View/UGradSubmitWindow.cpp View/UGradSubmitWindow.h
		g++ -c View/UGradSubmitWindow.cpp `pkg-config gtkmm-3.0 --cflags --libs`

CourseQueue.o:	Model/CourseQueue.cpp Model/CourseQueue.h
		g++ -c Model/CourseQueue.cpp

JobQueue.o:	Model/JobQueue.cpp Model/JobQueue.h
		g++ -c Model/JobQueue.cpp

Queue.o:	Model/Queue.cpp Model/Queue.h
		g++ -c Model/Queue.cpp	

Application.o:	Model/Application.cpp Model/Application.h
		g++ -c Model/Application.cpp

GradApp.o:	Model/GradApp.cpp Model/GradApp.h
		g++ -c Model/GradApp.cpp

UndergradApp.o:	Model/UndergradApp.cpp Model/UndergradApp.h
		g++ -c Model/UndergradApp.cpp

GradErrorCheck.o:	Model/GradErrorCheck.cpp Model/GradErrorCheck.h
		g++ -c Model/GradErrorCheck.cpp

UGradErrorCheck.o:	Model/UGradErrorCheck.cpp Model/UGradErrorCheck.h
		g++ -c Model/UGradErrorCheck.cpp

GradAppData.o:	Model/GradAppData.cpp Model/GradAppData.h
		g++ -c Model/GradAppData.cpp

UGradAppData.o:	Model/UGradAppData.cpp Model/UGradAppData.h
		g++ -c Model/UGradAppData.cpp

RelatedOneData.o:	Model/RelatedOneData.cpp Model/RelatedOneData.h
		g++ -c Model/RelatedOneData.cpp

RelatedTwoData.o:	Model/RelatedTwoData.cpp Model/RelatedTwoData.h
		g++ -c Model/RelatedTwoData.cpp

WorkExperienceData.o:	Model/WorkExperienceData.cpp Model/WorkExperienceData.h
		g++ -c Model/WorkExperienceData.cpp


Student.o:	Model/Student.cpp Model/Student.h
		g++ -c Model/Student.cpp

GradStudent.o:	Model/GradStudent.cpp Model/GradStudent.h	
		g++ -c Model/GradStudent.cpp

SummaryChoiceWindow.o: View/SummaryChoiceWindow.cpp View/SummaryChoiceWindow.h
		g++ -c View/SummaryChoiceWindow.cpp `pkg-config gtkmm-3.0 --cflags --libs`

UndergradStudent.o:	Model/UndergradStudent.cpp Model/UndergradStudent.h	
		g++ -c Model/UndergradStudent.cpp

Course.o:	Model/Course.cpp Model/Course.h
		g++ -c Model/Course.cpp

Job.o:		Model/Job.cpp Model/Job.h
		g++ -c Model/Job.cpp

Node.o:		Model/Node.cpp Model/Node.h
		g++ -c Model/Node.cpp

run:
		./cuTaes

clean:
		rm *.o cuTaes

test:	operatorTest.cpp Model/UndergradStudent.cpp Model/UndergradStudent.h Model/UndergradApp.cpp Model/UndergradApp.h Model/GradStudent.cpp Model/GradStudent.h Model/GradApp.cpp Model/GradApp.h Model/AppQueue.cpp Model/AppQueue.h
		g++ -c operatorTest.cpp
		g++ -o test operatorTest.o Course.o Job.o Student.o UndergradStudent.o GradStudent.o UndergradApp.o GradApp.o Application.o CourseQueue.o JobQueue.o AppQueue.o

runtest:	
		./test


package:
	tar -cvf 2404A4.tar main.cpp Model/Student.cpp Model/Application.cpp View/WindowApp.cpp Control/Control.cpp main.h Model/Student.h Model/Application.h View/WindowApp.h Control/Control.h Model/Queue.h Queue.cpp Model/Node.cpp Model/Node.h Model/AppQueue.cpp Model/AppQueue.h Model/CourseQueue.cpp Model/CourseQueue.h Model/JobQueue.cpp Model/JobQueue.h Model/Course.cpp Model/Course.h Model/Job.cpp Model/Job.h Model/UndergradStudent.h Model/UndergradStudent.cpp Model/GradStudent.cpp Model/GradStudent.h Model/GradApp.h Model/GradApp.cpp Model/UndergradApp.h Model/UndergradApp.cpp Makefile courses.txt gradResearch.txt UMLpdf.pdf 2404UMLandDoc.pdf README.txt operatorTest.cpp View/WorkExperienceForm.h View/WorkExperienceForm.cpp View/UnderGradForm.h View/UnderGradForm.cpp View/UnderGradAppPage.h View/UnderGradAppPage.cpp View/UnderGradAppForm.cpp View/UGradSubmitWindow.h View/UGradSubmitWindow.cpp View/SummaryChoiceWindow.h View/SummaryChoiceWindow.cpp View/StudentPage.h View/StudentPage.cpp Model/GradAppData.cpp Model/GradAppData.h Model/GradErrorCheck.cpp Model/GradErrorCheck.h Model/RelatedOneData.cpp Model/RelatedOneData.h Model/RelatedTwoData.cpp Model/RelatedTwoData.h Model/UGradAppData.cpp Model/UGradAppData.h Model/UGradErrorCheck.cpp Model/UGradErrorCheck.h Model/WorkExperienceData.cpp Model/WorkExperienceData.h View/AdminManager.cpp View/AdminManager.h View/AdminPage.h View/AdminPage.cpp View/AdminWindow.h View/AdminWindow.cpp View/AppManager.cpp View/AppManager.h View/AppPage.h View/AppPage.cpp View/ErrorWindow.cpp View/ErrorWindow.h View/Form.h View/Form.cpp View/GradAppPage.cpp View/GradAppPage.h View/GradForm.cpp View/GradForm.h View/GradSubmitWindow.cpp View/GradSubmitWindow.h View/MainMenu.cpp View/MainMenu.h View/RelatedCoursesOneForm.cpp View/RelatedCoursesOneForm.h View/RelatedCoursesTwoForm.cpp View/RelatedCoursesTwoForm.h
