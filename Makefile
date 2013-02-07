OBJECTS = main.o WindowApp.o Application.o Student.o Control.o

cuTaes: $(OBJECTS)
	g++ $(OBJECTS) -o cuTaes `pkg-config gtkmm-3.0 --cflags --libs` 

main.o: main.cpp 
	g++ -c main.cpp  `pkg-config gtkmm-3.0 --cflags --libs`


WindowApp.o:	WindowApp.cpp WindowApp.h
	g++ -c WindowApp.cpp  `pkg-config gtkmm-3.0 --cflags --libs`

Control.o:	Control.cpp Control.h
	g++ -c Control.cpp  `pkg-config gtkmm-3.0 --cflags --libs`


Application.o:	Application.cpp Application.h
	g++ -c Application.cpp

Student.o:	Student.cpp Student.h
	g++ -c Student.cpp

run:
	./cuTaes

clean:
	rm *.o cuTaes

package:
	tar -cvf 2404A1.tar main.cpp Student.cpp Application.cpp WindowApp.cpp Control.cpp main.h Student.h Application.h WindowApp.h Control.h Makefile courses.txt UMLpdf.pdf README.txt
