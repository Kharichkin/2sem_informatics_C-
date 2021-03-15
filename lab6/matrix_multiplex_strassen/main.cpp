#include <iostream>
using namespace std;

const unsigned N = 4;

int **sum(int **A, int **B, bool sign = true){
    unsigned int size = sizeof(A) / sizeof(int);

    int ** C = new int*[size];

    for (int i = 0; i < size; i++){
        C[i] = new int[size];

        for (int j = 0; j < size; j++){
            if (sign){
                C[i][j] = A[i][j] + B[i][j];
            }
            else{
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    }

    return C;
}

int **multiplex(int **A, int **B){
    unsigned int size = sizeof(A) / sizeof(int);

    int ** A11 = new int*[size / 2];
    int ** A12 = new int*[size / 2];
    int ** A21 = new int*[size / 2];
    int ** A22 = new int*[size / 2];
    int ** B11 = new int*[size / 2];
    int ** B12 = new int*[size / 2];
    int ** B21 = new int*[size / 2];
    int ** B22 = new int*[size / 2];

    for (int i = 0; i < size / 2; i++){
        A11[i] = new int[size / 2];
        A12[i] = new int[size / 2];
        A21[i] = new int[size / 2];
        A22[i] = new int[size / 2];
        B11[i] = new int[size / 2];
        B12[i] = new int[size / 2];
        B21[i] = new int[size / 2];
        B22[i] = new int[size / 2];
        for (int j = 0; j < size / 2; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + size/2];
            A21[i][j] = A[i + size/2][j];
            A22[i][j] = A[i + size/2][j + size/2];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + size/2];
            B21[i][j] = B[i + size/2][j];
            B22[i][j] = B[i + size/2][j + size/2];
        }
    }

    int ** P1 = new int*[size / 2];
    int ** P2 = new int*[size / 2];
    int ** P3 = new int*[size / 2];
    int ** P4 = new int*[size / 2];
    int ** P5 = new int*[size / 2];
    int ** P6 = new int*[size / 2];
    int ** P7 = new int*[size / 2];

    P1 = multiplex(sum(A11, A22), sum(B11, B22));
    P2 = multiplex(sum(A21, A22), B11);
    P3 = multiplex(A11, sum(B11, B22));
    P4 = multiplex(sum(A11, A22), sum(B11, B22));
    P5 = multiplex(sum(A11, A22), sum(B11, B22));
    P6 = multiplex(sum(A11, A22), sum(B11, B22));
    P7 = multiplex(sum(A11, A22), sum(B11, B22));

    return nullptr;
}

int main() {
    int ** A = new int*[N];
    A[0] = new int[N]{1, 2, 3, 4};
    A[1] = new int[N]{5, 6, 7, 8};
    A[2] = new int[N]{9, 10, 11, 12};
    A[3] = new int[N]{13, 14, 15, 16};

    int ** B = new int*[N];
    B[0] = new int[N]{1, 2, 3, 4};
    B[1] = new int[N]{5, 6, 7, 8};
    B[2] = new int[N]{9, 10, 11, 12};
    B[3] = new int[N]{13, 14, 15, 16};

    int ** C = new int*[N];

    /*int A[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int B[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int C[N][N];*/

    C = multiplex(A, B);

    return 0;
}