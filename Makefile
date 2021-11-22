main: main.o social.o
	g++ -o main main.o social.o

tests: tests.o time.o movie.o
	g++ -o tests tests.o social.o

main.o: main.cpp social.h

tests.o: tests.cpp doctest.h social.h

social.o: social.cpp social.h

clean:
	rm -f *.o *~
