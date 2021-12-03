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

    return visitedNode;
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

};

int main() {
  struct Node* root = new Node(6);

  root->insert(root, 10);
  root->insert(root, 20);

  cout << "Root: " << root->value << " Height: " << root->height << endl;
  cout << "right: " << root->right->value << " Height: " << root->right->height << endl;
  cout << "rightright: " << root->right->right->value  << " Height: " << root->right->right->height << endl;
}
