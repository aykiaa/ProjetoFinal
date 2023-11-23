#include "Locadora.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>

//Desenvolvimento classe locadora
Locadora::Locadora( string nome ) : _Nome(nome) 
{
    string nome_arquivo_logs = "Alugueis_" + nome + "_log.txt";
    _Logs.open( nome_arquivo_logs, ios::app);
    ControleEstoque _Controle_Estoque;
    ControleClientes _Controle_Clientes;
}
Locadora::~Locadora() 
{
    _Logs.close();
}

void Locadora::alugar_Filme( vector<int> codigos, int cpf ){
    map <int, Filme*> *estoque = &_Controle_Estoque.getEstoque();
    vector<int> codigos_invalidos;

    for(auto it:codigos )
    {
        if( (*estoque).find(it) == (*estoque).end() )
        {
            codigos_invalidos.push_back(it);
        }
    }
    
}

//Inserção do controle de filmes na classe locadora
Locadora::ControleEstoque::ControleEstoque() {}
Locadora::ControleEstoque::~ControleEstoque() //Desalocando ponteiros dos filmes 
{
    for( auto t = _Estoque.begin(); t != _Estoque.end(); t++ ) {
        delete _Estoque.at(t->first);
        _Estoque.erase(t);
    }
}

map <int, Filme*> Locadora::ControleEstoque::getEstoque() { return _Estoque; }

void Locadora::ControleEstoque::ler_Arquivo_de_Estoque( string nome_do_arquivo )
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

void Locadora::ControleEstoque::cadastrar_Filme( bool file, char tipo, int quantidade, int codigo, string titulo, string categoria ) 
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

void Locadora::ControleEstoque::remover_Filme( int codigo )
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

void Locadora::ControleEstoque::imprimir_Estoque( char tipo_ordenacao)
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

//Inserçào do controle de clientes na classe locadora
Locadora::ControleClientes::ControleClientes(){};
Locadora::ControleClientes::~ControleClientes(){};

void Locadora::ControleClientes::cadastrar_cliente(int cpf, string nome){
    if (any_of(_clientes.begin(), _clientes.end(), [cpf](const Cliente& cliente1) { return cliente1.get_cpf() == cpf;}))
    {
        cout << "ERRO: CPF repetido" << endl;
    }
    else if (cpf <=  0 || nome.empty())
    {
        cout << "ERRO: dados incorretos" << endl;
    }
    else
    {
        _clientes.emplace_back(cpf, nome);
        cout << "Cliente " << cpf << " cadastro com sucesso" << endl;
    };
}

void Locadora::ControleClientes::remover_cliente(int cpf){
    auto it = find_if(_clientes.begin(), _clientes.end(), [cpf] (const Cliente cliente1){ 
        return cliente1.get_cpf() == cpf;});
    
    if (it != _clientes.end())
    {
        _clientes.erase(it);
        cout << "Cliente " << cpf << " removido com sucesso" << endl;
    }
    else{
        cout << "ERRO: CPF inexistente" << endl;
    };
}

void Locadora::ControleClientes::imprimir_clientes(char tipo_ordenacao){
    vector <Cliente> clientes_ordernados = _clientes;
    if ( tipo_ordenacao == 'C')
    {
        sort(clientes_ordernados.begin(), clientes_ordernados.end(), [](const Cliente& c1, const Cliente& c2){
                return c1.get_cpf () < c2.get_cpf();
            });
    }
    
    else if ( tipo_ordenacao == 'N')
    {
        sort(clientes_ordernados.begin(), clientes_ordernados.end(), [](const Cliente& c1, const Cliente& c2){
                return c1.get_nome () <= c2.get_nome();
            });
    }

    for (const auto &cliente : clientes_ordernados)
    {
        cout << cliente.get_cpf() << " " << cliente.get_nome() << endl;
    };
}

Cliente* Locadora::ControleClientes::buscar_cliente(int cpf){
    auto it = find_if(_clientes.begin(), _clientes.end(), [cpf](const Cliente& cliente) {
        return cliente.get_cpf() == cpf;
    });

    if (it != _clientes.end()) {
        return &(*it); //retorna um apontador q vai ser usado para a funcao de printar os filmes alugados por tal cliente
    } 
    
    else 
    {
        cout << "ERRO: CPF inexistente" << endl;
        return nullptr;
    }
}