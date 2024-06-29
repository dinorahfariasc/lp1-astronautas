
astronauta.o: astronauta.cpp
	g++ -c astronauta.cpp

voo.o: voo.cpp
	g++ -c voo.cpp

final: main.cpp astronauta.o voo.o 
	g++ main.cpp astronauta.cpp voo.cpp -o final

limpar:
	rm *.o final

