/// O cabecalho implementa a classe Cliente, oferecendo metodos publicos parar acessar as informacoes do cliente no sistema de locadora de filmes, como:

/// 1- Nome
/// 2- Cpf
/// 3- Lista de filmes que foram alugados.

/// A amizade declarada com a classe Locadora sugere uma relacao especial, permitindo que a locadora acesse diretamente os detalhes internos da classe Cliente.

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
    long _cpf;
    vector <Filme*> _Filmes_Alugados;
public:
    Cliente(long cpf, string nome);
    ~Cliente();

    string get_nome() const;
    long get_cpf() const;

};


#endif
