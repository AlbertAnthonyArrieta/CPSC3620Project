#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>

class Node {
 public:

   /**
   * Constructor for Node. Has 2 parameterS, for the value of the node
   * and the height of the Node.
   */
    Node(int v, int h);

    /**
    * Desctructor for Node.
    */
    virtual ~Node();

    /**
    * Sets Node value to the integer argument passed.
    */
    void setValue(int v);

    /**
    * Sets Node height to the integer argument passed.
    */
    void setHeight(int h);

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
    int getValue();

    /**
    * Returns Height.
    */
    int getHeight();

    /**
    * Returns the Left Node.
    */
    Node* getLeftNode();

    /**
    * Returns the Right Node.
    */
    Node* getRightNode();

 private:
   int value;
   int height;
   Node* leftNode;
   Node* rightNode;
};

#endif
