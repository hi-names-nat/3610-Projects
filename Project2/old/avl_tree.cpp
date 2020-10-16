#include <iostream>
#include "avl_tree.h"

static int ALLOWED_IMBALANCE = 1;
void AVLTree::insert(const int key, BinaryNode *&passedLoc)
{


  if (passedLoc == NULL)
  {
    passedLoc = new BinaryNode(key);
    passedLoc->nodeKey = key;
  }
  else if (key < passedLoc->nodeKey)
    insert(key, passedLoc->left);
  else if (key > passedLoc->nodeKey)
    insert(key, passedLoc->right);

  Balance(root);
}

void AVLTree::remove(const int key, BinaryNode *passedLoc)
{
  if (passedLoc == NULL)
  {
    return;
  }
  if (key < passedLoc->nodeKey)
  {
    remove(key, passedLoc->left);
  }
  else if (passedLoc->nodeKey < key)
  {
    remove(key, passedLoc->right);
  }
  else if (passedLoc->left != nullptr && passedLoc->right != nullptr)
  {
    passedLoc->nodeKey = minNode(passedLoc->right)->nodeKey;
    remove(passedLoc->nodeKey, passedLoc->right);
  }
  else
  {
    BinaryNode *old = passedLoc;
    passedLoc = (passedLoc->left != nullptr) ? passedLoc->left : passedLoc->right;
    delete old;
  }
  Balance(passedLoc);
}

void AVLTree::Balance(BinaryNode *&balancepoint)
{
  if (balancepoint == NULL)
  {
    return;
  }

  if (getHeightAt(balancepoint->left) - getHeightAt(balancepoint->right) > ALLOWED_IMBALANCE)
  {
    if (getHeightAt(balancepoint->left->left) >= getHeightAt(balancepoint->left->right))
      rotateWithLeftChild(balancepoint);
    else
      doubleWithLeftChild(balancepoint);
  }
  else
  {
    if (getHeightAt(balancepoint->right) - getHeightAt(balancepoint->left) > ALLOWED_IMBALANCE)
      rotateWithRightChild(balancepoint);
    else
      doubleWithRightChild(balancepoint);
  }
  balancepoint->nodeHeight = std::max(getHeightAt(balancepoint->left), getHeightAt(balancepoint->right)) + 1;
}

void AVLTree::rotateWithLeftChild(BinaryNode *&target)
{
  BinaryNode *temp = target->left;

  //do the rotation
  target->left = temp->right;
  temp->right = target;

  //update heights
  target->nodeHeight = std::max(getHeightAt(target->left), getHeightAt(target->right)) + 1;
  temp->nodeHeight = std::max(getHeightAt(temp->left), target->nodeHeight) + 1;

  //move to root
  target = temp;
}

void AVLTree::rotateWithRightChild(BinaryNode *&target)
{
  BinaryNode *temp = target->right;

  //do the rotation
  target->right = temp->left;
  temp->left = target;

  //update height
  target->nodeHeight = std::max(getHeightAt(target->right), getHeightAt(target->left)) + 1;
  temp->nodeHeight = std::max(getHeightAt(temp->right), target->nodeHeight) + 1;

  //move to root
  target = temp;
}

void AVLTree::getInOrder(BinaryNode *node)
{
  if (node == NULL)
    return;

  //recur on left
  getInOrder(node->left);

  //print data
  std::cout << node->nodeKey << '\n';

  //recur on right
  getInOrder(node->right);
}

void AVLTree::getHeightInOrder(BinaryNode *node)
{
  if (node == NULL)
    return;

  //recur on left
  getInOrder(node->left);

  //print data
  std::cout << node->nodeHeight << '\n';

  //recur on right
  getInOrder(node->right);
}