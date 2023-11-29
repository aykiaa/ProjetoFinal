/// Cabecalho da classe Locadora, que fornece metodos publicos para as operacoes relacionadas a gestao de filmes, clientes e estoque. Alem disso, a classe inclui membros privados, como o nome da locadora, um objeto para registros de log, um mapa que mapeia identificadores para objetos da classe Filme e um vetor de clientes.

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

/// **Classe Locadora**

class Locadora
{
    private:
        string _Nome;
        ofstream _Logs;
        map <int, Filme*> _Estoque;
        vector <Cliente*> _Clientes;
    public:
/// Construtor da classe Locadora que inicializa o nome e abre o arquivo de logs.
        Locadora( string nome );
 /// Destrutor da classe Locadora que libera a memória alocada para clientes e filmes.
        ~Locadora();
/// Obtém o nome da locadora.
        void getNome();
/// Funções relacionadas a alugar e devolver filmes.
        void alugar_Filme( vector<int> codigos, long cpf );
        void devolver_Filme( long cpf );
/// Funções relacionadas ao cadastro, remoção, impressão e busca de clientes.
        void cadastrar_cliente( long cpf, string nome);
        void remover_cliente(long cpf);
        void imprimir_clientes(char tipo_ordenacao);
        Cliente* buscar_cliente(long cpf);
/// Métodos relacionados ao estoque de filmes.
        map <int, Filme*> getEstoque();
                
        void ler_Arquivo_de_Estoque( string nome_do_arquivo );
        void cadastrar_Filme( bool file, char tipo, int quantidade, int codigo, string titulo, string categoria ); //BOOL FILE DEVERÁ SER PREENCHIDO COMO 0 NO MAIN!!!
        void remover_Filme( int codigo );
        void imprimir_Estoque( char tipo_ordenacao );

};


#endif
