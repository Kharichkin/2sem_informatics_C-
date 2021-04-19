#include <iostream>

using namespace std;

int main() {
    int N, K;

    cin >> N;
    cin >> K;

    int x;
    int index = -1;

    for (int i = 0; i < N; i++){
        cin >> x;
        if (x == K){
            index = i + 1;
        }
    }

    cout << index;

    return 0;
}