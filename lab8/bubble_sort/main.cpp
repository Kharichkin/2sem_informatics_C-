#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

const unsigned int size = 100000;
unsigned int a_max = 100;

void print_array(int * array, unsigned int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}

void bubble_sort(int * array, unsigned int size){
    int temp;

    for (int i = 0; i < size; i++){
        for (int j = 1; j < size-i; j++){
            if (array[j-1] > array[j]){
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
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

    auto start = chrono::steady_clock::now();
    bubble_sort(array, size);
    auto finish = chrono::steady_clock::now();
    print_array(array, size);

    cout << (finish - start).count();

    return 0;
}
