#include "voo.h"
#include <iostream>
// condicoes: planejado, lancado, finalizado com sucesso ou n

using namespace std;

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

void Voo::lancar() {
   if (condicao == "planejado"){
      for (auto& astronauta : Passageiros) {
          astronauta->Estado = false;
          astronauta->Disponivel = true;
      }
      condicao = "lancado";
    }
    else {
      cout<< "voo nao lancado ou nao disponivel! nao pode ser explodido." << endl;
    }
}

void Voo::explodir() {
    if (condicao == "lancado"){
      for (auto& astronauta : Passageiros) {
          astronauta->Estado = false;
          astronauta->Disponivel = false;
      }
      condicao = "finalizado sem sucesso";
    }
}



void Voo::pousar(){
    if (condicao == "finalizado"){
      for (auto& astronauta : Passageiros) {
          astronauta->Estado = true;
          astronauta->Disponivel = true;
      }
      condicao = "finalizado com sucesso";
    }
    else {
      cout<< "voo nao lancado ou nao disponivel! nao pode pousar." << endl;
    }
}

void Voo::adicionar(Astronauta* astronauta){
    if (condicao == "planejado"){
      Passageiros.push_back(astronauta);
      cout << "Astronauta adicionado ao voo." << endl;
    } else {
        cout << "Nao e possivel adicionar astronautas. O voo nao esta planejado." << endl;
    }
}

void Voo::remover(Astronauta* astronauta) {
    if (condicao == "planejado") {
        Passageiros.remove(astronauta);
        cout << "Astronauta" << astronauta->Nome << "removido do voo." << endl;
    } else {
        cout << "Nao e possivel remover astronautas. O voo não esta planejado." << endl;
    }
    
}

void Voo::passageiros() {
    cout << "Lista de passageiros do voo: " << Codigo << endl; 
    for (const auto& astro : Passageiros) { 
        cout << "Nome: " << astro->Nome << ", CPF: " << astro->Cpf << ", Idade: " << astro->Idade;
        cout << ", Disponível: " << astro->Disponivel << ", Está vivo? " << astro->Estado  << endl;
    }
    cout << "condicao do voo: " << condicao << endl;
    cout << "finalizado? " << finalizada << endl;
}

