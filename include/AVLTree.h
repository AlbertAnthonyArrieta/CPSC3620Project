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
   */
   void insert(int val);

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
   void balance();

   /**
   * Left rotation algorithm.
   */
   void leftRotation();

   /**
   * Right rotation algorithm
   */
   void rightRotation();

   /**
   * Left-Right Rotation algorithm
   */
   void leftRightRotation();

   /**
   * RightLeftRotation algorithm
   */
   void rightLeftRotation();

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

 private:
   int height;
   Node* rootNode;
};

#endif
