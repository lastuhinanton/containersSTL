#include "binaryTree.h"

Node* BinaryTree::remove(Node *root, int value){
    if(root == nullptr) return root;
    else if(value < root->value) root->left = remove(root->left, value);
    else if(value > root->value) root->right = remove(root->right, value);
    else {
        if(root->left == nullptr || root->right == nullptr) {
            Node *new_root = (root->left == nullptr) ? root->right: root->left;
            delete root;
            root = new_root;
            new_root = nullptr;
        } else {
            Node *temp = GetMax(root->right);
            root->value = temp->value;
            root->right = remove(root->right, temp->value);
        }
    }
    return root;
}

Node* BinaryTree::insert(Node *root, int value){
    if(root == nullptr){
        return new Node(value);
    } 
    if(value < root->value) root->left = insert(root->left, value);
    else if(value > root->value) root->right = insert(root->right, value);
    return root;
}


Node* BinaryTree::GetMin(Node *root){
    if(root == nullptr || root->left == nullptr) return root;
    return GetMin(root->left);
}

Node* BinaryTree::GetMax(Node *root){
    if(root == nullptr || root->right == nullptr) return root;
    return GetMax(root->right);
}
Node* BinaryTree::SearchNode(Node *root, int value){
    if(root == nullptr || root->value == value) return root;
    return (value < root->value) ? SearchNode(root->left, value): SearchNode(root->right, value);
}

BinaryTree::~BinaryTree(){
    DeleteTree(root);
}

void BinaryTree::DeleteTree(Node *root){
    if(root == nullptr) return;
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
}

void BinaryTree::print(Node* root) {
    if (root == nullptr) {
        return;
    }
    print(root->left);
    std::cout << root->value << " ";
    print(root->right);
}