#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
using namespace std;
typedef pair<int, int> ii;
bool visited[200005];
vector<vector<int>> graph;
vector<ii> pairs;
int dfs(int node, int great){
    if(visited[node])
        return node;
    int g= great;
    visited[node]=true;
    if(node> great)
        g=node;
    vector<int> neigh= graph[node];
    for(int i = 0; i < neigh.size();i++){
        int temp = dfs(neigh[i],g);
        if(temp>g){
            g=temp;
        }
    }
    return g;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int n,m; cin>>n>>m;
    graph.resize(n+1);
    for(int i = 0; i < m; i++){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for(int i = 1; i<= n;i++ ){
        if(!visited[i]){
            int m= dfs(i,-1e8);
            pairs.pb({i,m});
        }
    }
    sort(pairs.begin(),pairs.end());
    int cant =0;
    for(int i =0 ; i < pairs.size()-1; i++){
        ii p1= pairs[i];
        ii p2= pairs[i+1];
        if(p1.ss>p2.ff){
            cant++;
            int last = p2.ss;
            if(p1.ss>last){
                last= p1.ss;
                pairs[i+1]={p2.first,last};
            }

        }
    }
    cout<<cant<<endl;
    return 0;
}
