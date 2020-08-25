#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)

using namespace std;
typedef long long int ll;
ll mod = 998244353;
ll mult(ll a, ll b){
    a += mod; b+= mod;
    ll res = a*b+mod;
    res %=mod;
    return res;
}
ll binpow(ll a, ll b){
    ll res= 1;
    while(b){
        if(b & 1) res = mult(res,a);
        a = mult(a,a);
        b>>=1;
    }
    return res;
}
int main()
{FIN;
    ll d; cin>>d;
    vector<ll> primes;
    for(ll i = 2; i*i<=d;i++){
        if(d%i == 0){
            primes.pb(i);
            while(d%i==0) d/=i;
        }
    }
    if(d >1) primes.pb(d);
    vector<ll> factorials(100,1),modInverseFactorials(100);
    fore(i,1,100){
        factorials[i]= mult(factorials[i-1],i);
    }
    modInverseFactorials[99] = binpow(factorials[99],mod-2);
    for(int i= 98; i>= 0; i--){
        modInverseFactorials[i] = mult(modInverseFactorials[i+1], i+1);
    }
    int q;cin >> q;
    fore(i,0,q){
        ll x,y; cin>>x>>y;
        vector<ll> up,dw;
        for(ll p: primes){
            int cnt = 0;
            while(x%p==0){
                x /= p;
                cnt--;
            }
            while(y%p == 0){
                y/=p;
                cnt++;
            }
            if(cnt>0) up.pb(cnt);
            else if(cnt  <0) dw.pb(-cnt);
        }
        ll ans = 1;
        ans = mult(ans,factorials[accumulate(up.begin(),up.end(),0)]);
        for(int i: up) ans = mult(ans, modInverseFactorials[i]);
        ans = mult(ans, factorials[accumulate(dw.begin(),dw.end(),0)]);
        for(int i: dw) ans = mult(ans,modInverseFactorials[i]);
        cout<<ans<<"\n";
    }
    return 0;
}
