#include "Locadora.hpp"
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <sstream>
#define RAND_MAX 14

//Desenvolvimento classe locadora
Locadora::Locadora( string nome ) : _Nome(nome) 
{
    string nome_arquivo_logs = "Alugueis_" + nome + "_log.txt";
    _Logs.open( nome_arquivo_logs, ios::app);
}
Locadora::~Locadora() 
{
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

void Locadora::alugar_Filme( vector<int> codigos, int cpf )
{
    if ( this->buscar_cliente( cpf ) == nullptr ) { exit(1); };

    //separando codigos em validos e invalidos
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

    //Streams para impressao do log
    stringstream stream_cliente;
    stream_cliente << "Cliente " << cpf << " " 
    << this->buscar_cliente( cpf )->get_nome()
    << " alugou os filmes:" << endl;

    string linha_cliente;
    getline (stream_cliente, linha_cliente);
    cout << linha_cliente << endl;
    _Logs << linha_cliente << endl;
    //

    for( auto novo_filme:filmes_alugados ) //vetor filmes de codigos validos
    {
        if( novo_filme->get_qtdDisp() > 0 ){
            novo_filme->_qtd_disp -= 1;

            this->buscar_cliente( cpf )->_Filmes_Alugados.push_back( novo_filme );

            //Streams para impressao do log
            stringstream stream_linha;
            stream_linha << novo_filme->get_id() 
            << " " << novo_filme->get_titulo()
            << " " << novo_filme->get_categoria();

            string linha;
            getline(stream_linha, linha);
            cout << linha << endl;
            _Logs << linha << endl;
            //
        }
    }

    for( auto t:codigos_invalidos ) //vector codigos invalidos
    {
        cout << "ERRO: Filme " << t << " inexistente" << endl;
    }
    
}

void Locadora::devolver_Filme( int cpf ){
    if ( this->buscar_cliente( cpf ) == nullptr ) { exit(1); };
    
    //Streams para impressão do Log
    stringstream stream_cliente;
    stream_cliente << "Cliente " << cpf << " " 
    << this->buscar_cliente( cpf )->get_nome()
    << " devolveu os filmes:" << endl;

    string linha_cliente;
    getline (stream_cliente, linha_cliente);
    cout << linha_cliente << endl;
    _Logs << linha_cliente << endl;
    //
    
    float valor_a_pagar = 0;
    for( auto filme_devolvido:( this->buscar_cliente( cpf )->_Filmes_Alugados ) ){
        filme_devolvido->_qtd_disp += 1;
        float valor_por_filme = filme_devolvido->calc_valor_locacao( rand() % 14 + 1 );
        valor_a_pagar += valor_por_filme;

        //Streams para impressão do Log
        stringstream stream_filme;
        stream_filme << filme_devolvido->get_id() 
        << " R$" << valor_por_filme;

        string linha_filme;
        getline(stream_filme, linha_filme);
        cout << linha_filme << endl;
        _Logs << linha_filme << endl;
        //
    }
    cout << "Total a pagar: " << valor_a_pagar << endl;
    _Logs << "Total a pagar: " << valor_a_pagar << endl;
}

//Inserção do controle de filmes na classe locadora
map <int, Filme*> Locadora::getEstoque() { return _Estoque; }

void Locadora::ler_Arquivo_de_Estoque( string nome_do_arquivo )
{
    ifstream arquivo_de_filmes;
    arquivo_de_filmes.open( nome_do_arquivo );

    char tipo;
    int quantidade, codigo;
    string titulo, categoria, linha_do_arquivo;

    int numero_de_filmes = 0;
    if( arquivo_de_filmes.is_open() )
    {
        while( getline( arquivo_de_filmes, linha_do_arquivo ) )
        {
            stringstream linha_do_arquivo;
            linha_do_arquivo >> tipo >> quantidade >> codigo >> titulo >> categoria;
            this->cadastrar_Filme(1, tipo, quantidade, codigo, titulo, categoria);
            numero_de_filmes += 1;
        }
    }
    arquivo_de_filmes.close();
    cout << numero_de_filmes << " Filmes cadastrados com sucesso" << endl; 
}

void Locadora::cadastrar_Filme( bool file, char tipo, int quantidade, int codigo, string titulo, string categoria ) 
{
    //CONFERINDO DADOS
    //OBS: NO MAIN, CONFERIR INPUT DE DADOS E IMPRIMIR ERROS ANTES DE CHAMAR A FUNÇÃO    

    if( _Estoque.find( codigo ) != _Estoque.end() )
    {
        cout << "ERRO: codigo repetido" << endl;
    }
    else if (tipo == 'D')
    {
        if( categoria == "" )
        {
            cout << "ERRO: dados incorretos" << endl;
        }
        else{
            Filme* Novo_Filme = new DVD(codigo, titulo, quantidade, categoria);
            _Estoque.emplace(codigo, Novo_Filme);
            if( !file )
            {
            cout << "Filme " << codigo << " cadastrado com sucesso" << endl;
            }
        }
    }
    else if(tipo == 'F')
    {
        if( categoria != "" )
        {
            cout << "ERRO: dados incorretos" << endl;
        }
        else
        {
            Filme* Novo_Filme = new Fita(codigo, titulo, quantidade);
            _Estoque.emplace(codigo, Novo_Filme);
            if( !file )
            {
            cout << "Filme " << codigo << " cadastrado com sucesso" << endl;
            }
        }
    }
}

void Locadora::remover_Filme( int codigo )
{
    if( _Estoque.find( codigo ) != _Estoque.end())
    {
        delete _Estoque.at( codigo );
        _Estoque.erase( codigo );
        cout << "Filme " << codigo << " removido com sucesso" << endl;
    }
    else 
    {
        cout << "ERRO: codigo inexistente" << endl;
    }
}

void Locadora::imprimir_Estoque( char tipo_ordenacao)
{
    vector <Filme> filmes_ordenados;
    for( auto it : _Estoque )
    {
        filmes_ordenados.push_back( *it.second );
    }

    if( tipo_ordenacao == 'T' )
    {
        sort  
        ( 
            filmes_ordenados.begin(), 
            filmes_ordenados.end(), 
            [](const Filme& F1, const Filme& F2 ) { return F1.get_titulo() <= F2.get_titulo(); } 
        );
    }
    else if( tipo_ordenacao != 'C' )
    {
        cout << "ERRO: comando invalido" << endl;
        exit(1);
    }

    for( auto it : filmes_ordenados ) 
    {
        cout << it.get_id() << " " 
        <<  it.get_titulo() << " " 
        << it.get_qtdDisp() << " " 
        << it.get_categoria() << endl;
    }

}

//Controle de Clientes

void Locadora::cadastrar_cliente(int cpf, string nome){
    if (any_of(_Clientes.begin(), _Clientes.end(), [cpf](const Cliente* cliente1) { return cliente1->get_cpf() == cpf;}))
    {
        cout << "ERRO: CPF repetido" << endl;
    }
    else if (cpf <=  0 || nome.empty())
    {
        cout << "ERRO: dados incorretos" << endl;
    }
    else
    {
        _Clientes.emplace_back(cpf, nome);
        cout << "Cliente " << cpf << " cadastro com sucesso" << endl;
    };
}

void Locadora::remover_cliente(int cpf){
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

void Locadora::imprimir_clientes(char tipo_ordenacao){
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
                return c1->get_nome () <= c2->get_nome();
            });
    }

    for ( auto cliente : clientes_ordernados)
    {
        cout << cliente->get_cpf() << " " << cliente->get_nome() << endl;
    };
}

Cliente* Locadora::buscar_cliente(int cpf){
    for( Cliente* it:_Clientes ){
        if( it->get_cpf() == cpf ) {
            return it; 
        }
        else if( it == _Clientes.back() ) {
            cout << "ERRO: CPF inexistente" << endl;
            return nullptr;
        }
    }
}