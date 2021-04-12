#include <iostream>

using namespace std;

struct Tree;

struct Leaf{
    int value = 0;
    Tree * left = nullptr;
    Tree * right = nullptr;
};

struct Tree{
    Leaf * root = nullptr;
    unsigned int number = 0;
};

void add_leaf(Tree * tree, int value){
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
    current_tree->root->value;
}

void delete_leaf(Tree * tree, int value){
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
        Tree * temporary_tree = current_tree->root->left;
        current_tree->root = temporary_tree->root;
        delete temporary_tree;
    }
    else if (current_tree->root->right->root->left->number == 0){
        Tree * temporary_tree = current_tree->root->right;
        current_tree->root = temporary_tree->root;
        delete temporary_tree;
    }
    else{
        Tree * temporary_tree = current_tree->root->right;
        while (temporary_tree->root->left->number != 0){

        }
    }
}

void print_tree(Tree * tree);



int main() {

    return 0;
}
