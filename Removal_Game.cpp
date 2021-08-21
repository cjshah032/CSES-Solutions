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

    int n;
    cin>>n;

    vll a(n);
    inputArr(a, n);

    vector<vll> dp(n, vll(n));

    if(n % 2 == 0) {
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if(i == j) dp[i][j] = 0;
                else if((j - i)%2) {
                    dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
                }
                else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
    }
    

    else {
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if(i == j) dp[i][j] = a[i];
                else if((j - i)%2 == 0) {
                    dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
                }
                else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
    }

    cout<<dp[0][n-1]<<endl;
}