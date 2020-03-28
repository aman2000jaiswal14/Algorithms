#include<bits/stdc++.h>
#include<list>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v,int w);
	void BFS();
};
Graph::Graph(int V)
{
	this->V=V;
	adj= new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	
 } 
 void Graph:: BFS()
 {
 bool *visited=new bool[V];
 for(int i=0;i<V;i++)
 visited[i]=false;
 list<int> queue;
 for(int i=0;i<V;i++)
 {	if(visited[i]==true)
 	continue;
 	int element;
 	queue.push_back(i);
 	visited[i]=true;
 	element=i;
 	int kk=0;
 	while(!queue.empty())
 	{
 	if(kk==0){
 	element=i;
 	cout<<element<<" ";
 	queue.pop_front();
 	}
 	else
 	{
 		element=queue.front();
 		queue.pop_front();
		cout<<element<<" ";
		 	 }
	 kk++;
 	list<int>::iterator j;
 	for(j=adj[element].begin();j!=adj[element].end();j++)
 	{
 		if(visited[*j]!=true)
 		{
 			visited[*j]=true;
 			queue.push_back(*j);
 			
		 }
	}
	 	
	}
 	
 }
 
 }
 int main()
 {int n,e,v1,v2;	
 cin>>n>>e;
 	Graph g(n);
 	for (int i=0;i<e;i++)
 	{
 		cin>>v1>>v2;
 		g.addEdge(v1,v2);
	 }
	 cout<<endl;
	 g.BFS();
	 return 0;
 }

