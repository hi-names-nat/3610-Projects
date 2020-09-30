#ifndef AVL_TREE_H
#define AVL_TREE_H

struct BinaryNode
{
  BinaryNode(const int key) : nodeHeight(nodeHeight), left(NULL), right(NULL) {}

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
  AVLTree() : root(NULL) {}
  ~AVLTree()
  {
    delete root;
  }

  void insert(const int key, BinaryNode *passedLoc);
  void remove(const int key, BinaryNode *passedLoc);

  int getHeightAt(BinaryNode *node) const
  {
    return node == nullptr ? -1 : node->nodeHeight;
  }

  BinaryNode *root;

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

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
      current = current->left;

    return current;
  }
};

#endif