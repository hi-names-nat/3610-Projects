#include <iostream>
#include "avl_tree.h"

//this code is modified from the book.
/***********************************
 * @desc: driver function that allows the getInOrder function to be executed
 * 
 * @params: none
 * 
 **********************************/
void AVLTree::printKey()
{
  getInOrder(root);
}

//this code is modified from the book.
/***********************************
 * 
 * @desc: function to get inorder key of nodes.
 * 
 * @params: node to be used recursively. 
 **********************************/
void AVLTree::getInOrder(BinaryNode *node)
{
  if (node == NULL)
    return;

  //recur on left
  getInOrder(node->left);

  //print data
  std::cout << node->key << '\n';

  //recur on right
  getInOrder(node->right);
}

//this code is modified from the book.
/***********************************
 * 
 * @desc: driver function for height(root)
 * 
 * @params: none
 **********************************/
void AVLTree::printHeight()
{
  height(root);
}

//this code is modified from the book.
/***********************************
 * 
 * @desc: function to get height of nodes. 1 being the lowest node.
 * 
 * @params: recursive node to pass
 **********************************/
void AVLTree::height(BinaryNode *node)
{
  if (node == NULL)
    return;

  //recur on left
  height(node->left);

  //print data
  std::cout << getHeightAt(node) << '\n';

  //recur on right
  height(node->right);

  return;
}

//this code is modified from the book.
/***********************************
 * 
 * @desc: function to get height of a node at node. 1 being the lowest node.
 * 
 * @params: node - node of which to find the height
 **********************************/
int AVLTree::getHeightAt(BinaryNode *node)
{
  //print data
  if (node == NULL)
    return 0;
  else
    return 1 + std::max(getHeightAt(node->left), getHeightAt(node->right));
}

//this code is modified from the book.
/***********************************
 * 
 * @desc: function to rotate to right
 * 
 * @params: node: node to rotate 
 **********************************/
void AVLTree::rotateToLeft(BinaryNode *&node)
{
  BinaryNode *p; //pointer to the root of the right subtree of root
  if (node == NULL)
    std::cerr << "Error in the tree" << std::endl;
  else if (node->right == NULL)
    std::cerr << "Error in the tree:"
              << " No right subtree to rotate." << std::endl;
  else
  {
    p = node->right;
    node->right = p->left; //the left subtree of p becomes the right subtree of node
    p->left = node;
    node = p; //make p the new subtree root node
  }
} //rotateLeft

//this code is modified from the book.
/***********************************
 * 
 * @desc: function to rotate to left
 * 
 * @params: node: node to rotate 
 **********************************/
void AVLTree::rotateToRight(BinaryNode *&node)
{
  BinaryNode *p; //pointer to the root of the left subtree of root
  if (node == NULL)
    std::cerr << "Error in the tree" << std::endl;
  else if (node->left == NULL)
    std::cerr << "Error in the tree:"
              << " No left subtree to rotate." << std::endl;
  else
  {
    p = node->left;
    node->left = p->right; //the right subtree of p becomes the right subtree of node
    p->right = node;
    node = p; //make p the new subtree root node
  }
}

//this code is modified from the book.
/***********************************
 * 
 * @desc: balancing function to balance on left side
 * 
 * @params: root node to balance
 **********************************/
void AVLTree::balanceFromLeft(BinaryNode *&node)
{
  BinaryNode *p;
  BinaryNode *w;
  p = node->left; //p points to the left subtree of node
  switch (p->bfactor)
  {
  case -1:
    node->bfactor = 0;
    p->bfactor = 0;
    rotateToRight(node);
    break;

  case 0:
    std::cerr << "Error: Cannot balance from the left." << std::endl;
    break;
  case 1:
    w = p->right;
    switch (w->bfactor) //adjust the balance factors
    {
    case -1:
      node->bfactor = 1;
      p->bfactor = 0;
      break;
    case 0:
      node->bfactor = 0;
      p->bfactor = 0;
      break;
    case 1:
      node->bfactor = 0;
      p->bfactor = -1;
    } //end switch

    w->bfactor = 0;
    rotateToLeft(p);
    node->left = p;
    rotateToRight(node);
  } //end switch
} //end balanceFromLeft

//this code is modified from the book.
/***********************************
 * 
 * @desc: balancing function to balance on right side
 * 
 * @params: root node to balance
 **********************************/
void AVLTree::balanceFromRight(BinaryNode *&node)
{
  BinaryNode *p;
  BinaryNode *w;
  p = root->right; //p points to the left subtree of root
  switch (p->bfactor)
  {
  case -1:
    w = p->left;
    switch (w->bfactor) //adjust the balance factors
    {
    case -1:
      root->bfactor = 0;
      p->bfactor = 1;
      break;
    case 0:
      root->bfactor = 0;
      p->bfactor = 0;
      break;
    case 1:
      root->bfactor = -1;
      p->bfactor = 0;
    } //end switch
    w->bfactor = 0;
    rotateToRight(p);
    root->right = p;
    rotateToLeft(root);
    break;
  case 0:
    std::cerr << "Error: Cannot balance from the left." << std::endl;
    break;
  case 1:
    root->bfactor = 0;
    p->bfactor = 0;
    rotateToLeft(root);
  } //end switch
} //end balanceFromRight

//this code is modified from the book.
/***********************************
 * 
 * @desc: function for inserting into thetree
 * 
 * @params - root: root node - newNode: node to insert - isTaller: bool used in recursion
 **********************************/
void AVLTree::insertIntoAVL(BinaryNode *&root, BinaryNode *newNode, bool &isTaller)
{
  if (root == NULL)
  {
    root = newNode;
    isTaller = true;
  }
  else if (root->key == newNode->key)
    std::cerr << "No duplicates are allowed." << std::endl;
  else if (root->key > newNode->key)

  {
    insertIntoAVL(root->left, newNode, isTaller);
    if (isTaller)
      switch (root->bfactor)
      {
      case -1:
        balanceFromLeft(root);
        isTaller = false;
        break;
      case 0:
        root->bfactor = -1;
        isTaller = true;
        break;
      case 1:
        root->bfactor = 0;
        isTaller = false;
      }
  }
  else
  {
    insertIntoAVL(root->right, newNode, isTaller);
    if (isTaller)
      switch (root->bfactor)
      {
      case -1:
        root->bfactor = 0;
        isTaller = false;
        break;
      case 0:
        root->bfactor = 1;
        isTaller = true;
        break;
      case 1:
        balanceFromRight(root);
        isTaller = false;
      }
  }
}


// This code is modified from code found on this website: https://www.geeksforgeeks.org/avl-tree-set-2-deletion/.
/***********************************
 * 
 * @desc: function for deleting into thetree
 * 
 * @params - root: root node - key: key to remove
 **********************************/
void AVLTree::deleteFromAVL(BinaryNode *&root, int key)
{

  // STEP 1: PERFORM STANDARD BST DELETE
  if (root == NULL)
  {
    delete root;
    return;
  }

  // If the key to be deleted is smaller
  // than the root's key, then it lies
  // in left subtree
  if (key < root->key)
    deleteFromAVL(root->left, key);

  // If the key to be deleted is greater
  // than the root's key, then it lies
  // in right subtree
  else if (key > root->key)
    deleteFromAVL(root->right, key);

  // if key is same as root's key, then
  // This is the node to be deleted
  else
  {
    // node with only one child or no child
    if ((root->left == NULL) || (root->right == NULL))
    {
      BinaryNode *temp = root->left ? root->left : root->right;

      // No child case
      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else             // One child case
        *root = *temp; // Copy the contents of
                       // the non-empty child
      free(temp);
    }
    else
    {
      // node with two children: Get the inorder
      // successor (smallest in the right subtree)
      BinaryNode *temp = minValueNode(root -> right);
      

      // Copy the inorder successor's
      // data to this node
      root->key = temp->key;

      // Delete the inorder successor
      deleteFromAVL(root->right, temp->key);
    }
  }

  // If the tree had only one node
  // then return
  if (root == NULL)
    return;

  // // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
  // root->height = 1 + std::max(getHeightAt(root->left), getHeightAt(root->right));

  // STEP 3: GET THE BALANCE FACTOR OF
  // THIS NODE (to check whether this
  // node became unbalanced)
  int balance = root->bfactor;

  // If this node becomes unbalanced,
  // then there are 4 cases

  // Left Left Case
  if (balance > 1 &&
      root->left->bfactor >= 0)
    return rotateToRight(root);

  // Left Right Case
  if (balance > 1 &&
      root->left->bfactor < 0)
  {
    rotateToLeft(root->left);
    return rotateToRight(root);
  }

  // Right Right Case
  if (balance < -1 &&
      root->right->bfactor <= 0)
    return rotateToLeft(root);

  // Right Left Case
  if (balance < -1 &&
      root->right->bfactor > 0)
  {
    rotateToRight(root->right);
    return rotateToLeft(root);
  }

  return;
}

/* Given a non-empty binary search tree,  
return the node with minimum key value  
found in that tree. Note that the entire  
tree does not need to be searched. */
BinaryNode* AVLTree::minValueNode(BinaryNode* node)  
{  
    BinaryNode* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}