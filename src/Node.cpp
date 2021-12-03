#include <iostream>
#include "../include/Node.h"
#include <string>
using namespace std;

Node::Node() {
}

Node::Node(int v) {
  this->setValue(v);
}

Node::~Node() {}

void Node::setValue(int v) {
  value = v;
}

void Node::setHeight(int h) {
  height = h;
}

void Node::setLeftNode(Node* ln) {
  leftNode = ln;
}

void Node::setRightNode(Node* rn) {
  rightNode = rn;
}

int Node::getValue() {
  return value;
}

int Node::getHeight() {
  return height;
}

Node* Node::getLeftNode() {
  return leftNode;
}

Node* Node::getRightNode() {
  return rightNode;
}
