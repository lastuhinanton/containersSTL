#ifndef _AVL_TREE_
#define _AVL_TREE_
#include <iostream>

class Node {
 public:
  int balance;
  int value;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(int value) : value(value), balance(0){};
};

class AVLTree {
 public:
  AVLTree() : root(nullptr) {}
  ~AVLTree();

  void print() { printAVLTree(root, 0); }
  void insert(int value) { root = Insert(root, value); }
  void remove(int value) { root = Remove(root, value); }
  int get_min() { return GetMin(root)->value; }
  int get_max() { return GetMax(root)->value; }
  bool search(int arg) { return SearchNode(root, arg) != nullptr; }
  void clear() {
    DeleteTree(root);
    root = nullptr;
  }

 private:
  Node *root;
  Node *Insert(Node *root, int value);
  Node *Remove(Node *root, int value);
  Node *GetMin(Node *root);
  Node *GetMax(Node *root);
  Node *SearchNode(Node *root, int value);
  void DeleteTree(Node *root);
  Node *LeftRotation(Node *root);
  Node *RightRotation(Node *root);
  Node *Rebalance(Node *root);
  int GetHeight(Node *root);
  void UpdateHeight(Node *root);
  int GetBalance(Node *root);

  void Print(Node *root);
  void Swap(Node *A, Node *B);
  void output(Node *root);
  void print_n(const Node *p, int n, int level, int prob);
  void printAVLTree(Node *root, int indent);
};

#endif
