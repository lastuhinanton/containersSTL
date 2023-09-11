#include "avlTree.h"
#include <iostream>

namespace s21 {
template <typename T>
void AVLTree<T>::set_repeate_value(bool t){
  repeate = t;
}

template <typename T>
int AVLTree<T>::GetHeight(Node<T> *root) {
  return root == nullptr ? -1 : root->balance;
}
template <typename T>
void AVLTree<T>::UpdateHeight(Node<T> *root) {
  root->balance = std::max(GetHeight(root->left), GetHeight(root->right)) + 1;
}
template <typename T>
Node<T> *AVLTree<T>::Remove(Node<T> *root, T value) {
  if (root == nullptr)
    return root;
  else if (value < root->value)
    root->left = Remove(root->left, value);
  else if (value > root->value)
    root->right = Remove(root->right, value);
  else {
    if (root->left == nullptr || root->right == nullptr) {
      Node<T> *new_root = (root->left == nullptr) ? root->right : root->left;
      delete root;
      root = new_root;
      new_root = nullptr;
    } else {
      Node<T> *temp = GetMin(root->right);
      root->value = temp->value;
      root->right = Remove(root->right, temp->value);
    }
  }
  if (root != nullptr) {
    UpdateHeight(root);
    root = Rebalance(root);
  }
  return root;
}
template <typename T>
Node<T> *AVLTree<T>::Insert(Node<T> *root, T value) {
  if (root == nullptr) {
    return new Node<T>(value);
  }
  if (value < root->value) {
    root->left = Insert(root->left, value);
  } else if (value > root->value) {
    root->right = Insert(root->right, value);
  } else if(value == root->value && repeate == true){
    root->right = Insert(root->right, value);
  }
  UpdateHeight(root);

  return Rebalance(root);
}
template <typename T>
int AVLTree<T>::GetBalance(Node<T> *root) {
  return (root == nullptr) ? 0 : GetHeight(root->right) - GetHeight(root->left);
}
template <typename T>
Node<T> *AVLTree<T>::Rebalance(Node<T> *root) {
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
template <typename T>
Node<T> *AVLTree<T>::RightRotation(Node<T> *root) {
  Node<T> *ltemp, *lrtemp;
  ltemp = root->left;
  lrtemp = ltemp->right;
  ltemp->right = root;
  root->left = lrtemp;
  root = ltemp;
  UpdateHeight(root->right);
  UpdateHeight(root);
  return root;
}
template <typename T>
Node<T> *AVLTree<T>::LeftRotation(Node<T> *root) {
  Node<T> *rtemp, *rltemp;
  rtemp = root->right;
  rltemp = rtemp->left;

  rtemp->left = root;
  root->right = rltemp;
  root = rtemp;
  UpdateHeight(root->left);
  UpdateHeight(root);
  return root;
}
template <typename T>
Node<T> *AVLTree<T>::GetMin(Node<T> *root) {
  if (root == nullptr || root->left == nullptr) return root;
  return GetMin(root->left);
}
template <typename T>
Node<T> *AVLTree<T>::GetMax(Node<T> *root) {
  if (root == nullptr || root->right == nullptr) return root;
  return GetMax(root->right);
}
template <typename T>
Node<T> *AVLTree<T>::SearchNode(Node<T> *root, T value) {
  if (root == nullptr || root->value == value) return root;
  return (value < root->value) ? SearchNode(root->left, value)
                               : SearchNode(root->right, value);

}
template <typename T>
AVLTree<T>::~AVLTree() {
  DeleteTree(root);
}

template <typename T>
void AVLTree<T>::DeleteTree(Node<T> *root) {
  if (root == nullptr) return;
  DeleteTree(root->left);
  DeleteTree(root->right);
  delete root;
}

template <typename T>
void AVLTree<T>::Print(Node<T> *root) {
  if (root == nullptr) {
    return;
  }
  Print(root->left);
  std::cout << root->value << " ";
  Print(root->right);
}
// template <typename T>
// void AVLTree<T>::output(Node<T> *root) {
//   int h = GetHeight(root);
//   int prob = 3;
//   if (root) {
//     for (int i = 0; i <= h; i++) {
//       print_n(root, i, 0, prob * (h - i));
//       std::cout << std::endl;
//     }
//   }
// }
// template <typename T>
// void AVLTree<T>::print_n(const Node<T> *p, int n, int level, int prob) {
//   if (p) {
//     if (level == n) {
//       for (int i = 1; i <= prob + 1; i++) std::cout << " ";
//       std::cout << p->value;
//     } else {
//       print_n(p->left, n, level + 1, prob);
//       print_n(p->right, n, level + 1, prob);
//     }
//   }
// }
// template <typename T>
// void AVLTree<T>::printAVLTree(Node<T> *root, int indent) {
//   if (root == nullptr) return;
//   const int spacing = 4;
//   if (root->right) {
//     printAVLTree(root->right, indent + spacing);
//   }
//   std::cout << std::setw(indent) << " ";
//   std::cout << root->value << std::endl;
//   if (root->left) {
//     printAVLTree(root->left, indent + spacing);
//   }
// }
}  // namespace s21