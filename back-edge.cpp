//    back edge
// can use in cycle detection





bool dfs(int node,int par)
{
	vis[node]=1;
	
	for(int child:ar[node])
	{
		if(!vis[child])
			if(dfs(child,node)==true)
				return true;

		else{
			if(child!=par)
				return true;
		}
	}
	return false;
}