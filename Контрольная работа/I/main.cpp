#include <iostream>

using namespace std;

int main() {
    int N, temp;

    cin >> N;

    int array1[N];
    int array2[N];

    for (int i = 0; i < N; i++){
        cin >> array1[i];
    }
    for (int i = 0; i < N; i++){
        cin >> array2[i];
    }

    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            if (array1[j] < array1[i]){
                temp = array1[j];
                array1[j] = array1[i];
                array1[i] = temp;

                temp = array2[j];
                array2[j] = array2[i];
                array2[i] = temp;
            }
            if (array1[j] == array1[i]){
                if (array2[j] < array2[i]){
                    temp = array2[j];
                    array2[j] = array2[i];
                    array2[i] = temp;
                }
            }
        }
    }

    for (int i = 0; i < N; i++){
        cout << array1[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < N; i++){
        cout << array2[i] << ' ';
    }

    return 0;
}