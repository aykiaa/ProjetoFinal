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