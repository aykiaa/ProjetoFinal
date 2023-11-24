#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>
#include <string>
#include <vector>

#include "Filmes.hpp"

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