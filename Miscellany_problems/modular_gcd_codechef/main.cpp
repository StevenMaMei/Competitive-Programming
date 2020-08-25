#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long int ll;
ll mod = 1e9+7;

ll binpow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a)%m;
        }
        a = (a*a)%m;
        b>>=1;
    }
    return ans;
}

ll gcd(ll a, ll b, ll n){
    if(a==b){
        return (binpow(a,n,mod)+binpow(b,n,mod))%mod;
    }

    ll cand = 1;
    ll num = a-b;
    for(ll i = 1; i*i<=num;i++){
        if(num%i == 0){
            ll temp = (binpow(a,n,i) + binpow(b,n,i))%i;
            if(temp == 0)cand = max(cand,i);
            temp = (binpow(a,n,num/i) + binpow(b,n,num/i))%(num/i);
            if(temp == 0)cand = max(cand,num/i);
        }
    }
    return cand%mod;
}
int main()
{FIN;
    int T; cin>>T;
    while(T--){
        ll a,b,n; cin>>a>>b>>n;
        cout<<gcd(a,b,n)<<"\n";
    }
    return 0;
}
