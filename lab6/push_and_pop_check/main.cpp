#include <iostream>
#include <chrono>
using namespace std;


struct Node{
    int value;
    struct Node * next;
};

struct List{
    unsigned int len;
    struct Node * tail;
    struct Node * head;
};

List create_empty_list(){
    List * empty_list = new List;
    empty_list->len = 0;
    empty_list->tail = nullptr;
    empty_list->head = nullptr;
    return *empty_list;
}

List copy_list(List * list){
    List copy_list = create_empty_list();
    Node * new_node = new Node;
    copy_list.head = new_node;
    Node * current_node = list->head;
    for (int i = 0; i < list->len; i++){
        new_node->value = current_node->value;
        current_node = current_node->next;
        if (i == list->len - 1){
            copy_list.tail = new_node;
            copy_list.tail->next = nullptr;
        }
        else {
            Node *temp = new Node;
            new_node->next = temp;
            new_node = temp;
        }
    }

    copy_list.len = list->len;
    return copy_list;
}

List merge(List * list1, List * list2){
    List merged_list = create_empty_list();
    Node * new_node = new Node;
    merged_list.head = new_node;
    Node * current_node = list1->head;
    for (int i = 0; i < list1->len; i++){
        new_node->value = current_node->value;
        current_node = current_node->next;
        Node *temp = new Node;
        new_node->next = temp;
        new_node = temp;
    }

    current_node = list2->head;
    for (int i = 0; i < list2->len; i++){
        new_node->value = current_node->value;
        current_node = current_node->next;
        if (i == list2->len - 1){
            merged_list.tail = new_node;
            merged_list.tail->next = nullptr;
        }
        else {
            Node *temp = new Node;
            new_node->next = temp;
            new_node = temp;
        }
    }

    merged_list.len = list1->len + list2->len;
    return merged_list;
}

void add_to_end(List * list, int value){
    struct Node * new_node = new Node;
    new_node->value = value;
    new_node->next = nullptr;

    if (list->len == 0){
        list->tail = new_node;
        list->head = new_node;
    }
    else{
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->len++;
}

void add_to_beginning(List * list, int value){
    struct Node * new_node = new Node;
    new_node->value = value;
    new_node->next = list->head;

    list->head = new_node;
    if (list->len == 0){
        list->tail = new_node;
    }
    list->len++;
}

void remove(List * list, unsigned int index){
    if (list->len == 0){
        cout << "Error: zero length list!";
    }
    else if (index >= list->len){
        cout << "Error: array out of bounds!";
    }
    else{
        Node * current_node = list->head;
        if (index == 0){
            if (list->len == 1){
                delete list->head;
                delete list->tail;
            }
            else{
                current_node = current_node->next;
                delete list->head;
                list->head = current_node;
            }
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                current_node = current_node->next;
            }
            current_node->next = current_node->next->next;
            delete current_node->next;
        }
        list->len--;
    }
}

void add(List * list, unsigned int index, int value){
    if (index > list->len){
        cout << "Error: array out of bounds!";
    }
    else{
        Node * new_node = new Node;
        Node * temp = new Node;
        temp = list->head;
        new_node->value = value;
        if (index == 0){
            list->head = new_node;
            list->head->next = temp;
        }
        else{
            for (int i = 0; i < index-1; i++){
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
        list->len++;
    }
}

void print_list(List * list){
    Node * current_node = list->head;
    for (int i = 0; i < list->len; i++){
        cout << current_node->value << " ";
        current_node = current_node->next;
    }
    cout << "\n";
}

struct Stack{
    struct List list;
};

Stack create_empty_stack(){
    Stack * stack = new Stack;
    stack->list = create_empty_list();
    return *stack;
}

void push(Stack * stack, int value){
    add_to_end(&stack->list, value);
}

void pop(Stack * stack){
    remove(&stack->list, stack->list.len-1);
}

void print_stack(Stack * stack){
    print_list(& stack->list);
}

int main() {
    Stack my_stack = create_empty_stack();
    int N = 8000;

    auto start1 = std::chrono::steady_clock::now();
    for (int i = 0; i < N; i++){
        push(& my_stack, 10);
    }
    auto finish1 = std::chrono::steady_clock::now();
    cout << "push: " << (finish1-start1).count() << endl;

    auto start2 = std::chrono::steady_clock::now();
    for (int i = 0; i < N; i++){
        pop(& my_stack);
    }
    auto finish2 = std::chrono::steady_clock::now();
    cout << "pop: " << (finish2-start2).count();
    return 0;
}