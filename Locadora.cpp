#include "Locadora.hpp"
#include <algorithm>

//Desenvolvimento classe locadora
Locadora::Locadora( string nome ) : _Nome(nome) {}
Locadora::~Locadora() {}


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

void Locadora::ControleEstoque::cadastrar_Filme( char tipo, int quantidade, int codigo, string titulo, string categoria ) 
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
        }
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

void Locadora::ControleClientes::listar_clientes(char tipo_ordenacao){
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
                return c1.get_nome () < c2.get_nome();
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
        cout << "Nenhum cliente foi encontrado" << endl;
        return nullptr;
    }
}