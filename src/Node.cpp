#include <iostream>
#include "../include/Node.h"
#include <string>
using namespace std;

Node::Node(unsigned int v) {
  this->setValue(v);
  this->setLeftNode(nullptr);
  this->setRightNode(nullptr);
}

Node::~Node() {}

void Node::setValue(unsigned int v) {
  this->value = v;
}

void Node::setHeight(unsigned int h) {
  this->height = h;
}

void Node::setLeftNode(Node* ln) {
  this->leftNode = ln;
}

void Node::setRightNode(Node* rn) {
  this->rightNode = rn;
}

unsigned int Node::getValue() {
  return value;
}

unsigned int Node::getHeight() {
  return height;
}

Node* Node::getLeftNode() {
  return leftNode;
}

Node* Node::getRightNode() {
  return rightNode;
}

bool Node::hasChildren() {
  if (this->getLeftNode() == 0 && this->getRightNode() == 0) {
    return false;
  } else {
    return true;
  }
}
