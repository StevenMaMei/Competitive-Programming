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

int main(){FIN;
    int n,m; cin>>n>>m;
    vector<vector<int>> edges(n+1);
    vector<ii> as;
    fore(i,0,m){
        int a,b; cin>>a>>b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    fore(i,1,n+1){
        int a; cin>>a;
        as.pb({a,i});
    }
    sort(as.begin(),as.end());
    bool can=true;
    vector<int> ans;
    vector<set<int>> track(n+1);
    fore(i,0,n){
        int currN= as[i].ss;
        int toAsign= as[i].ff;
        if(track[currN].lower_bound(toAsign)== track[currN].end() && sz(track[currN])==toAsign-1){
            ans.pb(currN);
            for(int vn: edges[currN]){
                track[vn].insert(toAsign);
            }
        }else{
            can=false;
            break;
        }
    }
    if(can){
        fore(i,0,sz(ans)){
            cout<<ans[i]<<" ";
        }
    }else{
        cout<<"-1";
    }
        cout<<"\n";
    return 0;
}
