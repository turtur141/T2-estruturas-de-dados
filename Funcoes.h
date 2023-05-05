#include <iostream>
#include "PilhaDinamica.h"

using namespace std;
void toupperstr(string &str);
void soma(PilhaDinamica<double>&, string);
void subtracao(PilhaDinamica<double>&, string);
void multiplicacao(PilhaDinamica<double>&, string);
void divisao(PilhaDinamica<double>&, string);

void soma(PilhaDinamica<double> &pilha,string opcao){
    bool ponto = false;
    string valorstr = "";
    double valor = 0.0, soma;
    if(opcao.at(4) == '(' and opcao.at(opcao.size()-1) == ')'){
        for(unsigned int i = 5; i<opcao.size()-1;i++){
            if(!isdigit(opcao.at(i)) and (opcao.at(i) == '.' and ponto == true))
                throw "Valor incorreto";
            if(opcao.at(i) == '.')
                ponto = true;
        }
        valorstr = opcao.substr(5,opcao.size()-6);
        valor = atof(valorstr.c_str());
    }
    soma = valor + topo(pilha);
    insere(pilha,soma);
}

void toupperstr(string &str){
    int strsize = str.size();
    for(int j=0;j<strsize;j++)
    {
        str[j] = toupper(str[j]);
    }
}


