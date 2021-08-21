#include <bits/stdc++.h> 
using namespace std; 

//input//
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define NArray int n; cin>>n; int a[n]; inputN
#define inputNxN for(int x=0; x<n; x++)for(int y=0; y<n; y++)cin>>a[x][y];
#define inputN for(int z=0; z<n; z++)cin>>a[z];
#define endl '\n'

//variable declarations//
#define vi  vector<int>
#define vii vector<pair<int, int>>
#define vs  vector<string>
#define qi queue<int>
#define long_max 9223372036854775807
#define int_max 2147483647

//common functions//
#define ll long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define bitcount _builtin_popcount
#define leadzero __builtin_clz
#define trailzero __builtin_ctz

int main() {
	// your code goes here
    FAST

    int n; long x;
    cin>>n>>x;
    
    long a[n];
    inputN
    
    unsigned long dp[x+1];
    sort(a, a+n);
    if(a[0] > x)
    {
        cout<<-1<<endl;
        return 0;
    }

    for(int i =0; i<x+1; i++)
        dp[i] = -1;
    
    dp[0] = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i] <= x)
        dp[a[i]] = 1;
    }
    
    bool flag = false;
    for(int i=1; i<x+1; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i < a[j])
                break;
            else {
                if(dp[i - a[j]] == -1)  
                    continue;
                
                dp[i] = min(dp[i], dp[i-a[j]]);
                flag = true;
            }
        }
        if(flag)
            dp[i] ++ ;
            
        flag = false;
    }
    
    if(dp[x] == -1)
        cout<<-1<<endl;
    else cout<<dp[x]<<endl;
    
	return 0;
}
