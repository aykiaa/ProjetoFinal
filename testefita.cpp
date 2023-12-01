#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fita.hpp"

TEST_CASE("Construção e Destruição da Fita") {
    Fita fita(1, "Fita", 10);

    CHECK(fita.get_id() == 1); 
    CHECK(fita.get_titulo() == "Fita"); 
    CHECK(fita.get_qtdDisp() == 10); 
    CHECK((fita.get_isRebobinada() == true || fita.get_isRebobinada() == false)); 

    
}

TEST_CASE("Métodos de Acesso da Fita") {
    Fita fita(2, "Fita2", 5);

    CHECK(fita.get_categoria() == ""); 
    CHECK(fita.get_tipo() == "FITA"); 

}

TEST_CASE("Valor de Locação") {
    Fita fita1(3, "Fita3", 8); 
  

    
    CHECK(fita1.calc_valor_locacao(1) == 7.0 || fita1.calc_valor_locacao(1) == 5.0);
    CHECK(fita1.calc_valor_locacao(3) == 7.0 || fita1.calc_valor_locacao(3) == 5.0); 
    CHECK(fita1.calc_valor_locacao(7) == 7.0 || fita1.calc_valor_locacao(7) == 5.0); 

    
    CHECK(fita1.calc_valor_locacao(-1) == 7.0 || fita1.calc_valor_locacao(-1) == 5.0);
}

