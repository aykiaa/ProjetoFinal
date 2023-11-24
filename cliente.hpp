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