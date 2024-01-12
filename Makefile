all : main

main : main.o joueur.o cartes.o partie.o
	@g++ main.o joueur.o cartes.o partie.o -o main

main.o : main.cpp
	@g++ -c main.cpp

joueur.o : cfiles/joueur.cpp
	@g++ -c cfiles/joueur.cpp

cartes.o : cfiles/cartes.cpp
	@g++ -c cfiles/cartes.cpp

partie.o : cfiles/partie.cpp
	@g++ -c cfiles/partie.cpp


clean :
	@rm main.o joueur.o cartes.o partie.o main.exe