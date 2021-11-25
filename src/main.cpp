#include <iostream>
#include "../include/Node.h"
#include "../include/AVLTree.h"
#include "AVLTree.cpp"
#include "Node.cpp"
#include <string>
using namespace std;
int main() {
  cout << "HELLO WORLD" << endl;

  AVLTree* tree = new AVLTree();

  //tree->insert(1);

  //int treeHeight = tree->getHeight();
  //cout << "Height of tree: " << treeHeight << endl;

  delete tree;
}
