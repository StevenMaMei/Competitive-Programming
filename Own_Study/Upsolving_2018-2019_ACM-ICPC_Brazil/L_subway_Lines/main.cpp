#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i = low;i<n;i++)
using namespace std;
map<int,int> heig;
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
        heig[node] = h;
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
};
int dist(int a,int b,int anc){
    int r = abs(a-anc);
    r+= abs(b-anc);
    r--;
    return r;
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

    int N,Q; cin>>N>>Q;
    vector<vector<int>> tr(N,vector<int>());
    fore(i,0,N-1){
        int U,V; cin>>U>>V;
        U--; V--;
        tr[U].pb(V);
        tr[V].pb(U);
    }
    LCA lc = LCA(tr,0);
    fore(i,0,Q){
        int A,B,C,D; cin>>A>>B>>C>>D;
        A--;B--;C--;D--;
        int X = dist(heig[A],heig[B], heig[lc.lca(A,B)]) + dist(heig[C],heig[D], heig[lc.lca(C,D)]);
        //cout<<heig[C]<<" "<<heig[D]<<" "<<heig[lc.lca(C,D)]<<endl;
        //cout<<dist(heig[C],heig[D], heig[lc.lca(C,D)])<<endl;
        int Y = min(dist(heig[A],heig[C],heig[lc.lca(A,C)]) + dist(heig[B],heig[D],heig[lc.lca(B,D)]) ,dist(heig[A],heig[D],heig[lc.lca(A,D)]) + dist(heig[B],heig[C],heig[lc.lca(B,C)]) );
        //cout<<"X: "<<X<<endl;
        //cout<<"Y: "<<Y<<endl;
        if(Y>X) cout<<0<<'\n';
        else cout<<(X -Y)/2+1<<'\n';
    }
    return 0;
}
