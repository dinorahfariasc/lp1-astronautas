#include "astronauta.h"

Astronauta::Astronauta(std::string nome, std::string cpf, int idade) {
    Nome = nome;
    Cpf = cpf;
    Idade = idade;
    Disponivel = true;
    Estado = true;
}

void Astronauta::adicionarVoo(int idVoo){
  Historico.push_back(idVoo);
}

const std::list<int>& Astronauta::obterHist() const {
    return Historico;
}

