#include "bits/stdc++.h"

#define fro(i,min,max) for(int i=min; i<max; i++)
#define test(t) long long t; cin>>t; while(t--)
#define gtest(t) long long t; cin>>t; for(int gcase = 1; gcase <= t; gcase++)
#define inputArr(arr,n) for(int i=0; i<n; i++) cin>>arr[i];
#define froV(v,itr) for(auto itr = v.begin(); itr != v.end(); itr++)
#define orf(i,max,min) for(int i=max-1; i>=min; i--)
#define orfV(v,itr) for(auto itr = v.rbegin(); itr != v.rend(); itr++)
#define fro_(i,min,max,diff) for(int i=min; i<max; i+=diff)
#define orf_(i,max,min,diff) for(int i=max-1; i>=min; i-=diff)
#define mem(a,b) memset(a, (b), sizeof(a))
#define vll vector<long long>
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define sll set<long long>
#define ss set<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mll map<long long, long long>
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    test(t)
    {
        int n;
        cin>>n;

        // cout<<n<<endl;
        ll dp[n+2][2];
        dp[n+1][0] = 1; dp[n+1][1] = 1;
        for(int i=n; i>=2; i--) {
            dp[i][0] = (dp[i+1][0] + dp[i+1][1]) + dp[i+1][0] + 2*dp[i+1][0];
            dp[i][0] %= MOD;

            dp[i][1] = (dp[i+1][0] + dp[i+1][1]) + dp[i+1][1];
            dp[i][1] %= MOD;
        }

        cout<<((dp[2][0]+dp[2][1])%MOD)<<endl;
    }
}