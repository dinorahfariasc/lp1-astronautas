#include <iostream>

using namespace std;

class astronauta {
    char nome[100];
    int idade;
    char cpf[12];
    int listaIds[0];
    int dispo;

};

class voo {
    int id;
    char listaCpf[0]; 
    int status;

};


int main () {

    int escolha;

    cout << "Escolha uma  opcao:" << endl;
    cout << "1 - Registrar Astronauta" << endl;
    cout << "2- Registrar VOO" << endl;

    cin >> escolha >> endl;

    if (escolha == 1) {
        //Chamada do construtor de astronauta
    } 
    else {
        //Chamada do construtor de voo
    }

    return 0;
}
