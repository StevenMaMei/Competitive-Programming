#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

const int MAXN = 5005;

typedef pair<int,int> ii;
typedef pair<ii,int> inf;

vector<int> g1[MAXN], g2[MAXN];
int dp[MAXN],visi[MAXN];
vector<inf> infos;
vector<ii> devicesIntervals[MAXN];
int n;

inf dfs(int v, vector<int>* g, int top){
    if(v> top) return {{v-top,v-top},0};
    int quantEdges = v>1?1:0;
    ii interval = {1e9,-1e9};
    for(auto cv: g[v]){
        auto currInf = dfs(cv,g,top);
        interval = {min(currInf.ff.ff,interval.ff), max(currInf.ff.ss,interval.ss)};
        quantEdges += currInf.ss;
    }
    //cout<<"l "<<interval.ff<<"r "<<interval.ss<<endl;
    infos.pb({interval,quantEdges});
    return {interval,quantEdges};
}

int solve(int pos){
    if(pos == n+1) return 0;
    int r= dp[pos];
    if(visi[pos]){
     //cout<<dp[pos]<<endl;
     return dp[pos];
    }
    visi[pos] = true;

    r= -1e9;
    for(auto x: devicesIntervals[pos])r = max(r, x.ss+ solve(x.ff+1));
    dp[pos] = r;
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL
    cin>>n;

    int a; cin>>a;
    fore(i,1,a){
        int p; cin>>p;
        g1[p].pb(i+1);
    }
    fore(i,0,n){
        int x; cin>>x;
        g1[x].pb(a+i+1);
    }

    int b; cin>>b;
    fore(i,1,b){
        int q; cin>>q;
        g2[q].pb(i+1);
    }
    fore(i,0,n){
        int y; cin>>y;
        g2[y].pb(b+i+1);
    }
    dfs(1,g1,a); dfs(1,g2,b);
    for(auto info: infos) devicesIntervals[info.ff.ff].pb({info.ff.ss,info.ss});
    memset(dp,-1,sizeof(dp));
    memset(visi,0,sizeof(visi));
    cout<<solve(1)<<endl;
    return 0;
}
