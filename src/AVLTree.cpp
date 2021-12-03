#include <iostream>
#include "../include/Node.h"
#include "../include/AVLTree.h"
#include "Node.cpp"
#include <string>
using namespace std;

AVLTree::AVLTree() {
  Node* root = NULL;
  this->setRoot(root);
  this->setHeight(0);
}

AVLTree::AVLTree(int values[]) {
  //will insert a bunch of the values and then balance the tree.
}

AVLTree::~AVLTree() {}

Node* AVLTree::insert(Node* visitedNode, int val) {
  Node* leftNode = visitedNode->getLeftNode();
  Node* rightNode = visitedNode->getRightNode();
  std::cout << v << std::endl;
  //if visited node is null
  if (visitedNode == NULL) {
    std::cout << "HERE" << std::endl;
    Node* newNode = new Node(val);
    return newNode;
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
  visitedNode->setHeight(1 + getMax(leftNode->getHeight(), rightNode->getHeight()));

  return balance(visitedNode, val);
}


void AVLTree::remove(int val) {}

bool AVLTree::search(int val) {
  return false;
}

Node* AVLTree::balance(Node* visitedNode, int val) {
  int balanceCheck;
  Node* leftNode = visitedNode->getLeftNode();
  Node* rightNode = visitedNode->getRightNode();
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

Node* AVLTree::leftRotation(Node* n) {
  Node* tempNode1 = n->getRightNode();
  Node* tempNode2 = tempNode1->getLeftNode();

  //rotation
  tempNode1->setLeftNode(n);
  n->setRightNode(tempNode2);

  //change heights
  Node* nLeftNode = n->getLeftNode();
  Node* nRightNode = n->getRightNode();
  Node* tn1LeftNode = tempNode1->getLeftNode();
  Node* tn1RightNode = tempNode1->getRightNode();

  n->setHeight(getMax(nLeftNode->getHeight(), nRightNode->getHeight()) + 1);
  tempNode1->setHeight(getMax(tn1LeftNode->getHeight(), tn1RightNode->getHeight()) + 1);

  return tempNode1;
}

Node* AVLTree::rightRotation(Node* n) {
  Node* tempNode1 = n->getLeftNode();
  Node* tempNode2 = tempNode1->getRightNode();

  //rotation
  tempNode1->setRightNode(n);
  n->setLeftNode(tempNode2);

  //change heights
  Node* nLeftNode = n->getLeftNode();
  Node* nRightNode = n->getRightNode();
  Node* tn1LeftNode = tempNode1->getLeftNode();
  Node* tn1RightNode = tempNode1->getRightNode();

  n->setHeight(getMax(nLeftNode->getHeight(), nRightNode->getHeight()) + 1);
  tempNode1->setHeight(getMax(tn1LeftNode->getHeight(), tn1RightNode->getHeight()) + 1);

  return tempNode1;
}

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

int AVLTree::getMax(int a, int b) {
  if (a > b) {
    return a;
  } else if (a < b) {
    return b;
  }
}
