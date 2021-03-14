#include <iostream>
using namespace std;

int create_empty_array(){
    int * array = new int[0];
    return *array;
}

void push(int * array, int value){
    int * next = new int;
    next = (& array[sizeof(array)/sizeof(int) - 1]) + 1;
    *next = value;
}

void pop(int * array){
    delete & array[sizeof(array)/sizeof(int) - 1];
}

void print_array(int * array){
    for (int i = 0; i < sizeof(array)/sizeof(int); i++){
        cout << array[i] << " ";
    }
}

int main() {
    int my_array = create_empty_array();
    push(& my_array, 10);
    push(& my_array, 20);
    push(& my_array, 30);
    print_array(& my_array);
    return 0;
}
