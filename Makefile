main: main.o social.o social2.o
	g++ -o main main.o social.o social2.o

tests: tests.o social.o social2.o
	g++ -o tests tests.o social.o social2.o

main.o: main.cpp social.h social2.h

tests.o: tests.cpp doctest.h social.h social2.h

social.o: social.cpp social.h

social2.o: social2.cpp social2.h

clean:
	rm -f *.o *~
