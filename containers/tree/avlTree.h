#ifndef _AVL_TREE_
#define _AVL_TREE_

namespace s21 {

template <typename T>
class Node {
 public:
  int balance;
  T value;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(T value) : value(value), balance(0){};
};

template <typename T>
class AVLTree {
 public:
  AVLTree() : root(nullptr) {repeate = false;}
  ~AVLTree();

  void print() { Print(root); }
  void insert(T value) { root = Insert(root, value); }
  void remove(T value) { root = Remove(root, value); }
  T get_min() { return GetMin(root)->value; }
  T get_max() { return GetMax(root)->value; }
  bool search(T arg) { return SearchNode(root, arg) != nullptr; }
  void clear() {
    DeleteTree(root);
    root = nullptr;
  }
  void set_repeate_value(bool t);
 private:
  bool repeate;
  Node<T> *root;
  Node<T> *Insert(Node<T> *root, T value);
  Node<T> *Remove(Node<T> *root, T value);
  Node<T> *GetMin(Node<T> *root);
  Node<T> *GetMax(Node<T> *root);
  Node<T> *SearchNode(Node<T> *root, T value);
  void DeleteTree(Node<T> *root);
  Node<T> *LeftRotation(Node<T> *root);
  Node<T> *RightRotation(Node<T> *root);
  Node<T> *Rebalance(Node<T> *root);
  int GetHeight(Node<T> *root);
  void UpdateHeight(Node<T> *root);
  int GetBalance(Node<T> *root);

  void Print(Node<T> *root);
  // void Swap(Node<T> *A, Node<T> *B);
  // void output(Node<T> *root);
  // void print_n(const Node<T> *p, int n, int level, int prob);
  // void printAVLTree(Node<T> *root, int indent);
};

}  // namespace s21
#include "avlTree.tcc"
#endif
