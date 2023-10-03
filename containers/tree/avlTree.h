#ifndef _AVL_TREE_
#define _AVL_TREE_
#include <iostream>
#include <limits>

// #include "s21_set.h"

template <class T, class U>
struct Node {
  int balance;
  T key;
  U data;
  Node* left;
  Node* right;
  Node* next = nullptr;
  Node* prev = nullptr;
};

template <class T, class U>
class AVLTree {
 public:
  using value_type = T;
  using second_type = U;
  using size_type = size_t;
  using node_type = Node<value_type, second_type>;
  using node_pointer = Node<value_type, second_type>*;

 private:
  // friend class set;
  node_pointer root_;
  size_type size_ = 0;
  bool repeate_;

 public:
  size_type* get_reference_of_size() { return &size_; }
  AVLTree() : root_(nullptr) { repeate_ = false; }
  AVLTree(const AVLTree& other) { *this = other; }
  AVLTree& operator=(const AVLTree& other) {
    if (this == &other) {
      return *this;
    }
    clear();
    CopyTree(other.root_);
    repeate_ = other.repeate_;
    size_ = other.size_;
    return *this;
  }
  AVLTree(AVLTree&& other) noexcept { *this = std::move(other); }
  AVLTree& operator=(AVLTree&& other) noexcept {
    if (this == &other) {
      return *this;
    }
    size_ = other.size_;
    repeate_ = other.repeate_;
    root_ = other.root_;
    other.size_ = 0;
    other.repeate_ = false;
    other.root_ = nullptr;
    return *this;
  }

  ~AVLTree() { clear(); }
  node_pointer begin() {
    node_pointer temp_min = GetMin(root_);
    node_pointer temp_max = GetMax(root_);

    if (temp_max != nullptr) temp_max->next = nullptr;
    if (temp_min != nullptr) temp_min->prev = nullptr;
    return temp_min;
  }
  node_pointer end() { return GetMax(root_); }

  void insert(value_type value, second_type data) {
    root_ = Insert(root_, value, data);
  }

  void remove(value_type value) { root_ = Remove(root_, value); }

  void print() { PrettyPrintTree(root_); }

  node_pointer search(value_type arg) { return SearchNode(root_, arg); }

  void clear() {
    DeleteTree(root_);
    root_ = nullptr;
    size_ = 0;
  }

  void set_repeate_value(bool t) { repeate_ = t; }

  value_type get_min() { return GetMin(root_)->key; }

  value_type get_max() { return GetMax(root_)->key; }

  size_type get_size() { return size_; }

  node_pointer get_root_pointer() { return root_; }

 private:
  void CopyTree(node_pointer root) {
    if (root != nullptr) {
      this->insert(root->key, root->data);
      CopyTree(root->left);
      CopyTree(root->right);
    }
  }

  void DeleteTree(node_pointer root) {
    if (root == nullptr) return;
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
  }
  void SetLeftRoot(node_pointer root) {
    root->left->next = root;
    if (root->prev != nullptr) {
      root->left->prev = root->prev;
      root->left->prev->next = root->left;
    }
    root->prev = root->left;
  }
  void SetRightRoot(node_pointer root) {
    root->right->prev = root;
    if (root->next != nullptr) {
      root->right->next = root->next;
      root->right->next->prev = root->right;
    }
    root->next = root->right;
  }

  node_pointer Insert(node_pointer root, value_type value, second_type data) {
    if (root == nullptr) {
      size_++;
      node_pointer node = new node_type;
      node->balance = 0;
      node->data = data;
      node->key = value;
      node->right = nullptr;
      node->left = nullptr;
      return node;
    }
    if (value < root->key) {
      bool is_null = root->left == nullptr;
      root->left = Insert(root->left, value, data);
      if (is_null) SetLeftRoot(root);

    } else if (value > root->key) {
      bool is_null = root->right == nullptr;
      root->right = Insert(root->right, value, data);
      if (is_null) SetRightRoot(root);

    } else if (value == root->key && repeate_ == true) {
      bool is_null = root->right == nullptr;
      root->right = Insert(root->right, value, data);
      if (is_null) SetRightRoot(root);
    }
    UpdateHeight(root);
    return Rebalance(root);
  }

  int GetHeight(node_pointer root) {
    return root == nullptr ? -1 : root->balance;
  }

  void UpdateHeight(node_pointer root) {
    root->balance = std::max(GetHeight(root->left), GetHeight(root->right)) + 1;
  }

  int GetBalance(node_pointer root) {
    return (root == nullptr) ? 0
                             : GetHeight(root->right) - GetHeight(root->left);
  }

  node_pointer Rebalance(node_pointer root) {
    int balance = GetBalance(root);
    if (balance == -2) {
      if (GetBalance(root->left) == 1) {
        root->left = LeftRotation(root->left);
      }
      root = RightRotation(root);
    } else if (balance == 2) {
      if (GetBalance(root->right) == -1) {
        root->right = RightRotation(root->right);
      }
      root = LeftRotation(root);
    }
    return root;
  }

  node_pointer RightRotation(node_pointer root) {
    node_type *ltemp, *lrtemp;
    ltemp = root->left;
    lrtemp = ltemp->right;
    ltemp->right = root;
    root->left = lrtemp;
    root = ltemp;
    UpdateHeight(root->right);
    UpdateHeight(root);
    return root;
  }

  node_pointer LeftRotation(node_pointer root) {
    node_type *rtemp, *rltemp;
    rtemp = root->right;
    rltemp = rtemp->left;

    rtemp->left = root;
    root->right = rltemp;
    root = rtemp;
    UpdateHeight(root->left);
    UpdateHeight(root);
    return root;
  }

  void PrettyPrintTree(node_pointer node, std::string prefix = "",
                       bool isLeft = true) {
    if (node == nullptr) {
      std::cout << "Empty tree";
      return;
    }

    if (node->right) {
      PrettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
    std::cout << prefix + (isLeft ? "└── " : "┌── ") +
                     std::to_string(node->key) + "\n";

    if (node->left) {
      PrettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
  }

  node_pointer Remove(node_pointer root, value_type value) {
    if (root == nullptr)
      return root;
    else if (value < root->key)
      root->left = Remove(root->left, value);
    else if (value > root->key)
      root->right = Remove(root->right, value);
    else {
      if (root->left == nullptr || root->right == nullptr) {
        size_ -= 1;
        node_pointer new_root =
            (root->left == nullptr) ? root->right : root->left;

        if (root->prev != nullptr) root->prev->next = root->next;
        if (root->next != nullptr) root->next->prev = root->prev;

        delete root;
        root = new_root;
        new_root = nullptr;
      } else {
        node_pointer temp = GetMin(root->right);
        root->key = temp->key;
        root->data = temp->data;
        root->right = Remove(root->right, temp->key);
      }
    }
    if (root != nullptr) {
      UpdateHeight(root);
      root = Rebalance(root);
    }
    return root;
  }

  node_pointer GetMin(node_pointer root) {
    if (root == nullptr || root->left == nullptr) return root;
    return GetMin(root->left);
  }

  node_pointer GetMax(node_pointer root) {
    if (root == nullptr || root->right == nullptr) return root;
    return GetMax(root->right);
  }

  node_pointer SearchNode(node_pointer root, value_type value) {
    if (root == nullptr || root->key == value) return root;
    return (value < root->key) ? SearchNode(root->left, value)
                               : SearchNode(root->right, value);
  }
};

#endif
