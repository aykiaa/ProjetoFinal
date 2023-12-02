/// Cabecalho da classe Fita.

#ifndef FITA_H
#define FITA_H
#include "Filme.hpp"
#include "teste_erros.hpp"
/// Classe Fita é uma subclasse de Filme.
class Fita : public Filme {

private:
    bool _isRebobinada; /// Indica se a fita está rebobinada.

public:
 /// Construtor da classe Fita.
    Fita(int id, string titulo, int qtd_disp);

 /// Destrutor da classe Fita.
    ~Fita();

 /// Método que retorna a categoria.
    virtual string get_categoria() override;

 /// Método que retorna o tipo do filme, no caso fita.
    virtual string get_tipo() override;

 /// Método que verifica se a fita está rebobinada.
    bool get_isRebobinada() const;

 /// Método que calcula o valor da locação da fita com base na quantidade de dias.    
    float calc_valor_locacao (int dias) const override;
};



#endif
