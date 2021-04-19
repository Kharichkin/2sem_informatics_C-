#include <iostream>

using namespace std;

int main() {
    int N, temp1, temp2;

    cin >> N;

    int zeroth = 0;
    int first = 0;
    int second = 1;
    int index = 2;

    while (second <= N){
        temp1 = second;
        temp2 = first;
        second = zeroth + first + second;
        first = temp1;
        zeroth = temp2;
        index++;
    }

    cout << index;

    return 0;
}
