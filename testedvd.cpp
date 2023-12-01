#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dvd.hpp"

TEST_CASE("Construtor DVD") {
  DVD dvd(1, "DVD", 15, "Lancamento");

  CHECK(dvd.get_id() == 1);
  CHECK(dvd.get_titulo() == "DVD");
  CHECK(dvd.get_qtdDisp() == 15);
  CHECK(dvd.get_categoria() == "Lancamento");
}

TEST_CASE("Métodos DVD") {
  DVD dvd(2, "DVD1", 10, "Estoque");

  CHECK(dvd.get_categoria() == "Estoque");
  CHECK(dvd.get_tipo() == "DVD");
}

TEST_CASE("Valor de Locação do DVD") {
  DVD dvd1(3, "DVD 1", 5, "Lancamento");
  DVD dvd2(4, "DVD 2", 7, "Estoque");
  DVD dvd3(5, "DVD 3", 3, "Promocao");
  DVD dvd4(6, "DVD 4", 2, "CategoriaInvalida");

  CHECK(dvd1.calc_valor_locacao(2) == 40.0);
  CHECK(dvd2.calc_valor_locacao(3) == 30.0);
  CHECK(dvd3.calc_valor_locacao(5) == 10.0);
  CHECK(dvd4.calc_valor_locacao(2) == 0.0);
}
