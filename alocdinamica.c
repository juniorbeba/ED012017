#include <stdio.h>
#include <stdlib.h>

/* Este programa aloca dinamicamente um vetor de inteiros (de acordo com a quantidade informada), preenche-o e retorna os dados informados para o usuario */


int *recebeVetor(int numElementos) {
    int *ponteiroVetor = (int *) malloc(numElementos * sizeof(int));
    return ponteiroVetor;
}


int main() {
    int *vetor;
    int qtdElementos, i;
    
    printf ("Informe a quantidade de elementos do vetor: \n");
    scanf ("%d", &qtdElementos);
    
    vetor = recebeVetor(qtdElementos);
    
    for (i = 0; i < qtdElementos; i++) {
        printf ("\nElemento numero %d: \n", i + 1);
        scanf ("%d", &vetor[i]);
    }
    
    for (i = 0; i < qtdElementos; i++) {
        printf ("\n%do elemento: %d\n", i + 1, vetor[i]);
    }
    
    
    free(vetor);
    return 0;
}