OBJECTS = main.o WindowApp.o Application.o Student.o Control.o Queue.o Node.o AppQueue.o CourseQueue.o JobQueue.o Job.o Course.o

cuTaes: $(OBJECTS)
		g++ $(OBJECTS) -o cuTaes `pkg-config gtkmm-3.0 --cflags --libs` 

main.o:		main.cpp main.h
		g++ -c main.cpp  `pkg-config gtkmm-3.0 --cflags --libs`


WindowApp.o:	WindowApp.cpp WindowApp.h
		g++ -c WindowApp.cpp  `pkg-config gtkmm-3.0 --cflags --libs`

Control.o:	Control.cpp Control.h
		g++ -c Control.cpp  `pkg-config gtkmm-3.0 --cflags --libs`

AppQueue.o:	AppQueue.cpp AppQueue.h
		g++ -c AppQueue.cpp

CourseQueue.o:	CourseQueue.cpp CourseQueue.h
		g++ -c CourseQueue.cpp

JobQueue.o:	JobQueue.cpp JobQueue.h
		g++ -c JobQueue.cpp

Queue.o:	Queue.cpp Queue.h
		g++ -c Queue.cpp	

Application.o:	Application.cpp Application.h
		g++ -c Application.cpp

Student.o:	Student.cpp Student.h
		g++ -c Student.cpp

Course.o:	Course.cpp Course.h
		g++ -c Course.cpp

Job.o:		Job.cpp Job.h
		g++ -c Job.cpp

Node.o:		Node.cpp Node.h
		g++ -c Node.cpp

run:
		./cuTaes

clean:
		rm *.o cuTaes

package:
	tar -cvf 2404A2.tar main.cpp Student.cpp Application.cpp WindowApp.cpp Control.cpp main.h Student.h Application.h WindowApp.h Control.h Queue.h Queue.cpp Node.cpp Node.h AppQueue.cpp AppQueue.h CourseQueue.cpp CourseQueue.h JobQueue.cpp JobQueue.h Makefile courses.txt UMLpdf.pdf README.txt
