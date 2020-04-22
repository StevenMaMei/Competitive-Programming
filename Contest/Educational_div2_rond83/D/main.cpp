#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long int ll;
ll mod = 998244353;

vector<ll> facts;
ll mult(ll a, ll b){return ((a+mod)*(b+mod))%mod;}
ll binpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b & 1) ans = ((ans+mod)* (a+mod))%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll inv(ll a){
    return binpow(a,mod-2);
}
int main()
{FIN;
    ll n,m; cin>>n>>m;

    facts.resize(m+1);
    facts[0]= 1;
    fore(i,1,m+1){
        facts[i]= mult(facts[i-1],ll(i));
    }
    if(n==2) {
        cout<<"0\n";
        return 0;
    }
    ll ans = 1;
    ans = mult(facts[m], inv(mult(facts[n-1],facts[m-n+1])));
    ans = mult(ans, n-2);
    ans = mult(ans, binpow(2,n-3));
    cout<<ans<<"\n";
    return 0;
}
