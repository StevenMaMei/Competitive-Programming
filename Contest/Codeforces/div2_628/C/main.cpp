#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxIcesi=b;i<thxIcesi;i++)
#define SZ(s) int(s.size())
#define FIN ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef pair<int,int> ii;
vector<vector<int>> tree;
vector<int> visited;
vector<ii> order;
map<ii,int> res;
queue<int> nextt;
void bfs(int ini){
    queue<int> q;
    q.push(ini);
    visited[ini] = 1;
    while(q.size()){
        int curr =q.front();
        q.pop();
        for(int n : tree[curr]){
            if(visited[n]==0){
                visited[n] = 1;
                int a = curr, b = n; if(a>b)swap(a,b);
                res[{a,b}] = nextt.front();
                //cout<<nextt.front()<<endl;
                nextt.pop();
                q.push(n);
            }
        }
    }
}
int main()
{ FIN;
    int n; cin>>n;
    tree.resize(n+1);
    visited.resize(n+1);
    fore(k,0,n-1){
        int a,b; cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
        if(a>b) swap(a,b);
        order.pb({a,b});
    }
    fore(i,0,n-1){
        nextt.push(i);
    }
    int ini = 1;
    int maxChild = 0;
    fore(i,1,n+1){
        if(SZ(tree[i])>= maxChild){
            maxChild=SZ(tree[i]);
            ini = i;
        }
    }

    bfs(ini);
    fore(i,0,SZ(order)){

        cout<<res[order[i]]<<"\n";
    }

    return 0;
}
