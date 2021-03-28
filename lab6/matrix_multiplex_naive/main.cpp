#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

const unsigned size = 256;
const unsigned a_max = 100;

int **multiplex(int **A, int **B, unsigned int size) {
    int **C = new int *[size];

    for (int i = 0; i < size; i++){
        C[i] = new int[size];

        for (int j = 0; j < size; j++){
            C[i][j] = 0;
            for (int k = 0; k < size; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
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

int main() {
    srand(time(0));

    int ** A = new int*[size];
    int ** B = new int*[size];

    put_random(A, size);
    put_random(B, size);

    print_matrix(A, size);
    print_matrix(B, size);

    int ** C;

    auto start = chrono::steady_clock::now();
    C = multiplex(A, B, size);
    auto finish = chrono::steady_clock::now();

    print_matrix(C, size);

    cout << (finish - start).count();

    return 0;
}
