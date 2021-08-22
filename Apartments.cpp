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
    ll k;
    cin>>n>>m>>k;
    map<ll, ll> f;
    map<ll, ll, greater<ll>> b;
    vll d(n);
    inputArr(d, n);
    fro(i,0,m) {
        ll a;
        cin>>a;
        if(f.find(a) == f.end())
        {
            f[a] = 1;
            b[a] = 1;
        }

        else {
            f[a] ++;
            b[a] ++;
        }
    }

    sort(d.begin(), d.end());
    int ans = 0;

    fro(i,0,n) {
        auto x = f.lower_bound(d[i]);
        auto y = b.lower_bound(d[i]);

        if(y != b.end() && y->first >= d[i] - k) {
            ++ ans;
            if(y->second == 1) {
                f.erase(y->first);
                b.erase(y->first);
            }

            else {
                --f[y->first];
                --b[y->first];
            }
        }

        else if(x != f.end() && x->first <= d[i] + k) {
            ++ ans;
            if(x->second == 1) {
                f.erase(x->first);
                b.erase(x->first);
            }

            else {
                --f[x->first];
                --b[x->first];
            }
        }
    }

    cout<<ans<<endl;    
}