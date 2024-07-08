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

// so pode lancar se todos astronautas estiverem disponiveis
void Voo::lancar() {
    if (condicao == "planejado") {
        bool todosDisponiveis = true;
        
        for (auto& astronauta : Passageiros) {
            if (!astronauta->Disponivel) {
                todosDisponiveis = false;
                break;
            }
        }

        if (todosDisponiveis) {
            for (auto& astronauta : Passageiros) {
                astronauta->Disponivel = false;
                astronauta->adicionarVoo(Codigo);
            }
            condicao = "lancado";
            cout << "Voo lancado com sucesso!" << endl;
        } else {
            cout << "Voo nao pode ser lancado: todos os passageiros devem estar disponiveis e vivos." << endl;
        }
    } 
}
void Voo::explodir() {
    if (condicao == "lancado"){
      for (auto& astronauta : Passageiros) {
          astronauta->Estado = false;
          astronauta->Disponivel = false;
      }
      condicao = "finalizado sem sucesso";
      cout << "voo explodido com sucesso"<< endl;
    }
    else {
      cout << "voo nao lançado, nao pode ser explodido" << endl;
    }
}



void Voo::pousar(){
    if (condicao == "lancado"){
      for (auto& astronauta : Passageiros) {
          astronauta->Estado = true;
          astronauta->Disponivel = true;
      }
      condicao = "finalizado com sucesso";
      finalizada = true;
      cout << "Voo finalizado com sucesso!"<< endl;
    }
     else {
      cout << "voo nao lançado, nao pode pousar" << endl;
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
        cout << ", Disponível: " << (astro->Disponivel ? "Sim":"Nao" ) << ", Está vivo? " << (astro->Estado ? "Sim":"Nao")  << endl;
    }
    cout << "Condicao do voo: " << condicao << endl;
    cout << "Finalizado? " << (finalizada ? "Sim":"Nao") << endl;
}

