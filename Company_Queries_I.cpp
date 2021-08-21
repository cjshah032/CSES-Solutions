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

    int n, q;
    cin>>n>>q;

    vi p(n);
    fro(i,1,n)
    {
        cin>>p[i];
        --p[i];
    }

    p[0] = -1;

    
    vector<vi> st(n, vi(20, -1));
    fro(i,0,n)
        st[i][0] = p[i];
    
    fro(j,1,21)
    {
        fro(i,0,n)
        {
            int b = st[i][j-1];
            if(b == -1)
                continue;

            st[i][j] = st[b][j-1];
        }
    }

    while(q--)
    {
        int a, k;
        cin>>a>>k;
        --a;

        if(k == 0){
            cout<<(a+1)<<endl;
        }

        int ans = a;

        while(k > 0)
        {
            int i = __builtin_clz(k);
            int b = 1<<(31-i);
            k -= b;
            ans = st[ans][31-i];
            if(ans == -1)
                break;
        }

        if(ans != -1)
            cout<<(ans+1)<<endl;
        else cout<<-1<<endl;
    }
}