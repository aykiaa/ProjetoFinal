#include "fita.hpp"
#include <cstdlib>


Fita::Fita(int id, string titulo, int qtd_disp) : Filme(id, titulo, qtd_disp){
    _isRebobinada = rand() % 2 == 0;   //randomizo se a fita estara rebobinada ou nao
}; 

Fita::~Fita(){};

bool Fita::get_isRebobinada() const {
    return _isRebobinada;
}

float Fita::calc_valor_locacao (int dias) const {
    if (_isRebobinada)
    {
        return 5.0;
    }
    else if (!_isRebobinada)
    {
        return 7.0; // 5 + 2 de multa
    }
};