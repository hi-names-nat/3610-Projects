//modify trees for AVL use
//normal code

#include <cstdlib>
#include <iostream>
#include "avl_tree.h"

int main(int argc, char const *argv[])
{
    std::cout << "enter orders\n";
    std::string userStr;

    AVLTree tree;

    while (true) {
        std::cin >> userStr;

        if (userStr[0] == 'i') {
            tree.insert(std::stoi(userStr.substr(2)), tree.root);
        }
        else if (userStr[0] == 'r') {
            tree.remove(std::stoi(userStr.substr(2)), tree.root);
        }
        else if (userStr[0] == 'h') {
            //print height
        }
        else if (userStr[0] == 'p') {
            //print key
        }
        else if (userStr[0] == 'q') {
            return(0);
        }
        else {
            std::cout << "invalid operation" << std::endl;
        }
    }
}
