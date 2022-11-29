#include "Assignment4-SinglyLinkedList.cpp"

class Polynomial
{
    struct node
    {
        int coeff;
        int deg;
        node *next;
    };
    node *start;

public:
    Polynomial();
    node *getFirstNode() { return start; }
    void insert(int, int);
    Polynomial addNumbers(Polynomial *);
};
Polynomial Polynomial::addNumbers(Polynomial *obj)
{
    node *t1 = start;
    node *t2 = obj->getFirstNode();
    Polynomial ans;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->deg == t2->deg)
        {
            ans.insert(t1->coeff + t2->coeff, t1->deg);
            t1 = t1->next;
            t2 = t2->next;
        }
        else
        {
            if (t1->deg > t2->deg)
            {
                ans.insert(t1->coeff, t1->deg);
                ans.insert(t2->coeff, t2->deg);
            }
            else
            {
                ans.insert(t2->coeff, t2->deg);
                ans.insert(t1->coeff, t1->deg);
            }
        }
    }
    if (t1)
    {
        while (t1 != NULL)
        {
            ans.insert(t1->coeff, t1->deg);
        }
    }
    if (t2)
    {

        while (t2 != NULL)
        {
            ans.insert(t2->coeff, t2->deg);
        }
    }
    return ans;
}
Polynomial::Polynomial() { start = NULL; }
void Polynomial::insert(int c, int d)
{
    node *n = new node;
    n->coeff = c;
    n->deg = d;
    if (start == NULL)
    {
        n->next = NULL;
        start = NULL;
    }
    else
    {
        node *t = start, *p = NULL;
        if (t->deg < d)
        {
            n->next = t;
            start = n;
        }
        else
        {
            p = t;
            t = t->next;
            while (t != NULL)
            {
                if (t->deg < d)
                {
                    n->next = t;
                    p->next = n;
                    break;
                }
                p = t;
                t = t->next;
            }
            if (t == NULL)
            {
                n->next = NULL;
                p->next = n;
            }
        }
    }
}

class ExtSinglyLinkedList : public SinglyLinkedList
{
private:
public:
    int countListItem();
    void reverseSll();
    node *middleNode();
    bool isCycle();
    int cycleLength();
    void sortList();
    void mergeList(ExtSinglyLinkedList *obj2);
    ExtSinglyLinkedList addTwoNumbers(ExtSinglyLinkedList *);
};
ExtSinglyLinkedList ExtSinglyLinkedList::addTwoNumbers(ExtSinglyLinkedList *obj2)
{
    int carry = 0;
    node *t1 = start;
    node *t2 = obj2->getFirstNode();
    ExtSinglyLinkedList ans;
    while (t1 != NULL && t2 != NULL)
    {
        int sum = t1->item + t2->item + carry;
        if (sum < 9)
        {
            ans.insertAtEnd(sum);
            carry = 0;
        }
        else
        {
            ans.insertAtEnd(sum % 10);
            carry = sum / 10;
        }
        sum = 0;
        t1 = t1->next;
        t2 = t2->next;
    }
    if (t1)
    {
        while (t1 != NULL)
        {
            if (carry)
            {
                ans.insertAtEnd(t1->item + carry);
                carry = 0;
            }
            t1 = t1->next;
        }
    }
    if (t2)
    {

        while (t2 != NULL)
        {
            if (carry)
            {
                ans.insertAtEnd(t2->item + carry);
                carry = 0;
            }
            t2 = t2->next;
        }
    }
    return ans;
}
void ExtSinglyLinkedList::mergeList(ExtSinglyLinkedList *obj2)
{
    node *t1 = obj2->start, *t2 = start;
    while (t1 != NULL)
    {
        insertAtStart(t1->item);
        t1 = t1->next;
    }
    sortList();
}
void ExtSinglyLinkedList::sortList()
{
    node *t1 = start, *t2;
    if (start->next != NULL)
    {
        while (t1 != NULL)
        {
            t2 = t1->next;
            while (t2 != NULL)
            {
                if (t1->item > t2->item)
                {
                    int temp = t1->item;
                    t1->item = t2->item;
                    t2->item = temp;
                }
                t2 = t2->next;
            }
            t1 = t1->next;
        }
    }
}
int ExtSinglyLinkedList::cycleLength()
{
    if (isCycle())
    {
        if (start->next == start)
            return 1;
        else
        {
            int count = 0;
            node *t1 = start, *t2 = start;
            do
            {
                t1 = t1->next;
                if (t1 == NULL)
                    return false;
                t1 = t1->next;
                t2 = t2->next;
            } while (t1 != t2);
            t1 = t1->next;
            while (t1 != t2)
            {
                count++;
                t1 = t1->next;
            }
            return count + 1;
        }
    }
    return 0;
}
bool ExtSinglyLinkedList::isCycle()
{
    if (start)
    {
        node *t1, *t2;
        if (start->next == NULL)
            return false;
        else if (start->next == start)
            return true;
        else
        {
            t1 = start, t2 = start;
            do
            {
                t1 = t1->next;
                if (t1 == NULL)
                    return false;
                t1 = t1->next;
                t2 = t2->next;
            } while (t1 != t2);
            return true;
        }
    }
    return false;
}
SinglyLinkedList::node *ExtSinglyLinkedList::middleNode()
{
    if (start)
    {
        if (start->next)
        {
            node *t1 = start, *t2 = start;
            while (t1 != NULL)
            {
                t1 = t1->next;
                if (t1 == NULL)
                    return t2;
                t1 = t1->next;
                t2 = t2->next;
            }
            return t2;
        }
        else
        {
            return start;
        }
    }
    return NULL;
}
void ExtSinglyLinkedList::reverseSll()
{
    node *t1, *t2, *t3;
    if (start)
    {
        // for double node
        if (start->next == NULL)
            return;
        else if (start->next->next == NULL)
        {
            t1 = start->next;
            t1->next = start;
            start->next = NULL;
            start = t1;
        }
        else // for more than two node
        {
            t1 = start;
            t2 = t1->next;
            t3 = t2->next;
            t1->next = NULL;
            cout << t1->item << " " << t2->item << " " << t3->item;
            do
            {
                t2->next = t1;
                t1 = t2;
                t2 = t3;
                t3 = t3->next;
            } while (t3 != NULL);
            t2->next = t1;
            start = t2;
        }
    }
}
int ExtSinglyLinkedList::countListItem()
{
    int count = 0;
    node *temp = start;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int main()
{
    ExtSinglyLinkedList obj1, obj2;
    obj1.insertAtStart(1);
    obj1.printList();
    obj1.insertAtEnd(2);
    obj1.printList();
    obj1.insertAtEnd(3);
    obj1.insertAtEnd(4);
    obj1.printList();
    obj1.reverseSll();
    obj1.insertAtEnd(5);
    obj1.printList();
    obj1.sortList();
    obj1.printList();

    cout << "\nObj2\n";
    obj2.insertAtStart(1);
    obj2.printList();
    obj2.insertAtEnd(2);
    obj2.printList();
    obj2.insertAtEnd(3);
    obj2.insertAtEnd(4);
    obj2.printList();
    obj2.reverseSll();
    obj2.insertAtEnd(5);
    obj2.printList();
    obj2.sortList();
    obj2.printList();

    obj1.mergeList(&obj2);
    obj1.printList();
    // cout << endl
    //      << obj.isCycle();
    return 0;
}