#ifndef LOCADORA_H
#define LOCADORA_H

#include "Filmes.hpp"
#include "dvd.hpp"
#include "fita.hpp"
#include "cliente.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Locadora 
    {
    private:
        string _Nome;

    public:
        Locadora( string nome );
        ~Locadora();

        void getNome();

        class ControleClientes
        {
            private:
                vector <Cliente> _clientes;
            public:
                ControleClientes();
                ~ControleClientes();

                void cadastrar_cliente(int cpf, string nome);
                void remover_cliente(int cpf);
                void listar_clientes(char tipo_ordenacao);
                Cliente* buscar_cliente(int cpf);
        };

        class ControleEstoque
        {
            private:
                map <int, Filme*> _Estoque; //Filmes são guardados em um mapa pelo código e apontador ao filme
            public:
                ControleEstoque();
                ~ControleEstoque();

                map <int, Filme*> getEstoque();
                
                void ler_Arquivo_de_Estoque( string nome_do_arquivo );
                void cadastrar_Filme( char tipo, int quantidade, int codigo, string titulo, string categoria );
                void remover_Filme( int codigo );
                void imprimir_Estoque();
        };
};


#endif