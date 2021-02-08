#include <iostream>
#include <cmath>

using namespace std;

int pow(int a, int b){
    int result = 1;
    for (int i = 0; i < b; i++){
        result *= a;
    }
    return result;
}

int main() {
    int N, k, power;
    power = -1;
    cin >> N;
    k = N;
    while (k != 0){
        k = k / 60;
        power++;
    }

    for (int i = power; i >= 1; i--){
        for(int k = 0; k < ((N / pow(60, i)) / 10); k++){
            cout << "<";
        }
        for (int k = 0; k < ((N / pow(60, i)) % 10); k++){
            cout << "v";
        }

        N = N % pow(60, i);
        cout << ".";
    }
    for (int k = 0; k < (N / 10); k++){
        cout << "<";
    }
    for (int k = 0; k < (N % 10); k++){
        cout << "v";
    }

    return 0;
}
