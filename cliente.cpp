/// Definição da classe Cliente serve como uma representação básica de um cliente, armazenando informações como CPF e nome.

/// Os métodos de acesso (get_cpf() e get_nome()) permitem recuperar essas informações de um objeto Cliente.

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
