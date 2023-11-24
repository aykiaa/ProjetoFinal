#ifndef FILMES_HPP
#define FILMES_HPP
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