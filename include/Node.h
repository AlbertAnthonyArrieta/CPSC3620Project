#ifndef NODE_H
#define NODE_H

class Node {
 public:

   /**
   * Default Constructor
   */
   Node();

   /**
   * Constructor for Node. Has 1 parameter for the value of the node.
   */
    Node(int v);

    /**
    * Desctructor for Node.
    */
    ~Node();

    /**
    * Sets Node value to the integer argument passed.
    */
    void changeValue(int v);

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

    void changeHeight(int newH);

    /**
    * Returns the Left Node.
    */
    Node* getLeftNode();

    void changeLeftNode(Node* newNode);

    /**
    * Returns the Right Node.
    */
    Node* getRightNode();

    void changeRightNode(Node* newNode);

    int getHeightTreeRec(Node* n);

    int maxNode(int a, int b);

 private:
   int value = 0;
   int height = 1;
   Node* leftNode = nullptr;
   Node* rightNode = nullptr;
};

#endif
