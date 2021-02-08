#include <iostream>
using namespace std;

int main() {
    int a, max;
    max = 0;
    do{
        cin >> a;
        if ((a % 2 == 0) && (a > max)){
            max = a;
        }
    } while (a != 0);
    cout << max << endl;
    return 0;
}
