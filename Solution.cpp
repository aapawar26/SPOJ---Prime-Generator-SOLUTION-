#include <bits/stdc++.h> 
using namespace std; 

void simpleSieve(int limit, vector<int>& prime) 
{ 
    bool mark[limit + 1]; 
    memset(mark, false, sizeof(mark)); 
  
    for (int i = 2; i <= limit; ++i) { 
        if (mark[i] == false) { 

            prime.push_back(i); 
            for (int j = i; j <= limit; j += i) 
                mark[j] = true; 
        } 
    } 
} 
  

void primesInRange(int low, int high) 
{ 

    int limit = floor(sqrt(high)) + 1; 
    vector<int> prime; 
    simpleSieve(limit, prime); 
  
    int n = high - low + 1; 
  

    bool mark[n + 1]; 
    memset(mark, false, sizeof(mark)); 

    for (int i = 0; i < prime.size(); i++) { 

        int loLim = floor(low / prime[i]) * prime[i]; 
        if (loLim < low) 
            loLim += prime[i]; 
        if(loLim==prime[i]) 
            loLim += prime[i]; 
 
        for (int j = loLim; j <= high; j += prime[i]) 
            mark[j - low] = true; 
    } 
  

    for (int i = low; i <= high; i++) 
        if (!mark[i - low]) 
            cout << i << " "; 
} 

int main() 
{ 
    int n;
    cin>>n;
    while(n--)
    {
    	int a,b;
    	cin>>a>>b;
    	if(a == 1 || a == 0)
    		a = 2;
    	primesInRange(a,b);
    	cout<<endl;

    }
    
    return 0; 
} 
