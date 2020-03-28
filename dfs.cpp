#include<bits/stdc++.h>
#include<list>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
public:
	Graph(int V)
	{
		this->V=V;
		adj=new list<int>[V];
	}
	void addEdge(int v,int w);
	void dfs();
};
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
 }
void Graph:: dfs()
{
	bool *visited= new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	list<int> stack;
	for(int i=0;i<V;i++)
	{
		if(visited[i]==true)
		continue;
		//new disjoint graph
		int element;
		int kk=0;
		stack.push_back(i);
		element=i;
		visited[i]=true;
		while(!stack.empty())
		{
			if(kk==0)
			{	
				cout<<element<<" ";
				stack.pop_back();
			}
			else{
				element=stack.back();
				stack.pop_back();
				cout<<element<<" ";
			}
			kk++;
			list<int>::iterator j;
			for(j=adj[element].begin();j!=adj[element].end();j++)
			{
				if(visited[*j]!=true)
				{
					visited[*j]99=true;
					stack.push_back(*j);
				}
			}
		}
	}
	
 } 
 
int main()
{	int n,e,v1,v2;
	cin>>n>>e;
	Graph g(n);
	for(int i=0;i<e;i++)
	{	cin>>v1>>v2;
		g.addEdge(v1,v2);
	}
	cout<<endl;
	g.dfs();
	return 0;
}

