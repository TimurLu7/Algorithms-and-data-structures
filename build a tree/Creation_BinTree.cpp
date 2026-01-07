#include <iostream>
#include <fstream>

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

    while (input >> key) {
        tree = insert(tree, key);
    }

    PreOrderTraversal(tree, output);

    input.close();
    output.close();

    return 0;
}