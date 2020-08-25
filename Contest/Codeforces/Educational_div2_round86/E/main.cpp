#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(ll i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
ll mod = 998244353;
ll add(ll a, ll b){
    return (a+b)%mod;
}
ll sub(ll a,ll b){
    return add(a,mod-b);
}
ll mult(ll a, ll b){
    return (((a+mod)%mod) * ((b+mod)%mod))%mod;
}
ll binpow(ll x,ll y){
    ll ans = 1;
    while(y>0){
        if(y&1) ans= mult(ans,x);
        x = mult(x,x);
        y = y>>1;
    }
    return ans;
}
ll inv(ll a){
    return binpow(a,mod-2);
}
ll fact[200010];
ll C(ll c,ll k){
    return mult(fact[c],inv(mult(fact[k],fact[c-k])));
}
int main()
{FIN;
    ll n,k; cin>>n>>k;
    if(k>=n){
        cout<<0<<"\n";
        return 0;
    }
    ll ans = 0;
    ll signo= 1;
    ll c = n-k;
    fact[0]= 1;
    fore(i,1,200010){
        fact[i]= mult(fact[i-1],i);
    }
    for(ll i = 0; i<=c;i++){
//            cout<<ans<<"\n";
        ll temp = mult(C(c,i),binpow(c-i,n));
        if(signo>0){
           ans = add(ans,temp);
        }else{
            ans = sub(ans,temp);
        }
//        cout<<"jejej\n";
        signo *=-1;
    }
    ans = mult(ans, C(n,c));
    if(k!= 0) ans = mult(ans,2);
    cout<<ans<<"\n";
    return 0;
}
