#include <stdio.h>
#include <stdlib.h>

/* Algoritmo que implementa lista. Feito em sala dia 05/03/2017 */


struct Node {
    int num;
    struct Node *prox;
}; 
typedef struct Node node;


void insere(node *LISTA) {
    int numero, desejo;
    node *novoElemento = (node *) malloc(sizeof(node));
    printf ("Se deseja inserir no inicio da lista, digite 1. Se não, digite 0: \n");
    scanf ("%d", &desejo);
    
    switch (desejo) {
        int i, posicao;
        case 1:
            printf ("Informe o numero a ser alocado: \n");
            scanf ("%d", &numero);
            novoElemento->num = numero;
            LISTA->prox = novoElemento;
            novoElemento->prox = NULL;
            printf ("O numero %d foi inserido com sucesso no inicio da lista! \n", numero);
            break;
            
        case 0:
            printf ("Informe a posicao em que deseja inserir: \n");
            scanf ("%d", &posicao);
            printf ("Informe o numero a ser inserido: \n");
            scanf ("%d", &numero);
            novoElemento->num = numero;
            node *atual = LISTA->prox;
            node *anterior = LISTA;
            for (i = 0; i < posicao; i++) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = novoElemento;
            novoElemento->prox = atual;
            break;
            
        default:
            printf ("Opcao invalida! Tente novamente: \n");
            break;
    }
}

int busca(node *LISTA) {
    int elementoBuscado;
    printf ("Informe o elemento a ser buscado: \n");
    scanf ("%d", &elementoBuscado);
    if (LISTA->prox == NULL) {
        printf ("A lista está vazia! Encerrando......\n");
        return 0;
    } else {
        node *ponteiroBusca = LISTA->prox;
        if (elementoBuscado == ponteiroBusca->num) {
            printf ("Elemento encontrado! É o primeiro elemento da lista! \n");
            return 1;
        } else {
            int i = 0;
            int encontrou = 0;
            while ((ponteiroBusca->prox != NULL) || (!encontrou)) {
                ponteiroBusca = ponteiroBusca->prox;
                if (elementoBuscado == ponteiroBusca->num) {
                    printf ("Elemento encontrado na posicao %d!\n", i + 1);
                    encontrou = 1;
                    return encontrou;
                }
                i++;
            }
            return encontrou;
        }
    }
}

int retira(node *LISTA) {
    int i, posicao;
    printf ("De que posicao deseja retirar o elemento: \n");
    scanf ("%d", &posicao);
    if (LISTA->prox == NULL) {
        printf ("A lista já está vazia! \n");
        return 1;
    } else {
        if (posicao == 1) {
            free(LISTA->prox);
            return 1;
        } else {
            node *atual = LISTA->prox;
            node *anterior = LISTA;
            for (i = 0; i < posicao; i++) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = atual->prox;
            free(atual);
            return 1;
        }
    }
}

void imprimeLista(node *LISTA) {
    if (LISTA->prox == NULL) {
        printf ("A lista está vazia! \n");
    } else {
        node *tmp = LISTA->prox;
        printf ("Lista: \n\n");
        while (tmp != NULL) {
            printf ("%d\n", tmp->num);
            tmp = tmp->prox;
        }
    }
}


int main() {
    int opcao;
    node *LISTA = (node *) malloc(sizeof(node));
    if (!LISTA) {
        printf ("A LISTA NAO PÔDE SER CRIADA! ENCERRANDO PROGRAMA......\n");
        exit(1);
    } else {
        LISTA->prox = NULL;
    }

    system("clear");
    printf ("BEM VINDO AO PROGRAMINHA DA LISTA! :) \n\n");
   
    
    while (opcao) {
        printf ("~~~ MENU PRINCIPAL ~~~\n\n");
        printf ("Selecione uma das opcoes abaixo: \n");
        printf ("0 - SAIR\n");
        printf ("1 - INSERIR ELEMENTO\n");
        printf ("2 - BUSCAR ELEMENTO\n");
        printf ("3 - REMOVER ELEMENTO\n");
        printf ("4 - IMPRIMIR ELEMENTOS\n");
        scanf ("%d", &opcao);
        if ((opcao > 4) || (opcao < 0)) {
            while ((opcao > 4) || (opcao < 0)) {
                printf ("Opcao invalida! Digite a opcao novamente: \n");
                scanf ("%d", &opcao);
            }
        }
        switch (opcao) {
            case 0:
                printf ("ATÉ A PROXIMA! :> \n");
                free(LISTA);
                /*exit(1);*/
                break;

            case 1:
                system("clear");
                insere(LISTA);
                break;
                
            case 2:
                system("clear");
                busca(LISTA);
                break;
                
            case 3:
                retira(LISTA);
                system("clear");
                break;
                
            case 4:
                imprimeLista(LISTA);
                break;
                
            
        }
    }
    
    return 0;
}
