/** Implementação da classe Fita.

O construtor inicializa os atributos da classe, herdando alguns de sua classe base Filme e introduzindo um novo atributo privado chamado _isRebobinada (este atributo é randomizado no momento da criação da fita, determinando se a fita está ou não rebobinada).

O destrutor faz a limpeza quando um objeto Fita é destruído.

A função get_categoria() retorna uma string vazia, indicando que as fitas não possuem categorias específicas.

O método get_isRebobinada() retorna o estado da fita, informando se ela está rebobinada ou não.

A função calc_valor_locacao(int dias) const calcula o valor de locação da fita com base no número de dias especificado.

1- Se a fita estiver rebobinada, o custo é de 5.0 reais;
2- Caso contrário, o custo é de 7.0 reais, considerando uma multa de 2.0 reais por não rebobinar a fita.**/

#include "fita.hpp"
#include <cstdlib>


Fita::Fita(int id, string titulo, int qtd_disp) : Filme(id, titulo, qtd_disp){
    _isRebobinada = rand() % 2 == 0;   //randomizo se a fita estara rebobinada ou nao
}; 
Fita::~Fita(){};

string Fita::get_categoria() { return ""; }

bool Fita::get_isRebobinada() const {
    return _isRebobinada;
}

float Fita::calc_valor_locacao (int dias) const {
    if (_isRebobinada)
    {
        return 5.0;
    }
    else
    {
        return 7.0; // 5 + 2 de multa
    }
};
