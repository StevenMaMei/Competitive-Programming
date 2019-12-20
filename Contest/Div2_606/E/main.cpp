#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;
struct node{
    bool visited[2];
    vector<int> neighs;
};

vector<node> graph;

void bfs(int mode, int v, int no){
    node currN = graph[v];
    currN.visited[mode] = true;
    queue<int> q;
    fore(i,0,currN.neighs.size()){
        q.push(currN.neighs[i]);
    }
    while(q.size()){
        int nv = q.front(); q.pop();
        if(!graph[nv].visited[mode] && nv != no){
            //cout<<nv<<" mode "<< mode<<endl;
            graph[nv].visited[mode] = true;
            int sz = graph[nv].neighs.size();
            fore(i,0,sz) q.push(graph[nv].neighs[i]);
        }
    }
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

    int t; cin>> t;
    while(t--){
        graph.clear();
        int n,m,a,b; cin>>n>>m>>a>>b;
        graph.resize(n+1);
        fore(i,0,m){
            int v1,v2; cin>>v1>>v2;
            graph[v1].neighs.pb(v2);
            graph[v2].neighs.pb(v1);
        }
        bfs(0,a, b);
        bfs(1,b, a);
        ll ca= 0;
        ll cb = 0;
        fore(i,1,n+1){
            node currN = graph[i];
            if(currN.visited[0] && !currN.visited[1] && i != a){
               // cout<<" a "<< i << endl;
                ca++;
            }else if(!currN.visited[0] && currN.visited[1] && i != b){
               // cout<<" b "<<i<<endl;
                cb++;
            }
        }
        cout<<ca*cb<<endl;
    }
    return 0;
}
