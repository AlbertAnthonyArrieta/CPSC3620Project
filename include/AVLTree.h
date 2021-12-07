#ifndef AVLTREE_H
#define AVLTREE_H
#include "Node.h"

class AVLTree {
 public:
   /**
   * Default Contructor for AVLTree. Creates an empty tree.
   */
   AVLTree();

   /**
   * Desctructor for Node.
   */
   ~AVLTree();

   void insert(int val);

   /**
   * Create and insert a new node holding the value of the passed argument.
   * This will be a recursive method and will need a node to visit.
   * Returns rootNode
   */
   Node* insertRec(Node* visitedNode, int val);

   void remove(int val);

   /**
   * Remove the node with the value of the passed argument.
   */
   Node* removeRec(Node* visitedNode, int val);

   /**
   * Searches for the node in the tree. Returns true if found. False otherwise.
   */
   bool search(int val);

   bool searchRec(Node* n, int val);

   /**
   * Left rotation algorithm.
   */
   Node* leftRotation(Node* n);

   /**
   * Right rotation algorithm
   */
   Node* rightRotation(Node* n);

   /**
   * Returns the height of the tree.
   */
   int getHeightTree();

   /**
   *  A small operation that compares 2 integers and returns the higher value.
   */
   int max(int a, int b);

   void displayTree();

   void displayTreeRec(Node* n, int space);

   Node* minNode(Node* node);

   int getNumNodes();

 private:
   int numNodes = 0;
   Node* rootNode = nullptr;
};

#endif
