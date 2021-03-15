#include <iostream>
using namespace std;

int main() {
    const unsigned N = 3;
    int A [N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B [N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int C [N][N];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            C[i][j] = 0;
            for (int k = 0; k < N; k++){
                C[i][j] += A[i][k] * B[k][j];
            }

            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
