#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*struct Node {
    int data;
    Node *left, *right, *right_sibling;
    int level;
};*/

void build_siblings(Node* this_root)
{
    if (!this_root)
        return;

    if (this_root->left)
    {
        this_root->left->right_sibling = this_root->right;

        if (!this_root->left->right_sibling && this_root->right_sibling)
        {
            this_root->left->right_sibling = this_root->right_sibling->left;

            if (!this_root->left->right_sibling)
                this_root->left->right_sibling = this_root->right_sibling->right;
        }
    }

    if (this_root->right && this_root->right_sibling)
    {
        this_root->right->right_sibling = this_root->right_sibling->left;

        if (!this_root->right->right_sibling)
            this_root->right->right_sibling = this_root->right_sibling->right;
    }

    build_siblings(this_root->left);
    build_siblings(this_root->right);
}

/*void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = new Node;
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->right_sibling = NULL;
        (*root)->level = 0;
        return;
    }
    if ((*root)->data > data)
        insert(&((*root)->left), data);
    if ((*root)->data < data)
        insert(&((*root)->right), data);
}

void mark_levels(Node* root) {
    if (!root)
        return;
    if (root->left) {
        root->left->level = root->level + 1;
        mark_levels(root->left);
    }
    if (root->right) {
        root->right->level = root->level + 1;
        mark_levels(root->right);
    }
}

void clear(Node* root) {
    if (!root)
        return;
    clear(root->left);
    clear(root->right);
    delete root;
}

void build_siblings(Node* root);

void print_siblings(Node* root) {
    if (!root)
        return;
    cout << root->data << " ";
    print_siblings(root->right_sibling);
}

bool print_level(Node* root, int level) {
    if (!root)
        return false;
    if (root->level == level) {
        print_siblings(root);
        cout << endl;
        return true;
    }
    if (print_level(root->left, level))
        return true;
    if (print_level(root->right, level))
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        insert(&root, tmp);
    }
    mark_levels(root);
    build_siblings(root);
    int level;
    cin >> level;
    print_level(root, level);;
    clear(root);
    return 0;
}*/


