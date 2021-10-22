#include "Tree.hpp"
#include <iostream>
using std::shared_ptr;
using std::cout;
using std::endl;
using namespace MyTreeNamespace;

int main() {
    cout << "An example of MyTree class." << endl;

    shared_ptr<MyTree<int>> t(new MyTree<int>);
    t->add_node(t->root, 1);
    t->add_node(t->root->left_son, 2);
    t->add_node(t->root->left_son->left_son, 3);
    t->add_node(t->root->right_son, 4);
    
    t->in_order_print();

    return 0;
}