#ifndef AVL_TREE_H
#define AVL_TREE_H

struct BinaryNode
{

  //constructor
  BinaryNode(const int key, const int bfactor = 0) : key(key), left(NULL), bfactor(bfactor), right(NULL) {}

  //destructor
  ~BinaryNode()
  {
    delete left;
    delete right;
    left = right = NULL;
  }

  //data value
  int key;

  //current balance
  int bfactor;

  //node arms
  BinaryNode *left, *right;
};

class AVLTree
{

public:
  //constructor
  AVLTree() : root(NULL) {}

  //destructor
  ~AVLTree()
  {
    delete root;
  }

  void printKey();
  void printHeight();

  //driver function for insertIntoAVL
  void insert(const int key)
  {
    BinaryNode *node = new BinaryNode(key);
    bool a = false;
    insertIntoAVL(root, node, a);
  };

  //driver function for delNode
  void delNode(const int key)
  {
    BinaryNode *node = new BinaryNode(key);
    deleteFromAVL(root, key);
  };

private:
  BinaryNode * minValueNode(BinaryNode* node);

  void insertIntoAVL(BinaryNode *&root, BinaryNode *newNode, bool &isTaller);
  void deleteFromAVL(BinaryNode *&root, int key);

  void rotateToLeft(BinaryNode *&node);
  void rotateToRight(BinaryNode *&node);
  void balanceFromLeft(BinaryNode *&node);
  void balanceFromRight(BinaryNode *&node);

  int getHeightAt(BinaryNode *node);

  void height(BinaryNode *node);

  void getInOrder(BinaryNode *root);

  BinaryNode *insert(const int key, BinaryNode *node);

  BinaryNode *root;
};

#endif

//val print
//height print
//delete
//insert
//balance