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

Node* AVLTree::insert(Node* visitedNode, int val) {
  Node* leftNode = visitedNode->getLeftNode();
  Node* rightNode = visitedNode->getRightNode();

  //if visited node is null
  if (visitedNode == NULL) {
    Node* newNode = new Node(val);
    return newNode();
  }

  //Compare left or right nodes
  if (val < visitedNode->getValue()) {
    leftNode = insert(leftNode, val);
  } else if (val > visitedNode->getValue()) {
    rightNode = insert(rightNode, val);
  } else {
    return visitedNode;
  }

  //Change heights after changes
  visitedNode->getHeight() = 1 + max(leftNode->getHeight(), rightNode->getHeight());

  return this->balance(visitedNode, val);
}


void AVLTree::remove(int val) {}

bool AVLTree::search(int val) {
  return false;
}

Node* AVLTree::balance(Node* visitedNode, int val) {
  int balanceCheck;
  Node* leftNode = visitedNode->getLeftNode();
  Node* rightNode = vistedNode->getRightNode();
  if (visitedNode == NULL) {
    balanceCheck = 0;
  } else {
    balanceCheck = leftNode->getHeight() - rightNode->getHeight();
  }

  //decide on what rotation to execute
  //left-left / right-right / left-right / right-left
  if (balanceCheck > 1 && leftNode->getValue() > val) {
    return rightRotation(visitedNode);
  } else if (balanceCheck < -1 && rightNode->getValue() < val) {
    return leftRotation(visitedNode);
  } else if (balanceCheck > 1 && leftNode->getValue() < val) {
    return rightRotation(visitedNode);
  } else if (balanceCheck < -1 && rightNode->getValue() > val) {
    return leftRotation(visitedNode);
  }

  return visitedNode;
}

Node* AVLTree::leftRotation() {}

Node* AVLTree::rightRotation() {}

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
