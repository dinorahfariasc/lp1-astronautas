#include "voo.h"

Voo::Voo(int codigo, std::list<Astronauta*> passageiros) {
    Codigo = codigo;
    Passageiros = passageiros;
    condicao = "planejado";
    finalizada = false;
}

Voo::Voo(int codigo) {
    Codigo = codigo;
    condicao = "planejado";
    finalizada = false;
}

void Voo::lanca() {
    condicao = "lançado";
    for (auto& astronauta : Passageiros) {
        astronauta->Disponivel = false;
    }
}

void Voo::explodir() {
    condicao = "finalizado";
    for (auto& astronauta : Passageiros) {
        astronauta->Estado = false;
        astronauta->Disponivel = false;
    }
}
