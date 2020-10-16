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


int sz = 200001;
vector< vector<int> >adj(sz);
vector<int>match(sz, 0), vis1(sz, 0), par(sz, 0), level(sz, 0);

int lvl = 0;

// This is template code
int minVertexCoverTree(int src) {
    vis1[src] = 1;
    int cc = adj[src].size(), isMarked[cc], child = 0;
    memset(isMarked, -1, sizeof(isMarked));
    Fd(0, cc) {
        int v = adj[src][i];
        if(vis1[v] == 0){
            child++;
            par[v] = src;
            isMarked[i] = minVertexCoverTree(v);
        }
    }
    // match[par[src]] = 1;
    if(child == 0) return 0;
    int fg = 0;
    for(int j = 0; j < cc; j++) {
        if(isMarked[j] == -1) continue;
        if(isMarked[j] == 0) {
            match[src] = 3;
            return 2;
        }
        if(isMarked[j] == 1) fg = 1;
    }
    if(fg == 1) {
        match[src] = 3;
        return 2;
    } else {
        return 1;
    }
    return 0;
}
