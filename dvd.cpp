#include <dvd.hpp>

DVD::DVD(int id, string titulo, int qtd_disp, string categoria) : Filme(id, titulo, qtd_disp), _categoria(categoria){};

DVD::~DVD(){};

string DVD::get_categoria(){
    return _categoria;
}


float DVD::calc_valor_locacao(int dias) const {
    if (_categoria == "Lancamento")
    {
        return (20.0*dias);
    }
    else if (_categoria == "Estoque")
    {
        return (10.0*dias);
    }
    else if (_categoria == "Promocao")
    {
        return 10.0;
    }
    else
    {
        cout << "Erro: Categoria Invalida";
        return 0.0;
    }
    
}