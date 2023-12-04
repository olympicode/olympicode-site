#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int edge_order[N],node_order[N];

struct Component{
	int size,max_a;
	vector<int> alive,all_nodes;
	Component(){}
	void init(int u,int A){
		size=1;
		max_a=A;
		alive=all_nodes={u};
	}
}components[N];
int my_component[N];

void Merge(int a,int b){
	if(a==b)return;

	if(components[a].size<components[b].size)swap(a,b);

	components[a].size+=components[b].size;
	components[a].max_a=max(components[a].max_a,components[b].max_a);

	for(int i:components[b].alive){
		components[a].alive.push_back(i);
	}
	for(int i:components[b].all_nodes){
		components[a].all_nodes.push_back(i);
		my_component[i]=a;
	}
}

void Resi(int N, int *A, int M, int *U, int *V, int *W, int *R){

	for(int i=1;i<=M;i++)edge_order[i]=i;
	sort(edge_order+1,edge_order+1+M,[&](int i,int j){return W[i]<W[j];});

	for(int i=1;i<=N;i++)node_order[i]=i;
	sort(node_order+1,node_order+1+N,[&](int i,int j){return A[i]<A[j];});

	for(int i=1;i<=N;i++){
		components[i].init(i,A[i]);
		my_component[i]=i;
	}

	int ptr=1;
	for(int i=1;i<=N;i++){
		while(ptr<=M && W[edge_order[ptr]]<=A[node_order[i]]){
			Merge(my_component[U[edge_order[ptr]]],my_component[V[edge_order[ptr]]]);
			ptr++;
		}

		if(components[my_component[node_order[i]]].max_a==A[node_order[i]]){

			for(int j:components[my_component[node_order[i]]].alive){
				R[j]=components[my_component[node_order[i]]].size;
			}

			components[my_component[node_order[i]]].alive.clear();
		}
	}
}
