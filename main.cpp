#include "head.h"
#include "metodos.cpp"


// Funcao de Login no Concordo

int comando_de_login(std::vector<string> conjunto, string email, string senha)
{
    // Iterator que auxilia a validacao

    auto it = find(conjunto.begin(), conjunto.end(), email);
    auto it1 = find(conjunto.begin(), conjunto.end(), senha);

    // Loga ou nao no sistema
            
    if (it !=  conjunto.end() && it1 != conjunto.end())
        {
            cout << "Logado como "<< email << endl;
            return 1;
        }
    else
        {
            cout << "Senha ou usuario invalidos!" << endl;
            return -1;
        }
}

int ache_o_elemento_para_apagar(std::vector<string> conjunto, std::vector<string>::iterator it)
{
    int i = 0;

    for(auto it2 = conjunto.begin(); it2 != conjunto.end(); it2++)
    {
        if(it == conjunto.end()) 
        {
            break;
        }
                    
        i++;

    }

}

int ache_o_elemento_para_apagar_inteiros(std::vector<int> lista, std::vector<int>::iterator it)
{
    int j = 0;

    for(auto it2 = lista.begin(); it2 != lista.end(); it2++)
    {
        if(it == lista.end()) 
        {
            break;
        }
                    
        j++;
    }

}


int main()
{
    string Comando, servidor, canal;
    sistema conjunto, tabela, banco_De_dados;
    Servidor informacao, lista;
    Usuario dados, id;
    CAnalTexto grupo, elemento;
    int id_selecionado;
    id.ID = 0;
    
    
    
    string situacao = "Nao esta logado";   // Comeca como nao logado.
    int aux_situacao;    // esta variavel serve como auxiliar da variavel situacao, pois a situacao so ira mudar caso o usuario faca o login corretamente.

    while(cin >> Comando)
    {
        // usuario off

        // Criando um usuario e adicionando no servidor.

        if (Comando ==  "creater-user")
        { 
            cin  >> dados.email; cin >> dados.senha; cin >> dados.nome;
            
            // Iterator que auxilia a validacao.

            auto it = find(conjunto.Conjunto_de_usuarios.begin(), conjunto.Conjunto_de_usuarios.end(), dados.email);
            
            // Validacao do Arquivo, se ja existe ele nao adiciona, se nao ele adiciona.

            if (it !=  conjunto.Conjunto_de_usuarios.end())
            {
                cout << "Usuario ja existe!"<<endl;    
            }
            else
            {
                // armazena no vector de sistema os usuarios.

                conjunto.Conjunto_de_usuarios.emplace_back(dados.email);
                conjunto.Conjunto_de_usuarios.emplace_back(" ");
                conjunto.Conjunto_de_usuarios.emplace_back(dados.senha);
                conjunto.Conjunto_de_usuarios.emplace_back(" ");
                conjunto.Conjunto_de_usuarios.emplace_back(dados.nome);
                conjunto.Conjunto_de_usuarios.emplace_back(" ");
                cout << "Usuario Criado Com Sucesso"<< endl;
            }            
        }

        // Logando no Sistema

        if(Comando == "login")
        {
            cin  >> dados.email; cin >> dados.senha;

            //chamada da funca comando de login, a qual vai retornar um inteiro que vai mudar a situacao ou nao.

            aux_situacao = comando_de_login(conjunto.Conjunto_de_usuarios, dados.email, dados.senha);

            if (aux_situacao == 1)
            {
                id.ID++;   // incrementa o ID
                situacao = "esta logado";  // muda caso satisfazer a condicao de usuario logado ou nao
                tabela.usuarios_logado.emplace(id.ID, std::make_pair("NULL", "NULL"));   // map que contem o id, servidor e canal respectivamente
                banco_De_dados.email_senha_usuario.emplace(id.ID, dados.email);   // associa o id com o email.        
            }
            else
            {
                situacao = "Nao esta logado";
            }
        }
            
        //usuario logado
 
        if (situacao == "esta logado")
        {
            // desconectando determinado id

            if(Comando == "disconnect")
            {
                cin >> id_selecionado;

                // verifica se o usuario esta logado ou nao

                if(banco_De_dados.email_senha_usuario.count(id_selecionado) == NULL)
                {
                    cout << "Nao esta conectado" << endl;
                }

                // se estiver logado (representado com o else) ele desconecta e remove do map

                else
                {
                    cout << "Desconectando o Usuario " << banco_De_dados.email_senha_usuario[id_selecionado] << endl;
                    banco_De_dados.email_senha_usuario.erase(id_selecionado);
                }
                   
            }

            // cria servidor

            else if(Comando == "creater-server")
            {
                cin >> id_selecionado; cin >> informacao.nome_do_servidor;
                
                // verifica se o usuario esta logado ou nao para a criacao do servidor

                if(banco_De_dados.email_senha_usuario.count(id_selecionado) == NULL)
                {
                    cout << "Nao esta conectado" << endl;
                }
                
                //se estiver ele e permitido a criacao do servidor
                
                else
                {
                    // Iterator que auxilia a validacao

                    auto it = find(conjunto.Conjunto_de_servidores.begin(), conjunto.Conjunto_de_servidores.end(), informacao.nome_do_servidor);

                    // verifica se o nome do servidor ja existe
                    
                    if (it !=  conjunto.Conjunto_de_servidores.end())
                    {
                        cout << "Servidor com esse nome ja existe" << endl;    
                    }
                    else
                    {
                        informacao.usuarioDonoId = id_selecionado;
                        lista.participantesIDs.push_back(informacao.usuarioDonoId); // ja adiciona id do dono do servidor ao vector de ids.
                        conjunto.Conjunto_de_servidores.push_back(informacao.nome_do_servidor);
                        banco_De_dados.id_servidor.emplace(id_selecionado, informacao.nome_do_servidor);  // associa o id ao servidor
                        cout << "Servidor criado" << endl;   
                    }    
                }
            }

            // mudar descricao do servidor

            else if(Comando == "set-server-desc")
            {
                cin >> id_selecionado; cin >> informacao.nome_do_servidor;

                //iterator que acha no conjunto de servidos o nome informado.
                
                auto it = find(conjunto.Conjunto_de_servidores.begin(), conjunto.Conjunto_de_servidores.end(), informacao.nome_do_servidor);

                //verifica se o id do usuario e o mesmo que esta vinculado o servidor.

                if(banco_De_dados.id_servidor[id_selecionado] == informacao.nome_do_servidor)
                {
                    cin >>  informacao.descricao_do_servidor;
                    lista.atribuicao_da_descricao.emplace(id_selecionado, informacao.descricao_do_servidor);
                    cout << "Descricao do servidor " << "'" << informacao.nome_do_servidor << "'" << " modificada!" << endl;
                }
                
                // verifica se o servidor existe.

                else if(it ==  conjunto.Conjunto_de_servidores.end())
                {
                    cout << "Servidor " << "'" << informacao.nome_do_servidor << "'" << " nao existe" << endl;

                }

                // verifica se o servidor e o mesmo do id vinculado a ele.
                
                else{
                    cout << "Voce nao pode alterar a descricao de um servidor que nao foi criado por voce" << endl;
                }

            }

            // mudar código de convite

            else if(Comando == "set-server-invite-code")
            {
                // caso o codigo de convite seja igual a "NULL" ele ira remover o codigo de convite deixando o servidor aberto

                cin >> id_selecionado; cin >> informacao.nome_do_servidor; cin >> informacao.codigo_de_convite;

                //iterator que acha no conjunto de servidos o nome informado.
                
                auto it = find(conjunto.Conjunto_de_servidores.begin(), conjunto.Conjunto_de_servidores.end(), informacao.nome_do_servidor);

                //verifica se o id do usuario e o mesmo que esta vinculado o servidor e remove ou adiciona o codigo de convite.

                if(banco_De_dados.id_servidor[id_selecionado] == informacao.nome_do_servidor)
                {
                    if(informacao.codigo_de_convite == "NULL")
                    {
                        lista.atribuicao_do_codigo_de_convite.emplace(informacao.nome_do_servidor, "NULL");
                        cout << "Codigo de convite do servidor " << "'" << informacao.nome_do_servidor << "'" << " removido!" << endl;    
                    }
                    else
                    {
                        lista.atribuicao_do_codigo_de_convite.emplace(informacao.nome_do_servidor, informacao.codigo_de_convite);
                        cout << "Codigo de convite do servidor " << "'" << informacao.nome_do_servidor << "'" << " modificado!" << endl;
                    }
                    
                }
                
                // verifica se o servidor existe.

                else if(it ==  conjunto.Conjunto_de_servidores.end())
                {
                    cout << "Servidor " << "'" << informacao.nome_do_servidor << "'" << " nao existe" << endl;
                }

                // verifica se o servidor e o mesmo do id vinculado a ele.
                
                else{
                    cout << "Voce nao pode alterar o codigo de convite de um servidor que nao foi criado por voce" << endl;
                }

            }

            // listar servidores

            else if(Comando == "list-servers")
            {
                // Chamada do metodo

                conjunto.imprimir(conjunto.Conjunto_de_servidores);           
            }

            // remover o servidor

            else if(Comando == "remove-server")
            {
                int i;

                cin >> id_selecionado; cin >> informacao.nome_do_servidor;

                //iterator que acha no conjunto de servidos o nome informado.
                
                auto it = find(conjunto.Conjunto_de_servidores.begin(), conjunto.Conjunto_de_servidores.end(), informacao.nome_do_servidor);

                //chama o metodo, que acha o elemento, o qual vai ser apagado do conjunto servidor.

                i = ache_o_elemento_para_apagar(conjunto.Conjunto_de_servidores, it);

                // verifica se de fato quem esta, tentando apagar e o dono do servidor, se for ele apaga, se nao for ele so imprimi uma menssagem para o usuario.
            
                if(banco_De_dados.id_servidor[id_selecionado] == informacao.nome_do_servidor)
                {
                    conjunto.Conjunto_de_servidores.erase(conjunto.Conjunto_de_servidores.begin()+i);
                    cout << "Servidor " << "'" << informacao.nome_do_servidor << "'" << " removido" << endl;    
                }

                //verifica se o servidor existe.

                else if(it ==  conjunto.Conjunto_de_servidores.end())
                {
                    cout << "Servidor " << "'" << informacao.nome_do_servidor << "'" << " nao encontrado" << endl;
                }
                else{
                    cout << "Voce nao e o dono do servidor " << "'" << informacao.nome_do_servidor << "'" << endl;
                }    
            }

            //entra no servidor

            else if(Comando == "enter-server")
            {
                cin >> id_selecionado; cin >> informacao.nome_do_servidor; cin >> informacao.codigo_de_convite;

                // verifica se o id em questao, e o mesmo id que esta vinculado o servidor, se nao for ele entra no if abaixo.

                if(banco_De_dados.id_servidor[id_selecionado] != informacao.nome_do_servidor)
                {
                    // se o dono do servidor, tiver deixado o sevidor aberto, basta digitar NULL

                    if(lista.atribuicao_do_codigo_de_convite[informacao.nome_do_servidor] == "NULL")
                    {
                        lista.participantesIDs.push_back(id_selecionado);
                        cout << "usuario entrou com sucesso" << endl;    
                    }

                    // se o dono do servidor, tiver deixado o sevidor com o codigo de convite, o mesmo pedira.

                    else if(lista.atribuicao_do_codigo_de_convite[informacao.nome_do_servidor] == informacao.codigo_de_convite)
                    {
                        lista.participantesIDs.push_back(id_selecionado);
                        cout << "entrou usando o codigo de convite" << endl;
                    }

                    // se o servidor requer codigo de convite, porem digitou o NULL, ou o codigo de convite nao bate.

                    else
                    {
                        cout << "“Servidor requer codigo de convite ou codigo de convite esta errado" << endl;
                    }    
                }
                  
            }

            // sair do servidor

            else if(Comando == "leave-server")
            {
                cin >> id_selecionado; cin >> informacao.nome_do_servidor;

                int j;
                    
                //iterator que acha no conjunto de servidos o nome informado.

                std::vector<int>::iterator it;

                it = find(lista.participantesIDs.begin(), lista.participantesIDs.end(), id_selecionado);

                //chama a funcao, que acha o elemento, o qual vai ser apagado da lista de ids do servidor.

                j = ache_o_elemento_para_apagar_inteiros(informacao.participantesIDs, it);

                // sai do serivdor o excluindo da lista de ids do servidor.

                if(it != lista.participantesIDs.end())
                {
                    lista.participantesIDs.erase(lista.participantesIDs.begin() + j);
                    cout << "Saindo do servidor " << "'" << informacao.nome_do_servidor << "'" << endl;    
                }
                else
                {
                    cout << "Voce nao esta visualizando nenhum servidor" << endl;     
                }
            }

            // Imprimi uma lista de participantes do servidor.

            else if(Comando == "list-participants")
            {
                conjunto.imprimir_lista_de_ids(lista.participantesIDs);
            }

            // lista os canais, observe que ele so ira entrar se id selecionado estiver ocupado na lista de servidores.
            
            else if(Comando == "list-channels")
            {
                conjunto.imprimir(lista.canaisTexto);
            }

            // cria os canais, observe que ele so ira entrar se id selecionado estiver ocupado na lista de servidores.

            else if(Comando == "creater-channel")
            {
                cin >> id_selecionado; cin >> elemento.nome_do_canal;
                    
                // Iterator que auxilia a validacao

                auto it = find(lista.canaisTexto.begin(), lista.canaisTexto.end(), elemento.nome_do_canal);

                // verifica se o nome do canal ja existe
                    
                if (it !=  lista.canaisTexto.end())
                {
                    cout << "Canal de texto '" << elemento.nome_do_canal << "' ja existe" << endl;    
                }
                else
                {
                    lista.canaisTexto.push_back(elemento.nome_do_canal);
                    lista.atribuicao_do_canal.emplace(id_selecionado, elemento.nome_do_canal);  // associa o id ao canal.
                    cout << "Canal de texto '" << elemento.nome_do_canal << "' criado" << endl;   
                }    
            }

            else if(Comando == "enter-channel")
            {
                cin >> id_selecionado; cin >> elemento.nome_do_canal;

                // Iterator que auxilia a validacao

                auto it = find(lista.canaisTexto.begin(), lista.canaisTexto.end(), elemento.nome_do_canal);

                // verifica se o nome do canal ja existe

                if (it !=  lista.canaisTexto.end())
                {
                    lista.atribuicao_do_canal.emplace(id_selecionado, elemento.nome_do_canal);
                    cout << "entrou no canal '" << elemento.nome_do_canal << "'" << endl;
                }

                else
                {
                    cout << "Canal '" << elemento.nome_do_canal << "' nao existe" << endl;
                }    
                      
            }

            // sai do canal.

            else if(Comando == "leave-channel")
            {
                cin >> id_selecionado; cin >> elemento.nome_do_canal;

                int j;
                    
                //iterator que acha no conjunto de servidos o nome informado.

                std::vector<string>::iterator it;

                it = find(lista.canaisTexto.begin(), lista.canaisTexto.end(), elemento.nome_do_canal);

                //chama a funcao, que acha o elemento, o qual vai ser apagado da lista de ids do servidor.

                j = ache_o_elemento_para_apagar(lista.canaisTexto, it);

                // ve se o canal existe, se existir ele sai do canal de texto.

                if(it != lista.canaisTexto.end())
                {
                    lista.canaisTexto.erase(lista.canaisTexto.begin() + j);
                    cout << "Saindo do canal " << "'" << elemento.nome_do_canal << "'" << endl;    
                }
                else if(lista.atribuicao_do_canal[id_selecionado] == elemento.nome_do_canal)
                {
                    cout << "Voce nao este canal de texto" << endl;     
                }

            }

        }

        // Saindo do sistema do concordo.       
             
        if(Comando == "quit" )
        {
            cout << "Saindo do Concordo" << endl;
            return 0;
        }

    }
        
    return 0;
    
}

