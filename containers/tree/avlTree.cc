#include "avlTree.h"

#include <cmath>
#include <iomanip>

int AVLTree::GetHeight(Node *root) {
  return root == nullptr ? -1 : root->balance;
}
void AVLTree::UpdateHeight(Node *root) {
  root->balance = std::max(GetHeight(root->left), GetHeight(root->right)) + 1;
}

Node *AVLTree::Remove(Node *root, int value) {
  if (root == nullptr)
    return root;
  else if (value < root->value)
    root->left = Remove(root->left, value);
  else if (value > root->value)
    root->right = Remove(root->right, value);
  else {
    if (root->left == nullptr || root->right == nullptr) {
      Node *new_root = (root->left == nullptr) ? root->right : root->left;
      delete root;
      root = new_root;
      new_root = nullptr;
    } else {
      Node *temp = GetMin(root->right);
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

Node *AVLTree::Insert(Node *root, int value) {
  if (root == nullptr) {
    return new Node(value);
  }
  if (value < root->value) {
    root->left = Insert(root->left, value);

  } else if (value >= root->value) {
    root->right = Insert(root->right, value);
  }
  UpdateHeight(root);

  return Rebalance(root);
}
int AVLTree::GetBalance(Node *root) {
  return (root == nullptr) ? 0 : GetHeight(root->right) - GetHeight(root->left);
}

Node *AVLTree::Rebalance(Node *root) {
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

Node *AVLTree::RightRotation(Node *root) {
  Node *ltemp, *lrtemp;
  ltemp = root->left;
  lrtemp = ltemp->right;
  ltemp->right = root;
  root->left = lrtemp;
  root = ltemp;
  UpdateHeight(root->right);
  UpdateHeight(root);
  return root;
}
Node *AVLTree::LeftRotation(Node *root) {
  Node *rtemp, *rltemp;
  rtemp = root->right;
  rltemp = rtemp->left;

  rtemp->left = root;
  root->right = rltemp;
  root = rtemp;
  UpdateHeight(root->left);
  UpdateHeight(root);
  return root;
}

Node *AVLTree::GetMin(Node *root) {
  if (root == nullptr || root->left == nullptr) return root;
  return GetMin(root->left);
}

Node *AVLTree::GetMax(Node *root) {
  if (root == nullptr || root->right == nullptr) return root;
  return GetMax(root->right);
}
Node *AVLTree::SearchNode(Node *root, int value) {
  if (root == nullptr || root->value == value) return root;
  return (value < root->value) ? SearchNode(root->left, value)
                               : SearchNode(root->right, value);
}

AVLTree::~AVLTree() { DeleteTree(root); }

void AVLTree::DeleteTree(Node *root) {
  if (root == nullptr) return;
  DeleteTree(root->left);
  DeleteTree(root->right);
  delete root;
}

void AVLTree::Print(Node *root) {
  if (root == nullptr) {
    return;
  }
  Print(root->left);
  std::cout << "value = " << root->value << " balance = " << root->balance
            << std::endl;
  Print(root->right);
}

void AVLTree::output(Node *root) {
  int h = GetHeight(root);
  int prob = 3;
  if (root) {
    for (int i = 0; i <= h; i++) {
      print_n(root, i, 0, prob * (h - i));
      std::cout << std::endl;
    }
  }
}

void AVLTree::print_n(const Node *p, int n, int level, int prob) {
  if (p) {
    if (level == n) {
      for (int i = 1; i <= prob + 1; i++) std::cout << " ";
      std::cout << p->value;
    } else {
      print_n(p->left, n, level + 1, prob);
      print_n(p->right, n, level + 1, prob);
    }
  }
}
void AVLTree::printAVLTree(Node *root, int indent = 0) {
  if (root == nullptr) return;
  const int spacing = 4;
  if (root->right) {
    printAVLTree(root->right, indent + spacing);
  }
  std::cout << std::setw(indent) << " ";
  std::cout << root->value << std::endl;
  if (root->left) {
    printAVLTree(root->left, indent + spacing);
  }
}