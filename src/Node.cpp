#include "Node.h"

Node::Node(int val) {
  value = val;
  leftNode = nullptr;
  rightNode = nullptr;
  height = 1;
}

Node::~Node() {
  delete leftNode;
  delete rightNode;
}

int Node::getValue() {
  return value;
}

void Node::changeValue(int v) {
  value= v;
}

Node* Node::getLeftNode() {
  return leftNode;
}

void Node::changeLeftNode(Node* newNode) {
  leftNode = newNode;
}

Node* Node::getRightNode() {
  return rightNode;
}

void Node::changeRightNode(Node* newNode) {
  rightNode = newNode;
}

int Node::getHeight() {
  if (this == nullptr) {
    return 0;
  } else {
    return height;
  }
}

void Node::changeHeight(int newH) {
  height = newH;
}

int Node::getHeightTreeRec(Node* n) {
  if (n == nullptr) {
    return 0;
  } else {
    return maxNode(n->getHeightTreeRec(n->getLeftNode()),n->getHeightTreeRec(n->getRightNode())) + 1;
  }
}

int Node::maxNode(int a, int b) {
  if (a > b) {
    return a;
  } else if (a < b) {
    return b;
  }
}
