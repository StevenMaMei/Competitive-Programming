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
int n;
vector<int> g[100005];
int main(){FIN;
    cin>>n;
    vector<pair<ii,int>> in;
    fore(i,0,n){
        int a,b,c; cin>>a>>b>>c;
        in.pb({{a,b},c});
    }
    fore(i,0,n){
        pair<ii,int> p = in[i];
        g[p.ff.ss].pb(p.ss);
//        cout<<p.ff.ss<<" "<<p.ss<<"jejej\n";
    }
    for(int i = 0; i<=100000;i++){
        sort(g[i].begin(),g[i].end(),greater<>());
    }
    int ans = 0;
    for(int i = 100000; i>=1; i--){
        int k=0;
        for(int j= 0; j<sz(g[i]);j++){
            if(g[i][j] >0 && sz(g[i-1])>0 && sz(g[i-1])>k ){
//                cout<<g[i][j].ff<<" "<<i<< " "<<g[i-1][k].ff<<" "<<i-1<<"\n";
//                cout<<"jejejej 1 "<<g[i-1][k].ss<<"\n";
                g[i-1][k]--;
//                cout<<"jejejej 2 "<<g[i-1][k].ss<<"\n";
                k++;
                ans++;
            }
        }
    }
    //LOS DOS FORS ESTÁN BIEN
//    for(int i = 0; i<=100000;i++){
//        int k = 0;
//        for(int j = 0; j<sz(g[i]);j++){
////            cout<<i<<" "<<j<<" "<<g[i][j]<<"eejeje\n";
//            if(g[i][j]>0 && sz(g[i+1])>k){
//                g[i+1][k]--;
//                k++;
//                ans++;
//            }
//        }
//    }

    cout<<ans<<"\n";
    return 0;
}
