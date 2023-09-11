#include <set>
#include <map>
#include <iostream>
#include <cstdlib>
#include "tree/avlTree.h"


using namespace std;

void remove_and_print(AVLTree *tree, int value){
    tree->remove(value);
    cout <<endl;
    cout <<"### del "<< value <<  " ###"<< endl;
    cout << "max = "<< tree->get_max() << endl;
    cout << "min = "<< tree->get_min() << endl;
    tree->print();
    cout << "#################################";


}

int main(){
    AVLTree tree;
    tree.insert(0);
    tree.insert(2);
    tree.insert(1);
    tree.insert(10);
    tree.insert(8);
    tree.insert(14);
    tree.insert(14);
    tree.insert(11);
    tree.insert(19);
    tree.insert(13);
    tree.insert(-13);
    

    cout << "max = "<< tree.get_max() << endl;
    cout << "min = "<< tree.get_min() << endl;
    tree.print();

    remove_and_print(&tree, 14);
    remove_and_print(&tree, 11);
    remove_and_print(&tree, 0);

    
    return 0;
}