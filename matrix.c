#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX],
                 int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX],
                      int result[MAX][MAX],
                      int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for transpose
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX],
                     int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int sum[MAX][MAX], product[MAX][MAX], transpose[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, r1, c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, r2, c2);

    // Matrix Addition
    if(r1 == r2 && c1 == c2) {
        addMatrices(A, B, sum, r1, c1);
        printf("\nMatrix Addition Result:\n");
        displayMatrix(sum, r1, c1);
    } else {
        printf("\nMatrix Addition not possible.\n");
    }

    // Matrix Multiplication
    if(c1 == r2) {
        multiplyMatrices(A, B, product, r1, c1, c2);
        printf("\nMatrix Multiplication Result:\n");
        displayMatrix(product, r1, c2);
    } else {
        printf("\nMatrix Multiplication not possible.\n");
    }

    // Transpose of Matrix A
    transposeMatrix(A, transpose, r1, c1);
    printf("\nTranspose of Matrix A:\n");
    displayMatrix(transpose, c1, r1);

    return 0;
}