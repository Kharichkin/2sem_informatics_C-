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

void shaker_sort(int * array, unsigned int size){
    int temp;

    for (int i = 0; i < size; i++){
        if (i % 2 == 0) {
            for (int j = i+1; j < size; j++) {
                if (array[j - 1] > array[j]) {
                    temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;
                }
            }
        }
        else{
            for (int j = size-i-1; j > 0; j--) {
                if (array[j] < array[j-1]) {
                    temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;
                }
            }
        }
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

    shaker_sort(array, size);
    print_array(array, size);

    return 0;
}