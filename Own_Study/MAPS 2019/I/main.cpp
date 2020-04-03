#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define MAXN 100005
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
int n,m;
vector<int> g[MAXN];
vector<vector<int>> g2;
vector<int> c2;
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks=0, current_scc=0;


void topoSort(int u){
    stacked[u] = true;
    for(int i : g2[u]){
        if(!stacked[i]) topoSort(i);
    }
    s.push(u);
}
void tarjan(int u){
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  const vector<int> &out = g[u];
  for (int k=0, m=out.size(); k<m; ++k){
    const int &v = out[k];
    if (d[v] == -1){
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }else if (stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }
  if (d[u] == low[u]){
    int v;
    do{
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    }while (u != v);
    current_scc++;
  }
}
int main()
{
    cin>>n>>m;
    memset(d,-1,sizeof(d));
    memset(stacked,0,sizeof(stacked));
    fore(i,0,m){
        int x,y; cin>>x>>y;
        g[x].pb(y);
    }
    fore(i,0, n){
        if(d[i]==-1)
            tarjan(i);
    }
    g2.resize(current_scc);
    c2.resize(current_scc);
    fore(i,0,n){
        c2[scc[i]]++;
        for(int j : g[i]){
            g2[scc[i]].pb(scc[j]);
        }
    }
    while(s.size())s.pop();
    memset(stacked,0,sizeof(stacked));
    fore(i,0,current_scc){
        if(!stacked[i])
            topoSort(i);
    }



    ll acum = 0;
    memset(stacked,0,sizeof(stacked));
    map<int,ii> pos;
    int cnt = 0;
    while(s.size()){

        int curr = s.top();
        s.pop();
        acum += c2[curr];
        pos[curr] = {cnt++,acum};
    }
    ll sum = 0;
    fore(i,0,n){
        sum+= n;
        ii p = pos[scc[i]];
        sum -= p.ss;
        for(int j : g[i]){
            if(pos[scc[j]].ff > p.ff) sum--;
        }
    }




   cout<<sum<<endl;
    return 0;
}
