#include <iostream>
#include "../include/Node.h"
#include "../include/AVLTree.h"
#include "Node.cpp"
#include <string>
using namespace std;

AVLTree::AVLTree() {
  Node* node = new Node(0);
  this->setRoot(node);
  this->setHeight(0);
}

AVLTree::AVLTree(int values[]) {
  //will insert a bunch of the values and then balance the tree.
}

AVLTree::~AVLTree() {}

void AVLTree::insert(Node* visitedNode, unsigned int val) {
  //if visited node is null
  if (visitedNode->getValue() == 0) {
    visitedNode->setValue(val);

    //if this is an empty tree
    if (this->getHeight() == 0) {
      visitedNode->setHeight(1);
      this->setRoot(visitedNode);
    }
  }
  cout << "VISITED" << endl;


  if (visitedNode->getValue() > val) {
    insert(visitedNode->getLeftNode(), val);
  } else if (visitedNode->getValue() < val){
    insert(visitedNode->getRightNode(), val);
  }
  //this->balance();
}


void AVLTree::remove(unsigned int val) {}

bool AVLTree::search(unsigned int val) {
  return false;
}

void AVLTree::balance() {
}

void AVLTree::leftRotation() {}

void AVLTree::rightRotation() {}

void AVLTree::leftRightRotation() {}

void AVLTree::rightLeftRotation() {}

void AVLTree::setRoot(Node* node) {
  this->rootNode = node;
}

void AVLTree::setHeight(unsigned int h) {
  this->height = h;
}

Node* AVLTree::getRoot() {
  return rootNode;
}

unsigned int AVLTree::getHeight() {
  return height;
}
