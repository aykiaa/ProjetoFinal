#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Locadora.hpp"
#include "doctest.h"

TEST_CASE("Cadasatro de clientes") {
  Locadora locadora("Americanas");

  locadora.cadastrar_cliente(131454677950, "Neris");
  locadora.cadastrar_cliente(65875432143, "Obina");

  CHECK(locadora.buscar_cliente(131454677950) != nullptr);
  CHECK(locadora.buscar_cliente(65875432143) != nullptr);

  locadora.remover_cliente(131454677950);
  CHECK(locadora.buscar_cliente(131454677950) == nullptr);
}

TEST_CASE("Cadastro de filmes") {
  Locadora locadora("Americanas2");

  locadora.cadastrar_Filme(false, 'D', 10, 1, "Superman", "Lançamento");
  locadora.cadastrar_Filme(false, 'F', 5, 2, "Batman", "");

  auto estoque = locadora.getEstoque();
  CHECK(estoque.find(1) != estoque.end());
  CHECK(estoque.find(2) != estoque.end());

  locadora.remover_Filme(1);
  CHECK(estoque.find(1) == estoque.end());
}
