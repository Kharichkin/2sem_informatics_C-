#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const unsigned size = 3;
const unsigned a_max = 100;

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

        for (int i = 0; i < size; i++) {
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
    cout << "\n";
}

int random(int a){
    int result = rand() % (a + 1);
    if (rand() % 2 == 1){
        result = - result;
    }
    return result;
}

void put_random(int ** A, unsigned int size){
    for (int i = 0; i < size; i++){
        A[i] = new int[size];
        for (int j = 0; j < size; j++){
            A[i][j] = random(a_max);
        }
    }
}

void complement(int ** A, int ** A_compl, unsigned int size, unsigned int complemented_size){
    for (int i = 0; i < complemented_size; i++){
        A_compl[i] = new int[complemented_size];
        for (int j = 0; j < complemented_size; j++){
            if ((i < size) && (j < size)){
                A_compl[i][j] = A[i][j];
            }
            else{
                A_compl[i][j] = 0;
            }
        }
    }
}

void decomplement(int ** A, int ** A_compl, unsigned int size){
    for (int i = 0; i < size; i++){
        A[i] = new int[size];
        for (int j = 0; j < size; j++){
            A[i][j] = A_compl[i][j];
        }
    }
}

int main() {
    srand(time(0));

    int ** A = new int*[size];
    int ** B = new int*[size];

    put_random(A, size);
    put_random(B, size);

    print_matrix(A, size);
    print_matrix(B, size);

    unsigned int complemented_size = 1;
    while (complemented_size < size){
        complemented_size = complemented_size * 2;
    }

    int ** A_compl = new int*[complemented_size];
    int ** B_compl = new int*[complemented_size];

    complement(A, A_compl, size, complemented_size);
    complement(B, B_compl, size, complemented_size);

    int ** C_compl;

    C_compl = multiplex(A_compl, B_compl, complemented_size);

    delete [] A_compl;
    delete [] B_compl;

    int ** C = new int*[size];

    decomplement(C, C_compl, size);

    delete [] C_compl;

    print_matrix(C, size);

    return 0;
}