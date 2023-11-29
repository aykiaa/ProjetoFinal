/// Implementacao da classe Locadora, que gerencia as operacoes da locadora de filmes.

/// A classe fornece metodos para operacoes como:

/// 1- Alugar e devolver filmes
/// 2- Cadastrar e remover clientes
/// 3- Imprimir clientes ordenados
/// 4- Buscar clientes por CPF
/// 5- Obter o estoque
/// 6- Ler informacoes de um arquivo de estoque
/// 7- Cadastrar e remover filmes do estoque
/// 8- Imprimir o estoque ordenado.

/// O metodo alugar_Filme lida com a locacao de filmes, separando os codigos de filmes validos e invalidos, atualizando o estoque e registrando as operações no log. O metodo devolver_Filme trata a devolucao de filmes, calculando o valor a ser pago pelo cliente com base nos filmes devolvidos e registrando no log.

/// Os metodos de controle de estoque (ler_Arquivo_de_Estoque, cadastrar_Filme, remover_Filme, imprimir_Estoque) realizam operacoes relacionadas ao estoque de filmes.

/// Os metodos de controle de clientes (cadastrar_cliente, remover_cliente, imprimir_clientes, buscar_cliente) tratam a gestao de clientes, incluindo a adicao, remocao e impressao de clientes.

/// Resumindo o codigo implementa a logica principal para gerenciar as operacoes da nossa locadora, manipulando o estoque de filmes, operacoes de aluguel e devolução, alem do cadastro e remocao de clientes. Ele utiliza recursos como leitura de arquivos, manipulacao de strings e operacoes sobre containers, como vetores e mapas.

#include "Locadora.hpp"
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <map>

//Desenvolvimento classe locadora
Locadora::Locadora( string nome ) : _Nome(nome) 
{ /// O construtor Locadora(string nome) inicializa os membros, incluindo o nome da locadora e o objeto de log.
    string nome_arquivo_logs = "Alugueis_" + nome + "_log.txt";
    _Logs.open( nome_arquivo_logs, ios::trunc);
}

Locadora::~Locadora() 
{ /// O destrutor realiza a limpeza dos recursos de forma dinamica, tanto para clientes quanto para filmes.
    for( auto it = _Clientes.back(); it != _Clientes.front(); it-- ){
        delete it;
        _Clientes.pop_back();
    }
    for( auto it:_Estoque ){
        delete it.second;
        _Estoque.erase( it.first );
    }
    _Logs.close();
}

void Locadora::alugar_Filme( vector<int> codigos, long cpf )
{
    if ( this->buscar_cliente( cpf ) == nullptr ) { return; };

    /// Separando codigos em validos e invalidos
    vector<int> codigos_invalidos;
    vector<Filme*> filmes_alugados;
    for( auto id_novo_filme:codigos ) 
    {
        if( _Estoque.find( id_novo_filme ) == _Estoque.end() )
        {
            codigos_invalidos.push_back( id_novo_filme );
        }
        else
        {
            filmes_alugados.push_back( _Estoque.at( id_novo_filme ) );
        }
    }
    
    /// Streams para impressao do log
    if( filmes_alugados.empty() == false ){
        
        stringstream stream_cliente;
        stream_cliente << "Cliente " << cpf << " " 
        << this->buscar_cliente( cpf )->get_nome()
        << " alugou os filmes:" << endl;

        string linha_cliente;
        getline (stream_cliente, linha_cliente);
        cout << linha_cliente << endl;
        _Logs << linha_cliente << endl;
        //
    }

    for( auto novo_filme:filmes_alugados ) /// Vetor filmes de codigos validos
    {
        if( novo_filme->get_qtdDisp() > 0 ){
            novo_filme->_qtd_disp -= 1;

            this->buscar_cliente( cpf )->_Filmes_Alugados.push_back( novo_filme );

            /// Streams para impressao do log
            stringstream stream_linha;
            stream_linha << novo_filme->get_id() 
            << " " << novo_filme->get_titulo()
            << " " << novo_filme->get_tipo();

            string linha;
            getline(stream_linha, linha);
            cout << linha << endl;
            _Logs << linha << endl;
            
        }
        else 
            cout << "ERRO: " 
            << novo_filme->get_id() 
            << " " << novo_filme->get_titulo() 
            << " " << novo_filme-> get_categoria() << "indisponivel" << endl; 
    }

    for( auto t:codigos_invalidos ) /// Vector codigos invalidos
    {
        cout << "ERRO: Filme " << t << " inexistente" << endl;
    }
    
}

void Locadora::devolver_Filme( long cpf ){
    if ( this->buscar_cliente( cpf ) == nullptr ) { return; };

    vector <Filme*> *filmes_alugados = &(this->buscar_cliente( cpf )->_Filmes_Alugados);
    float valor_a_pagar = 0.0;
    float valor_por_filme = 0.0;
    int dias = rand() % 14 + 1;
    
        /// Streams para impressão do Log
        stringstream stream_cliente;
        stream_cliente << "Cliente " << cpf << " " 
        << this->buscar_cliente( cpf )->get_nome()
        << " devolveu os filmes:" << endl;

        string linha_cliente;
        getline (stream_cliente, linha_cliente);
        cout << linha_cliente << endl;
        _Logs << linha_cliente << endl;
        

    for( auto filme_devolvido : (*filmes_alugados) ){
        filme_devolvido->_qtd_disp += 1;
        valor_por_filme = filme_devolvido->calc_valor_locacao(dias);
        valor_a_pagar += valor_por_filme;

            /// Streams para impressão do Log
            stringstream stream_filme;
            stream_filme << filme_devolvido->get_id() 
            << " R$" << valor_por_filme;

            string linha_filme;
            getline(stream_filme, linha_filme);
            cout << linha_filme << endl;
            _Logs << linha_filme << endl;
            
    }
    filmes_alugados->clear();

    cout << "Total a pagar: R$" << valor_a_pagar << endl;
    _Logs << "Total pago: R$" << valor_a_pagar << endl;
}

/// Controle do Estoque
map <int, Filme*> Locadora::getEstoque() { return _Estoque; }

void Locadora::ler_Arquivo_de_Estoque( string nome_do_arquivo )
{ /// Faz a leitura de um aquivo do estoque
    ifstream arquivo_de_filmes;
    arquivo_de_filmes.open( nome_do_arquivo );

    char tipo;
    int quantidade, codigo, contador;
    string titulo, categoria, linha_do_arquivo;

    int numero_de_filmes = 0;
    if( arquivo_de_filmes.is_open() )
    {
        while( getline( arquivo_de_filmes, linha_do_arquivo ) )
        {   
            stringstream stream_linha_do_arquivo;
            stream_linha_do_arquivo << linha_do_arquivo;
            stream_linha_do_arquivo >> tipo >> quantidade >> codigo >> titulo >> categoria;

            this->cadastrar_Filme(1, tipo, quantidade, codigo, titulo, categoria);
            numero_de_filmes += 1;
        }
        arquivo_de_filmes.close();
        cout << numero_de_filmes << " Filmes cadastrados com sucesso" << endl;
    }
    else 
        cout << "ERRO: arquivo inexistente" << endl; 
}

void Locadora::cadastrar_Filme( bool file, char tipo, int quantidade, int codigo, string titulo, string categoria ) 
{ /// funcao responsavel pelo cadastro de filmes
    //CONFERINDO DADOS
    //OBS: NO MAIN, CONFERIR INPUT DE DADOS E IMPRIMIR ERROS ANTES DE CHAMAR A FUNÇÃO    

    if( _Estoque.find( codigo ) != _Estoque.end() )
    {
        cout << "ERRO: codigo repetido" << endl;
        return;
    }

    switch(tipo){
        case('D') : {
            if( categoria == "" && file == false){
                cout << "ERRO: dados incorretos" << endl;
                return;
            }
            else{
                Filme* Novo_Filme = new DVD(codigo, titulo, quantidade, categoria);
                _Estoque.emplace(codigo, Novo_Filme);
            }
        }
        case ('F') : {
            if( categoria != "" && file == false){
                cout << "ERRO: dados incorretos" << endl;
                return;
            }
            else{
                Filme* Novo_Filme = new Fita(codigo, titulo, quantidade);
                _Estoque.emplace(codigo, Novo_Filme);
            }
        }
        default : {
            if(!file){
                cout << "ERRO: dados incorretos" << endl;
                return;
            }
        }
    }

    if( file == false ) {
        cout << "Filme " << codigo << " cadastrado com sucesso" << endl;
    }
}

void Locadora::remover_Filme( int codigo )
{ /// Remove um filme
    if( _Estoque.find( codigo ) != _Estoque.end() )
    {
        delete _Estoque.find( codigo )->second;
        _Estoque.erase( codigo );
        cout << "Filme " << codigo << " removido com sucesso" << endl;
    }
    else 
    {
        cout << "ERRO: codigo inexistente" << endl;
    }
}

void Locadora::imprimir_Estoque( char tipo_ordenacao)
{ /// Retorna os titulos que estao em estoque em ordem.
    vector <Filme*> filmes_ordenados;
    for( auto it : _Estoque )
    {
        filmes_ordenados.push_back( it.second );
    }

    switch(tipo_ordenacao){
        case('T') : {
            sort( 
            filmes_ordenados.begin(), 
            filmes_ordenados.end(), 
            [](const Filme* F1,const Filme* F2 ) { return F1->get_titulo() <= F2->get_titulo(); } 
            );
            break;
        }
        case('C') : {
            sort( 
            filmes_ordenados.begin(), 
            filmes_ordenados.end(), 
            [](const Filme* F1,const Filme* F2 ) { return F1->get_id() <= F2->get_id(); } 
            );
            break;
        }
        default : {
            cout << "ERRO: comando invalido" << endl;
            return;
        }
    }

    for( Filme* it : filmes_ordenados ) {
        cout << it->get_id() << " " 
        <<  it->get_titulo() << " " 
        << it->get_qtdDisp() << " " 
        << it->get_tipo() << " "
        << it->get_categoria() << endl;
    }


}

/// Controle de Clientes
void Locadora::cadastrar_cliente( long cpf , string nome){
    
    if( any_of(_Clientes.begin(), _Clientes.end(), 
        [cpf](const Cliente* C) {return C->get_cpf() == cpf;} ) == true )
    {
        cout << "ERRO: CPF repetido" << endl;
        return;
    }

    else if (cpf <=  0 || nome.empty() || (to_string(cpf).length() != 11) ) //Verifica se o CPF informado eh valido
    {
        cout << "ERRO: dados incorretos" << endl;
        return;
    }

    else
    {
        Cliente* novo_cliente = new Cliente(cpf, nome);
        _Clientes.emplace_back(novo_cliente);
        cout << "Cliente " << cpf << " cadastrado com sucesso" << endl;
    }
}

void Locadora::remover_cliente(long cpf){ /// Remove um cliente 
    auto it = find_if(
      _Clientes.begin(), 
      _Clientes.end(), 
      [cpf] (const Cliente* cliente1){ return cliente1->get_cpf() == cpf;}
    );

    if (it != _Clientes.end())
    {
        _Clientes.erase(it);
        cout << "Cliente " << cpf << " removido com sucesso" << endl;
    }
    else{
        cout << "ERRO: CPF inexistente" << endl;
    };
}

void Locadora::imprimir_clientes(char tipo_ordenacao){ /// Retorna os clientes em ordem
    vector <Cliente*> clientes_ordernados = _Clientes;
    if ( tipo_ordenacao == 'C')
    {
        sort(clientes_ordernados.begin(), clientes_ordernados.end(), [](const Cliente* c1, const Cliente* c2){
                return c1->get_cpf () < c2->get_cpf();
            });
    }
    
    else if ( tipo_ordenacao == 'N')
    {
        sort(clientes_ordernados.begin(), clientes_ordernados.end(), [](const Cliente* c1, const Cliente* c2){
                return c1->get_nome () < c2->get_nome();
            });
    }

    for ( auto cliente : clientes_ordernados)
    {
        cout << cliente->get_cpf() << " " << cliente->get_nome() << endl;
    };
}

Cliente* Locadora::buscar_cliente(long cpf){ /// Faz a busca de clientes por CPF
    for( Cliente* it:_Clientes ){
        if( it->get_cpf() == cpf ) {
            return it; 
        }
    }
    cout << "ERRO: CPF inexistente" << endl;
    return nullptr;
}
