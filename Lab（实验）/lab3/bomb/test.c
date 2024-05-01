#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define BLOCK_SIZE 10

void matrix_multiply(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i += BLOCK_SIZE) {
        for (int j = 0; j < N; j += BLOCK_SIZE) {
            for (int k = 0; k < N; k += BLOCK_SIZE) {
                for (int ii = i; ii < i + BLOCK_SIZE; ii++) {
                    for (int jj = j; jj < j + BLOCK_SIZE; jj++) {
                        for (int kk = k; kk < k + BLOCK_SIZE; kk++) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    // Initialize matrices A and B with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100; // Random value between 0 and 99
            B[i][j] = rand() % 100;
            C[i][j] = 0; // Initialize result matrix C to 0
        }
    }

    // Perform matrix multiplication
    matrix_multiply(A, B, C);

    // Print the result matrix C (optional)
    printf("Result matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}