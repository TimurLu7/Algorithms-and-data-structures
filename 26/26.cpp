#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Tree {
    int key;
    Tree* left;
    Tree* right;

    Tree(int a) {
        key = a;
        left = 0;
        right = 0;
    }
};

Tree* insert(Tree* top, int key) {
    if (top == 0) {
        return new Tree(key);
    }
    if (key == top->key) {
        return top;
    }
    if (key < top->key) {
        top->left = insert(top->left, key);
    }
    else {
        top->right = insert(top->right, key);
    }
    return top;
}

Tree* right_remove(Tree* top, int key) {
    if (top == 0) {
        return 0;
    }

    if (key < top->key) {
        top->left = right_remove(top->left, key);
    }
    else if (key > top->key) {
        top->right = right_remove(top->right, key);
    }
    else {
        if (top->left == 0) {
            Tree* temp = top->right;
            delete top;
            return temp;
        }
        else if (top->right == 0) {
            Tree* temp = top->left;
            delete top;
            return temp;
        }
        else {
            Tree* temp = top->right;
            while (temp->left != 0) {
                temp = temp->left;
            }
            top->key = temp->key;
            top->right = right_remove(top->right, temp->key);
        }
    }
    return top;
}

void PreOrderTraversal(Tree* top, ofstream& output) {
    if (top != 0) {
        output << top->key << endl;
        PreOrderTraversal(top->left, output);
        PreOrderTraversal(top->right, output);
    }
}

int count(Tree* top) {
    if (top == 0) {
        return 0;
    }
    return count(top->left) + count(top->right) + 1;
}

void main_func(Tree* top, int& max_d, int& key) {
    if (top == 0) {
        return;
    }

    int lcount = count(top->left);  
    int rcount = count(top->right); 

    int d = abs(lcount - rcount);

    if (d > max_d || (d == max_d && top->key > key)) {
        max_d = d;
        key = top->key;
    }

    main_func(top->left, max_d, key);
    main_func(top->right, max_d, key);
}

int main() {
    setlocale(LC_ALL, "rus");
    ifstream input("tst.in");
    ofstream output("tst.out");

    Tree* tree = 0;
    int key;

    while (input >> key) {
        tree = insert(tree, key);
    }

    int max_d = -1;
    int fkey = -1;
    main_func(tree, max_d, fkey);

    if (fkey != -1) {
        tree = right_remove(tree, fkey);
    }

    PreOrderTraversal(tree, output);

    input.close();
    output.close();

    return 0;
}