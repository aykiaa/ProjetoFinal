/*/ Cabeçalho da classe abstrata Filme, a qual possui membros privados, incluindo um identificador único, um título e a quantidade disponível de cópias.

O seu construtor Filme(int id, string titulo, int qtd_disp) é responsável por inicializar esses atributos.

O destrutor virtual é declarado, indicando que a classe é abstrata e pode conter métodos virtuais puros.

A classe Filme inclui métodos públicos de acesso como:

1- get_id() para obter o identificador
2- get_titulo() para obter o título
3- get_qtdDisp() para obter a quantidade disponível.

Além disso, a classe declara métodos virtuais puros get_categoria() e calc_valor_locacao(int dias) const, indicando que as classes derivadas devem implementar esses métodos./*/

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
    int get_id() const;
    string get_titulo() const;
    int get_qtdDisp() const;

    virtual float calc_valor_locacao (int dias) const = 0;
};

#endif
