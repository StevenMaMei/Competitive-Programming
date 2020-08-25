#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
vector<vector<int>> tree;
vector<int> order;

ll ans = 0;
int dfs(int u, int p, int l){
    int cantChilds=0;

    for(int i : tree[u]){
        if(i!=p) cantChilds+= dfs(i,u,l+1)+1;
    }
    order.pb(cantChilds-(l-1));
    return cantChilds;
}


int main()
{
    int n,k; cin>>n>>k;
    tree.resize(n+1);
    fore(i,0,n-1){
        int x,y; cin>>x>>y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs(1,0,1);
    sort(order.begin(),order.end(),greater<>());
    fore(i,0,n-k) ans+= order[i];
    cout<<ans<<"\n";
    return 0;
}
