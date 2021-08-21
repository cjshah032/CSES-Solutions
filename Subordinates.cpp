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

void makeDirectedGraph(vi& p, vector<vi>& g) {
    int n = p.size();
    fro(i,1,n) {
        g[p[i]-1].pb(i);
    }
}

int dfs(vector<vi>& g, vi& ch, int u) {
    int sum = 0;
    for(auto x: g[u]) {
        sum += dfs(g, ch, x);
    }

    ch[u] = sum;
    return sum + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vi p(n);
    fro(i,1,n) 
        cin>>p[i];

    vector<vi> g(n, vi());
    makeDirectedGraph(p, g);

    vi ch(n);
    dfs(g, ch, 0);

    fro(i,0,n) {
        cout<<ch[i]<<" ";
    }
}