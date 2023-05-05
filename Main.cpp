#include <iostream>
#include "PilhaDinamica.h"
#include "Funcoes.h"

using namespace std;

int main()
{
    bool ligado = false;
    string opcao = "";
    PilhaDinamica<double> pilha;
    cout << "|COMANDOS|\n\n";
    cout << "INICIO\n";
    cout << "ZERAR\n";
    cout << "SOMA(X)\n";
    cout << "SUBTRAI(X)\n";
    cout << "MULTIPLICA(X)\n";
    cout << "DIVIDE(X)\n";
    cout << "PARCELAS\n";
    cout << "IGUAL\n";
    cout << "SAIR\n\n";
    cout << "Digite um comando...\n";
    while(opcao != "SAIR"){
        cout << endl;
        getline(cin,opcao);
        toupperstr(opcao);
        if(ligado == false){
            if(opcao == "INICIO"){
                ligado = true;
                cria(pilha);
                insere(pilha,0.0);
                cout << "Inicializado!";
            }
        }
        else{
            if(opcao == "ZERAR"){
                destroi(pilha);
                insere(pilha,0.0);
                cout << "Zerado!";
            }
            if(opcao.substr(0,4) == "SOMA")
                try{
                    soma(pilha, opcao);
                    cout << "Feito!";
                }
                catch(const char* msg){
                    cerr << msg;
                }
            if(opcao.substr(0,5) == "IGUAL"){
                cout << topo(pilha);
            }
        }
        if(ligado == false)
            cout << "Primeiro inicialize o programa!";
    }
    destroi(pilha);
}