#include "AVLtree.cpp"
#include "Node.cpp"
#include <chrono>
using namespace std;
int main() {
  AVLTree* FirstAVLTree = new AVLTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Inserting 10" << std::endl;
  FirstAVLTree->insert(10);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Inserting 20" << std::endl;
  FirstAVLTree->insert(20);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Inserting 30" << std::endl;
  FirstAVLTree->insert(30);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Inserting 5" << std::endl;
  FirstAVLTree->insert(5);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Inserting 2" << std::endl;
  FirstAVLTree->insert(2);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Inserting 3" << std::endl;
  FirstAVLTree->insert(3);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Inserting 4" << std::endl;
  FirstAVLTree->insert(4);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Inserting 1" << std::endl;
  FirstAVLTree->insert(1);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Searching for 5" << std::endl;
  if(FirstAVLTree->search(5)) {
    std::cout << "Found" << std::endl;
  } else {
    std::cout << "Not Found" << std::endl;
  }

  std::cout << "Removing 5" << std::endl;
  FirstAVLTree->remove(5);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;

  std::cout << "Searching for 5" << std::endl;
  if(FirstAVLTree->search(5)) {
    std::cout << "Found" << std::endl;
  } else {
    std::cout << "Not Found" << std::endl;
  }

  std::cout << "Removing 3" << std::endl;
  FirstAVLTree->remove(3);
  std::cout << "Resulting Tree" << std::endl;
  FirstAVLTree->displayTree();

  std::cout << "Height of the Tree: " << FirstAVLTree->getHeightTree() << std::endl;
  std::cout << "Number of Nodes: " << FirstAVLTree->getNumNodes() << std::endl;
}
