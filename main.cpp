/// Programa principal de gerenciamento das operacoes da locadora, utilizando as classes Filme, DVD, Fita, Cliente e Locadora.

/// No loop principal, o programa lê comandos do usuario, como a leitura de um arquivo de estoque, cadastro e remoção de filmes, cadastro e remoção de clientes, impressao de estoque, locação e devolução de filmes, entre outras operações.

/// Por fim, o programa continua executando até que o comando "FS" seja inserido, encerrando a execucao.

#include <iostream>
#include <string>
#include "Filme.hpp"
#include "dvd.hpp"
#include "cliente.hpp"
#include "fita.hpp"
#include "Locadora.hpp"

#include <sstream>
#include <algorithm>
#include <ctype.h>

using namespace std;
/// Função auxiliar que verifica se um caractere nao e numerico.
bool isNotNumeric(const char& c){
    if ( isdigit(c) ) 
        return false;
    else 
        return true;
};
/// Função principal que gerencia as operacoes da locadora.
int main(){
    string comando;
    Locadora localiza("localiza");
    while(cin>>comando){
        if(comando=="LA"){
            string nome_arquivo;
            cin >> nome_arquivo;
            localiza.ler_Arquivo_de_Estoque( nome_arquivo );
        }
        else if(comando=="CF"){
            int codigo, quantidade;
            char tipo;
            string titulo, categoria;
            cin >> tipo;
            cin >> quantidade;
            cin >> codigo;
            cin >> titulo;
              if(tipo == 'D')
                cin >> categoria;
              else
                categoria = "";
            localiza.cadastrar_Filme(0, tipo, quantidade, codigo, titulo, categoria);
        }
        else if(comando=="RF"){
            int codigo;
            cin >> codigo;
            localiza.remover_Filme( codigo );
        }
        else if(comando=="LF"){
            char letra;
            cin >> letra;
            localiza.imprimir_Estoque( letra );
        }
        else if(comando=="CC"){
            long cpf;
            string nome;
            cin>>cpf;
            cin>>nome;
            localiza.cadastrar_cliente(cpf,nome);
        }
        else if(comando=="RC"){
            long cpf;
            cin>>cpf;
            localiza.remover_cliente(cpf);
        }
        else if(comando=="LC"){
            char letra;
            cin>>letra;
            localiza.imprimir_clientes(letra);
        }
        else if(comando=="AL"){
            vector<int> codigos;
            long cpf, novo_codigo;
            cin >> cpf;
            string string_codigo, linha_input;

            getline(cin, linha_input);
            stringstream istream;
            istream << " " << linha_input << " ";

            while( getline(istream, string_codigo, ' ') ){
                if( any_of( string_codigo.begin(), string_codigo.end(), isNotNumeric) ) {}
                else if( string_codigo.empty() == true ) {}
                else {
                    stringstream stream_codigos;
                    stream_codigos << string_codigo;
                    stream_codigos >> novo_codigo;
                    codigos.push_back( novo_codigo );
                }
            }

            localiza.alugar_Filme(codigos, cpf);
        }
        else if(comando=="DV"){
            long cpf;
            cin>>cpf;
            localiza.devolver_Filme(cpf);
        }
        else if(comando=="FS"){
            break;
        }
        else
            cout << "ERRO: comando inexistente" << endl;
        
    }


return 0;
}
