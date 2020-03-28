#include<bits/stdc++.h>
#include<list>
using namespace std;
class Graph{
	int V;
	list<int> * adj;
public:	
	Graph(int V)
	{
	this->V=V;
	adj=new list<int>[V];
	}
	void addEdge(int u,int v);
	int iscycle();
};
void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
	
}
int Graph:: iscycle()
{
	bool *visited = new bool[V];
	bool *vis=new bool[V];
	for(int i=0;i<V;i++)
	{visited[i]=false;
	vis[i]=false;
	}
	list<int> stack;
	for(int ee=0;ee<V;ee++)
	{
		
		int	element;
		if(visited[ee]==false)
		{
		element=ee;
		stack.push_back(element);
		visited[element]=true;
		vis[element]=true;
		}
		else
		continue;
	while(!stack.empty())
	{
		list<int>:: iterator i;
		bool check=false;
		
//		cout<<"element "<<element<<endl;
		for(i=adj[element].begin();i!=adj[element].end();++i)
		{
		/*	
			cout<<"visited"<<endl;
			for(int k=0;k<V;k++)
			cout<<visited[k]<<" ";
			cout<<endl;
			cout<<*i<<" ii"<<endl;
			*/
			if(vis[*i]==true)
			return true;
			if(visited[*i]==false)
			{	
//				cout<<"*i tttt "<<*i<<endl;
				check=true;
				visited[*i]=true;
				stack.push_back(*i);
				vis[*i]=true;	
				element=*i;
				break;
			}
		}
		
		
		if(check==false)
		{	int popelement=stack.back();
//			cout<<"pop "<<popelement<<endl;
			vis[popelement]=false;
			stack.pop_back();
			element=stack.back();
		}
		/*
		cout<<"stack : ";
		list<int>::iterator kk;
		for(kk=stack.begin();
		kk!=stack.end();kk++)
		cout<< *kk <<" ";
		cout<<endl;
		cout<<"vis : "<<endl;
			for(int k=0;k<V;k++)
			cout<<vis[k]<<" ";
			cout<<endl;
			*/
	}
	}
	return false;
}
int main()
{
	int v,e,v1,v2;
	cin>>v>>e;
	Graph g(v);
	for(int i=0;i<e;i++)
	{
		cin>>v1>>v2;
		g.addEdge(v1,v2);
	}
	cout<<endl;
	cout<<g.iscycle();
	return 0;
}
