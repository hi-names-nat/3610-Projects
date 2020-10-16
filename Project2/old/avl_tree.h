#ifndef AVL_TREE_H
#define AVL_TREE_H

struct BinaryNode
{
  BinaryNode(const int key){
    nodeKey = key;
    nodeHeight = -1;
    left = NULL;
    right = NULL;
  }

  ~BinaryNode()
  {
    delete left;
    delete right;
    left = right = NULL;
  }

  int nodeKey;
  int nodeHeight;
  BinaryNode *left = NULL, *right = NULL;
};

class AVLTree
{

public:
  BinaryNode *root;

  AVLTree() : root(NULL) {}
  ~AVLTree()
  {
    delete root;
  }

  //insertion, removal
  void insert(const int key, BinaryNode *&passedLoc);
  void remove(const int key, BinaryNode *passedLoc);

  void insert(const int key) {
    insert(key, root);
  };

  void remove(const int key) {
    remove(key, root);
  };

  //getters
  void getInOrder(BinaryNode *node);
  void getHeightInOrder(BinaryNode *node);
  int getHeightAt(BinaryNode *node) const
  {
    return node == nullptr ? -1 : node->nodeHeight;
  }

  

private:
  void Balance(BinaryNode *&balancepoint);

  void rotateWithLeftChild(BinaryNode *&target);
  void rotateWithRightChild(BinaryNode *&target);

  void doubleWithLeftChild(BinaryNode *&target)
  {
    rotateWithRightChild(target->left);
    rotateWithLeftChild(target);
  }

  void doubleWithRightChild(BinaryNode *&target)
  {
    rotateWithLeftChild(target->right);
    rotateWithRightChild(target);
  }

  BinaryNode *minNode(BinaryNode *node)
  {
    BinaryNode *current = node;

    //loop down to find the leftmost leaf
    while (current->left != NULL)
      current = current->left;

    return current;
  }

  BinaryNode *maxNode(BinaryNode *node)
  {
    BinaryNode *current = node;

    //loop down to find the rightmost leaf 
    while (current -> right != NULL)
      current = current -> right;

    return current;
  }
};

#endif