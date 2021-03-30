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

void merge(int * array, int * array1, int * array2, unsigned int size1, unsigned int size2){
    int j1 = 0, j2 = 0;
    for (int i = 0; i < size1+size2; i++){
        if (j1 == size1){
            array[i] = array2[j2];
            j2++;
        }
        else if (j2 == size2){
            array[i] = array1[j1];
            j1++;
        }
        else {
            if (array1[j1] < array2[j2]) {
                array[i] = array1[j1];
                j1++;
            } else {
                array[i] = array2[j2];
                j2++;
            }
        }
    }
}

void merge_sort(int * array, unsigned int size){
    if (size > 1) {
        int *array1 = new int[size / 2];
        int *array2 = new int[size - size / 2];

        for (int i = 0; i < size / 2; i++) {
            array1[i] = array[i];
        }
        for (int i = 0; i < size - size / 2; i++) {
            array2[i] = array[size / 2 + i];
        }

        merge_sort(array1, size / 2);
        merge_sort(array2, size - size / 2);

        merge(array, array1, array2, size / 2, size - size / 2);

        delete [] array1;
        delete [] array2;
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
    merge_sort(array, size);
    auto finish = chrono::steady_clock::now();
    print_array(array, size);

    cout << (finish - start).count();
    return 0;
}