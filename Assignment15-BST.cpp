#include <iostream>
using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
private:
    node *root;

protected:
    void preorderRec(node *);
    void inorderRec(node *);
    void postorderRec(node *);
    node *deleteNode(node *, int);

public:
    BST();
    bool isEmpty();
    void insert(int);
    void preorder();
    void inorder();
    void postorder();
    void del(int);
    node *getRoot() { return root; }
    node *search(int);
    ~BST();
};
BST::~BST()
{
}
node *BST::search(int item)
{
    node *temp = root;
    while (temp)
    {
        if (temp->item == item)
            return temp;
        if (temp->item < item)
            temp = temp->right;
        else if (temp->item > item)
            temp = temp->left;
    }
    return NULL;
}
void BST::postorderRec(node *root)
{
    // Left Right Root
    if (root)
    {
        postorderRec(root->left);
        postorderRec(root->right);
        cout << root->item << " ";
    }
}
node *BST::deleteNode(node *ptr, int data)
{
    if (ptr == NULL)
        return NULL;
    if (data < ptr->item)
        ptr->left = deleteNode(ptr->left, data);
    else if (data > ptr->item)
        ptr->right = deleteNode(ptr->right, data);
    else
    {
        // No child
        if (ptr->left == NULL && ptr->right == NULL)
        {
            delete ptr;
            return NULL;
        }
        // single child
        if (ptr->left == NULL || ptr->right == NULL)
        {
            node *child = ptr->left ? ptr->left : ptr->right;
            delete ptr;
            return child;
        }
        // two children
        node *pred, *parpred;
        parpred = ptr;
        pred = ptr->left;
        while (pred->right != NULL)
        {
            parpred = pred;
            pred = pred->right;
        }
        ptr->item = pred->item;
        parpred->right = deleteNode(pred, pred->item);
    }
    return ptr;
}
void BST::del(int data)
{
    root = deleteNode(root, data);
}
void BST::postorder()
{
    postorderRec(root);
}
void BST::inorderRec(node *root)
{
    // Left Root Right
    if (root)
    {
        inorderRec(root->left);
        cout << root->item << " ";
        inorderRec(root->right);
    }
}
void BST::inorder()
{
    inorderRec(root);
}
void BST::preorderRec(node *root)
{
    // Root Left Right
    if (root)
    {
        cout << root->item << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }
}
void BST::preorder()
{
    preorderRec(root);
}
void BST::insert(int data)
{
    node *n = new node;
    n->item = data;
    n->left = n->right = NULL;
    if (root == NULL)
        root = n;
    else
    {
        node *temp = root;
        while (n->item != temp->item)
        {
            if (n->item < temp->item)
            {
                if (temp->right != NULL)
                    temp = temp->left;
                else
                {
                    temp->left = n;
                    break;
                }
            }
            else
            {
                if (temp->right != NULL)
                    temp = temp->left;
                else
                {
                    temp->left = n;
                    break;
                }
            }
        }
        if (n->item == temp->item)
            delete n; // newly created object
    }
}
bool BST::isEmpty() { return root == NULL; }
BST::BST() { root = NULL; }