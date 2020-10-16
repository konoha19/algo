#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define Fd(start, end) for(int i = start; i < end; i++)
#define Fb(end, start) for(int i = end - 1; i >= start; i--)
#define pr pair<int,int>
#define prll pair<ll,ll>
#define N 200001
#define ll long long int
#define mod 998244353
#define MOD 1000000007

int ctm = 0;
vector<int>vis1(N,0), vis(N,0);
vector<ll>seglr1(9*N, 0), seglr2(9*N, 0), segrl1(9*N, 0), segrl2(9*N, 0);

vector< vector<int> >directed_graph(N+1);
vector<int>top_order;


// tree
int sz = 200001;
// int arr[sz] = {0};
vector< vector<int> >adj(sz);
vector<int>match(sz, 0), vis1(sz, 0), par(sz, 0), level(sz, 0);


// topological sort
void top_dfs(int src) {
    vis[src] = 1;
    for(int i = 0; i < directed_graph[src].size(); i++) {
        if(vis[directed_graph[src][i]] == 0) {
            top_dfs(directed_graph[src][i]);
        }
    }
    top_order.push_back(src);
}

// sub-node count dfs
int simpledfs(int src) {
    vis[src] = 1;
    
    Fd(0, adj[src].size()) {
        int v = adj[src][i];
        if(vis[v] == 0){
            child[src] +=  simpledfs(v);
        }
    }
    return child[src] + 1;
}
