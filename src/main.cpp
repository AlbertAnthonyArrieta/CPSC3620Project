#include <iostream>
#include <string>
using namespace std;

struct Node {
  int value;
  struct Node* left;
  struct Node* right;
  int height = 0;

  Node(int val) {
    value = val;
    left = NULL;
    right = NULL;
    height = 1;
  }

  Node* insert(Node* visitedNode, int val) {

    //insert
    if (visitedNode == NULL) {
      Node* newNode = new Node(val);
      return newNode;
    }

    if (visitedNode->value > val) {
      cout << "WENT LEFT" << endl;
      visitedNode->left = insert(visitedNode->left, val);
    }

    if (visitedNode->value < val) {
      cout << "WENT RIGHT" << endl;
      visitedNode->right = insert(visitedNode->right, val);
    }

    //change height
    visitedNode->height = 1 + max(visitedNode->left->getHeight(), visitedNode->right->getHeight());

    //balance
    int balanceFactor;
    if (visitedNode == NULL) {
      balanceFactor = 0;
    } else {
      cout << "Left height: " << visitedNode->left->getHeight() << endl;
      cout << "Right height: " << visitedNode->right->getHeight() << endl;
      balanceFactor = visitedNode->left->getHeight() - visitedNode->right->getHeight();
    }

    //rotations
    if (balanceFactor > 1 && visitedNode->left->value > val) {
      cout << "right rotation" << endl;
      return rightRotation(visitedNode);
    } else if (balanceFactor < -1 && visitedNode->right->value < val) {
      cout << "left rotation" << "Balance factor = " << balanceFactor << endl;
      return leftRotation(visitedNode);
    } else if (balanceFactor > 1 && visitedNode->left->value < val) {
      cout << "left right rotation" << endl;
      visitedNode->left = leftRotation(visitedNode->left);
      return rightRotation(visitedNode);
    } else if (balanceFactor < -1 && visitedNode->right->value > val) {
      cout << "right left rotation" << endl;
      visitedNode->right = rightRotation(visitedNode->right);
      return leftRotation(visitedNode);
    }

    return visitedNode;
  }

  // Node* remove(Node* visitedNode, int val) {
  //
  // }

  bool search(Node* visitedNode, int val) {
      if (visitedNode == NULL) {
        cout << "NODE NOT FOUND" << endl;
        return false;
      }

      if (visitedNode->value > val) {
        return search(visitedNode->left, val);
      } else if (visitedNode->value < val) {
        return search(visitedNode->right, val);
      } else if(visitedNode->value == val) {
        cout << "NODE FOUND" << endl;
        return true;
      }
    }

  int getHeight() {
    if (this == NULL) {
      return 0;
    } else {
      return height;
    }
  }

  int max(int a, int b) {
    if (a > b) {
      return a;
    } else if (a < b) {
      return b;
    }
  }

  Node* leftRotation(Node* n) {
    Node* tempNode1 = n->right;
    Node* tempNode2 = tempNode1->left;

    //rotation
    tempNode1->left = n;
    n->right = tempNode2;
    //change heights
    Node* nLeftNode = n->left;
    Node* nRightNode = n->right;
    Node* tn1LeftNode = tempNode1->left;
    Node* tn1RightNode = tempNode1->right;

    n->height = max(nLeftNode->getHeight(), nRightNode->getHeight()) + 1;
    tempNode1->height = max(tn1LeftNode->getHeight(), tn1RightNode->getHeight()) + 1;

    return tempNode1;
  }

  Node* rightRotation(Node* n) {
    Node* tempNode1 = n->left;
    Node* tempNode2 = tempNode1->right;

    //rotation
    tempNode1->right = n;
    n->left = tempNode2;

    //change heights
    Node* nLeftNode = n->left;
    Node* nRightNode = n->right;
    Node* tn1LeftNode = tempNode1->left;
    Node* tn1RightNode = tempNode1->right;

    n->height = max(nLeftNode->getHeight(), nRightNode->getHeight()) + 1;
    tempNode1->height = max(tn1LeftNode->getHeight(), tn1RightNode->getHeight()) + 1;

    return tempNode1;
  }

  void displayTree(Node* node) {
    //Display the structure of the tree.
  }

};

int main() {
  struct Node* root = new Node(6);

  root = root->insert(root, 10);
  root = root->insert(root, 20);
  root = root->insert(root, 30);
  root = root->insert(root, 5);
  root = root->insert(root, 2);
  root = root->insert(root, 3);
  root = root->insert(root, 4);
  root = root->insert(root, 1);



  cout << "=========================" << endl;
  cout << "Root: " << root->value << " Height: " << root->height << endl;
  cout << "Right: " << root->right->value << endl;
  cout << "Left: " << root->left->value << endl;
  cout << "LeftLeft: " << root->right->right->value << endl;

  root-> search(root, 50);
}
