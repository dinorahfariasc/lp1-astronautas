#include <iostream>
#include <list>

using namespace std;


class Astronauta {

public:
    string Nome;
    string Cpf;
    int Idade;
    bool Disponivel;
    bool Estado;
    list<string> Historico;
    list<string> Escala;

    // construtor 
    Astronauta(string nome, string cpf, int idade){
        Nome = nome;
        Cpf = cpf;
        Idade = idade;
        this->Disponivel = true;
        this->Estado = true;

    }
};

class Voo {
    public:
    int Codigo;
    list<Astronauta> Passageiros;
    string condicao; // (planejado, execucao, finalizado)
    bool finalizada;       

    // construtor
    Voo(int codigo, list<Astronauta> passageiros){
        Codigo = codigo;
        Passageiros = passageiros;
        this->condicao = "planejado";
        this->finalizada = false;

    }
    // construtor 2
    Voo(int codigo){
        Codigo = codigo;
        this->condicao = "planejado";
        this->finalizada = false;
    }

};

int main(){
    
    list<Astronauta> todos;
   
    Astronauta astro1("Dinorah", "689518225", 20);

    cout << "Nome: " << astro1.Nome << endl;
    cout << "cpf: " << astro1.Cpf << endl;
    cout << "idade: " << astro1.Idade << endl;
    cout << "o astronauta esta vivo? " << astro1.Estado << endl;
    cout << "o astronauta esta disponivel? " << astro1.Disponivel << endl;

    
    Voo voo1(5001);

    cout << "Codigo: " << voo1.Codigo << endl;
    cout << "tamanho da tripulacao: "<<voo1.Passageiros.size() << endl;

    voo1.Passageiros.push_back(astro1);

    cout << "tamanho da tripulacao: "<<voo1.Passageiros.size() << endl;
    //Voo voo2(5002, todos);

    // listando a tripulacao de um voo
    for (Astronauta i : voo1.Passageiros)
    {
        cout << "tripulacao: " << i.Nome << endl;
        
    }

   list<string> menu = {"Menu: ", "1 - Cadastrar Astronauta", "2 - Cadastrar Voo", "3 - Adicionar Astronaura em voo", "4 - Remover Astronauta de um voo", "5 - Lançar um voo", "6 - Explodir voo","7 - Sair"};

    //int x = 0;
    //int opcao;

   /*  while (x = 0)
    {
        for (string i : menu)
        {
            cout << i << endl;
        }
        cin >> opcao;
        
        if(opcao == 1){
            cout << "Digite o nome do astronauta: ";
            string nome;
            cin >> nome;

            cout << "Digite o cpf do astronauta: ";
            string cpf;
            cin >> cpf;

            cout << "Digite a idade do astronauta: ";
            int idade;
            cin >> idade;

            Astronauta astro(nome, cpf, idade);
        }

        else if(opcao == 2){
            cout << "Digite o codigo do voo: ";
            int codigo;
            cin >> codigo;

            Voo voo(codigo);
        }
        else if(opcao == 3){
            cout << "Digite o codigo do voo: ";
            int codigo;
            cin >> codigo;

            cout << "Digite o cpf do astronauta: ";
            string cpf;
            cin >> cpf;

        }

        else if(opcao == 5){
            cout << "Voo lançado com sucesso!" << endl;
        }
        else if(opcao == 6){
            cout << "Voo explodido com sucesso!" << endl;
        }
        else if(opcao == 7){
            cout << "Saindo..." << endl;
            x = 1;
        }
        else{
            cout << "Opção inválida!" << endl;
        }


        
    }
    */


}