#include<bits/stdc++.h>
#include<list>
#include<vector>
#define inf 1e9
using namespace std;
int minimum_cost(int lcp[],bool visited[],int v,int * value)
{   int mv=inf;
    int mi=-1;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false && mv>=lcp[i])
		{
		mv=lcp[i];
		mi=i;
		}
	}
	*value=mv;
	return mi;
}
class Graph{
	int V;
	list<int> *adj;
	list<int> *wt;
public:
	Graph(int V)
	{
		this->V=V;
		adj=new list<int>[V];
		wt=new list<int>[V];
	}
	void addEdge(int u,int v,int w);
	void dijkstra(int s);
};
void Graph::addEdge(int u,int v,int w)
{
	adj[u].push_back(v);
	wt[u].push_back(w);
	/*
	// for undirected graph
	adj[v].push_back(u);
	wt[v].push_back(w);
	*/
}
void Graph::dijkstra(int s)
{
	bool *visited=new bool[V];
	int lcp[V];
	for(int i=0;i<V;i++){
	visited[i]=false;
	lcp[i]=inf;
	}
//	list<int> arr;
	lcp[s]=0;
	visited[s]=true;
	int count=1;
	int element=s;
//	arr.push_back(s);
	int min_cost=0;
	while(count!=V)
	{
		list<int>::iterator i;
		list<int>::iterator j;
		for (i=adj[element].begin(),j=wt[element].begin() ; i!=adj[element].end() ; i++,j++)
		{
			if(visited[*i]!=true)
			{
				if(lcp[*i] > (*j + min_cost))
				{
					lcp[*i]= *j + min_cost ;
				}
			}
		}
		
		int value;
		element=minimum_cost(lcp,visited,V,&value);
		min_cost=value;
		visited[element]=true;
		count++;
	}
	
	for(int k=0;k<V;k++)
	cout<<lcp[k]<<" ";
	
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v,e,v1,v2,w;
	cin>>v>>e;
	Graph g(v);
	for(int i=0;i<e;i++)
	{
		cin>>v1>>v2>>w;
		g.addEdge(v1,v2,w);
	}
	cout<<endl;
	g.dijkstra(0);
	return 0;
	
}
