/// Cabeçalho que define a estrutura da classe Fita, apresentando as funcionalidades específicas para fitas no sistema de locadora da filmes como:

/// 1- Id
/// 2- Título
/// 3- Quantidade
/// 4- Valor
/// 5- Rebobinação

#ifndef FITA_H
#define FITA_H
#include "Filme.hpp"

class Fita : public Filme {

private:
    bool _isRebobinada;

public:
    Fita(int id, string titulo, int qtd_disp);
    ~Fita();

    virtual string get_categoria() override;
    bool get_isRebobinada() const;
    
    float calc_valor_locacao (int dias) const override;

};



#endif
