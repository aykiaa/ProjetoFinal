/// Cabecalho da classe Locadora, que representa a locadora de filmes.

/// A classe inclui membros privados, como o nome da locadora, um objeto para registros de log, um mapa que mapeia identificadores para objetos da classe Filme e um vetor de clientes.

/// O construtor e responsavel por inicializar o nome da locadora e o objeto de logs.

/// O destrutor faz a limpeza.

/// A classe fornece metodos publicos para as seguintes operacoes:

/// 1- alugar e devolver filmes
/// 2- cadastrar e remover clientes
/// 3- imprimir clientes ordenados
/// 4- buscar clientes por CPF
/// 5- obter o estoque
/// 6- ler informações de um arquivo de estoque
/// 7- cadastrar e remover filmes do estoque
/// 8- imprimir o estoque ordenado.

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

        void alugar_Filme( vector<int> codigos, int cpf );
        void devolver_Filme( int cpf );

        void cadastrar_cliente( int cpf, string nome);
        void remover_cliente(int cpf);
        void imprimir_clientes(char tipo_ordenacao);
        Cliente* buscar_cliente(int cpf);

        map <int, Filme*> getEstoque();
                
        void ler_Arquivo_de_Estoque( string nome_do_arquivo );
        void cadastrar_Filme( bool file, char tipo, int quantidade, int codigo, string titulo, string categoria ); //BOOL FILE DEVERÁ SER PREENCHIDO COMO 0 NO MAIN!!!
        void remover_Filme( int codigo );
        void imprimir_Estoque( char tipo_ordenacao );

};


#endif
