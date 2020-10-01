// kadane's algorithm

int global_max=0;
int curr_max=INT_MIN;
for(int i=0;i<n;i++)
{
	curr_max+=a[i];
	if(global_max<curr_max)
		global_max=curr_max;

	if(curr_max<0)
		curr_max=0;
}
return global_max;



