/// Definicao da classe DVD, que herda caracteristicas da classe base Filme e adiciona funcionalidades especificas para DVDs no sistema da locadora.

/// O construtor da classe DVD e utilizado para inicializar os atributos da classe, incluindo um (id), um título, a quantidade disponivel, e uma categoria especifica.

/// O destrutor realiza a limpeza quando um objeto DVD e removido.

/// A funcao get_categoria() retorna a categoria do DVD.

/// A funcao calc_valor_locacao(int dias) calcula o valor de locacao do DVD com base no número de dias para os quais o cliente deseja aluga-lo.

/// O valor e determinado pela categoria do DVD:

/// 1- "Lançamento", o custo é de 20.0 reais por dia;
/// 2- "Estoque", o custo é de 10.0 reais por dia;
/// 3- "Promoção", o custo é fixo em 10.0 reais;
/// 4- Caso contrario, uma mensagem de erro é exibida indicando uma categoria invalida, e o valor de retorno é 0.0.

#include "dvd.hpp"

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
