#include <iostream>
#include "../include/Node.h"
#include "../include/AVLTree.h"
#include "AVLTree.cpp"
#include <string>
using namespace std;
int main() {
  cout << "WELCOME TO AVL TREE" << endl;
  AVLTree* tree = new AVLTree();

  tree->insert(tree->getRoot(), 5);

  //expecting to be 1
  cout << "Tree Height: " << tree->getHeight() << endl;
  //expecting to be 5
  cout << "Tree Root: " << tree->getRoot()->getValue() << endl;

  delete tree;
}
//CURRENT TASK: change the height of tree correctly
