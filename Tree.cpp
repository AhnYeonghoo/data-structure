
#include <iostream>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int value;
};

class BinarySearchTree
{
private:
    Node* root;
    Node* tail;
    
    void inOrder(Node* current)
    {
        if (current != nullptr)
        {
            inOrder(current->left);
            cout << current->value << endl;
            inOrder(current->right);
        }
    }
    
    Node* searchMaxNode(Node* node)
    {
        if (node == NULL) return NULL;
        while(node->right != NULL) node = node->right;
        return node;
    }

    Node* removeSequence(Node* node, int value);

public:
    BinarySearchTree() : root(nullptr) {};
    ~BinarySearchTree() {};

    void addNode(int value);
    bool searchValue(int value);
    
};

void BinarySearchTree::addNode(int value)
{
    Node* node = new Node();
    Node* tempRoot = nullptr;
    
    node->value = value;
    if (root == nullptr) 
    {
        root = node;
    }
    else
    {
        Node* ptr = root;
        while (ptr != nullptr)
        {
            tempRoot = ptr;
            if (node->value < ptr->value)
            {
                ptr = ptr->left;
            }
            else 
            {
                ptr = ptr->right;
            }
        }
        if (node->value < tempRoot->value)
        {
            tempRoot->left = node;
        }
        else
        {
            tempRoot->right = node;
        }
    }
}

bool BinarySearchTree::searchValue(int value)
{
    Node* ptr = root;
    Node* tempRoot = nullptr;
    
    while (ptr != nullptr)
    {
        if (ptr->value == value)
        {
            cout << value << "Found" << endl;
        }
        else if (ptr->value > value)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    cout << value << "Not Found" << endl;
    return false;
}