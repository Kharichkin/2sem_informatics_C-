#include <iostream>
using namespace std;

int main() {
    int N, a;

    cin >> N;

    bool flag = true;

    for (int i = 0; i < N; i++){
        cin >> a;

        if ((a % 4 == 0) && (a / 1000 != 4) && (a / 1000 != 5)){
            flag = false;
            cout << a << endl;
        }
        else if ((a % 7 == 0) && (a / 1000 != 1) && (a / 1000 != 7)){
            flag = false;
            cout << a << endl;
        }
        else if ((a % 9 == 0) && (a / 1000 != 8) && (a / 1000 != 9)){
            flag = false;
            cout << a << endl;
        }
    }

    if (flag){
        cout << 0 << endl;
    }

    return 0;
}
