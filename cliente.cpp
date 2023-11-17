#include "cliente.hpp"
#include <algorithm>


Cliente::Cliente(int cpf, string nome) : _cpf(cpf),  _nome(nome){};

Cliente::~Cliente(){};


int Cliente::get_cpf() const{
    return  _cpf;
}

string Cliente::get_nome() const{
    return _nome;
}

ControleClientes::ControleClientes(){};
ControleClientes::~ControleClientes(){};

void ControleClientes::cadastrar_cliente(int cpf, string nome){
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

void ControleClientes::remover_cliente(int cpf){
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

void ControleClientes::listar_clientes(char tipo_ordenacao){
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

Cliente* ControleClientes::buscar_cliente(int cpf){
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