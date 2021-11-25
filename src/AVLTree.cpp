#include <iostream>
#include "../include/Node.h"
#include "../include/AVLTree.h"
#include "Node.cpp"
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
  Node* newNode = new Node(val);
  int treeHeight = this->getHeight();
  if (treeHeight == 0) {
    newNode->setHeight(1);
    this->setRoot(newNode);
  }
  this->balance();
}

void AVLTree::remove(int val) {}

bool AVLTree::search(int val) {
  return false;
}

void AVLTree::balance() {
  Node* visitedNode = this->getRoot();
  Node* leftNode = visitedNode->getLeftNode();
  Node* rightNode = visitedNode->getRightNode();
  if (leftNode == 0 && rightNode == 0) {
    this->setHeight(visitedNode->getHeight());
    cout << "no children" << endl;
  }


}

void AVLTree::leftRotation() {}

void AVLTree::rightRotation() {}

void AVLTree::leftRightRotation() {}

void AVLTree::rightLeftRotation() {}

void AVLTree::setRoot(Node* node) {
  this->rootNode = node;
}

void AVLTree::setHeight(int h) {
  this->height = h;
}

Node* AVLTree::getRoot() {
  return rootNode;
}

int AVLTree::getHeight() {
  return height;
}
