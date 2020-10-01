#include<bits/stdc++.h>

using namespace std;
int size=2;
int* arr=(int*)malloc(2*sizeof(int));

void update()
{
    size=size*2;
    int* temp=(int*)malloc(size*sizeof(int));
    for(int i=0;i<=size/2;i++)
    {
        temp[i]=arr[i];
    }
    arr=temp;
}

int main()
{
    int inp=0,k=0;
    while(inp!=-100)
    {
        cin>>inp;
        if(inp==1)
        {
            for(int i=0;i<k;i++)
                cout<<arr[i]<<" ";
        }
        else if(k<=size)
            arr[k++]=inp;
        else
        {
            update();
            arr[k++]=inp;
        }
        
    }
    return 0;
}
