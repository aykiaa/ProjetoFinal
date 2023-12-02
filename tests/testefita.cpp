#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fita.hpp"
#include <set>
#include <iostream>

Fita fita1(1, "Fita", 10);
Fita fita2(2, "Fita2", 5);
Fita fita3(3, "Fita3", 8);

TEST_CASE("Construção e Destruição da Fita") {
    CHECK(fita1.get_id() == 1); 
    CHECK(fita1.get_titulo() == "Fita"); 
    CHECK(fita1.get_qtdDisp() == 10); 

    std::set<bool> valores_booleanos = {true, false};
    CHECK(valores_booleanos.count( fita1.get_isRebobinada() ) > 0);
    
}

TEST_CASE("Métodos de Acesso da Fita") {
    CHECK(fita2.get_categoria() == ""); 
    CHECK(fita2.get_tipo() == "FITA"); 
}

TEST_CASE("Valor de Locação") {
    if(fita3.get_isRebobinada() == true){
        CHECK(fita3.calc_valor_locacao(1) == 5.0);
        CHECK(fita3.calc_valor_locacao(3) == 5.0);
        CHECK(fita3.calc_valor_locacao(7) == 5.0);
        CHECK(fita3.calc_valor_locacao(-1) == 5.0);
    }   
    else{
        CHECK(fita3.calc_valor_locacao(1) == 7.0);
        CHECK(fita3.calc_valor_locacao(3) == 7.0); 
        CHECK(fita3.calc_valor_locacao(7) == 7.0);     
        CHECK(fita3.calc_valor_locacao(-1) == 7.0);
    }
}