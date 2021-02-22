#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int *array = new int [N];
    for (int i = 0; i < N; i++){
        cin >> array[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += array[i];
    }
    double avg = sum/N;
    sum = 0;
    for (int i = 0; i < N; i++){
        if (array[i] > avg){
            sum += array[i];
        }
    }

    delete [] array;
    cout << sum << endl;
    return 0;
}
