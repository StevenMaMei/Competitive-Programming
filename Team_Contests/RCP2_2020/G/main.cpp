#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,thx=b;i<thx;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
#define N 300005

using namespace std;
typedef long long  ll;
auto rnd=bind(uniform_int_distribution<long long>(1,1e13), mt19937(time(0)));

int n;
vector<int> tree[N];
map<ll,ll> m;
ll subt[N];
set<ll> diffTrees;

ll f(ll s){
    if(!m.count(s)){
        m[s] = rnd();
    }
    return m[s];
}
ll dfs1(int u, int p){
    ll sum = 0;
    for(int v: tree[u])if(v != p) sum += dfs1(v,u);
    subt[u] = f(sum);
    return subt[u];
}
void dfs2(int u, ll pSum= 0, int p=-1){
    ll sum =0;
    for(int v : tree[u])if(v!= p){
        sum += subt[v];
    }
    if(u != 0)sum += f(pSum-subt[u]);
    diffTrees.insert(f(sum));
    for(int v: tree[u])if(v!= p){
        dfs2(v,sum,u);
    }
}
int main()
{FIN;
    cin>>n;
    fore(i,0,n-1){
        int a,b; cin>>a>>b;
        a--;b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    dfs1(0,-1);
    dfs2(0);
    cout<<SZ(diffTrees)<<"\n";
    return 0;
}
