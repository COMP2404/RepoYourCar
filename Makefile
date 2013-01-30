app:		Main.o Application.o Student.o Application.h Student.h
		g++ -o app Main.o Application.o Student.o
		
Main.o:		Main.cpp Application.h Student.h
		g++ -c Main.cpp

Application.o:	Application.cpp Application.h
		g++ -c Application.cpp

Student.o:	Student.cpp Student.h
		g++ -c Student.cpp

clean:
		rm -f *.o app

package:	
		tar -cvf 2404A1.tar Main.cpp Application.cpp Student.cpp Application.h Student.h Makefile
