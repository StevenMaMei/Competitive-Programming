#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(long long i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ll> can(ll cant, ll memo, vector<ii> &pairs){
    ll curCant=0,curMemo=0;
    vector<ll> toR;
    for(ii c: pairs){
        if(curCant == cant){
            break;
        }
        if(curMemo + c.ff<=memo ){
            curCant++;
            curMemo += c.ff;
            toR.pb(c.ss);
        }else{
            break;
        }
    }
    if(curCant==cant && curMemo<=memo) return toR;
    else{
        toR.clear();
        return toR;
    }
    assert(false);
}
int main(){FIN;
    ll n,d; cin>>n>>d;
    ll a,b; cin>>a>>b;
    vector<ii> pairs;
    fore(i,0,n){
        ll x,y; cin>>x>>y;
        pairs.pb({x*a+y*b,i+1});
    }
    sort(pairs.begin(),pairs.end());
    ll lo=0, hi=n+100;
    vector<ll> ans;
    while(hi-lo>1){
        ll med = (lo+hi)/2;
        vector<ll> indx= can(med,d,pairs);
//            cout<<hi<<" "<<lo<<" "<<med<<"\n";
        if(sz(indx)>0){
            ans=indx;
            lo=med;
        }else{
            hi=med;
        }
    }
    cout<<lo<<"\n";
    fore(i,0,sz(ans)){
        cout<<ans[i]<<" ";
    }
    return 0;
}
