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
    if(n == 1) {
        cout<<0<<endl;
        return 0;
    }

    vector<vi> g(n, vi());
    fro(i,0,n-1) {
        int a, b;
        cin>>a>>b;

        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    queue<int> q;
    q.push(0);
    vi v(n, 0);
    int len = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        v[u] = 1;

        for(auto x: g[u]) 
        {
            if(v[x] == 1)
                continue;
            q.push(x);
        }

        if(q.empty())
            len = u;
    }

    v.assign(n,0);
    vi lengths(n,0);

    queue<pii> s;
    s.push({len, 0});
    int mx = 0; int ind;

    while(!s.empty())
    {
        int u = s.front().first;
        int d = s.front().second;
        lengths[u] = max(lengths[u], d);
        s.pop();
        v[u] = 1;

        for(auto x: g[u]) 
        {
            if(v[x] == 1)
                continue;
            s.push({x, d+1});
        }

        if(d > mx) {
            mx = d;
            ind = u;
        }
    }

    v.assign(n,0);
    s.push({ind, 0});
    while(!s.empty())
    {
        int u = s.front().first;
        int d = s.front().second;
        lengths[u] = max(lengths[u], d);
        s.pop();
        v[u] = 1;

        for(auto x: g[u]) 
        {
            if(v[x] == 1)
                continue;
            s.push({x, d+1});
        }
    }

    fro(i,0,n) {
        cout<<lengths[i]<<" ";
    }
}