tiro:	main.o tiro.o oneofthree.o twoofthree.o threeofthree.o
	g++ main.o tiro.o oneofthree.o twoofthree.o threeofthree.o -lncurses

main.o:	main.cpp tiro.h oneofthree.h twoofthree.h threeofthree.h
	g++ -c main.cpp 

tiro.o:	tiro.cpp tiro.h
	g++ -c tiro.cpp 

oneofthree.o:	oneofthree.cpp oneofthree.h tiro.h
	g++ -c oneofthree.cpp 

twoofthree.o:	twoofthree.cpp twoofthree.h tiro.h
	g++ -c twoofthree.cpp 

threeofthree.o:	threeofthree.cpp threeofthree.h tiro.h
	g++ -c threeofthree.cpp 

