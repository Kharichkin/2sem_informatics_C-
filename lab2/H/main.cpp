#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, div;
    div = 2;
    cin >> N;
    while (N != 1) {
        if (N % div == 0) {
            N = N / div;
            cout << div << endl;
        }
        else {
            div++;
        }
    }
    return 0;
}
