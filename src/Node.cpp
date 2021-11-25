#include <iostream>
#include "../include/Node.h"
#include <string>
using namespace std;

Node::Node(int v, int h) {
  this.setValue(v);
  this.setHeight(h);
}

Node::~Node() {}

void Node::setValue(int v) {
  this.value = v;
}

void Node::setHeight(int h) {
  this.height = h;
}

void Node::setLeftNode(Node* ln) {
  this.leftNode = ln;
}

void Node::setRightNode(Node* rn) {
  this.rightNode = rn;
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
