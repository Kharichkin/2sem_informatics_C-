#include <iostream>
using namespace std;

int* now_get_me_some_bytes(unsigned int N){
    return new int[N];
}
void now_free_some_bytes(int* ptr){
    delete [] ptr;
}

int main() {
    unsigned int N;
    cin >> N;
    int *array = now_get_me_some_bytes(N);

    for (int i = 0; i < N; i++){
        cin >> array[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += array[i];
    }

    if (sum % 2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }

    now_free_some_bytes(array);
    return 0;
}
