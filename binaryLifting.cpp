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
vector< vector<int> >adj(sz);
vector<int>match(sz, 0), vis1(sz, 0), par(sz, 0), level(sz, 0);

int lvl = 0;
void simpleDfs(int src, int lvl) {
    vis1[src] = 1, level[src] = lvl;
    int cc = adj[src].size();
    Fd(0, cc) {
        int v = adj[src][i];
        if(vis1[v] == 0){
            par[v] = src;
            simpleDfs(v, lvl+1);
        }
    }  

}

int binLift[200001][18];
void binaryLifting(int n) {
    simpleDfs(1);
    Fd(0, 18) binLift[1][i] = -1;
    
    for(int j = 0; j < 18; j++) {
        for(int i = 2; i <= n; i++){
            
            if(j == 0) binLift[i][j] = par[i];
            else binLift[i][j] = binLift[i][j-1] != -1 ? binLift[binLift[i][j-1]][j-1] : -1;

        }
        
    }
    

}