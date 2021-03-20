#include<bits/stdc++.h>
using namespace std;
#define int long long
void r_k_p()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Graph{
	int V;
	list<pair<int,int>> l;
public:
	Graph(int V){
		this->V = V;
	}
	void addEdge(int u,int v){
		l.push_back(make_pair(u,v));
	}
	// find
	int findSet(int i,int *parent){
		if(parent[i]==-1){
			return i;
		}
		return findSet(parent[i],parent);
	}
	// union
	void unionSet(int x,int y,int parent[]){
		int s1 = findSet(x,parent);
		int s2 = findSet(y,parent);
		if(s1!=s2){
			parent[s1] = s2;
		}
		return;
	}

	bool contains_cycle(){
		// DSU logic to check if graph contain cycle or 
		int *parent = new int[V];
		for(int i=0;i<V;i++){
			parent[i] = -1;
		}
		for(auto edge: l){
			int i = edge.first;
			int j = edge.second;

			int s1 = findSet(i,parent);
			int s2 = findSet(j,parent);
			if(s1!=s2){
				unionSet(s1,s2,parent);
			}else{
				return true;
			}
		}
		delete [] parent;
		return false;
	}
};
int32_t main()
{
    r_k_p();
     // 0 based indexing
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    if(g.contains_cycle()){
    	cout<<"cycle is present"<<"\n";
    }else{
    	cout<<"no cycle is not present"<<"\n";
    }
    return 0;    
}