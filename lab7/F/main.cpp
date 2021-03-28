#include <iostream>
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

List create_empty(){
    List * empty_list = new List;
    empty_list->len = 0;
    empty_list->tail = nullptr;
    empty_list->head = nullptr;
    return *empty_list;
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

            /*if (index == list->len){
                list->tail = new_node;
            }*/
        }
        list->len++;
    }
}

void print_list(List * list){
    Node * current_node = list->head;
    for (int i = 0; i < list->len; i++){
        cout << current_node->value << "\n";
        current_node = current_node->next;
    }
}

int main() {
    int N, index;
    char sign;

    cin >> N;

    List goblins = create_empty();
    List output = create_empty();

    for (int i = 0; i < N; i++){
        cin >> sign;
        if (sign == '+'){
            cin >> index;
            add_to_end(&goblins, index);

        }
        else if (sign == '*'){
            cin >> index;
            int temp = goblins.len;
            add(&goblins, temp/2 + temp%2, index);
        }
        else if (sign == '-'){
            add_to_end(&output, goblins.head->value);
            remove(&goblins, 0);
        }
    }

    print_list(&output);

    return 0;
}