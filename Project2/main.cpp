#include <iostream>
#include "avl_tree.h"
using namespace std;

int main(int argc, char** argv) {

  AVLTree tree;

  char option;
  int key;
  std:: cout << "please enter commands ONE AT A TIME\n";
  do {
    cin >> option;
    switch(option) {
      case 'i':
        cin >> key;
        tree.insert(key);
        break;
      case 'r':
        cin >> key;
        tree.delNode(key);
        break;
      case 'h':
        tree.printHeight();
        break;
      case 'p':
        tree.printKey();
        break;
      default:
        break;
    }
  } while(option != 'q');
}