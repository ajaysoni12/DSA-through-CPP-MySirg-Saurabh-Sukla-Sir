#include "Assignment9-StackUsingArray.cpp"
#include "Assignment11-QueueUsingArray.cpp"
#include <bits/stdc++.h>
using namespace std;

class GraphMatrix
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    GraphMatrix();
    void createGraph(int v, int e);
    void printGraphMatrix();
    void printAdjacentNode(int);
    bool isIsolatedNode(int);
    void bfs();
    void dfs();
    ~GraphMatrix();
};

GraphMatrix::~GraphMatrix()
{
    for (int i = 0; i < v_count; i++)
        delete[] adj[i];

    delete[] adj;
}

void GraphMatrix::dfs()
{
    int sourceNode = 0;
    bool visit[v_count];
    for (int i = 0; i < v_count; i++)
        visit[i] = false;

    Stack stack(v_count);
    stack.push(sourceNode);

    visit[sourceNode] = true;
    int n;

    cout << "Graph Matrix vertex(dfs): ";

    while (!stack.isEmpty())
    {
        n = stack.peek();
        stack.pop();

        vector<int> d_array; // store neighbours of n
        for (int i = 0; i < v_count; i++)
            if (adj[n][i] == 1)
                d_array.push_back(i);

        // for all neighbours of n
        for (int j = 0; j < d_array.size(); j++)
        {
            if (visit[d_array.at(j)] == false)
            {
                cout << d_array.at(j) << " ";
                stack.push(d_array.at(j));
                visit[d_array.at(j)] = true;
            }
        }
    }
}

void GraphMatrix::bfs()
{
    int sourceNode = 0;
    bool visit[v_count];
    for (int i = 0; i < v_count; i++)
        visit[i] = false;

    Queue queue(v_count);
    queue.insertRear(sourceNode);

    visit[sourceNode] = true;
    int n;

    cout << "Graph Matrix vertex(bfs): ";

    while (!queue.isEmpty())
    {
        n = queue.getFront();
        queue.deleteFront();

        vector<int> d_array; // store neighbours of n
        for (int i = 0; i < v_count; i++)
            if (adj[n][i] == 1)
                d_array.push_back(i);

        // for all neighbours of n
        for (int j = 0; j < d_array.size(); j++)
        {
            if (visit[d_array.at(j)] == false)
            {
                cout << d_array.at(j) << " ";
                queue.insertRear(d_array.at(j));
                visit[d_array.at(j)] = true;
            }
        }
    }
}

bool GraphMatrix::isIsolatedNode(int v)
{
    if (v >= 0 && v < v_count)
    {
        for (int i = 0; i < v_count; i++)
            if (adj[v][i] == 1)
                return false;
        return true;
    }
    cout << "\nInvalid vertex!";
    return false;
}

void GraphMatrix::printAdjacentNode(int v)
{
    if (v >= 0 && v < v_count)
    {
        cout << "\nAdjancent node is: ";
        for (int i = 0; i < v_count; i++)
            if (adj[v][i] == 1)
                cout << "v" << i << " ";
    }
    else
        cout << "\nInvalid vertex!";
}

void GraphMatrix::printGraphMatrix()
{
    cout << "\nGraph Matrix is: " << endl;
    for (int i = 0; i < v_count; i++)
    {
        for (int j = 0; j < v_count; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

void GraphMatrix::createGraph(int v, int e)
{
    v_count = v;
    e_count = e;

    adj = new int *[v_count];

    for (int i = 0; i < v_count; i++)
        adj[i] = new int[v_count];

    for (int i = 0; i < v_count; i++)
        for (int j = 0; j < v_count; j++)
            adj[i][j] = 0;

    for (int i = 1; i <= e_count; i++)
    {
        int u, v;
        cout << "\nEnter two adjancent node who connect through this edge: ";
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

GraphMatrix::GraphMatrix()
{
    v_count = 0;
    e_count = 0;
    adj = NULL;
}

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
    void assignAdjNode(vector<int> &);
    ~Adj();
};
Adj::~Adj()
{
    while (start)
        removeFirstNode();
}
void Adj::assignAdjNode(vector<int> &d_array)
{
    node *t = start;
    while (t != NULL)
    {
        d_array.push_back(t->vertex);
        t = t->next;
    }
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
    void dfs();
    void bfs();
    ~GraphList();
};
GraphList::~GraphList()
{
    delete[] arr;
}

void GraphList::dfs()
{
    int sourceNode = 0;
    bool visit[v_count];
    for (int i = 0; i < v_count; i++)
        visit[i] = false;

    Stack stack(v_count);
    stack.push(sourceNode);

    visit[sourceNode] = true;
    int n;

    cout << "Graph Matrix vertex(dfs): ";

    while (!stack.isEmpty())
    {
        n = stack.peek();
        stack.pop();

        vector<int> d_array; // store neighbours of n
        arr[n].assignAdjNode(d_array);

        // for all neighbours of n
        for (int j = 0; j < d_array.size(); j++)
        {
            if (visit[d_array.at(j)] == false)
            {
                cout << d_array.at(j) << " ";
                stack.push(d_array.at(j));
                visit[d_array.at(j)] = true;
            }
        }
    }
}

void GraphList::bfs()
{
    int sourceNode = 0;
    bool visit[v_count];
    for (int i = 0; i < v_count; i++)
        visit[i] = false;

    Queue queue(v_count);
    queue.insertRear(sourceNode);

    visit[sourceNode] = true;
    int n;

    cout << "Graph Matrix vertex(bfs): ";

    while (!queue.isEmpty())
    {
        n = queue.getFront();
        queue.deleteFront();

        vector<int> d_array; // store neighbours of n
        arr[n].assignAdjNode(d_array);

        // for all neighbours of n
        for (int j = 0; j < d_array.size(); j++)
        {
            if (visit[d_array.at(j)] == false)
            {
                cout << d_array.at(j) << " ";
                queue.insertRear(d_array.at(j));
                visit[d_array.at(j)] = true;
            }
        }
    }
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
    G.bfs();
    return 0;
}