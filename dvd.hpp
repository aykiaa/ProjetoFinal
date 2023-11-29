/// Cabecalho da classe DVD, oferecendo metodos publicos para acessar as informaçoes dos DVDs como: categoria, quantidade, título, e id.

#ifndef DVD_H
#define DVD_H
#include "Filme.hpp"

class DVD : public Filme {
private:
    string _categoria; /// Categoria do DVD.

public:
/// Construtor da classe DVD, que inicializa os membros.
    DVD(int id, string titulo, int qtd_disp, string categoria);
/// Destrutor da classe DVD.
    ~DVD();
/// Método que retorna a categoria.    
    virtual string get_categoria();
/// Método que retorna o tipo do filme.
    virtual string get_tipo() override;
/// Método que calcula o valor da locação, com base na quantidade de dias.
    float calc_valor_locacao (int dias) const override;



};

#endif
