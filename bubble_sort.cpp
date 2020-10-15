void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   bool swapp; 
   for (i = 0; i < n-1; i++) 
   { 
     swapp = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(arr[j], arr[j+1]); 
           swapp = true; 
        } 
     }  
     if (swapp == false) 
        break; 
   } 
} 
