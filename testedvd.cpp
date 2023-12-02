#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dvd.hpp"

DVD dvd_A(1, "DVD", 15, "Lancamento");
DVD dvd_B(2, "DVD1", 10, "Estoque");

DVD dvd_1(3, "DVD 1", 5, "Lancamento");
DVD dvd_2(4, "DVD 2", 7, "Estoque");
DVD dvd_3(5, "DVD 3", 3, "Promocao");
DVD dvd_4(6, "DVD 4", 2, "CategoriaInvalida");

TEST_CASE("Construtor DVD") {
  CHECK(dvd_A.get_id() == 1);
  CHECK(dvd_A.get_titulo() == "DVD");
  CHECK(dvd_A.get_qtdDisp() == 15);
  CHECK(dvd_A.get_categoria() == "Lancamento");
}

TEST_CASE("Métodos DVD") {
  CHECK(dvd_B.get_categoria() == "Estoque");
  CHECK(dvd_B.get_tipo() == "DVD");
}

TEST_CASE("Valor de Locação do DVD") {
  CHECK(dvd_1.calc_valor_locacao(2) == 40.0);
  CHECK(dvd_2.calc_valor_locacao(3) == 30.0);
  CHECK(dvd_3.calc_valor_locacao(5) == 10.0);
  CHECK(dvd_4.calc_valor_locacao(2) == 0.0);
}
