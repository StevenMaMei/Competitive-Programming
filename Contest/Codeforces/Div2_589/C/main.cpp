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
ll mod = (1e9) +7;

ll g(ll y,ll p){
    ll ans=1;
    while(y % (ans*p) ==0){
        ans *= p;
    }
    return ans;
}
ll binpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans = (ans%mod*a%mod)%mod;
        }
        b>>=1;
        a = (a%mod*a%mod)%mod;

    }
    return ans%mod;
}
int main(){FIN;
    ll x,n; cin>>x>>n;
    vector<ll> pr;
    ll cx= x;
    for(ll i = 2; i*i<=cx;i++){
        if(cx%i==0){
            pr.pb(i);
            while(cx%i==0){
                cx/=i;
            }
        }
    }
//    fore(i,0,sz(pr))cout<<pr[i]<<"jeje\n";
    if(cx>1) pr.pb(cx);
    ll ans=1;
    for(ll p:pr){
        ll cur=n;
        ll power=0;
        while(cur ){

            power += cur/p;
            cur /= p;
        }
        ans *= binpow(p,power);
        ans %=mod;
    }
    cout<<ans<<"\n";
    return 0;
}
