#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;
class ChristmasSongBroadcast{
    struct Edge {
        int u, v, weight;
        bool operator<(const Edge& other) const{
            return weight < other.weight;
        }
    };


    void kruskal(int &cost,int &n, vector<Edge> &edges){
        vector<int> tree_id(n);
        vector<Edge> result;
        for (int i = 0; i < n; i++)
            tree_id[i] = i;

        sort(edges.begin(), edges.end());

        for (Edge e : edges) {
            if (tree_id[e.u] != tree_id[e.v]) {
                cost += e.weight;
                result.push_back(e);

                int old_id = tree_id[e.u], new_id = tree_id[e.v];
                for (int i = 0; i < n; i++) {
                    if (tree_id[i] == old_id)
                        tree_id[i] = new_id;
                }
            }
        }
    }
    int minimW(int x,int A,int B,int maxT,int mod){
        ll ans = (ll(A)*ll(x)+ll(B))%ll(mod);
        if(maxT==1 || ans==0)return ans;
        ll it=1;
        while(x <maxT){
//        cout<<x<<" jejej\n";
           int temp = int(ceil(double(it*ll(mod)-ll(B))/(A)))-x;
            if(temp == 0)break;
            if(x+temp>= maxT) break;
            ll newAns = ( (ll(A)*(ll(x+temp)%ll(mod)))%ll(mod)+ll(B%mod))%mod;
            ans = min(ans, newAns);
            if(ans == 0)break;
            it++;
            x+= temp;
        }
        return int(ans);

    }
    public:  int minimizeCost(int T, vector <int> A, vector <int> B, vector <string> directCost){
        int n=0;
        int cost = 0;
        int mod = 1e9+7;
        vector<Edge> edges;
//                cout<<"jejej"<<"\n";
        n= sz(directCost)+1;
        for(int i = 0; i<sz(directCost);i++){
            for(int j = i+1; j<sz(directCost);j++){
                Edge e; e.u=i; e.v=j; e.weight=int(directCost[i][j]);
                edges.pb(e);
            }
        }
        for(int i = 0; i<sz(A);i++){
            int weight= minimW(0,A[i],B[i],T,mod);
            Edge e={i,n-1,weight};
            edges.pb(e);
        }
        kruskal(cost,n,edges);
        return cost;
    };
};

int main(){FIN;
    ChristmasSongBroadcast c;
    vector<int> A={100, 100, 100, 100};
    vector<int> B= {0, 35, 999999910, 123456789};
    vector<string> d= {"-01z","0-Az", "1A-z","zzz-"};
    cout<<c.minimizeCost(2,A,B,d);
    return 0;
}
