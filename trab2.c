#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * TRABALHO 2 - ESTRUTURAS DE DADOS
 * ALUNO: MAURICIO APRIGIO ANTERO JUNIOR
 * MATRICULA: 15/0141831 
 */


struct Agenda {
    char nome[50], email[30];
    int telefone;
    struct Agenda *prox;
}; typedef struct Agenda agenda;



int vazia(agenda *AGENDA) {
    if (AGENDA->prox == NULL) 
        return 1;
    else
        return 0;
}


agenda *aloca() {
    agenda *contatoNovo = (agenda *) malloc(sizeof(agenda));
    
    if (!contatoNovo) {
        printf ("ERRO!! SEM MEMORIA SUFICIENTE! ENCERRANDO...........\n");
        exit(1);
    }
    else {
        printf ("Nome do contato novo: \n");
        scanf (" %[^\n]s", contatoNovo->nome);
        setbuf(stdin, NULL);
        
        printf ("Telefone do contato novo: \n");
        scanf (" %d", &contatoNovo->telefone);
        setbuf(stdin, NULL);
        
        printf ("E-mail do contato novo: \n");
        scanf (" %[^\n]s", contatoNovo->email);
        setbuf(stdin, NULL);
        
        /* COLOCAMOS O PROXIMO ELEMENTO COMO NULL PORQUE IREMOS INSERI-LO, SEMPRE, AO FINAL DA LISTA */
        contatoNovo->prox = NULL;
        return contatoNovo;
    }
}


/* A FUNCAO INSERE IRÁ APENAS INSERIR AO FINAL DA LISTA, UMA VEZ QUE SERÁ POSSIVEL AO USUARIO ORDENÁ-LA FUTURAMENTE, SE DESEJAR */

void insereContato(agenda *AGENDA) {
    agenda *novo = aloca();
    
    if (vazia(AGENDA)) {
        AGENDA->prox = novo;
    }
    else {
        agenda *tmp = AGENDA->prox;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    printf ("Usuário inserido com sucesso!! \n");
    printf ("Pressione 'ENTER' para retornar ao menu principal.......\n");
    getchar();
}


void ordenaContatos(agenda *AGENDA) {
    if (vazia(AGENDA)) {
        printf ("A agenda está vazia! Insira seus contatos para que possa removê-los! \n");
        printf ("Pressione 'ENTER' para retornar ao menu principal.......\n");
        getchar();
    }
    else {
        agenda *aux1, *aux2;
        char string[70];
        aux1 = AGENDA;
        
        while (aux1 != NULL) {
            aux2 = aux1->prox;
            
            while (aux2 != NULL) {
                if(strcmp(aux1->nome, aux2->nome) > 0) {
                    strcpy(string, aux1->nome);
                    strcpy(aux1->nome, aux2->nome);
                    strcpy(aux2->nome, string);
                }
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }
        printf ("Sua agenda foi ordenada com sucesso!!\n\n");
        printf ("Pressione 'ENTER' para retornar ao menu principal.......\n");
        getchar();
    }
}


void removeContato(agenda *AGENDA) {
    if (vazia(AGENDA)) {
        printf ("A agenda está vazia! Insira seus contatos para que possa removê-los! \n");
        printf ("Pressione 'ENTER' para retornar ao menu principal.......\n");
        getchar();
    }
    else {
        char remover[50];
        agenda *atual = AGENDA->prox;
        agenda *anterior = AGENDA;
        printf ("Informe o nome do contato que deseja remover: \n");
        scanf (" %[^\n]s", remover);
        setbuf(stdin, NULL);
        
        while (atual->prox != NULL) {
            if (strcmp(remover, atual->nome) == 0) {
                anterior->prox = atual->prox;
                free(atual);
                printf ("Contato removido com sucesso!! \n");
                printf ("Pressione 'ENTER' para retornar ao menu principal.......\n");
                getchar();
            }
            anterior = atual;
            atual = atual->prox;
        }
        /* O PROXIMO IF É PARA O CASO DE O CONTATO BUSCADO SER O ULTIMO DA LISTA, OU PARA O CASO DE A LISTA CONTER APENAS UM CONTATO */
        if ((atual->prox == NULL) && (strcmp(remover, atual->nome) == 0)) {
            anterior->prox = NULL;
            free(atual);
            printf ("Contato removido com sucesso!! \n");
            printf ("Pressione 'ENTER' para retornar ao menu principal.......\n");
            getchar();
        }
    }
}


void listaContatos(agenda *AGENDA) {
    if (vazia(AGENDA)) {
        printf ("A agenda está vazia! Insira seus contatos para que possa listá-los! \n");
        printf ("Pressione 'ENTER' para retornar ao menu principal.......\n");
        getchar();
        return ;
    }
    else {
        printf ("Contatos na agenda: \n\n");
        agenda *ptr = AGENDA->prox;
        while (ptr != NULL) {
            printf ("Nome: %s\n", ptr->nome);
            printf ("E-mail: %s\n", ptr->email);
            printf ("Telefone: %d\n", ptr->telefone);
            printf ("-----------------------------------------------\n\n");
            ptr = ptr->prox;
        }
        printf ("Pressione 'ENTER' para retornar ao menu principal.......\n");
        getchar();
    }
}


/* A FUNÇÃO DE BUSCA FOI IMPLEMENTADA JUNTO COM A FUNÇÃO DE EDIÇÃO DE CONTATO, UMA VEZ QUE, SE AS FIZESSE SEPARADAS, A FUNÇÃO DE EDIÇÃO NECESSITARIA DA FUNÇÃO DE BUSCA EM SUA IMPLEMENTAÇÃO, O QUE AUMENTARIA A EXTENSÃO DO CÓDIGO SEM NECESSIDADE */

void buscaContato(agenda *AGENDA) {
    if (vazia(AGENDA)) {
        printf ("A agenda está vazia! Insira seus contatos para que possa listá-los! \n");
        printf ("Pressione 'ENTER' para retornar ao menu principal.......\n");
        getchar();
    }
    else {
        int opcao, continua;
        do {
            printf ("BUSCAR CONTATO: \n\n");
            printf ("Escolha uma das opções abaixo para efetuar a busca: \n");
            printf ("[1] - Buscar por NOME\n");
            printf ("[2] - Buscar por TELEFONE\n");
            printf ("[3] - Buscar por E-MAIL\n");
            printf ("[0] - Cancelar da busca e voltar ao MENU\n\n");
            printf ("Como deseja buscar: \n");
            scanf (" %d", &opcao);
            setbuf(stdin, NULL);
            while ((opcao != 1) && (opcao != 2) && (opcao != 3) && (opcao != 0)) {
                printf ("Opção inválida!! Tente novamente: \n");
                scanf (" %d", &opcao);
                setbuf(stdin, NULL);
            }
            
            switch (opcao) {
                case 1:
                    /* BUSCAR POR NOME */
                {
                    system("clear");
                    char nome[70];
                    int encontrou = 0;
                    agenda *ptr = AGENDA;
                    printf ("Informe o nome completo do contato buscado: \n");
                    scanf (" %[^\n]c", nome);
                    setbuf(stdin, NULL);
                    
                    while((ptr->prox != NULL) && (!encontrou)) {
                        ptr = ptr->prox;
                        if (strcmp(nome, ptr->nome) == 0) {
                            printf ("\nContato encontrado! \n\n");
                            printf ("Nome: %s\n", ptr->nome);
                            printf ("Telefone: %d\n", ptr->telefone);
                            printf ("E-mail: %s\n", ptr->email);
                            encontrou = 1;
                        }
                    }
                    
                    if (!encontrou) {
                        printf ("Contato não encontrado! \n\n");
                    }
                    else {
                        int alterar;
                        printf ("\nGostaria de alterar alguma informação do contato? Caso SIM, digite 1; caso NÃO, digite 0\n");
                        scanf (" %d", &alterar);
                        setbuf(stdin, NULL);
                        
                        if (alterar) {
                            int opcao;
                            system("clear");
                            
                            printf ("O que gostaria de alterar em seu contato?\n\n");
                            printf ("[1] - Alterar NOME\n");
                            printf ("[2] - Alterar TELEFONE\n");
                            printf ("[3] - Alterar E-MAIL\n\n");
                            printf ("Opção desejada: \n");
                            scanf (" %d", &opcao);
                            setbuf(stdin, NULL);
                            
                            switch (opcao) {
                                case 1:
                                {
                                    char novoNome[70];
                                    system("clear");
                                    printf ("Informe o novo nome do contato: \n");
                                    scanf (" %[^\n]s", novoNome);
                                    setbuf(stdin, NULL);
                                    strcpy(ptr->nome, novoNome);
                                    printf ("\nContato alterado com sucesso!\n");
                                    break;
                                }
                                
                                case 2:
                                {
                                    int novoTelefone;
                                    system("clear");
                                    printf ("Informe o novo número de telefone do contato: \n");
                                    scanf (" %d", &novoTelefone);
                                    setbuf(stdin, NULL);
                                    ptr->telefone = novoTelefone;
                                    printf ("Contato alterado com sucesso\n");
                                    break;
                                }
                                    
                                case 3:
                                {
                                    char novoEmail[70];
                                    system("clear");
                                    printf ("Informe o novo e-mail do contato: \n");
                                    scanf (" %[^\n]s", novoEmail);
                                    setbuf(stdin, NULL);
                                    strcpy(ptr->email, novoEmail);
                                    printf ("\nContato alterado com sucesso!\n");
                                    break;
                                }
                            }
                        }
                    }
                    
                    break;
                }
                    
                case 2:
                    /* BUSCAR POR TELEFONE */
                    
                {

                    system("clear");
                    int telefone;
                    int encontrou = 0;
                    agenda *ptr = AGENDA->prox;
                    printf ("Informe o telefone do contato buscado: \n");
                    scanf (" %d", &telefone);
                    setbuf(stdin, NULL);
                    while(ptr != NULL) {
                        if (ptr->telefone == telefone) {
                            printf ("\nContato encontrado! \n\n");
                            printf ("Nome: %s\n", ptr->nome);
                            printf ("Telefone: %d\n", ptr->telefone);
                            printf ("Endereço: %s\n", ptr->email);
                            encontrou = 1;
                        }
                        ptr = ptr->prox;
                    }
                    
                    if (!encontrou) {
                        printf ("Contato não encontrado! \n");
                    }
                    else {
                        int alterar;
                        printf ("\nGostaria de alterar alguma informação do contato? Caso SIM, digite 1; caso NÃO, digite 0\n");
                        scanf (" %d", &alterar);
                        setbuf(stdin, NULL);
                        
                        if (alterar) {
                            int opcao;
                            system("clear");
                            printf ("O que gostaria de alterar em seu contato?\n\n");
                            printf ("[1] - Alterar NOME\n");
                            printf ("[2] - Alterar TELEFONE\n");
                            printf ("[3] - Alterar E-MAIL\n\n");
                            printf ("Opção desejada: \n");
                            scanf (" %d", &opcao);
                            setbuf(stdin, NULL);
                            
                            switch (opcao) {
                                case 1:
                                {
                                    char novoNome[70];
                                    system("clear");
                                    printf ("Informe o novo nome do contato: \n");
                                    scanf (" %[^\n]s", novoNome);
                                    setbuf(stdin, NULL);
                                    strcpy(ptr->nome, novoNome);
                                    printf ("\nContato alterado com sucesso!\n");
                                    break;
                                }
                                
                                case 2:
                                {
                                    int novoTelefone;
                                    system("clear");
                                    printf ("Informe o novo número de telefone do contato: \n");
                                    scanf (" %d", &novoTelefone);
                                    setbuf(stdin, NULL);
                                    ptr->telefone = novoTelefone;
                                    printf ("Contato alterado com sucesso\n");
                                    break;
                                }
                                    
                                case 3:
                                {
                                    char novoEmail[70];
                                    system("clear");
                                    printf ("Informe o novo e-mail do contato: \n");
                                    scanf (" %[^\n]s", novoEmail);
                                    setbuf(stdin, NULL);
                                    strcpy(ptr->email, novoEmail);
                                    printf ("\nContato alterado com sucesso!\n");
                                    break;
                                }
                            }
                        }
                    }
                    
                    
                    break;
                }
                    
                case 3:
                    /* BUSCAR POR EMAIL */
                    
                {

                    system("clear");
                    char email[30];
                    int encontrou = 0;
                    agenda *ptr = AGENDA->prox;
                    printf ("Informe o e-mail do contato buscado: \n");
                    scanf (" %[^\n]c", email);
                    setbuf(stdin, NULL);
                    
                    while(ptr != NULL) {
                        if (strcmp(email, ptr->email) == 0) {
                            printf ("\nContato encontrado! \n\n");
                            printf ("Nome: %s\n", ptr->nome);
                            printf ("Telefone: %d\n", ptr->telefone);
                            printf ("Endereço: %s\n", ptr->email);
                            encontrou = 1;
                        }
                        ptr = ptr->prox;                        
                    }
                    
                    if (!encontrou) {
                        printf ("Contato não encontrado!\n");
                    }
                    else {
                        int alterar;
                        printf ("\nGostaria de alterar alguma informação do contato? Caso SIM, digite 1; caso NÃO, digite 0\n");
                        scanf (" %d", &alterar);
                        setbuf(stdin, NULL);
                        
                        if (alterar) {
                            int opcao;
                            system("clear");
                            printf ("O que gostaria de alterar em seu contato?\n\n");
                            printf ("[1] - Alterar NOME\n");
                            printf ("[2] - Alterar TELEFONE\n");
                            printf ("[3] - Alterar E-MAIL\n\n");
                            printf ("Opção desejada: \n");
                            scanf (" %d", &opcao);
                            setbuf(stdin, NULL);
                            
                            switch (opcao) {
                                case 1:
                                {
                                    char novoNome[70];
                                    system("clear");
                                    printf ("Informe o novo nome do contato: \n");
                                    scanf (" %[^\n]s", novoNome);
                                    setbuf(stdin, NULL);
                                    strcpy(ptr->nome, novoNome);
                                    printf ("\nContato alterado com sucesso!\n");
                                    break;
                                }
                                
                                case 2:
                                {
                                    int novoTelefone;
                                    system("clear");
                                    printf ("Informe o novo número de telefone do contato: \n");
                                    scanf (" %d", &novoTelefone);
                                    setbuf(stdin, NULL);
                                    ptr->telefone = novoTelefone;
                                    printf ("Contato alterado com sucesso\n");
                                    break;
                                }
                                    
                                case 3:
                                {
                                    char novoEmail[70];
                                    system("clear");
                                    printf ("Informe o novo e-mail do contato: \n");
                                    scanf (" %[^\n]s", novoEmail);
                                    setbuf(stdin, NULL);
                                    strcpy(ptr->email, novoEmail);
                                    printf ("\nContato alterado com sucesso!\n");
                                    break;
                                }
                            }
                        }
                    }
                    
                    break;
                }
                    
                case 0:
                    /* SAIR DA BUSCA */
                    return ;
                    break;
            }
            
            printf ("\n\nDeseja realizar uma nova busca? Caso SIM, digite 1; caso NÃO, digite 0\n");
            scanf (" %d", &continua);
            setbuf(stdin, NULL);
            system("clear");
        } while (continua && opcao);
    }
}



int main() {
    int opcao;
    printf ("BEM VINDO AO PROGRAMINHA DA AGENDA!! \n\n");
    agenda *AGENDA = (agenda *) malloc(sizeof(agenda));
    
    do {
        system("clear");
        printf ("**************************\n");
        printf ("***** MENU PRINCIPAL *****\n");
        printf ("**************************\n\n");
        printf ("1 - Inserir Contato(s)\n");
        printf ("2 - Ordenar Contatos\n");
        printf ("3 - Listar Contatos\n");
        printf ("4 - Buscar\\Mostrar Contato\n");
        printf ("5 - Remover Contato(s)\n");
        printf ("0 - Sair\n\n");
        printf ("INFORME A OPÇÃO DESEJADA: \n");
        scanf ("%d", &opcao);
        setbuf(stdin, NULL);
        while ((opcao != 0) && (opcao != 1) && (opcao != 2) && (opcao != 3) && (opcao != 4) && (opcao != 5) && (opcao != 6)) {
            printf ("Opcao invalida! Tente novamente: \n");
            scanf ("%d", &opcao);
            setbuf(stdin, NULL);
        }
        
        switch(opcao) {
            case 0:
                system("clear");
                printf ("Obrigado por usar nosso software! Até mais!! :D \n");
                /* SAIR */
                break;
                
            case 1:
                system("clear");
                insereContato(AGENDA);
                /* INSERIR */
                break;
                
            case 2:
                system("clear");
                ordenaContatos(AGENDA);
                /* ORDENAR */
                break;
                
            case 3:
                system("clear");
                listaContatos(AGENDA);
                /* LISTAR */
                break;
                
            case 4:
                system("clear");
                buscaContato(AGENDA);
                /* BUSCAR */
                break;
                
            case 5:
                system("clear");
                removeContato(AGENDA);
                /* REMOVER */
                break;
                
            default:
                /**/
                break;
        }
    } while (opcao != 0);
    
    /* LIBERAÇÃO DE MEMORIA */
    
    if (AGENDA->prox == NULL) {
        free(AGENDA);
    }
    else {
        agenda *anterior, *atual;
        atual = AGENDA->prox;
        anterior = AGENDA;
        while (atual != NULL) {
            free(anterior);
            anterior = atual;
            atual = atual->prox;
        }
    }
    
    return 0;
}