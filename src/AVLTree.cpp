#include <iostream>
#include "Node.h"
#include "AVLTree.h"
#include <string>
using namespace std;

AVLTree::AVLTree() {
  setHeight(0);
}

AVLTree::AVLTree(int values[]) {
  //will insert a bunch of the values and then balance the tree.
}

AVLTree::~AVLTree() {}

void AVLTree::insert(int val) {
  
}

void AVLTree::remove(int val) {}

bool AVLTree::search(int val) {}

void AVLTree::balance() {}

void AVLTree::leftRotation() {}

void AVLTree::rightRotation() {}

void AVLTree::leftRightRotation() {}

void AVLTree::rightLeftRotation() {}

void AVLTree::setRoot(Node* node) {
  this.rootNode = node;
}

void AVLTree::setHeight(int h) {
  this.height = h;
}

Node* AVLTree::getRoot() {
  return rootNode;
}

int AVLTree::getHeight() {
  return height;
}
