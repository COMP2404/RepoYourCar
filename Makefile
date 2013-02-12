OBJECTS = main.o WindowApp.o Application.o Student.o Control.o Queue.o Node.o appNode.o Job.o Course.o

cuTaes: $(OBJECTS)
		g++ $(OBJECTS) -o cuTaes `pkg-config gtkmm-3.0 --cflags --libs` 

main.o:		main.cpp 
		g++ -c main.cpp  `pkg-config gtkmm-3.0 --cflags --libs`


WindowApp.o:	WindowApp.cpp WindowApp.h
		g++ -c WindowApp.cpp  `pkg-config gtkmm-3.0 --cflags --libs`

Control.o:	Control.cpp Control.h
		g++ -c Control.cpp  `pkg-config gtkmm-3.0 --cflags --libs`

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

appNode.o:	appNode.cpp appNode.h
		g++ -c appNode.cpp

run:
		./cuTaes

clean:
		rm *.o cuTaes

package:
	tar -cvf 2404A2.tar main.cpp Student.cpp Application.cpp WindowApp.cpp Control.cpp main.h Student.h Application.h WindowApp.h Control.h Queue.h Queue.cpp Makefile courses.txt UMLpdf.pdf README.txt
