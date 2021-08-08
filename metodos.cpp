#include "head.h"

void sistema::imprimir(std::vector<string> lista_de_servidores)
{

   for(auto it = lista_de_servidores.begin(); it != lista_de_servidores.end(); it++)
        {
            cout << *it << endl;
        }

}


void sistema::imprimir_lista_de_ids(std::vector<int> lista_de_servidores)
{

   for(auto it = lista_de_servidores.begin(); it != lista_de_servidores.end(); it++)
        {
            cout << *it << endl;
        }

}

