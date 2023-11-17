#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Cliente
{
private:
    string _nome;
    int _cpf;

public:
    Cliente(int cpf, string nome);
    ~Cliente();

    string get_nome() const;
    int get_cpf() const;

};

class ControleClientes
{
private:
    vector <Cliente> _clientes;
public:
    ControleClientes();
    ~ControleClientes();

    void cadastrar_cliente(int cpf, string nome);
    void remover_cliente(int cpf);
    void listar_clientes(char tipo_ordenacao);
    Cliente* buscar_cliente(int cpf);
};


#endif