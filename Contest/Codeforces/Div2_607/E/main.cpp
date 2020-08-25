#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;
struct node{
    int parent = -1;
    int numOfChilds= 0;
    vector<ii> neighs;
};

vector<node> tree;
vector<pair<ii,int>> edges;
vector<int> visited;

int dfs(int currNode){
    if(visited[currNode]){
        return 0;
    }
    visited[currNode] = true;
    int cant =0;
    for(auto p: tree[currNode].neighs){
        if(!visited[p.ff]){
            tree[p.ff].parent = currNode;
            cant += dfs(p.ff);
        }
    }
    tree[currNode].numOfChilds = cant;
    return cant+1;
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
    int t; cin>>t;
    while (t--){
        tree.clear();
        edges.clear();
        visited.clear();
        int k; cin>>k;

        tree.resize(2*k+1);
        visited.resize(2*k+1);

        fore(i,0,2*k-1){
            int a,b,t; cin>>a>>b>>t;
            tree[a].neighs.pb({b,t});
            tree[b].neighs.pb({a,t});
            edges.pb({{a,b},t});
        }
        dfs(1);
        ll maxim = 0;
        ll minim = 0;
        for(auto p: edges){
            int ca = tree[p.ff.ff].numOfChilds+1;
            int cb =tree[p.ff.ss].numOfChilds+1;
            int pa = tree[p.ff.ff].parent;
            int pb = tree[p.ff.ss].parent;
            if(ca<cb){
              swap(ca,cb);
              swap(pa,pb);
            }
            if(pa >= 0){
                ca = tree[1].numOfChilds+1;
            }
            ca -= cb;
            maxim += ((ll)p.ss)*((ll)min(ca, cb));
           // cout<<p.ss<<" ca: "<< ca<<" cb: "<<cb<<".-. "<<endl;
            minim += (ll)(ca%2)*((ll)p.ss);
        }
        cout<<minim<<" "<<maxim<<endl;


    }
    return 0;
}
