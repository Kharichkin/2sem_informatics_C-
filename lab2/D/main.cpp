#include <iostream>
using namespace std;

int main() {
    int N, temp;
    cin >> N;
    bool flag = true;
    while (N != 1){
        if (N%2 != 0){
            flag = false;
        }
        N = N/2;
    }
    if (flag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
