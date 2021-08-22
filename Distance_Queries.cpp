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

int n, q;
vector<vi> g;
vi l; 

vi t; vi ef; vi ff;
vi v; 

void dfs(int u, int d) {
    ff[u] = ef.size();
    l[u] = d;
    ef.pb(u);
    v[u] = 1;
    for(auto x: g[u]) {
        if(v[x] == 0) {
            dfs(x, d+1);
            ef.push_back(u);
        }
    }
}

bool cmp(int a, int b) {
    return l[a] < l[b];
}

int build(int v, int tl, int tr)
{
    if(tl == tr){
        return t[v] = ef[tl];
    }

    else {
        int tm = (tl+tr)/2;
        int x = build(2*v+1, tl, tm);
        int y = build(2*v+2, tm+1, tr);
        if(cmp(x, y))
            return t[v] = x;
        return t[v] = y;
    }
}

int fin_min(int v, int tl, int tr, int low, int high)
{
    if(low > high) 
        return n;
    if(low <= tl && high >= tr)
        return t[v];
    int tm = (tl+tr)/2;
    int x = fin_min(2*v+1, tl, tm, low, min(tm, high));
    int y = fin_min(2*v+2, tm+1, tr, max(tm+1, low), high);
    if(cmp(x, y))
        return x;
    return y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    if(n == 1) {
        while(q--) {
            int a, b;
            cin>>a>>b;

            cout<<0<<endl;
        }

        return 0;
    }
    
    g.assign(n, vi());

    fro(i,0,n-1)
    {
        int a, b;
        cin>>a>>b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ff.assign(n,0);
    v.assign(n,0);
    l.assign(n+1, INF);

    dfs(0, 0);

    int N = ef.size();
    t.assign(4*N, n);

    build(0, 0, N-1);
    while(q--) {
        int a, b;
        cin>>a>>b;

        --a; --b;
        int x = min(ff[a], ff[b]);
        int y = max(ff[a], ff[b]);

        int lvl = l[fin_min(0, 0, N-1, x, y)];
        int ans = abs(lvl - l[a]) + abs(lvl - l[b]);
        cout<<ans<<endl;
    }
}