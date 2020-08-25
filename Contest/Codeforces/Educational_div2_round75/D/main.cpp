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
typedef pair<ll,ll> ii;
ll n,s;
vector<ii> rang;

bool can (ll mid){
    ll sum = 0;
    vector<ll> v;
    ll cnt = 0;
    fore(i,0,n){
        if(rang[i].ss<mid){
            sum += rang[i].ff;
        }else if(rang[i].ff>=mid){
            sum+= rang[i].ff;
            cnt++;
        }else{
            v.pb(rang[i].ff);
        }
    }

    ll need = max(ll(0),(n+1)/2 -cnt);
    if(sz(v)< need ) return false;

    fore(i,0,sz(v)){
        if(i<sz(v) - need){
            sum += v[i];
        }else{
            sum += mid;
        }
    }
    return sum<= s;
}
int main(){FIN;

    int t; cin>>t;
    while(t--){
        cin>>n>>s;
        rang.clear(); rang.resize(n);

        fore(i,0,n){
            cin>>rang[i].ff>>rang[i].ss;
        }
        sort(rang.begin(),rang.end());
        ll l=0,r=1e9+100;
        while(r-l>1){
            ll mid = (l+r)/2;
            if(can(mid)) l= mid;
            else r= mid;
        }
        cout<<l<<"\n";
    }
    return 0;
}
