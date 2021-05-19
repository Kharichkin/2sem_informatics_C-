#include <iostream>

using namespace std;

int main() {
    int N = 1;

    for (int j = 0; j < 50; j++){
        N = N * 2;
        cout << j+1 << ": " << N << endl;
    }

    return 0;
}
