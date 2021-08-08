#ifndef head_h
#define head_h

#include <iostream>
#include <string.h>
#include<map>
#include<vector>
#include <cstring>
#include<stdlib.h>
#include <algorithm>
#include<iterator>
#include <map>
#include <utility>


using namespace std;

class Usuario
{
public:
    string email;
    string senha;
    string nome;
    int ID;
};

class Servidor
{
public:
    string nome_do_servidor;
    string descricao_do_servidor;
    string codigo_de_convite;
    int usuarioDonoId;
    std::vector<int> participantesIDs;
    std::vector<string> canaisTexto;

    std::map<int,string> atribuicao_da_descricao;  // atribui a descreicao ao id do usuario.
    std::map<string, string> atribuicao_do_codigo_de_convite; // atribui o codigo de convite com o nome do servidor.
    std::map<int,string> atribuicao_do_canal;
};

class sistema
{
public:
    std::vector<string> Conjunto_de_usuarios;
    std::map <int, pair<string, string>> usuarios_logado;
    std::vector<string> Conjunto_de_servidores;

    std::map <int, string> email_senha_usuario;  //atribui o id do usuario com o seu respectivo email.
    std::map<int, string> id_servidor;  //atribui o id do usuario ao servidor criado.

    void imprimir(std::vector<string> Conjunto_de_servidores);
    void imprimir_lista_de_ids(std::vector<int> Conjunto_de_servidores);

};

class CAnalTexto
{
public:
    string nome_do_canal;
};

#endif