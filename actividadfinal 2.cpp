#include <stdio.h>


void imprimirMatriz(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("(%d,%d): %d\t", i, j, matriz[i][j]);
        }
        printf("\n");
    }
}


int esMatrizMagica(int matriz[3][3]) {
  
    int sumaFila = matriz[0][0] + matriz[0][1] + matriz[0][2];


    printf("\nSUMA DE LA FILA 1: %d\n", sumaFila);
    for (int i = 1; i < 3; i++) {
        int sumaFilaActual = matriz[i][0] + matriz[i][1] + matriz[i][2];
        printf("SUMA DE LA FILA %d: %d\n", i + 1, sumaFilaActual);
        if (sumaFilaActual != sumaFila) {
            return 0;  
        }
    }

    
    for (int j = 0; j < 3; j++) {
        int sumaColumna = matriz[0][j] + matriz[1][j] + matriz[2][j];
        printf("SUMA DE LA COLUMNA %d: %d\n", j + 1, sumaColumna);
        if (sumaColumna != sumaFila) {
            return 0; 
        }
    }

   
    int sumaDiagonalPrincipal = matriz[0][0] + matriz[1][1] + matriz[2][2];
    printf("SUMA DE LA DIAGONAL: %d\n", sumaDiagonalPrincipal);
    if (sumaDiagonalPrincipal != sumaFila) {
        return 0; 
    }

    
    int sumaDiagonalSecundaria = matriz[0][2] + matriz[1][1] + matriz[2][0];
    printf("SUMA DE LA DIAGONAL SECUNDARIA: %d\n", sumaDiagonalSecundaria);
    if (sumaDiagonalSecundaria != sumaFila) {
        return 0;  
    }

    return 1;  
}

int main() {
    int matriz[3][3];

  
    printf("Ingresa los elementos de la matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

  
    printf("\nMATRIZ INGRESADA:\n");
    imprimirMatriz(matriz);


    if (esMatrizMagica(matriz)) {
        printf("\nLa matriz es magica.\n");
    } else {
        printf("\nLa matriz no es magica.\n");
    }

    return 0;
}

