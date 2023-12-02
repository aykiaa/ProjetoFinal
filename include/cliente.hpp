/// Arquivo de cabeçalho da classe cliente.
#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include <vector>

#include "Filme.hpp"

using namespace std;



class Cliente
{
  friend class Locadora; /// Declaração de amizade, o que permite o acesso de  membros privados da classe Cliente.
private:
    string _nome;
    long _cpf;
    vector <Filme*> _Filmes_Alugados;
public:
/// Construtor da classe Cliente, inicializa os membros nome e cpf.
    Cliente(long cpf, string nome);
/// Destrutor da classe Cliente.
    ~Cliente();

    string get_nome() const;
    long get_cpf() const;

};


#endif
