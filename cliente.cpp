/// Definicao da classe Cliente serve como uma representacao basica de um cliente, armazenando informacoes como CPF e nome.

/// Os metodos de acesso (get_cpf() e get_nome()) permitem recuperar essas informacoes de um objeto Cliente.

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
