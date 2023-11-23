#ifndef LOCADORA_H
#define LOCADORA_H

#include "Filmes.hpp"
#include "dvd.hpp"
#include "fita.hpp"
#include "cliente.hpp"

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


class Locadora
{
    public:
        Locadora( string nome );
        ~Locadora();

        void getNome();

        void alugar_Filme( vector<int> codigos, int cpf );
        void devolver_Filme();

      class ControleClientes
        {
            private:
                vector <Cliente> _clientes;
            public:
                ControleClientes();
                ~ControleClientes();

                void cadastrar_cliente(int cpf, string nome);
                void remover_cliente(int cpf);
                void imprimir_clientes(char tipo_ordenacao);
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
                void cadastrar_Filme( bool file, char tipo, int quantidade, int codigo, string titulo, string categoria ); //BOOL FILE DEVERÁ SER PREENCHIDO COMO 0 NO MAIN!!!
                void remover_Filme( int codigo );
                void imprimir_Estoque( char tipo_ordenacao );
        };
    private:
        string _Nome;
        ofstream _Logs;
        ControleEstoque _Controle_Estoque;
        ControleClientes _Controle_Clientes;

};


#endif