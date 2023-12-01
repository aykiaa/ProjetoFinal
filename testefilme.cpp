#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Filme.hpp"

TEST_CASE("Testes Filme") {
    SUBCASE("Teste construtor e métodos") {
        Filme filme(1, "Avatar", 3);
        CHECK_EQ(filme.get_id(), 1);
        CHECK_EQ(filme.get_titulo(), "Avatar");
        CHECK_EQ(filme.get_qtdDisp(), 3);
    }

}
