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

void insertion_sort(int * array, unsigned int size){
    int temp;

    for (int i = 1; i < size; i++){
        int j = i;
        while (j > 0){
            if (array[i] < array[j-1]){
                j--;
            }
            else{
                break;
            }
        }

        temp = array[i];
        for (int k = i; k > j; k--){
            array[k] = array[k-1];
        }
        array[j] = temp;
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

    insertion_sort(array, size);
    print_array(array, size);

    return 0;
}