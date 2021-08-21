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

    int n, m;
    cin>>n>>m;

    vi a(n);
    inputArr(a, n);

    vector<vll> dp(n, vll(m+1,0));
    fro(i,0,n) {
        fro(j,1,m+1) {
            if(i == 0 && a[i] == 0) dp[i][j] = 1;
            else if(i == 0 && a[i] != 0 && a[i] == j) dp[i][j] = 1;
            else if(i == 0 && a[i] != 0 && a[i] != j) dp[i][j] = 0;
            else if(a[i] != 0) {
                if(a[i] == j) {
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%MOD;
                    if(j < m) (dp[i][j] +=  dp[i-1][j+1]) %= MOD;
                }

                else dp[i][j] = 0;
            }
            else {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%MOD;
                if(j < m) (dp[i][j] +=  dp[i-1][j+1]) %= MOD;
            }
        }   
    }

    ll ans = 0;
    fro(i,1,m+1) {
        (ans += dp[n-1][i]) %= MOD;
    }

    cout<<ans<<endl;
}