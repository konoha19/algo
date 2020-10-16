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

int lvl = 0;

// maxDis contains the final result
int maxDistanceBetNodes(int src, int &maxDis) {
    vis1[src] = 1;
    int cc = adj[src].size(), dis[cc], child = 0;
    memset(dis, -1, sizeof(dis));
    Fd(0, cc) {
        int v = adj[src][i];
        if(vis1[v] == 0){
            child++;
            dis[i] = maxDistanceBetNodes(v, maxDis);
        }
    }        
    if(child == 0) {
        maxDis = max(maxDis, 0);
        return 0;
    }
    sort(dis, dis + cc);
    if(child == 1) {
        maxDis = max(maxDis, dis[cc-1]+1);
    }else {
        maxDis = max(maxDis, dis[cc-1]+dis[cc-2]+2);
    }

    return dis[cc-1]+1;
    

    ///

}