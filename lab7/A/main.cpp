#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, answer;

    cin >> a >> b >> c >> d >> answer;

    if ((a + answer == b) && (c * answer == d)){
        cout << 5;
    }
    else if ((a + answer == b) || (c * answer == d)){
        cout << 4;
    }
    else if (answer == 1024){
        cout << 3;
    }
    else{
        cout << 2;
    }

    return 0;
}
