#include<stdio.h>
#include<string.h>

void print1(int *N, int w) {
    for (int i = 0; i < w; i++) {
        printf("%d ", N[i]);
    }
    printf("\n");
}//標準

void print2(int (*N)[3]) {
    for (int i = 0; i < 3; i++) {
        printf("%d ", (*N)[i]);
    }
    printf("\n");
}//比較不喜歡這個

void print3(int (*N)[3], int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", N[i][j]);
        }
        printf("\n");
    }
}

void print4(int **N, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", N[i][j]);
        }
        printf("\n");
    }
}

void print5(int *N, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", *(N + i * w + j));
        }
        printf("\n");
    }
}

int main() {
    int A[3] = {1, 2, 3};
    int B[3] = {4, 5, 6};
    int C[3] = {7, 8, 9};
    int D[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int *P[3] = {D[0], &D[1][0], D[2]};
    print1(A, 3);
    print2(&B);
    print3(D, 3);//&D[0] = D
    print4(P, 3, 3);
    print5((int *)D, 3, 3);
    return 0;
}
