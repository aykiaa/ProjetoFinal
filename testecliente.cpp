#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "cliente.hpp"

TEST_CASE("Construtor Cliente") {
    Cliente cliente1(11243658900, "Gilberto");
    Cliente cliente2(13179912634, "Edenilson");

    CHECK(cliente1.get_cpf() == 11243658900);
    CHECK(cliente1.get_nome() == "Gilberto"); 

    CHECK(cliente2.get_cpf() == 13179912634); 
    CHECK(cliente2.get_nome() == "Edenilson"); 

    
}

