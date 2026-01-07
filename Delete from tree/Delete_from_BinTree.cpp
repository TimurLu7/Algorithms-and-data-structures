#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int v) {
        key = v;
        left = 0;
        right = 0;
    }
};

Node* insert(Node* tree, int key) {
    if (tree == 0) {
        return new Node(key);
    }

    if (key == tree->key) {
        return tree;
    }

    if (key < tree->key) {
        tree->left = insert(tree->left, key);
    }
    else {
        tree->right = insert(tree->right, key);
    }

    return tree;
}

Node* Min(Node* tree) {
    while (tree->left != 0) {
        tree = tree->left;
    }
    return tree;
}

Node* remove(Node* tree, int key) {
    if (tree == 0) {
        return 0;
    }

    if (key < tree->key) {
        tree->left = remove(tree->left, key);
    }
    else if (key > tree->key) {
        tree->right = remove(tree->right, key);
    }
    else {
        if (tree->left == 0) {
            Node* temp = tree->right;
            delete tree;
            return temp;
        }
        else if (tree->right == 0) {
            Node* temp = tree->left;
            delete tree;
            return temp;
        }
        else {
            Node* temp = Min(tree->right);
            tree->key = temp->key;
            tree->right = remove(tree->right, temp->key);
        }
    }
    return tree;
}

void PreOrderTraversal(Node* tree, ofstream& output) {
    if (tree != 0) {
        output << tree->key << endl;
        PreOrderTraversal(tree->left, output);
        PreOrderTraversal(tree->right, output);
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    
    Node* tree = 0;
    int key;
    input >> key;
    int keyToDel = key;

    string empty;
    getline(input, empty);
    getline(input, empty);

    while (input >> key) {
        tree = insert(tree, key);
    }

    tree = remove(tree, keyToDel);

    PreOrderTraversal(tree, output);

    input.close();
    output.close();

    return 0;
}