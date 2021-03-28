#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;

    int array[N][N];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> array[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << array[N - 1 - j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
