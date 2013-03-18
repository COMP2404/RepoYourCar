OBJECTS = main.o WindowApp.o Application.o Student.o Control.o Queue.o Node.o AppQueue.o CourseQueue.o JobQueue.o Job.o Course.o GradStudent.o UndergradStudent.o GradApp.o UndergradApp.o

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

Student.o:	Model/Student.cpp Model/Student.h
		g++ -c Model/Student.cpp

GradStudent.o:	Model/GradStudent.cpp Model/GradStudent.h	
		g++ -c Model/GradStudent.cpp

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
	tar -cvf 2404A3.tar main.cpp Student.cpp Application.cpp WindowApp.cpp Control.cpp main.h Student.h Application.h WindowApp.h Control.h Queue.h Queue.cpp Node.cpp Node.h AppQueue.cpp AppQueue.h CourseQueue.cpp CourseQueue.h JobQueue.cpp JobQueue.h Course.cpp Course.h Job.cpp Job.h UndergradStudent.h UndergradStudent.cpp GradStudent.cpp GradStudent.h GradApp.h GradApp.cpp UndergradApp.h UndergradApp.cpp Makefile courses.txt gradResearch.txt UMLpdf.pdf 2404UMLandDoc.pdf README.txt operatorTest.cpp
