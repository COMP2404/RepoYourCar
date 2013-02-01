OBJECTS = main.o WindowApp.o Application.o Student.o 

cuTaes: $(OBJECTS)
	g++ $(OBJECTS) -o cuTaes `pkg-config gtkmm-3.0 --cflags --libs` 

main.o: main.cpp 
	g++ -c main.cpp  `pkg-config gtkmm-3.0 --cflags --libs`


WindowApp.o:	WindowApp.cpp WindowApp.h
	g++ -c WindowApp.cpp  `pkg-config gtkmm-3.0 --cflags --libs`


Application.o:	Application.cpp Application.h
	g++ -c Application.cpp

Student.o:	Student.cpp Student.h
	g++ -c Student.cpp

run:
	./RepoYourCar

clean:
	rm *.o cuTaes
