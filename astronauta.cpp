#include "astronauta.h"

Astronauta::Astronauta(std::string nome, std::string cpf, int idade) {
    Nome = nome;
    Cpf = cpf;
    Idade = idade;
    Disponivel = true;
    Estado = true;
}
