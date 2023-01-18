#include <iostream>
using namespace std;

struct node
{
public:
    int item;
    int vertex;
    node *next;
};

class Adj
{
private:
    int vertex;
    node *start;

public:
    Adj();
    Adj(int);
    void setVertex(int);
    void addNode(int, int);
    void removeFirstNode();
    void printList();
    ~Adj();
};
Adj::~Adj()
{
    while (start)
        removeFirstNode();
}
void Adj::printList()
{
    node *t = start;
    while (t != NULL)
    {
        cout << " v(" << t->vertex << ", " << t->item << ")  ";
        t = t->next;
    }
    cout << endl;
}
void Adj::removeFirstNode()
{
    if (start)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
}
void Adj::addNode(int v, int item)
{
    node *temp = new node;
    temp->vertex = v;
    temp->item = item;
    temp->next = start;
    start = temp;
}
void Adj::setVertex(int v)
{
    vertex = v;
}

Adj ::Adj(int v)
{
    vertex = v;
    start = NULL;
}
Adj ::Adj()
{
    start = NULL;
}
class GraphList
{
private:
    int v_count;
    Adj *arr;

public:
    GraphList();
    void createGraph(int);
    void addEdge(int, int, int);
    void printGraph();
    ~GraphList();
};
GraphList::~GraphList()
{
    delete[] arr;
}
void GraphList::printGraph()
{
    cout << "\nGraph no.\tand there edge: \n";
    for (int i = 0; i < v_count; i++)
    {
        cout << "v(" << i << "): ";
        arr[i].printList();
    }
}
void GraphList::addEdge(int v1, int v2, int item)
{
    arr[v1].addNode(v2, item);
}
void GraphList::createGraph(int v)
{
    int n;
    v_count = v;
    arr = new Adj[v];
    int data, vno;
    for (int i = 0; i < v; i++)
    {
        arr[i].setVertex(i);
        cout << "\nHow many adjacent node of v" << i << " : ";
        cin >> n;
        while (n--)
        {
            cout << "\nEnter vertex number: ";
            cin >> vno;
            cout << "\nEnter data to store: ";
            cin >> data;
            addEdge(i, vno, data);
        }
    }
}
GraphList ::GraphList()
{
    v_count = 0;
    arr = NULL;
}
int main()
{
    GraphList G;
    G.createGraph(6);
    G.printGraph();
    return 0;
}