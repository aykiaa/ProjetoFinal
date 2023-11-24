#include "Filmes.hpp"


Filme::Filme(int id, string titulo, int qtd_disp) : _id(id), _titulo(titulo), _qtd_disp(qtd_disp){};

Filme::~Filme(){};

int Filme::get_id() const{
    return _id;
}

string Filme::get_titulo() const{
    return _titulo;
}

int Filme::get_qtdDisp() const{
    return _qtd_disp;
}