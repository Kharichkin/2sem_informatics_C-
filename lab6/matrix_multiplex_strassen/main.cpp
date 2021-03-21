#include <iostream>
using namespace std;

const unsigned N = 4;

int **sum(int **A, int **B, unsigned int size, bool sign = true){
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

int **multiplex(int **A, int **B, unsigned int size){
    int **C = new int *[size];

    if (size > 1) {
        int **A11 = new int *[size / 2];
        int **A12 = new int *[size / 2];
        int **A21 = new int *[size / 2];
        int **A22 = new int *[size / 2];
        int **B11 = new int *[size / 2];
        int **B12 = new int *[size / 2];
        int **B21 = new int *[size / 2];
        int **B22 = new int *[size / 2];

        for (int i = 0; i < size / 2; i++) {
            A11[i] = new int[size / 2];
            A12[i] = new int[size / 2];
            A21[i] = new int[size / 2];
            A22[i] = new int[size / 2];
            B11[i] = new int[size / 2];
            B12[i] = new int[size / 2];
            B21[i] = new int[size / 2];
            B22[i] = new int[size / 2];
            for (int j = 0; j < size / 2; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + size / 2];
                A21[i][j] = A[i + size / 2][j];
                A22[i][j] = A[i + size / 2][j + size / 2];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + size / 2];
                B21[i][j] = B[i + size / 2][j];
                B22[i][j] = B[i + size / 2][j + size / 2];
            }
        }

        int **P1;
        int **P2;
        int **P3;
        int **P4;
        int **P5;
        int **P6;
        int **P7;

        P1 = multiplex(sum(A11, A22, size/2), sum(B11, B22, size/2), size/2);
        P2 = multiplex(sum(A21, A22, size/2), B11, size/2);
        P3 = multiplex(A11, sum(B12, B22, size/2,false), size/2);
        P4 = multiplex(A22, sum(B21, B11, size/2,false), size/2);
        P5 = multiplex(sum(A11, A12, size/2), B22, size/2);
        P6 = multiplex(sum(A21, A11, size/2,false), sum(B11, B12, size/2), size/2);
        P7 = multiplex(sum(A12, A22, size/2,false), sum(B21, B22, size/2), size/2);

        int **C11;
        int **C12;
        int **C21;
        int **C22;

        C11 = sum(sum(sum(P1, P4, size/2), P5, size/2, false), P7, size/2);
        C12 = sum(P3, P5, size/2);
        C21 = sum(P2, P4, size/2);
        C22 = sum(sum(sum(P1, P2, size/2,false), P3, size/2), P6, size/2);

        for (int i = 0; i < size / 2; i++) {
            C[i] = new int[size];

            if (i < size / 2) {
                for (int j = 0; j < size; j++) {
                    if (j < size / 2) {
                        C[i][j] = C11[i][j];
                    } else {
                        C[i][j] = C12[i][j - size / 2];
                    }
                }
            } else {
                for (int j = 0; j < size; j++) {
                    if (j < size / 2) {
                        C[i][j] = C21[i - size / 2][j];
                    } else {
                        C[i][j] = C22[i - size / 2][j - size / 2];
                    }
                }
            }
        }
    }

    else{
        C[0] = new int[1];

        C[0][0] = A[0][0] * B[0][0];
    }

    return C;
}

void print_matrix(int ** A, unsigned int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int ** A = new int*[N];
    A[0] = new int[N]{1, 2, 3, 4};
    A[1] = new int[N]{5, 6, 7, 8};
    A[2] = new int[N]{9, 10, 11, 12};
    A[3] = new int[N]{13, 14, 15, 16};
    cout << A[1][1];
    int ** B = new int*[N];
    B[0] = new int[N]{1, 2, 3, 4};
    B[1] = new int[N]{5, 6, 7, 8};
    B[2] = new int[N]{9, 10, 11, 12};
    B[3] = new int[N]{13, 14, 15, 16};

    int ** C;

    /*int A[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int B[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int C[N][N];*/


    /*C = multiplex(A, B, N);

    print_matrix(C, N);*/

    return 0;
}