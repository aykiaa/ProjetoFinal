/// Define a implementacao da classe Filme.

/// A classe possui um construtor que inicializa os atributos da instancia (_id, _titulo e _qtd_disp) com os valores fornecidos como argumentos.

/// O seu destrutor e usado para limpeza quando um objeto Filme e destruido.

/// A classe também fornece metodos publicos de acesso para recuperar informacoes sobre um filme. Os metodos:

/// 1- get_id() retorna o identificador unico do filme, 
/// 2- get_titulo() retorna o titulo do filme, 
/// 3- get_qtdDisp() retorna a quantidade disponivel de copias desse filme.

/// Essa classe serve como uma base para as classes derivadas, como DVD e Fita, que adicionam funcionalidades especificas para diferentes tipos de filmes.

#include "Filme.hpp"


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
