int findIndex(int arr[],int low,int high,int element)
{
  if(low>high)
    return -1;
  int mid=low+(high-low)/2;
  if(arr[mid]==element)
    return mid;
  else if(arr[mid]>element)
    return findIndex(arr,low,mid-1,element);
  return findIndex(arr,mid+1,high,element);
}
