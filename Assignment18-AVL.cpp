#include <iostream>
using namespace std;

struct node
{
    node *left;
    int item;
    node *right;
    int height;
};

class AVL
{
private:
    node *root;

protected:
    node *inserElementRec(node *, int);
    node *deleteElementRec(node *, int);
    void inorderTraversalRec(node *);
    void preorderTraversalRec(node *);
    void postorderTraversalRec(node *);
    node *minValueNode(node *);

public:
    AVL();
    int getBalanceFactor(node *);
    int getHeight(node *);
    node *rightRotate(node *);
    node *leftRotate(node *);
    void inserElement(int);
    void deleteElement(int);
    void updateAnscestorsHeights(node *, int);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
};

node *AVL::minValueNode(node *ptr)
{
    node *current = ptr;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

node *AVL::deleteElementRec(node *ptr, int data)
{
    if (ptr == NULL)
        return NULL;
    else if (data < ptr->item)
        ptr->left = deleteElementRec(ptr->left, data);
    else if (data > ptr->item)
        ptr->right = deleteElementRec(ptr->right, data);
    else
    {
        /* no child or one child */
        if (ptr->left == NULL || ptr->right == NULL)
        {
            node *child = ptr->left ? ptr->left : ptr->right;

            // no child
            if (child == NULL)
            {
                child = ptr;
                ptr = NULL;
            }
            else
                *ptr = *child; // copy value
            delete child;
        }
        else
        {
            // two childerns
            // node with two children: Get the inorder successor (smallest in the right subtree)
            node *child = minValueNode(ptr->right);
            ptr->item = child->item;
            ptr->right = deleteElementRec(ptr->right, child->item);
        }
    }

    // if tree has only one node then return
    if (ptr == NULL)
        return ptr;

    ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;

    int balance = getBalanceFactor(ptr);

    /* Left Left Case */
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    /* Right Right Case */
    if (balance < -1 && getBalanceFactor(ptr->right) <= 0)
        return leftRotate(ptr);

    /* Left Right Case */
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(root);
    }

    /* Right Left Case */
    if (balance < -1 && getBalanceFactor(ptr->right) > 0)
    {
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }
    return ptr;
}

void AVL::deleteElement(int data)
{
    root = deleteElementRec(root, data);
}

void AVL::postorderTraversalRec(node *ptr)
{
    if (ptr)
    {
        postorderTraversalRec(ptr->left);
        postorderTraversalRec(ptr->right);
        cout << " " << ptr->item << "(" << getBalanceFactor(ptr) << ")";
    }
}

void AVL::postorderTraversal()
{
    postorderTraversalRec(root);
}

void AVL::preorderTraversalRec(node *ptr)
{
    if (ptr)
    {
        cout << " " << ptr->item << "(" << getBalanceFactor(ptr) << ")";
        preorderTraversalRec(ptr->left);
        preorderTraversalRec(ptr->right);
    }
}

void AVL::preorderTraversal()
{
    preorderTraversalRec(root);
}

void AVL::inorderTraversalRec(node *ptr)
{
    if (ptr)
    {
        inorderTraversalRec(ptr->left);
        cout << " " << ptr->item << "(" << getBalanceFactor(ptr) << ")";
        inorderTraversalRec(ptr->right);
    }
}

void AVL::inorderTraversal()
{
    inorderTraversalRec(root);
}

void AVL::updateAnscestorsHeights(node *ptr, int data)
{
    if (ptr->item == data)
        ptr->height = 1;
    else
    {
        if (data < ptr->height)
            updateAnscestorsHeights(ptr->left, data);
        else if (data > ptr->height)
            updateAnscestorsHeights(ptr->right, data);
        ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
    }
}

node *AVL::inserElementRec(node *ptr, int data)
{
    /* 1. */
    if (ptr == NULL)
    {
        node *n = new node;
        n->left = NULL;
        n->item = data;
        n->right = NULL;
        n->height = 1;
        return n;
    }
    if (data < ptr->item)
        ptr->left = inserElementRec(ptr->left, data);
    else if (data > ptr->item)
        ptr->right = inserElementRec(ptr->right, data);
    else
        return ptr; // duplicate element not allowed

    /* 2. After inserElementing chnage height of ancestors nodes */
    ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;

    /* 3.Get the balance factor of this
        ancestor node to check whether
        this node became unbalanced */
    int balance = getBalanceFactor(ptr);

    /* 4. If this node becomes unbalanced, then there are 4 cases */

    /* Left Left Case */
    if (balance > 1 && data < ptr->left->item) // balance > 1 means left side inserElemention
        return rightRotate(ptr);

    /* Right Right Case */
    if (balance < -1 && data > ptr->right->item) // balance < -1 means right side inserElemention
        return leftRotate(ptr);

    /* Left Right Case */
    if (balance > 1 && data > ptr->left->item) // balance > 1 means left side inserElemention but data is greater then right side
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }

    /* Right Left Case */
    if (balance < -1 && data < ptr->right->item) // balance > 1 means left side inserElemention but data is greater then right side
    {
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }

    /* return the unchange node pointer */
    return ptr;
}

void AVL::inserElement(int data)
{
    root = inserElementRec(root, data);
}

node *AVL::rightRotate(node *a)
{
    // clockwise rotatation
    node *b = a->left;
    node *RT = b->right;

    b->right = a;
    a->left = RT;

    // edit Height
    a->height = max(getHeight(a->left), getHeight(a->right)) + 1;
    b->height = max(getHeight(b->left), getHeight(b->right)) + 1;

    return b;
}

node *AVL::leftRotate(node *a)
{
    // anticlockwise rotation
    node *b = a->right;
    node *LT = b->left;

    b->left = a;
    a->right = LT;

    // edit Height
    a->height = max(getHeight(a->left), getHeight(a->right)) + 1;
    b->height = max(getHeight(b->left), getHeight(b->right)) + 1;

    return b;
}

int AVL::getHeight(node *ptr)
{
    if (ptr == NULL)
        return 0;
    return ptr->height;
}

int AVL::getBalanceFactor(node *ptr)
{
    if (ptr == NULL)
        return 0;
    return getHeight(ptr->left) - getHeight(ptr->right);
}

AVL::AVL() { root = NULL; }

int main()
{
    AVL tree;
    tree.inserElement(50);
    tree.inserElement(30);
    tree.inserElement(70);
    tree.inserElement(90);
    tree.inserElement(110);
    cout << endl;
    tree.deleteElement(100);
    tree.inorderTraversal();
    cout << endl;
    return 0;
}