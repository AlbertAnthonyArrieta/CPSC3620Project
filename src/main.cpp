#include <iostream>
#include "../include/Node.h"
#include "../include/AVLTree.h"
#include "AVLTree.cpp"
#include <string>
using namespace std;
int main() {
  cout << "HELLO WORLD" << endl;
  AVLTree* tree = new AVLTree();

  tree->insert(5);

  int treeHeight = tree->getHeight();
  Node* root = tree->getRoot();
  int rootVal = root->getValue();
  cout << "Height of tree: " << treeHeight << endl;
  cout << "Root Node: " << rootVal << endl;


  delete tree;
}
