/*/ Define a implementação da classe Filme.

A classe possui um construtor que inicializa os atributos da instância (_id, _titulo e _qtd_disp) com os valores fornecidos como argumentos.

O seu destrutor é usado para limpeza quando um objeto Filme é destruído.

A classe também fornece métodos públicos de acesso para recuperar informações sobre um filme. Os métodos:

1- get_id() retorna o identificador único do filme, 
2- get_titulo() retorna o título do filme, 
3- get_qtdDisp() retorna a quantidade disponível de cópias desse filme.

Essa classe serve como uma base para as classes derivadas, como DVD e Fita, que adicionam funcionalidades específicas para diferentes tipos de filmes./*/

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
