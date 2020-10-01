//gfg implementation of modular exponentiation

#include <bits/stdc++.h>
using namespace std;
#define p 1000000007
#define ll long long int

ll power(unsigned ll y) 
{ 
  ll x=2;
   unsigned ll res = 1; 
    x = x % p;  
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
} 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    unsigned long long int n;
	    cin>>n;
	    long long int odd=power(n-1);
	    long long int even=odd-1;
	    cout<<even<<" "<<odd<<"\n";
	}
	return 0;
}

