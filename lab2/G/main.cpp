#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    bool flag = true;

    cin >> N;
    for (int i = 2; i < sqrt(N); i++){
        if (N % i == 0){
            flag = false;
        }
    }
    if (flag){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
