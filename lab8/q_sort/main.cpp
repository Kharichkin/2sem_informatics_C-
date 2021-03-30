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

void q_sort(int * array, unsigned int size){
    if (size > 1) {
        int temp;
        int q_index = size/2;
        int q = array[q_index];

        for (int i = q_index; i >= 0; i--) {
            if (array[i] > q){
                temp = array[i];
                for (int k = i; k < size-1; k++){
                    array[k] = array[k+1];
                }
                array[size-1] = temp;
                q_index--;
            }
        }
        for (int i = q_index; i < size; i++) {
            if (array[i] < q){
                temp = array[i];
                for (int k = i; k > 0; k--){
                    array[k] = array[k-1];
                }
                array[0] = temp;
                q_index++;
            }
        }

        int *array1 = new int[q_index];
        int *array2 = new int[size - q_index];

        for (int i = 0; i < q_index; i++) {
            array1[i] = array[i];
        }
        for (int i = 0; i < size - q_index; i++) {
            array2[i] = array[q_index + i];
        }

        q_sort(array1, q_index);
        q_sort(array2, size - q_index);

        for (int i = 0; i < size; i++) {
            if (i < q_index){
                array[i] = array1[i];
            }
            else{
                array[i] = array2[i - q_index];
            }
        }

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

    q_sort(array, size);
    print_array(array, size);

    return 0;
}