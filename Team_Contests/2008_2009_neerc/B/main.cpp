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
typedef pair<ll,ll>ii;
int main(){FIN;
    ll f1,a,b,c,m,n; cin>>f1>>a>>b>>c>>m>>n;
    map<ll,ll> mp;
    fore(i,0,m)fore(j,0,n){
        ll k; cin>>k;
        mp[k]++;
    }
    vector<ii>prices(sz(mp));
    vector<ii> stocks;
    prices[0]={f1,0};
    fore(i,1,sz(mp)){
        prices[i]={(a*prices[i-1].ff+b)%c +1, i};
    }
    sort(prices.begin(),prices.end(),greater<ii>());
    for(ii p: mp){
        stocks.pb({p.ss,p.ff});
    }
    sort(stocks.begin(),stocks.end(),greater<ii>());
    cout<<sz(mp)<<"\n";
    vector<ll> ans(sz(mp));
    int currIndx=0;
    for(ii p: stocks){
        ii curPri = prices[currIndx++];
        ans[curPri.ss]= p.ss;
    }
    fore(i,0,sz(mp)){
        if(i+1==sz(mp)){
            cout<<ans[i]<<"\n";
        }else{
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
