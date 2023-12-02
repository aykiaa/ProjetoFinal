/// Cabeçalho da classe abstrata Filme, a qual possui membros privados, incluindo um identificador unico, um titulo e a quantidade disponivel de copias.

/// Alem disso, a classe declara metodos virtuais puros get_categoria() e calc_valor_locacao(int dias) const, indicando que as classes derivadas devem implementar esses metodos.

#ifndef FILME_H
#define FILME_H
#include <iostream>
#include <string>
#include "teste_erros.hpp"
using namespace std;


class Filme
{
  friend class Locadora;
private:
    int _id;
    string _titulo;
    int _qtd_disp;

public:
    Filme(int id, string titulo, int qtd_disp); /// Construtor que realiza a iniciação e inclusão de metodos publicos de acesso.
    virtual ~Filme(); /// O destrutor virtual e declarado, indicando que a classe e abstrata e pode conter metodos virtuais puros.
    
    virtual string get_categoria() = 0;
    virtual string get_tipo() = 0;
    int get_id() const; /// get_id() para obter o identificador
    string get_titulo() const; /// get_titulo() para obter o titulo
    int get_qtdDisp() const; /// get_qtdDisp() para obter a quantidade disponivel.

    virtual float calc_valor_locacao (int dias) const = 0;
};

#endif
