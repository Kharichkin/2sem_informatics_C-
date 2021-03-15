#include <iostream>
using namespace std;

struct Queue{
    int * array;
    unsigned int len;
    unsigned int max_len;
};

Queue create_empty_stack(){
    Queue * queue = new Queue;
    queue->array = new int[2];
    queue->len = 0;
    queue->max_len = 2;
    return *queue;
}

void enqueue(Queue * queue, int value){
    if (queue->len == queue->max_len){
        int* temp = queue->array;
        queue->max_len = queue->max_len * 2;
        queue->array = new int[queue->max_len];
        for (int i = 0; i < queue->len; i++){
            queue->array[i] = temp[i];
        }
        delete [] temp;
    }
    queue->array[queue->len] = value;
    queue->len++;
}

void dequeue(Queue * queue){
    if (queue->len - 1 == queue->max_len / 2){
        int* temp = queue->array;
        queue->max_len = queue->max_len / 2;
        queue->array = new int[queue->max_len];
        for (int i = 0; i < queue->len; i++){
            queue->array[i] = temp[i+1];
        }
        delete [] temp;
        queue->len--;
    }
    else{
        int* temp = queue->array;
        queue->array = new int[queue->max_len];
        for (int i = 0; i < queue->len; i++){
            queue->array[i] = temp[i+1];
        }
        delete [] temp;
        queue->len--;
    }
}


void print_queue(Queue * queue){
    for (int i = 0; i < queue->len; i++){
        cout << queue->array[i] << " ";
    }
}

int main() {
    Queue my_queue = create_empty_stack();
    enqueue(&my_queue, 10);
    enqueue(&my_queue, 20);
    enqueue(&my_queue, 30);
    enqueue(&my_queue, 40);
    dequeue(&my_queue);
    dequeue(&my_queue);
    print_queue(& my_queue);
    return 0;
}