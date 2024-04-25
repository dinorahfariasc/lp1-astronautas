#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
#include <list>

class Astronauta {
public:
    std::string Nome;
    std::string Cpf;
    int Idade;
    bool Disponivel;
    bool Estado;
    std::list<std::string> Historico;  
    std::list<std::string> Escala;

    // Construtor 
    Astronauta(std::string nome, std::string cpf, int idade);
};

#endif
