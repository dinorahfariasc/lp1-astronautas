#ifndef VOO_H
#define VOO_H

#include <list>
#include "astronauta.h"

class Voo {
public:
    int Codigo;
    std::list<Astronauta*> Passageiros;
    std::string condicao; // (planejado, execucao, finalizado)
    bool finalizada;

    // Construtores
    Voo(int codigo, std::list<Astronauta*> passageiros);
    Voo(int codigo);

    // Métodos
    void lanca();
    void explodir();
};

#endif
