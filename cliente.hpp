/** O cabeçalho implementa a classe Cliente, oferecendo métodos públicos parar acessar as informações do cliente no sistema de locadora de filmes, como:

1- Nome
2- Cpf
3- Lista de filmes que foram alugados.

A amizade declarada com a classe Locadora sugere uma relação especial, permitindo que a locadora acesse diretamente os detalhes internos da classe Cliente.**/

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include <vector>

#include "Filme.hpp"

using namespace std;



class Cliente
{
  friend class Locadora;
private:
    string _nome;
    int _cpf;
    vector <Filme*> _Filmes_Alugados;
public:
    Cliente(int cpf, string nome);
    ~Cliente();

    string get_nome() const;
    int get_cpf() const;

};


#endif
