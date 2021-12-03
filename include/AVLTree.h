#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include <iostream>
using namespace std;

//NOTE: Feel free to add any functions I did not cover.

class AVLTree {
 public:
   /**
   * Default Contructor for AVLTree. Creates an empty tree.
   */
   AVLTree();

   /**
   * Constructor for AVLTree. Takes in an array of integers to be created into Nodes..
   */
   AVLTree(int values[]);

   /**
   * Desctructor for Node.
   */
   virtual ~AVLTree();

   /**
   * Create and insert a new node holding the value of the passed argument.
   * This will be a recursive method and will need a node to visit.
   * Returns rootNode
   */
   Node* insert(Node* visitedNode, int val);

   /**
   * Remove the node with the value of the passed argument.
   */
   void remove(int val);

   /**
   * Searches for the node in the tree. Returns true if found. False otherwise.
   */
   bool search(int val);

   /**
   * Checks and balances tree with the use of rotations.
   */
   Node* balance(Node* visitedNode, int val);

   /**
   * Left rotation algorithm.
   */
   Node* leftRotation(Node* n);

   /**
   * Right rotation algorithm
   */
   Node* rightRotation(Node* n);

   /**
   * Sets the passed node as the root (Could just pass the value instead maybe?)
   */
   void setRoot(Node* node);

   /**
   * Sets the current height of the tree.
   */
   void setHeight(int h);

   /**
   * Returns the root node.
   */
   Node* getRoot();

   /**
   * Returns the height of the tree.
   */
   int getHeight();

   /**
   *  A small operation that compares 2 integers and returns the higher value.
   */
   int getMax(int a, int b);

 private:
   int height;
   Node* rootNode;
};

#endif
