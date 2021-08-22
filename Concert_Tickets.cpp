/// Note that this code gives WA on CSES platform as it checks directly for 
/// matching text. However this code is produces correct greedy solution
/// for maximum tickets sold and the corresponding tickets being sold out.

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

    vll h(n);
    vector<vll> t(m, vll(2));
    inputArr(h, n);
    fro(i,0,m) {
        cin>>t[i][0];
        t[i][1] = i;
    }

    sort(h.begin(), h.end());
    sort(t.begin(), t.end());

    vll ans(m);
    int j = n-1;
    orf(i,m,0) {
        while(j >= 0 && h[j] > t[i][0])
            --j;
        if(j < 0) {
            ans[t[i][1]] = -1;
        }

        else {
            ans[t[i][1]] = h[j];
            --j;
        }
    }

    fro(i,0,m)
        cout<<ans[i]<<endl;
}