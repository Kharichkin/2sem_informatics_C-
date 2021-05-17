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
    int current_height;
    if (tree->number > 0) {
        current_height = 1;
        if ((tree->root->left->number != 0) || (tree->root->right->number != 0)) {
            if (tree->root->left->number == 0) {
                current_height = height(tree->root->right) + 1;
            } else if (tree->root->right->number == 0) {
                current_height = height(tree->root->left) + 1;
            } else {
                current_height = max(height(tree->root->left), height(tree->root->right)) + 1;
            }
        }
    }
    else{
        current_height = 0;
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

void small_left_rotation(Tree * tree){
    Node* tree_root = tree->root;
    Node* subtree_root = tree->root->right->root;
    Tree* right_tree = tree->root->right->root->right;
    Tree* central_tree = tree->root->right->root->left;
    Tree* left_tree = tree->root->left;

    tree->root = subtree_root;
    tree->root->right = right_tree;
    tree->root->left = new Tree;
    tree->root->left->number = left_tree->number + central_tree->number + 1;
    tree->root->left->root = tree_root;
    tree->root->left->root->right = central_tree;
    tree->root->left->root->left = left_tree;
}

void big_left_rotation(Tree * tree){
    Node* tree_root = tree->root;
    Node* subtree_root = tree->root->right->root;
    Node* subsubtree_root = tree->root->right->root->left->root;
    Tree* right_tree = tree->root->right->root->right;
    Tree* central_right_tree = tree->root->right->root->left->root->right;
    Tree* central_left_tree = tree->root->right->root->left->root->left;
    Tree* left_tree = tree->root->left;

    tree->root = subsubtree_root;
    tree->root->right = new Tree;
    tree->root->left = new Tree;
    tree->root->right->number = right_tree->number + central_right_tree->number + 1;
    tree->root->left->number = left_tree->number + central_left_tree->number + 1;
    tree->root->right->root = subtree_root;
    tree->root->right->root->right = right_tree;
    tree->root->right->root->left = central_right_tree;
    tree->root->left->root = tree_root;
    tree->root->left->root->left = left_tree;
    tree->root->left->root->right = central_left_tree;
}

void small_right_rotation(Tree * tree){
    Node* tree_root = tree->root;
    Node* subtree_root = tree->root->left->root;
    Tree* right_tree = tree->root->right;
    Tree* central_tree = tree->root->left->root->right;
    Tree* left_tree = tree->root->left->root->left;

    tree->root = subtree_root;
    tree->root->left = left_tree;
    tree->root->right = new Tree;
    tree->root->right->number = right_tree->number + central_tree->number + 1;
    tree->root->right->root = tree_root;
    tree->root->right->root->left = central_tree;
    tree->root->right->root->right = right_tree;
}

void big_right_rotation(Tree * tree){
    Node* tree_root = tree->root;
    Node* subtree_root = tree->root->left->root;
    Node* subsubtree_root = tree->root->left->root->right->root;
    Tree* right_tree = tree->root->right;
    Tree* central_right_tree = tree->root->left->root->right->root->right;
    Tree* central_left_tree = tree->root->left->root->right->root->left;
    Tree* left_tree = tree->root->left->root->left;

    tree->root = subsubtree_root;
    tree->root->right = new Tree;
    tree->root->left = new Tree;
    tree->root->right->number = right_tree->number + central_right_tree->number + 1;
    tree->root->left->number = left_tree->number + central_left_tree->number + 1;
    tree->root->right->root = tree_root;
    tree->root->right->root->right = right_tree;
    tree->root->right->root->left = central_right_tree;
    tree->root->left->root = subtree_root;
    tree->root->left->root->left = left_tree;
    tree->root->left->root->right = central_left_tree;
}

void rebalance(Tree * tree){
    if((height(tree->root->right) - height(tree->root->left)) == 2 && (height(tree->root->right->root->left) <= height(tree->root->right->root->right))){
        small_left_rotation(tree);
    }
    if((height(tree->root->right) - height(tree->root->left)) == 2 && (height(tree->root->right->root->left) > height(tree->root->right->root->right))){
        big_left_rotation(tree);
    }
    if((height(tree->root->left) - height(tree->root->right)) == 2 && (height(tree->root->left->root->right) <= height(tree->root->left->root->left))){
        small_right_rotation(tree);
    }
    if((height(tree->root->left) - height(tree->root->right)) == 2 && (height(tree->root->left->root->right) > height(tree->root->left->root->left))){
        big_right_rotation(tree);
    }
}

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

    rebalance(tree);
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

    rebalance(tree);
}

int main() {
    Tree my_tree;

    add_value(&my_tree, 1);
    add_value(&my_tree, 6);
    add_value(&my_tree, 5);
    add_value(&my_tree, 4);
    add_value(&my_tree, 3);
    add_value(&my_tree, 2);


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
