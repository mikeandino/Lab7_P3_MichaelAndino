proyecto:	main.o 
	g++ main.o -o run

main.o:	main.cpp User.h
	g++ -c main.cpp
