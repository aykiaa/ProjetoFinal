/*/ Cabeçalho da classe DVD, oferecendo métodos públicos para acessar as informaçoes dos DVDs como: categoria, quantidade, título, e id.

Dessa forma estabelecendo a estrutura básica da classe, fornecendo suas funcionalidades no sistema da locadora. /*/

#ifndef DVD_H
#define DVD_H
#include "Filme.hpp"

class DVD : public Filme {
private:
    string _categoria;

public:
    DVD(int id, string titulo, int qtd_disp, string categoria);
    ~DVD();
    
    virtual string get_categoria();

    float calc_valor_locacao (int dias) const override;



};

#endif
