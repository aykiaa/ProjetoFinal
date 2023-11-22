#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Cliente
{
private:
    string _nome;
    int _cpf;

public:
    Cliente(int cpf, string nome);
    ~Cliente();

    string get_nome() const;
    int get_cpf() const;

};


#endif