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
            simpleDfs(v, lvl+1);
        }
    }  

}


// vector< vector<int> >binLift(sz, vector<int>(18));
int binLift[200001][18];
void binaryLifting(int n) {
    // simpleDfs(1);
    Fd(0, 18) binLift[1][i] = -1;
    
    for(int j = 0; j < 18; j++) {
        for(int i = 2; i <= n; i++){
            
            if(j == 0) binLift[i][j] = par[i];
            else binLift[i][j] = binLift[i][j-1] != -1 ? binLift[binLift[i][j-1]][j-1] : -1;

        }
        
    }
    

}

int LCABinLifting(int u, int v) {
    int u1, v1;
    if(level[u] > level[v]) {
        v1 = u, u1 = v;
    }else{
        v1 = v, u1 = u;
    }
    int d = level[v1] - level[u1];
    // cout<<d<<endl;

    int curr = 0;
    
    while(d != 0) {
        
        if(d&1) {
            v1 = binLift[v1][curr];
            // k = k - (1<<curr);
        }
        d = d >> 1;
        curr++;
    }
    if(u1 == v1) return u1;

    for(int i = 17; i >= 0; i--) {
        if(binLift[u1][i] != -1 && (binLift[u1][i] != binLift[v1][i])) {
            u1 = binLift[u1][i], v1 = binLift[v1][i];
        } 
    }
    

    return par[u1];


}
