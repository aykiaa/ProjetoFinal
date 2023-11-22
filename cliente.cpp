#include "cliente.hpp"
#include <algorithm>


Cliente::Cliente(int cpf, string nome) : _cpf(cpf),  _nome(nome){};

Cliente::~Cliente(){};


int Cliente::get_cpf() const{
    return  _cpf;
}

string Cliente::get_nome() const{
    return _nome;
}