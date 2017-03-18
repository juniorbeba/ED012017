#include <stdio.h>

int main() {
    int matriz[3][4];
    int i, j, vetor[10];
    
    
    /* RECEBE VETOR */
    for (i = 0; i < 10; i++) {
        printf ("Informe o valor da posição [%d]: \n", i);
        scanf ("%d", &vetor[i]);
    }
    
    /* MOSTRA VETOR */
    printf ("Vetor preenchido: \n");
    for (i = 0; i < 10; i++) {
        printf ("%d ", vetor[i]);
    }
    
    
    printf ("\n");
    
    
    /* RECEBE MATRIZ */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf ("Informe o valor da célula [%d][%d]: \n", i, j);
            scanf ("%d", &matriz[i][j]); /* Um valor aleatório */
        }
        printf ("\n");
    }
    
    /* MOSTRA MATRIZ */
    printf ("\n\nMatriz preenchida: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j   < 4; j++) {
            printf ("%d ", matriz[i][j]);
        }
        printf ("\n");
    }
    
    return 0;
}
