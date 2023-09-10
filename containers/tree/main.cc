#include <set>
#include <map>
#include <iostream>
#include <cstdlib>
#include "avlTree.h"


using namespace std;

int main(){
    AVLTree tree;
    // tree.insert(0);
    // tree.insert(2);
    // tree.insert(1);
    // tree.insert(10);
    // tree.insert(8);
    // tree.insert(14);
    // tree.insert(11);
    // tree.insert(19);
    // tree.insert(13);
    // tree.insert(-13);

    for (int i =0; i < 100; i++){
        int random = 1 + rand() % 99999;
        tree.insert(random);
    }
    tree.print();


    return 0;
}