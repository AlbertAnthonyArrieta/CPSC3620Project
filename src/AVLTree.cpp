#include "AVLTree.h"
#include "Node.h"
#include <iostream>

AVLTree::AVLTree() {
  numNodes = 0;
  rootNode = nullptr;
}

void AVLTree::insert(int val) {
  if (search(val)) {
    return;
  }
  numNodes++;
  rootNode = insertRec(rootNode, val);
}

Node* AVLTree::insertRec(Node* visitedNode, int val) {
  //insert
  if (visitedNode == nullptr) {
    Node* newNode = new Node(val);
    return newNode;
  }

  if (visitedNode->getValue() > val) {
    visitedNode->changeLeftNode(insertRec(visitedNode->getLeftNode(), val));
  }

  if (visitedNode->getValue() < val) {
    visitedNode->changeRightNode(insertRec(visitedNode->getRightNode(), val));
  }

  //change height
  visitedNode->changeHeight(1 + max(visitedNode->getLeftNode()->getHeight(), visitedNode->getRightNode()->getHeight()));

  //balance
  int balanceFactor;
  if (visitedNode == nullptr) {
    balanceFactor = 0;
  } else {
    balanceFactor = visitedNode->getLeftNode()->getHeight() - visitedNode->getRightNode()->getHeight();
  }

  //rotations
  if (balanceFactor > 1 && visitedNode->getLeftNode()->getValue() > val) {
    return rightRotation(visitedNode);
  } else if (balanceFactor < -1 && visitedNode->getRightNode()->getValue() < val) {
    return leftRotation(visitedNode);
  } else if (balanceFactor > 1 && visitedNode->getLeftNode()->getValue() < val) {
    visitedNode->changeLeftNode(leftRotation(visitedNode->getLeftNode()));
    return rightRotation(visitedNode);
  } else if (balanceFactor < -1 && visitedNode->getRightNode()->getValue() > val) {
    visitedNode->changeRightNode(rightRotation(visitedNode->getRightNode()));
    return leftRotation(visitedNode);
  }
  return visitedNode;
}

Node* AVLTree::leftRotation(Node* n) {
  Node* tempNode1 = n->getRightNode();
  Node* tempNode2 = tempNode1->getLeftNode();

  //rotation
  tempNode1->changeLeftNode(n);
  n->changeRightNode(tempNode2);

  //change heights
  n->changeHeight(max(n->getLeftNode()->getHeight(), n->getRightNode()->getHeight()) + 1);
  tempNode1->changeHeight(max(tempNode1->getLeftNode()->getHeight(), tempNode1->getRightNode()->getHeight()) + 1);
  return tempNode1;
}

Node* AVLTree::rightRotation(Node* n) {
  Node* tempNode1 = n->getLeftNode();
  Node* tempNode2 = tempNode1->getRightNode();

  //rotation
  tempNode1->changeRightNode(n);
  n->changeLeftNode(tempNode2);

  //change heights
  n->changeHeight(max(n->getLeftNode()->getHeight(), n->getRightNode()->getHeight()) + 1);
  tempNode1->changeHeight(max(tempNode1->getLeftNode()->getHeight(), tempNode1->getRightNode()->getHeight()) + 1);
  return tempNode1;
}

int AVLTree::max(int a, int b) {
  if (a > b) {
    return a;
  } else if (a < b) {
    return b;
  }
}

void AVLTree::remove(int val) {
  if (!search(val)) {
    return;
  }
  numNodes--;
  rootNode = removeRec(rootNode,val);
}

Node* AVLTree::removeRec(Node* visitedNode, int val) {
  if (visitedNode == nullptr) {
    return visitedNode;
  }

  if (visitedNode->getValue() > val) {
    visitedNode->changeLeftNode(removeRec(visitedNode->getLeftNode(), val));
  } else if (visitedNode->getValue() < val) {
    visitedNode->changeRightNode(removeRec(visitedNode->getRightNode(), val));
  } else {
    if (visitedNode->getLeftNode() == nullptr || visitedNode->getRightNode() == nullptr) {
      Node* tempNode = visitedNode->getLeftNode() ? visitedNode->getLeftNode() : visitedNode->getRightNode();

      if (tempNode == nullptr) {
          tempNode = visitedNode;
          visitedNode = nullptr;
      } else {
        *visitedNode = *tempNode;
        free(tempNode);
      }

    } else {
      Node* tempNode = minNode(visitedNode->getRightNode());

      //delete
      visitedNode->changeValue(tempNode->getValue());
      visitedNode->changeRightNode(removeRec(visitedNode->getRightNode(), tempNode->getValue()));
    }
  }

  if (visitedNode == nullptr) {
    return visitedNode;
  }

  //change heights
  visitedNode->changeHeight(1 + max(visitedNode->getLeftNode()->getHeight(), visitedNode->getRightNode()->getHeight()));

  //balance
  int balanceFactor;
  if (visitedNode == nullptr) {
    balanceFactor = 0;
  } else {
    balanceFactor = visitedNode->getLeftNode()->getHeight() - visitedNode->getRightNode()->getHeight();
  }

  //rotations
  if (balanceFactor > 1 && visitedNode->getLeftNode()->getValue() >= 0) {
    return rightRotation(visitedNode);
  } else if (balanceFactor < -1 && visitedNode->getRightNode()->getValue() <= 0) {
    return leftRotation(visitedNode);
  } else if (balanceFactor > 1 && visitedNode->getLeftNode()->getValue() < 0) {
    visitedNode->changeLeftNode(leftRotation(visitedNode->getLeftNode()));
    return rightRotation(visitedNode);
  } else if (balanceFactor < -1 && visitedNode->getRightNode()->getValue() > 0) {
    visitedNode->changeRightNode(rightRotation(visitedNode->getRightNode()));
    return leftRotation(visitedNode);
  }
  return visitedNode;
}

Node* AVLTree::minNode(Node* node) {
  Node* n = node;

  while (n->getLeftNode() != nullptr) {
    n = n->getLeftNode();
  }

  return n;
}

void AVLTree::displayTree() {
  std::cout << "|--";
  std::cout << rootNode->getValue() << std::endl;
  if (rootNode->getLeftNode() != nullptr) {
    displayTreeRec(rootNode->getLeftNode(), 1);
  }
  if (rootNode->getRightNode() != nullptr) {
    displayTreeRec(rootNode->getRightNode(), 1);
  }
}

void AVLTree::displayTreeRec(Node* n, int space) {
  for (int i = 1; i < space * 2; i++) {
    std::cout << "|  ";
  }
  std::cout << "|--";
  std::cout << n->getValue() << std::endl;
  space++;
  if (n->getLeftNode() != nullptr) {
    displayTreeRec(n->getLeftNode(),space);
  }
  if (n->getRightNode() != nullptr) {
    displayTreeRec(n->getRightNode(),space);
  }
}

bool AVLTree::search(int val) {
  if (rootNode == nullptr) {
    return false;
  }
  if (rootNode->getValue() == val) {
    return true;
  }
  if(searchRec(rootNode->getLeftNode(), val)) {
    return true;
  }
  return searchRec(rootNode->getRightNode(), val);
}

bool AVLTree::searchRec(Node* n, int val) {
  if (n == nullptr) {
    return false;
  }
  if (n->getValue() == val) {
    return true;
  }
  if(searchRec(n->getLeftNode(), val)) {
    return true;
  }
  return searchRec(n->getRightNode(), val);
}

int AVLTree::getHeightTree() {
  if (rootNode == nullptr) {
    return 0;
  } else {
    return max(rootNode->getHeightTreeRec(rootNode->getLeftNode()),rootNode->getHeightTreeRec(rootNode->getRightNode())) + 1;
  }
}

int AVLTree::getNumNodes() {
  return numNodes;
}
