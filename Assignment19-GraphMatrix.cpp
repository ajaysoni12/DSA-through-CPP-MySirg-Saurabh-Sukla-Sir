#include <iostream>
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
    ~GraphMatrix();
};

GraphMatrix::~GraphMatrix()
{
    for (int i = 0; i < v_count; i++)
        delete[] adj[i];

    delete[] adj;
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

int main()
{
    GraphMatrix G;
    G.createGraph(4, 4);
    G.printGraphMatrix();
    return 0;
}