#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef pair<int,int> ii;
const int MAX = 300005;
int INF = int(1e9);
int dp[MAX],temp[MAX];
vector<ii> W[MAX];
int main(){FIN;
    int n,m; cin>>n>>m;
    vector<pair<int,ii>> edges;
    fore(i,0,m){
        int u,v,w; cin>>u>>v>>w;
        W[w].pb({u,v});
    }

    fore(i,0,MAX){
        fore(j,0,sz(W[i])){
            temp[W[i][j].ss]=0;
        }

        fore(j,0,sz(W[i])){
            int u = W[i][j].ff, v= W[i][j].ss;
            temp[v]= max(temp[v], dp[u]+1);
        }
         fore(j,0,sz(W[i])){
            int u = W[i][j].ff, v= W[i][j].ss;
            dp[v]= max(dp[v], temp[v]);
        }
    }


    int mx = 1;
    fore(i,0,n+1){
//        cout<<i<<" "<<dp[i]<<"\n";
        mx = max(mx,dp[i]);
    }

    cout<<mx<<"\n";
    return 0;
}
