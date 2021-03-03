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

List copy_list(List * list){
    List copy_list = create_empty();
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
    List merged_list = create_empty();
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

int main() {
    List my_list = create_empty();
    add_to_end(&my_list, 10);
    add_to_beginning(&my_list, 20);
    add_to_beginning(&my_list, 30);
    add_to_beginning(&my_list, 40);
    print_list(&my_list);
    List copy = copy_list(&my_list);
    remove(&copy, 0);
    print_list(&copy);
    remove(&copy, 2);
    print_list(&copy);
    remove(&copy, 1);
    print_list(&copy);
    remove(&copy, 0);
    print_list(&copy);
    add(&copy, 0, 10);
    print_list(&copy);
    add(&copy, 0, 20);
    print_list(&copy);
    add(&copy, 2, 30);
    print_list(&copy);
    add(&copy, 1, 40);
    print_list(&copy);
    print_list(&my_list);
    List merged_list = merge(&my_list, &copy);
    print_list(&merged_list);
    return 0;
}
