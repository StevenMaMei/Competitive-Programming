#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
const int MAXN=(1e5)+10;
vector<int> graph[MAXN];
set<int> isBad[MAXN];
void bfs(int v){


    queue<int> q; q.push(v);
    vector<bool> visited(MAXN);
    visited[v]=true;
    while(sz(q)){
        int curr = q.front(); q.pop();
        for(int u: graph[curr]){
            if(sz(isBad[u])<2 && !visited[u]){
                visited[u]=true;
                isBad[u].insert(v);
                q.push(u);
            }
        }

    }
}
int main(){FIN;
    int n,m,t; cin>>n>>m>>t;
    vector<int> possibleBads;
    fore(i,0,m){
        int a,b; cin>>a>>b;
        if(b==t){
            possibleBads.pb(a);
            isBad[a].insert(a);
        }else{

            graph[b].pb(a);
        }
    }
    for(int i: possibleBads){
        bfs(i);
    }
    sort(possibleBads.begin(),possibleBads.end());
    int acum=0;
    vector<int> ans;
    for(int i: possibleBads){
        if(sz(isBad[i])<2){
            acum++;
            ans.pb(i);
        }
    }
    cout<<acum<<"\n";
    for(int i: ans)cout<<i<<"\n";
    return 0;
}
