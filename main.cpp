#include <iostream>
#include <list>
#include "astronauta.h"
#include "voo.h"

using namespace std;

int main() {
    list<Astronauta> todos_astros;
    list<Voo> todos_voos;

    list<string> menu = {"--------------------------","Menu: ", "1 - Cadastrar Astronauta", "2 - Cadastrar Voo", "3 - Adicionar Astronaura em voo", "4 - Remover Astronauta de um voo", "5 - Lançar um voo", "6 - Explodir voo","7 - Pousar","8 - Mostrar todos os voos","9 - Mostrar passageiros por voo","10 - Mostrar passageiros mortos", "11 - Sair", "--------------------------",};

    cout<< "teste"<< endl;
    int x = 0;
    int opcao;

    while (x == 0)
    {
      for (string i : menu)
        {
            cout << i << endl;
        }
        cin >> opcao;
        
        if (opcao == 1) {
        cout << "Digite o nome do astronauta: ";
        string nome;
        cin >> nome;

        cout << "Digite o cpf do astronauta: ";
        string cpf;
        cin >> cpf;

        // Verificar se o CPF já existe
        bool cpfExiste = false;
        for (const auto& astro : todos_astros) {
            if (astro.Cpf == cpf) {
                cpfExiste = true;
                break;
            }
        }

        if (cpfExiste) {
            cout << "Ja existe um astronauta com esse CPF." << endl;
        } else {
            cout << "Digite a idade do astronauta: ";
            int idade;
            cin >> idade;

            Astronauta astro(nome, cpf, idade);
            todos_astros.push_back(astro);
        }
    }

        else if(opcao == 2){
            cout << "Digite o codigo do voo: ";
            int codigo;
            cin >> codigo;
            
            for(auto& voo : todos_voos){
                if (codigo == voo.Codigo){
                  cout << "ja existe um voo com esse codigo"<< endl;
                  break;
              }
              else {
                  Voo voo(codigo);
                  todos_voos.push_back(voo);
                  cout<< "voo criado com sucesso"<< endl;
              }
            }

            
        }
        else if (opcao == 3 || opcao == 4) {
            cout << "Digite o codigo do voo: "<< endl;
            int codigo;
            cin >> codigo;

            // Verifica se o voo está planejado e existe
            bool vooEncontrado = false;
            for (auto& voo : todos_voos) {
                if (voo.Codigo == codigo && voo.condicao == "planejado") {
                    vooEncontrado = true;

                    cout << "Digite o CPF do astronauta: ";
                    string cpf;
                    cin >> cpf;

                    // Verifica se o astronauta existe, está disponível e vivo
                    bool astronautaEncontrado = false;
                    for (auto& astro : todos_astros) {
                        if (astro.Cpf == cpf && astro.Disponivel && astro.Estado) {
                            if (opcao == 3){
                            voo.adicionar(&astro);
                            astronautaEncontrado = true;
                            break;
                            }
                            else if (opcao == 4){
                            voo.remover(&astro);
                            astronautaEncontrado = true;
                            }
                        }
                    }

                    if (!astronautaEncontrado) {
                        cout << "Astronauta não encontrado, não disponível ou não vivo." << endl;
                    }

                    break; // Sai do loop de voos após encontrar e processar o voo desejado
                }
                }

              if (!vooEncontrado) {
                  cout << "Voo não encontrado ou não está planejado." << endl;
              }
        }
    
        else if(opcao == 5){
            cout << "Digite o codigo do voo: ";
            int codigo;
            cin >> codigo;

            // Verifica se o voo está planejado 
            bool vooEncontrado = false;
            for (auto& voo : todos_voos) {
                if (voo.Codigo == codigo) {
                    vooEncontrado = true;
                    voo.lancar();
                    break;
                  }
                }

              if (!vooEncontrado) {
                  cout << "Voo não encontrado " << endl;
              }
            cout << "Voo lancado com sucesso!" << endl;
        }
        else if(opcao == 6){
            cout << "Digite o codigo do voo: ";
            int codigo;
            cin >> codigo;

            // Verifica se o voo está planejado 
            bool vooEncontrado = false;
            for (auto& voo : todos_voos) {
                if (voo.Codigo == codigo) {
                    vooEncontrado = true;
                    voo.explodir();
                    cout<< "voo explodido com sucesso"<< endl;
                    break;
                  }
                }

              if (!vooEncontrado) {
                  cout << "voo nao lancado ou nao disponivel! nao pode ser explodido. " << endl;
              }
        }
        
        else if(opcao == 7){ cout << "Digite o codigo do voo: ";
            int codigo;
            cin >> codigo;

            // Verifica se o voo está planejado 
            bool vooEncontrado = false;
            for (auto& voo : todos_voos) {
                if (voo.Codigo == codigo) {
                    vooEncontrado = true;
                    voo.pousar();
                    cout << "pousado com sucesso! " << endl;
                    break;
                  }
                }

              if (!vooEncontrado) {
                  cout << "Voo não encontrado " << endl;
              }
        }
        
        else if(opcao == 8){
           cout<< "voos" << endl;
           for(auto& voo : todos_voos){
            cout << voo.Codigo << " - "<< voo.condicao << " " << endl;
           }
        }
        
        else if(opcao == 9){
            cout << "Digite o codigo do voo: ";
            int codigo;
            cin >> codigo;

            // Verifica se o voo está planejado 
            bool vooEncontrado = false;
            for (auto& voo : todos_voos) {
                if (voo.Codigo == codigo) {
                    vooEncontrado = true;
                    voo.passageiros();
                    break;
                  }
                }

              if (!vooEncontrado) {
                  cout << "Voo não encontrado " << endl;
              }
        }
        
        else if(opcao == 10){
          cout << "Passageiros que foram de base" << endl;
          for(auto& astro : todos_astros){
              if(astro.Estado == false){
                cout << astro.Nome << " "<<astro.Cpf << endl;
              }
          }
           
        }
        
        else if (opcao == 11){
            cout << "Saindo..." << endl;
            x = 1;
        }
        
        else{
            cout << "Opção inválida!" << endl;
        }
        
    }
    return 0;
};
