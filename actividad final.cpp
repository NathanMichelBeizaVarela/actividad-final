#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 7

void llenarMatrizAleatoria(int matriz[FILAS][COLUMNAS]) {
    int i, j;

    srand(time(NULL));

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % 10;  
        }
    }
}

void imprimirMatriz(int matriz[FILAS][COLUMNAS]) {
    int i, j;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int calcularSumaDiagonalPrincipal(int matriz[FILAS][COLUMNAS]) {
    int i, suma = 0;

    for (i = 0; i < FILAS && i < COLUMNAS; i++) {
        suma += matriz[i][i];
    }

    return suma;
}

int calcularSumaFila(int fila, int matriz[FILAS][COLUMNAS]) {
    int j, suma = 0;

    for (j = 0; j < COLUMNAS; j++) {
        suma += matriz[fila][j];
    }

    return suma;
}

int calcularSumaColumna(int columna, int matriz[FILAS][COLUMNAS]) {
    int i, suma = 0;

    for (i = 0; i < FILAS; i++) {
        suma += matriz[i][columna];
    }

    return suma;
}

int calcularSumaFilasPares(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;

    for (i = 0; i < FILAS; i += 2) {
        for (j = 0; j < COLUMNAS; j++) {
            suma += matriz[i][j];
        }
    }

    return suma;
}

int calcularSumaColumnasImpares(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;

    for (j = 1; j < COLUMNAS; j += 2) {
        for (i = 0; i < FILAS; i++) {
            suma += matriz[i][j];
        }
    }

    return suma;
}

int calcularSumaTriangularSuperior(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;

    for (i = 0; i < FILAS; i++) {
        for (j = i + 1; j < COLUMNAS; j++) {
            suma += matriz[i][j];
        }
    }

    return suma;
}

int calcularSumaTriangularInferior(int matriz[FILAS][COLUMNAS]) {
    int i, j, suma = 0;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < i; j++) {
            suma += matriz[i][j];
        }
    }

    return suma;
}

int main() {
    int matriz[FILAS][COLUMNAS];

    llenarMatrizAleatoria(matriz);

    printf("Matriz aleatoria:\n");
    imprimirMatriz(matriz);
    printf("\n");

    int sumaDiagonal = calcularSumaDiagonalPrincipal(matriz);
    int sumaFila1 = calcularSumaFila(0, matriz);
    int sumaFila3 = calcularSumaFila(2, matriz);
    int sumaFila5 = calcularSumaFila(4, matriz);
    int sumaFilasPares = calcularSumaFilasPares(matriz);
    int sumaColumna2 = calcularSumaColumna(1, matriz);
    int sumaColumna4 = calcularSumaColumna(3, matriz);
    int sumaColumna6 = calcularSumaColumna(5, matriz);
    int sumaColumnasImpares = calcularSumaColumnasImpares(matriz);
    int sumaTriangularSuperior = calcularSumaTriangularSuperior(matriz);
    int sumaTriangularInferior = calcularSumaTriangularInferior(matriz);

    printf("Suma de la diagonal principal: %d\n", sumaDiagonal);
    printf("Suma de la fila 1: %d\n", sumaFila1);
    printf("Suma de la fila 3: %d\n", sumaFila3);
    printf("Suma de la fila 5: %d\n", sumaFila5);
    printf("Suma de las filas pares: %d\n", sumaFilasPares);
    printf("Suma de la columna 2: %d\n", sumaColumna2);
    printf("Suma de la columna 4: %d\n", sumaColumna4);
    printf("Suma de la columna 6: %d\n", sumaColumna6);
    printf("Suma de las columnas impares: %d\n", sumaColumnasImpares);
    printf("Suma triangular superior: %d\n", sumaTriangularSuperior);
    printf("Suma triangular inferior: %d\n", sumaTriangularInferior);

    return 0;
}


