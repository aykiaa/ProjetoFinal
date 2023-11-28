/// Cabeçalho da classe abstrata Filme, a qual possui membros privados, incluindo um identificador unico, um titulo e a quantidade disponivel de copias.

/// O seu construtor Filme(int id, string titulo, int qtd_disp) e responsavel por inicializar esses atributos.

/// O destrutor virtual e declarado, indicando que a classe e abstrata e pode conter metodos virtuais puros.

/// A classe Filme inclui metodos publicos de acesso como:

/// 1- get_id() para obter o identificador
/// 2- get_titulo() para obter o titulo
/// 3- get_qtdDisp() para obter a quantidade disponivel.

/// Alem disso, a classe declara metodos virtuais puros get_categoria() e calc_valor_locacao(int dias) const, indicando que as classes derivadas devem implementar esses metodos.

#ifndef FILME_H
#define FILME_H
#include <iostream>
#include <string>
using namespace std;


class Filme
{
  friend class Locadora;
private:
    int _id;
    string _titulo;
    int _qtd_disp;

public:
    Filme(int id, string titulo, int qtd_disp);
    virtual ~Filme();
    
    virtual string get_categoria() = 0;
    virtual string get_tipo() = 0;
    int get_id() const;
    string get_titulo() const;
    int get_qtdDisp() const;

    virtual float calc_valor_locacao (int dias) const = 0;
};

#endif
