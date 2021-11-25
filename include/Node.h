#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>

class Node {
 public:

   /**
   * Constructor for Node. Has 1 parameter for the value of the node.
   */
    Node(unsigned int v);

    /**
    * Desctructor for Node.
    */
    virtual ~Node();

    /**
    * Sets Node value to the integer argument passed.
    */
    void setValue(unsigned int v);

    /**
    * Sets Node height to the integer argument passed.
    */
    void setHeight(unsigned int h);

    /**
    * Sets leftNode to the Node argument passed.
    */
    void setLeftNode(Node* ln);

    /**
    * Sets rightNode to the node argument passed.
    */
    void setRightNode(Node* rn);

    /**
    * Returns value.
    */
    unsigned int getValue();

    /**
    * Returns Height.
    */
    unsigned int getHeight();

    /**
    * Returns the Left Node.
    */
    Node* getLeftNode();

    /**
    * Returns the Right Node.
    */
    Node* getRightNode();

    /**
    * Checks if the node has any left or right nodes.
    */
    bool hasChildren();

 private:
   unsigned int value;
   unsigned int height;
   Node* leftNode;
   Node* rightNode;
};

#endif
