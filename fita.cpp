/// Implementacao da classe Fita.

/// A funcao calc_valor_locacao(int dias) const calcula o valor de locação da fita com base no numero de dias especificado.

/// 1- Se a fita estiver rebobinada, o custo é de 5.0 reais;
/// 2- Caso contrário, o custo é de 7.0 reais, considerando uma multa de 2.0 reais por não rebobinar a fita.

#include "fita.hpp"
#include <cstdlib>

/// O construtor inicializa os atributos da classe, herdando alguns de sua classe base Filme e introduzindo um novo atributo privado chamado _isRebobinada (este atributo é randomizado no momento da criacao da fita, determinando se a fita esta ou não rebobinada).
Fita::Fita(int id, string titulo, int qtd_disp) : Filme(id, titulo, qtd_disp){
    _isRebobinada = rand() % 2 == 0;   //randomizo se a fita estara rebobinada ou nao
}; 
/// O destrutor faz a limpeza quando um objeto Fita é destruido.
Fita::~Fita(){};
/// A função get_categoria() retorna uma string vazia, indicando que as fitas não possuem categorias especificas.
string Fita::get_categoria() { return ""; }
string Fita::get_tipo() { return "FITA"; }
/// O metodo get_isRebobinada() retorna o estado da fita, informando se ela esta rebobinada ou nao.
bool Fita::get_isRebobinada() const {
    return _isRebobinada;
}
/// A funcao calcula o valor de locação da fita a partir do numero de dias.
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
