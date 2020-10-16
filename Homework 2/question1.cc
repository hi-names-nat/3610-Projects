#include <list>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    public:
        Node();
        Node(int val = 0, Node* left = NULL, Node* right = NULL) {
            val = value;
            leftNode = left;
            rightNode = right;
        }
        ~Node();

    int value;
    Node* leftNode;
    Node* rightNode;


};

int leafCount(Node* root);
int nr_leafCount(Node* root);

int main(int argc, char const *argv[])
{
    Node* root = new Node(0, new Node(1, NULL, NULL), new Node(2, NULL, NULL));
    Node* temp = root -> leftNode;
    temp -> leftNode = new Node(3, NULL, NULL);
    temp = root -> rightNode;

    temp -> rightNode = new Node(4, NULL, NULL);
    temp -> leftNode = new Node(5, NULL, NULL);

    cout << leafCount(root) << endl;

    cout << nr_leafCount(root) << endl;

    cout << "aba" << endl;
}





int leafCount(Node* root) {
    int total = 0;
    if (root -> rightNode == NULL && root -> leftNode == NULL) {
        return 1;
    }
    
    if (root -> leftNode != NULL) 
    {
        total += leafCount(root -> leftNode);
    }
    if (root -> rightNode != NULL) 
    {
        total += leafCount(root -> rightNode);
    }
    return total;
    
}

/* Function to get the count of leaf Nodes in
   a binary tree*/
// modified from this example code: https://www.geeksforgeeks.org/iterative-program-count-leaf-nodes-binary-tree/
int nr_leafCount(Node* root)
{
    // If tree is empty
    if (!root)
        return 0;
 
    // Initialize empty queue.
    std::queue<Node *> q;
 
    // Do level order traversal starting from root
    int count = 0; // Initialize count of leaves
    q.push(root);
    while (!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();
 
        if (temp->leftNode != NULL)
            q.push(temp->leftNode);
        if (temp->rightNode != NULL)
            q.push(temp->rightNode);
        if (temp->leftNode == NULL && temp->rightNode == NULL)
            count++;
    }
    return count;
}