#ifndef DVD_HPP
#define DVD_HPP
#include <Filmes.hpp>

class DVD : public Filme {
private:
    string _categoria;

public:
    DVD(int id, string titulo, int qtd_disp, string categoria);
    ~DVD();
    string get_categoria();

    float calc_valor_locacao (int dias) const override;



};

#endif