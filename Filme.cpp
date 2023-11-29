/// Define a implementacao da classe Filme.

/// Essa classe serve como uma base para as classes derivadas, como DVD e Fita, que adicionam funcionalidades especificas para diferentes tipos de filmes.

#include "Filme.hpp"


Filme::Filme(int id, string titulo, int qtd_disp) : _id(id), _titulo(titulo), _qtd_disp(qtd_disp){}; /// A classe possui um construtor que inicializa os atributos da instancia (_id, _titulo e _qtd_disp) com os valores fornecidos como argumentos.

Filme::~Filme(){};/// O seu destrutor e usado para limpeza quando um objeto Filme e destruido.

int Filme::get_id() const{ /// Armazena e retorna o identificador unico do filme. 
    return _id;
}

string Filme::get_titulo() const{ /// Armazena e retorna o titulo do filme.
    return _titulo;
}

int Filme::get_qtdDisp() const{ /// Armazena e retorna a quantidade disponivel de copias desse filme.
    return _qtd_disp;
}
