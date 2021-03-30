#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const unsigned int size = 10;
unsigned int a_max = 100;

void print_array(int * array, unsigned int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}

void shell_sort(int * array, unsigned int size){
    int temp;
    int d = size/2;
    while (d > 0) {
        for (int i = d; i < size; i++) {
            int j = i-d;
            if (array[i] < array[j]){
                temp = array[i];
                for (int k = i; k > j; k--) {
                    array[k] = array[k - 1];
                }
                array[j] = temp;
            }
        }

        d = d/2;
    }
}

int random(int a){
    int result = rand() % (a + 1);
    if (rand() % 2 == 1){
        result = - result;
    }
    return result;
}

void put_random(int * array, unsigned int size){
    for (int i = 0; i < size; i++){
        array[i] = random(a_max);
    }
}

int main() {
    srand(time(0));

    int array [size];

    put_random(array, size);
    print_array(array, size);

    shell_sort(array, size);
    print_array(array, size);

    return 0;
}