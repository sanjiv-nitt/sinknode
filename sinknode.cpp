/*
For given graph G(V, E) for its adjacency matrix representation mat[V][V].
we have,
if mat[i][j] => there is an edge from node i to node j.
so, if a vertex k is sink vertex then mat[i][k] = 1 where i != k && 1=< i <= V
and mat[k][i] = 0 where i {1, V}

which means row[k] of mat will have all 0
and col[k] of mat will have all 1 except mat[k][k] which will be 0

It turns out that given a binary matrix find a row k which is all 0 and column k which is all 1 except [k][k]

This can be solved in O(V)
             0 0 1 1 1 0
	     1 0 0 1 0 1
	     0 0 1 1 0 0
	     0 0 0 0 0 0
	     1 1 1 1 0 0
	     0 1 1 1 0 1

*/

#include<iostream>
#include<vector>

using namespace std;

// Graph class represents a directed graph using adjacency matrix representation
class Graph
{
    int V;    // No. of vertices
    vector<vector<bool>> mat; // matrix to store adjacency matrix
public:
    Graph(int V);   // Constructor
    void add_edge(int v, int w);   // function to add an edge to graph
    int is_sink();
    void print();
};

Graph::Graph(int V)
{
    this->V = V;
    for (int i = 0; i < V; i++) mat.push_back(vector<bool> (V, 0));
}

void Graph::print()
{
    for (int i = 0; i < this->V; i++) {
        for (int j = 0; j < this->V; j++) {
            cout << this->mat[i][j]<<" ";
        }
        cout << endl;
    }
}
void Graph::add_edge(int v, int w)
{
    mat[v][w] = 1;
}

int Graph::is_sink()
{
    int count = 0;
	int i = 0, j = 0, sink_node = 0;
	while (j < this->V && i < this->V) {
        sink_node = i;
		if (this->mat[i][j] == 0) j++;
		else i = j + 1;
	}

	for (int j = 0; j < this->V; j++) {
		if (this->mat[sink_node][j]) return -1;
	}
	return sink_node;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.print();
	int node =  g.is_sink();
	if (node != -1) cout <<"Sync node is" << node<<endl;
	else cout<<"No sync node found"<<endl;

    return 0;
}
