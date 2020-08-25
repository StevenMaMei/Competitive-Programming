#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(long long int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
    int lca_len(int u,int v){
        int p = lca(u,v);
        int ph = height[p];
        int ch1 = height[u];
        int ch2 = height[v];
        int ans = (ch1-ph)+(ch2-ph);

        return ans ;
    }
};

int main()
{FIN;

    int n; cin>>n;
    vector<vector<int>> adj(n);
    fore(i,0,n-1){
        int a,b; cin>>a>>b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    LCA lc =LCA(adj);

    int q; cin>>q;
    while(q--){
        int x,y,a,b,k; cin>>x>>y>>a>>b>>k;
        x--;y--;a--;b--;
        int without = lc.lca_len(a,b);
        int ans = (int)1e9+7;
        if(k%2== without%2 && (k>= without) && (k-without)%2 == 0){
            ans = without;
        }
        int with = lc.lca_len(a,y)+lc.lca_len(x,b)+1;
        if(k%2== with%2 && (k>= with) && (k-with)%2 == 0){
            ans= (ans,with);
        }
         with = lc.lca_len(a,x)+lc.lca_len(y,b)+1;
         if(k%2== with%2 && (k>= with) && (k-with)%2 == 0){
            ans= (ans,with);
        }

        if(ans<= k )cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
