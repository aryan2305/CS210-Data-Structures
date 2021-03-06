#include <iostream>
#include <vector>
#include <queue>

using namespace std;



struct Graph{
	int v;
	bool **adj;
	public:
		Graph(int vcount);
		void addEdge(int u,int v);
		void deleteEdge(int u,int v);
		vector<int> BFS(int s);
		vector<int> DFS(int s);
		void DFSUtil(int s,vector<int> &dfs,vector<bool> &visited);
		int countComponents();
		bool isSameComponent(int v1, int v2);
		bool DFS_checkComponent(int s, vector<bool> &visited, int final);
};

Graph::Graph(int vcount){
	this->v = vcount;
	this->adj=new bool*[vcount];
	for(int i=0;i<vcount;i++)
		this->adj[i]=new bool[vcount];
	for(int i=0;i<vcount;i++)
		for(int j=0;j<vcount;j++)
			adj[i][j]=false;
}

void Graph::addEdge(int u,int w){
	this->adj[u][w]=true;
	this->adj[w][u]=true;
}

void Graph::deleteEdge(int u,int w){
	this->adj[u][w]=false;
	this->adj[w][u]=false;
}

vector<int> Graph::BFS(int s){
	vector<bool> visited(this->v);
	vector<int> bfs;
	queue<int> que;
	que.push(s);
	visited[s]=true;
	while(!que.empty()){
		bfs.push_back(que.front());
		for(int i=0;i<this->v;i++){
			if(adj[que.front()][i]==true && visited[i]==false){
				visited[i]=true;
				que.push(i);
			}
		}
		que.pop();
	}

	//In case the graph have multiple component then we will have to print other components as well
	for (int i = 0; i < this->v; ++i)
	{
		if(visited[i]==false)
		{
			que.push(i);
			visited[i]=true;
			while(!que.empty()){
				bfs.push_back(que.front());
				for(int j=0;j<this->v;j++){
					if(adj[que.front()][j]==true && visited[j]==false){
						visited[j]=true;
						que.push(j);
					}
				}
				que.pop();
			}
		}
	}
	return bfs;
}

void Graph::DFSUtil(int s, vector<int> &dfs, vector<bool> &visited){
	visited[s]=true;
	dfs.push_back(s);
	for(int i=0;i<this->v;i++){
		if(this->adj[s][i]==true && visited[i]==false)
			DFSUtil(i,dfs,visited);
	}
}

vector<int> Graph::DFS(int s){
	vector<bool> visited(this->v);
	vector<int> dfs;
	DFSUtil(s,dfs,visited);

	//In case the graph have multiple component then we will have to print other components as well
	for (int i = 0; i < this->v; ++i)
	{
		if(visited[i]==false)
			DFSUtil(i,dfs,visited);		
	}
	return dfs;
}


int Graph::countComponents(){
//write this function using either BFS or DFS
	vector<bool> visited(this->v);
	int count=0;
	vector<int> dfs;
	for(int i=0;i<this->v;i++){
		if(visited[i]==false)
		{
			count++;
			DFSUtil(i,dfs,visited);
		}
	}

    return (count);
}


bool Graph::DFS_checkComponent(int s, vector<bool> &visited, int final){
	visited[s]=true;
	for(int i=0;i<this->v;i++){
		if(this->adj[s][i]==true && visited[i]==false)
			{
				if(i==final)
					return true;
				if(DFS_checkComponent(i,visited,final))
					return true;
			}
	}
	return false;
}

bool Graph::isSameComponent(int v1, int v2){
//write this function using either BFS or DFS

	vector<bool> visited(this->v);
	return DFS_checkComponent(v1,visited,v2);
}


