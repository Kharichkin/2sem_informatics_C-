#include <iostream>
#include <vector>

using namespace std;

struct Tree;

struct Node{
    int value;
    Tree * left = nullptr;
    Tree * right = nullptr;
};

struct Tree{
    Node * root = nullptr;
    unsigned int number = 0;
};

void add_value(Tree * tree, int value){
    Tree * current_tree = tree;
    while (current_tree->number != 0){
        if(value < current_tree->root->value){
            current_tree->number++;
            current_tree = current_tree->root->left;
        }
        else{
            current_tree->number++;
            current_tree = current_tree->root->right;
        }
    }
    current_tree->number++;
    current_tree->root = new Node;
    current_tree->root->value = value;
    current_tree->root->left = new Tree;
    current_tree->root->right = new Tree;
}

bool find_value(Tree * tree, int value){
    bool is_here = false;
    Tree * current_tree = tree;
    while(current_tree->number != 0){
        if(current_tree->root->value == value){
            is_here = true;
            break;
        }
        else if(value < current_tree->root->value){
            current_tree = current_tree->root->left;
        }
        else{
            current_tree = current_tree->root->right;
        }
    }

    return is_here;
}

void delete_value(Tree * tree, int value){
    Tree * current_tree = tree;
    while (current_tree->root->value != value){
        if(value < current_tree->root->value){
            current_tree->number--;
            current_tree = current_tree->root->left;
        }
        else{
            current_tree->number--;
            current_tree = current_tree->root->right;
        }
    }

    current_tree->number--;
    if (current_tree->root->right->number == 0){
        current_tree->root = current_tree->root->left->root;
    }
    else{
        Tree * temporary_tree = current_tree->root->right;
        while (temporary_tree->root->left->number != 0){
            temporary_tree = temporary_tree->root->left;
        }
        temporary_tree->root->left = current_tree->root->left;
        current_tree->root = current_tree->root->right->root;
    }
}

vector<Node *> find_leaves(Tree * tree){
    vector<Node *> leaves;

    if(tree->root->left->number != 0){
        vector<Node *> temp_leaves = find_leaves(tree->root->left);
        for (int i = 0; i < temp_leaves.size(); i++){
            leaves.push_back(temp_leaves[i]);
        }
    }
    if((tree->root->left->number == 0) && (tree->root->right->number == 0)){
        leaves.push_back(tree->root);
    }
    if(tree->root->right->number != 0){
        vector<Node *> temp_leaves = find_leaves(tree->root->right);
        for (int i = 0; i < temp_leaves.size(); i++){
            leaves.push_back(temp_leaves[i]);
        }
    }

    return leaves;
}

int height(Tree * tree){
    int current_height = 0;
    if ((tree->root->left->number != 0) || (tree->root->right->number != 0)){
        if (tree->root->left->number == 0){
            current_height = height(tree->root->right) + 1;
        }
        else if (tree->root->right->number == 0){
            current_height = height(tree->root->left) + 1;
        }
        else{
            current_height = max(height(tree->root->left), height(tree->root->right)) + 1;
        }
    }

    return current_height;
}

void infix_traverse(Tree * tree){
    if(tree->root->left->number != 0){
        infix_traverse(tree->root->left);
    }
    cout << tree->root->value << ' ';
    if(tree->root->right->number != 0){
        infix_traverse(tree->root->right);
    }
}

void prefix_traverse(Tree * tree){
    cout << tree->root->value << ' ';
    if(tree->root->left->number != 0){
        prefix_traverse(tree->root->left);
    }
    if(tree->root->right->number != 0){
        prefix_traverse(tree->root->right);
    }
}

void postfix_traverse(Tree * tree){
    if(tree->root->left->number != 0){
        postfix_traverse(tree->root->left);
    }
    if(tree->root->right->number != 0){
        postfix_traverse(tree->root->right);
    }
    cout << tree->root->value << ' ';
}

int main() {
    Tree my_tree;

    add_value(&my_tree, 3);
    add_value(&my_tree, 2);
    add_value(&my_tree, 1);
    add_value(&my_tree, 4);
    add_value(&my_tree, 6);
    add_value(&my_tree, 5);



    cout << "Infix traverse: ";
    infix_traverse(&my_tree);
    cout << endl;

    cout << "Prefix traverse: ";
    prefix_traverse(&my_tree);
    cout << endl;

    cout << "Postfix traverse: ";
    postfix_traverse(&my_tree);
    cout << endl;

    vector<Node *> leaves = find_leaves(&my_tree);
    cout << "Leaves: ";
    for(int i = 0; i < leaves.size(); i++){
        cout << leaves[i]->value << ' ';
    }
    cout << endl;

    cout << height(&my_tree);

    return 0;
}
