#ifndef _BINARY_TREE_
#define _BINARY_TREE_
#include <iostream>

class Node{
public:
    int value;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int value):value(value){};
};

class BinaryTree{
private:
    Node* root;
    Node* insert(Node *root, int value);
    Node* remove(Node *root, int value);
    void print(Node* root);
    Node* GetMin(Node *root);
    Node* GetMax(Node *root);
    Node* SearchNode(Node *root, int value);
    void DeleteTree(Node *root);
public:
    BinaryTree():root(nullptr){}
    ~BinaryTree();
    // bool search(int value){return SearchNode(root, value) ? true: false;}
    // int getMax(){return GetMax(root) ? GetMax(root)->value: -1;}
    // int getMin(){return GetMin(root)->value;}
    void print(){print(root);}
    void insert(int value){ root = insert(root, value);}
    void remove(int value){ root = remove(root, value);}
    void clear(){DeleteTree(root); root = nullptr;}
};


#endif
























































// class TreeNode {
// public:
//     int data;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
// };

// class BinaryTree {
// private:
//     TreeNode* root;
//     TreeNode* insert(TreeNode* currentNode, int value);
//     void inOrderTraversal(TreeNode* currentNode);

// public:
//     BinaryTree();
//     void insert(int value);
//     void inOrderTraversal();
// };