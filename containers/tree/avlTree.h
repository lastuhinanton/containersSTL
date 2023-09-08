#ifndef _AVL_TREE_
#define _AVL_TREE_
#include <iostream>

class Node{
public:
    int balance;
    int value;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int value):value(value), balance(0){};
};

class AVLTree{
private:
    Node* root;
    Node* insert(Node *root, int value);
    Node* remove(Node *root, int value);
    void print(Node* root);
    Node* GetMin(Node *root);
    Node* GetMax(Node *root);
    Node* SearchNode(Node *root, int value);
    void DeleteTree(Node *root);
    Node* LeftRotation(Node *root);
    Node* RightRotation(Node *root);
    Node* Rebalance(Node *root);
    int GetHeight(Node *root);
    void UpdateHeight(Node *root);
    int GetBalance(Node *root);
    void Swap(Node *A, Node *B);
    void output(Node *root);
    void print_n(const Node *p, int n, int level, int prob);
    void printAVLTree(Node* root, int indent);

    
public:
    AVLTree():root(nullptr){}
    ~AVLTree();

    void print(){printAVLTree(root, 0);}
    void insert(int value){ root = insert(root, value);}
    void remove(int value){ root = remove(root, value);}
    void clear(){DeleteTree(root); root = nullptr;}
};


#endif



