#include <bits/stdc++.h>
#include <iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void DFSUtil(int v, bool visited[], int disc_time[], int lowest[], int parent[], bool cutvertices[]); 
public: 
    Graph(int V);   
    void addEdge(int v, int w);   // function to add an edge to graph 
    void DFS();    
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
	 //the graph is undirected
    adj[v].push_back(w); 
    adj[w].push_back(v);  
} 
  
void Graph::DFSUtil(int u, bool visited[], int disc_time[],int lowest[], int parent[], bool cutvertices[]) 
{ 
    
    static int time = 0; 
  
    // Count of children in DFS Tree 
    int children = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and lowest value 
    disc_time[u] = lowest[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        /*If v is not visited yet, then make it a child of u 
        in DFS tree and recur for it*/ 
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            DFSUtil(v, visited, disc_time, lowest, parent, cutvertices); 
  
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
            lowest[u]  = min(lowest[u], lowest[v]); 
  
            
  
            // If u is the start of DFS tree and has two or more chilren then it is a cut vertiex 
            if (parent[u] == NIL && children > 1) 
               cutvertices[u] = true; 
  
            // If u is not the start vertex of the given dfs tree and lowest value of one of its child is more 
            // than discovery value of u. 
            if (parent[u] != NIL && lowest[v] >= disc_time[u]) 
               cutvertices[u] = true;

           	// If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a cut edge
            if (lowest[v] > disc_time[u]) 
            cout <<u <<" " << v << endl; 
        } 
  
        // Update lowest value of u for parent function calls. 
        else if (v != parent[u]) 
            lowest[u]  = min(lowest[u], disc_time[v]); 
    } 
} 
  
// Funciton for DFS Traversal 
void Graph::DFS() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc_time = new int[V]; 
    int *lowest = new int[V]; 
    int *parent = new int[V]; 
    bool *cutvertices = new bool[V]; // To store cutvertices 
  
    // Initialize parent and visited, and cutvertices arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
        cutvertices[i] = false; 
    } 
  	
  	cout<<"Cut Edges:"<<endl;
    
    // Call the recursive helper function to find cutvertices and cut edges 
    for (int i = 0; i < V; i++) 
       if (visited[i] == false) 
          DFSUtil(i, visited, disc_time, lowest, parent, cutvertices); 
  	
  	cout<<"Cut vertices:"<<endl;

    // Now cutvertices[] contains cutvertices, print them 
    for (int i = 0; i < V; i++) 
        if (cutvertices[i] == true) 
            cout << i << " "; 
    cout<<endl;
} 


int main() 
{ 
    int n;
    cin>>n;
    Graph g(n+1);
    int e;
    cin>>e;
    int x,y;
    for (int i = 1; i <= e; ++i)
    {
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.DFS(); 
     
    return 0; 
} 