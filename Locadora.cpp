/*/ Implementação da classe Locadora, que gerencia as operações da locadora de filmes.

O construtor Locadora(string nome) inicializa os membros, incluindo o nome da locadora e o objeto de log.

O destrutor realiza a limpeza dos recursos dinamicamente tanto para clientes quanto para filmes.

A classe fornece métodos para operações como:

1- Alugar e devolver filmes
2- Cadastrar e remover clientes
3- Imprimir clientes ordenados
4- Buscar clientes por CPF
5- Obter o estoque
6- Ler informações de um arquivo de estoque
7- Cadastrar e remover filmes do estoque
8- Imprimir o estoque ordenado.

O método alugar_Filme lida com a locação de filmes, separando os códigos de filmes válidos e inválidos, atualizando o estoque e registrando as operações no log. O método devolver_Filme trata a devolução de filmes, calculando o valor a ser pago pelo cliente com base nos filmes devolvidos e registrando no log.

Os métodos de controle de estoque (ler_Arquivo_de_Estoque, cadastrar_Filme, remover_Filme, imprimir_Estoque) realizam operações relacionadas ao estoque de filmes.

Os métodos de controle de clientes (cadastrar_cliente, remover_cliente, imprimir_clientes, buscar_cliente) tratam a gestão de clientes, incluindo a adição, remoção e impressão de clientes.

Resumindo o código implementa a lógica principal para gerenciar as operações da nossa locadora, manipulando o estoque de filmes, operações de aluguel e devolução, além do cadastro e remoção de clientes. O código utiliza recursos como leitura de arquivos, manipulação de strings e operações sobre containers, como vetores e mapas./*/

#include "Locadora.hpp"
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <map>

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
    vector <Filme*> *filmes_alugados = &(this->buscar_cliente( cpf )->_Filmes_Alugados);
    
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
    for( auto filme_devolvido = filmes_alugados->back(); filme_devolvido == filmes_alugados->front(); filme_devolvido-- ){
        filme_devolvido->_qtd_disp += 1;
        float valor_por_filme = filme_devolvido->calc_valor_locacao( rand() % 14 + 1 );
        valor_a_pagar += valor_por_filme;
        filmes_alugados->pop_back();

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

//Controle do Estoque
map <int, Filme*> Locadora::getEstoque() { return _Estoque; }

void Locadora::ler_Arquivo_de_Estoque( string nome_do_arquivo )
{
    ifstream arquivo_de_filmes;
    arquivo_de_filmes.open( nome_do_arquivo );

    char tipo;
    int quantidade, codigo, contador;
    string titulo, categoria, linha_do_arquivo, input, aux1, aux;

    int numero_de_filmes = 0;
    if( arquivo_de_filmes.is_open() )
    {
        while( getline( arquivo_de_filmes, linha_do_arquivo ) )
        {   
            contador = 0;
            stringstream aux;
            aux << " " << linha_do_arquivo << " ";
            //cout << linha_do_arquivo << endl;
            while(getline(aux, input, ' ')){
                cout << input << " ";
                stringstream aux1;
                aux1 << input;
                switch( contador ){
                    case (0) : 
                        aux1 >> tipo;
                        contador ++;
                        break;
                    case (1) :
                        aux1 >> quantidade;
                        contador ++;
                        break;
                    case (2) :
                        aux1 >> codigo;
                        contador ++;
                        break;
                    case (3) :
                        aux1 >> titulo;
                        contador ++;
                        break;
                    case (4) :
                        if(tipo == 'D') aux1 >> categoria;
                        else if(tipo == 'F') categoria = "";
                        contador = 0;
                        break;
                default : break;
                }
                cout << endl;
            }
            //istream >> tipo >> quantidade >> codigo >> titulo >> categoria;
            cout << tipo << " " << quantidade << " " << codigo << " " << titulo << " " << categoria << endl;
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
        
        Filme* Novo_Filme = new DVD(codigo, titulo, quantidade, categoria);
        _Estoque.emplace(codigo, Novo_Filme);
        if( !file )
        {
        cout << "Filme " << codigo << " cadastrado com sucesso" << endl;
        }
        
    }
    else if(tipo == 'F')
    {
        if( categoria != "" )
        {
            cout << "ERRO: dados incorretos" << endl;
        }
        
        Filme* Novo_Filme = new Fita(codigo, titulo, quantidade);
        _Estoque.emplace(codigo, Novo_Filme);
        if( !file )
        {
        cout << "Filme " << codigo << " cadastrado com sucesso" << endl;
        }
    }
}

void Locadora::remover_Filme( int codigo )
{
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
{
    vector <Filme*> filmes_ordenados;
    for( auto it : _Estoque )
    {
        filmes_ordenados.push_back( it.second );
    }

    if( tipo_ordenacao == 'T' )
    {
        sort  
        ( 
            filmes_ordenados.begin(), 
            filmes_ordenados.end(), 
            [](const Filme* F1,const Filme* F2 ) { return F1->get_titulo() <= F2->get_titulo(); } 
        );
        for( Filme* it : filmes_ordenados ) 
        {
            cout << it->get_id() << " " 
            <<  it->get_titulo() << " " 
            << it->get_qtdDisp() << " " 
            << it->get_categoria() << endl;
        }
    }
    else if(tipo_ordenacao == 'C'){
        sort  
        ( 
            filmes_ordenados.begin(), 
            filmes_ordenados.end(), 
            [](const Filme* F1,const Filme* F2 ) { return F1->get_id() <= F2->get_id(); } 
        );
        for( Filme* it : filmes_ordenados ) 
        {
            cout << it->get_id() << " " 
            <<  it->get_titulo() << " " 
            << it->get_qtdDisp() << " " 
            << it->get_categoria() << endl;
        }
    }
    else if( tipo_ordenacao != 'C' )
    {
        cout << "ERRO: comando invalido" << endl;
        
    }


}

//Controle de Clientes

void Locadora::cadastrar_cliente( int cpf , string nome){
    
    if( any_of(_Clientes.begin(), _Clientes.end(), 
        [cpf](const Cliente* C) {return C->get_cpf() == cpf;} ) == true )
    {
        cout << "ERRO: CPF repetido" << endl;
    }

    else if (cpf <=  0 || nome.empty() || to_string(cpf).length() != 11) //Verifica se o CPF informado eh valido
    {
        cout << "ERRO: dados incorretos" << endl;
    }
    
    else
    {
        Cliente* novo_cliente = new Cliente(cpf, nome);
        _Clientes.emplace_back(novo_cliente);
        cout << "Cliente " << cpf << " cadastrado com sucesso" << endl;
    }
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
                return c1->get_nome () < c2->get_nome();
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
    }
    cout << "ERRO: CPF inexistente" << endl;
    return nullptr;
}
