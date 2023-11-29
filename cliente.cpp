/// Implementação da classe Cliente, armazenando informacoes como CPF e nome.

#include "cliente.hpp"
#include <algorithm>

/// Construtor da classe Cliente, que inicializa os membros cpf e nome.
Cliente::Cliente(long cpf, string nome) : _cpf(cpf),  _nome(nome){};
/// Destrutor da classe Cliente.
Cliente::~Cliente(){};


long Cliente::get_cpf() const{ /// Armazena o cpf do cliente
    return  _cpf;
}

string Cliente::get_nome() const{ /// Armazena o nome do cliente
    return _nome;
}
