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
    std::list<int> Historico;

    // Construtor 
    Astronauta(std::string nome, std::string cpf, int idade);
    
    // metodos
    void adicionarVoo(int idVoo);
    const std::list<int>& obterHist() const;
};

#endif
