OBJECTS = main.o WindowApp.o Application.o Student.o Control.o Queue.o Node.o AppQueue.o CourseQueue.o JobQueue.o Job.o Course.o GradStudent.o UndergradStudent.o GradApp.o UndergradApp.o AdminPage.o AdminManager.o AdminWindow.o SummaryChoiceWindow.o MainMenu.o ErrorWindow.o GradAppPage.o UnderGradAppPage.o StudentPage.o AppManager.o GradForm.o UnderGradForm.o RelatedCoursesOneForm.o RelatedCoursesTwoForm.o WorkExperienceForm.o Form.o AppPage.o GradErrorCheck.o UGradErrorCheck.o GradAppData.o UGradAppData.o GradSubmitWindow.o UGradSubmitWindow.o RelatedOneData.o RelatedTwoData.o WorkExperienceData.o
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

test:	operatorTest.cpp UndergradStudent.cpp UndergradStudent.h UndergradApp.cpp UndergradApp.h GradStudent.cpp GradStudent.h GradApp.cpp GradApp.h AppQueue.cpp AppQueue.h
		g++ -c operatorTest.cpp
		g++ -o test operatorTest.o Course.o Job.o Student.o UndergradStudent.o GradStudent.o UndergradApp.o GradApp.o Application.o CourseQueue.o JobQueue.o AppQueue.o

runtest:	
		./test


package:
	tar -cvf 2404A4.tar main.cpp Student.cpp Application.cpp WindowApp.cpp Control.cpp main.h Student.h Application.h WindowApp.h Control.h Queue.h Queue.cpp Node.cpp Node.h AppQueue.cpp AppQueue.h CourseQueue.cpp CourseQueue.h JobQueue.cpp JobQueue.h Course.cpp Course.h Job.cpp Job.h UndergradStudent.h UndergradStudent.cpp GradStudent.cpp GradStudent.h GradApp.h GradApp.cpp UndergradApp.h UndergradApp.cpp Makefile courses.txt gradResearch.txt UMLpdf.pdf 2404UMLandDoc.pdf README.txt operatorTest.cpp WorkExperienceForm.h WorkExperienceForm.cpp UnderGradForm.h UnderGradForm.cpp UnderGradAppPage.h UnderGradAppPage.cpp UnderGradAppForm.h UnderGradAppForm.cpp UGradSubmitWindow.h UGradSubmitWindow.cpp SummaryChoiceWindow.h SummaryChoiceWindow.cpp StudentPage.h StudentPage.cpp GradAppData.cpp GradAppData.h GradErrorCheck.cpp GradErrorCheck.h RelatedOneData.cpp RelatedOneData.h RelatedTwoData.cpp RelatedTwoData.h UGradAppData.cpp UGradAppData.h UGradErrorCheck.cpp UGradErrorCheck.h WorkExperienceData.cpp WorkExperienceData.h AdminManager.cpp AdminManager.h AdminPage.h AdminPage.cpp AdminWindow.h AdminWindow.cpp AppManager.cpp AppManager.h AppPage.h AppPage.cpp ErrorWindow.cpp ErrorWindow.h Form.h Form.cpp GradAppPage.cpp GradAppPAge.h GradForm.cpp GradForm.h GradSubmitWindow.cpp GradSubmitWindow.h MainMenu.cpp MainMenu.h RelatedCoursesOneForm.cpp RelatedCoursesOneForm.h RelatedCoursesTwoForm.cpp RelatedCoursesTwoForm.h
