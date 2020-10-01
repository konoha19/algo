


dfs(int node,int par)
{
	vis[node]=1;
	in[node]=low[node]=timer++;

	for(int child: node)
	{
		//case: 1
		if(child==par)
			continue;
		//case: 2
		if(vis[child])
		{
			//child is a back-edge
			low[node]=min(low[node],in[child]);
		}
		else
		{
			//child is child
			dfs(child,node);

			if(low[child]>in[node])
				cout<<ar[child]<<"--"<<ar[node]<<"is a bridge"<<"\n";

			low[node]=min(low[node],low[child]); 

		}
	}
}