//! Cabecalho da classe Locadora, que fornece metodos publicos para as operacoes relacionadas a gestao de filmes, clientes e estoque. Alem disso, a classe inclui membros privados, como o nome da locadora, um objeto para registros de log, um mapa que mapeia identificadores para objetos da classe Filme e um vetor de clientes.

#ifndef LOCADORA_H
#define LOCADORA_H

#include "Filme.hpp"
#include "dvd.hpp"
#include "fita.hpp"
#include "cliente.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;


class Locadora
{
    private:
        string _Nome;
        ofstream _Logs;
        map <int, Filme*> _Estoque;
        vector <Cliente*> _Clientes;
    public:
        Locadora( string nome );
        ~Locadora();

        void getNome();

        void alugar_Filme( vector<int> codigos, long cpf );
        void devolver_Filme( long cpf );

        void cadastrar_cliente( long cpf, string nome);
        void remover_cliente(long cpf);
        void imprimir_clientes(char tipo_ordenacao);
        Cliente* buscar_cliente(long cpf);

        map <int, Filme*> getEstoque();
                
        void ler_Arquivo_de_Estoque( string nome_do_arquivo );
        void cadastrar_Filme( bool file, char tipo, int quantidade, int codigo, string titulo, string categoria ); //BOOL FILE DEVERÁ SER PREENCHIDO COMO 0 NO MAIN!!!
        void remover_Filme( int codigo );
        void imprimir_Estoque( char tipo_ordenacao );

};


#endif
