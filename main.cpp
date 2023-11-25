#include <iostream>
#include <string>
#include "Filme.hpp"
#include "dvd.hpp"
#include "cliente.hpp"
#include "fita.hpp"
#include "Locadora.hpp"

#include <sstream>

using namespace std;

int main(){
    string comando;
    Locadora localiza("localiza");
    while(1){
        cin>>comando;
        if(comando=="LA"){
            
        }
        else if(comando=="CF"){

        }
        else if(comando=="RF"){
            
        }
        else if(comando=="LF"){
            
        }
        else if(comando=="CC"){
            int cpf;
            string nome;
            cin>>cpf;
            cin>>nome;
            localiza.cadastrar_cliente(cpf,nome);
        }
        else if(comando=="RC"){
            int cpf;
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
            int cpf, novo_codigo;
            cin >> cpf;
            string string_codigo;

            while( getline(cin, string_codigo, ' ') ){
                stringstream stream_codigos;
                stream_codigos << string_codigo;
                stream_codigos >> novo_codigo;
                cout<<novo_codigo<<endl;
                codigos.push_back( novo_codigo );
            }

            localiza.alugar_Filme(codigos, cpf);
        }
        else if(comando=="DV"){
            
        }
        else if(comando=="FS"){
            
        }
        
    }


return 0;
}












