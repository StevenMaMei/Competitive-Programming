#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

vector<int> group;
bool visited[1000010];
void dfs(int curN, vector<vector<int>> &g){
    if(visited[curN]) return;
    visited[curN]=true;
    group.pb(curN);
    for(int v: g[curN]){
        dfs(v,g);
    }
}
int main(){FIN;
    int n,m; cin>>n>>m;
    vector<int> permutation(n);
    fore(i,0,n){
        cin>>permutation[i];
    }
    vector<vector<int>> g(n);
    fore(i,0,m){
        int a,b; cin>>a>>b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    fore(i,0,n){
        if(!visited[i]){
//            cout<<i<<" jejje\n";
            group.clear();
            dfs(i,g);
            vector<int> temp;
            for(int v: group){
                temp.pb(permutation[v]);
            }
            sort(temp.begin(),temp.end(),greater<int>());
            sort(group.begin(),group.end());
            fore(j,0,sz(group)){
                permutation[group[j]]= temp[j];
            }
        }
    }
    fore(i,0,n){
        if(i+1 == n){
            cout<<permutation[i]<<"\n";
        }else{
            cout<<permutation[i]<<" ";
        }
    }
    return 0;
}
