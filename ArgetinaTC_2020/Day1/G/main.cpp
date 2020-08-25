#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef pair<int,int> ii;
 int n,k;
vector<bool> visited;
vector<int> parent;
ii dfs(int u,int dist,int par, vector<vector<int>> &graph){
    visited[u]=true;
    if(sz(graph[u])==1 && par != u){
        return {dist,u};
    }
    ii diameter = {0,0};
    for(int v: graph[u]){
        if(!visited[v]){
            ii pos= dfs(v,dist+1,par,graph);
            parent[v]=u;
            if(pos.ff>diameter.ff){
                diameter = pos;
            }
        }
    }
    return diameter;
}
bool verify(int u, int dist,int val,vector<vector<int>> &graph){
    visited[u]=true;
    if(sz(graph[u])==1){
        return dist == val;
    }
    bool meet=true;
    for(int v: graph[u]){
        if(!visited[v]){
            if( !(sz(graph[v])==1 || sz(graph[v])>=4) ){
                return false;
            }
            meet &= verify(v,dist+1,val,graph);
        }
    }
    return meet;

}
int main(){FIN;
   cin>>n>>k;
    vector<vector<int>> graph(n+1);
    visited.resize(n+10);
    parent.resize(n+10);
    fore(i,0,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    ii diameter = {0,0};

    for(int i = 1; i<=n; i++){
        if(sz(graph[i])==1){
            diameter = dfs(i,1,i,graph);
            break;
        }
    }
//    cout<<diameter.ff<<" "<<diameter.ss<<"\n";
    int curDiam=diameter.ff;
    if(diameter.ff%2 == 1){
        diameter.ff = diameter.ff/2+1;
    }else{
        diameter.ff = diameter.ff/2;
    }
    while(curDiam != diameter.ff){
        diameter.ss = parent[diameter.ss];
        curDiam--;
    }
    int center = diameter.ss;
//    cout<<center<<"\n";
    if(sz(graph[center])<3){
        cout<<"No\n";
        return 0;
    }
    visited.clear(); visited.resize(n+10);
    bool meet = verify(center,1,k+1,graph);
    if(meet){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}
