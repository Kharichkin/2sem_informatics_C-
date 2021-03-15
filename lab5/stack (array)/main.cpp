#include <iostream>
using namespace std;

struct Stack{
    int * array;
    unsigned int len;
    unsigned int max_len;
};

Stack create_empty_stack(){
    Stack * stack = new Stack;
    stack->array = new int[2];
    stack->len = 0;
    stack->max_len = 2;
    return *stack;
}

void push(Stack * stack, int value){
    if (stack->len == stack->max_len){
        int* temp = stack->array;
        stack->max_len = stack->max_len * 2;
        stack->array = new int[stack->max_len];
        for (int i = 0; i < stack->len; i++){
            stack->array[i] = temp[i];
        }
        delete [] temp;
    }
    stack->array[stack->len] = value;
    stack->len++;
}

void pop(Stack * stack){
    if (stack->len - 1 == stack->max_len/2){
        int* temp = stack->array;
        stack->max_len = stack->max_len / 2;
        stack->array = new int[stack->max_len];
        for (int i = 0; i < stack->len; i++){
            stack->array[i] = temp[i];
        }
        delete [] temp;
    }
    stack->len--;
}

void print_stack(Stack * stack){
    for (int i = 0; i < stack->len; i++){
        cout << stack->array[i] << " ";
    }
}

int main() {
    Stack my_stack = create_empty_stack();
    push(& my_stack, 10);
    push(& my_stack, 20);
    push(& my_stack, 30);
    push(& my_stack, 40);
    pop(& my_stack);
    pop(& my_stack);
    print_stack(& my_stack);
    return 0;
}
