#include <bits/stdc++.h>
using namespace std;
//std::vector<std::vector<int> > ar;
char ar[1001][1001];
bool vis[1001][1001];
int n,m;
bool isValid(int x,int y)
{
 if(x<1 || x>n || y<1 || y>m)
  return false;
 if(vis[x][y]==true || ar[x][y]=='#')
  return false;
 return true;
}
void dfs(int x,int y)
{
 vis[x][y]=true;
 if(isValid(x-1,y))
  dfs(x-1,y);
 if(isValid(x+1,y))
  dfs(x+1,y);
 if(isValid(x,y-1))
  dfs(x,y-1);
 if(isValid(x,y+1))
  dfs(x,y+1);
}
int main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=m;j++)
      cin>>ar[i][j];
    }
 int cc=0;
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
   if(ar[i][j]=='.' && vis[i][j]==false )
   {
    dfs(i,j);
    cc++;
   }
 }
 cout<<cc<<"\n";
}
