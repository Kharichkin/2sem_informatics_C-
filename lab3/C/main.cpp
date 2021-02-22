#include <iostream>
using namespace std;

void print_array(int array[]){
    for (int i = 0; i < 6; i++){
        cout << array[i] << ' ';
    }
}

int main() {
    int array[6];
    for (int i = 0; i < 6; i++){
        cin >> array[i];
    }

    print_array(array);
    return 0;
}
