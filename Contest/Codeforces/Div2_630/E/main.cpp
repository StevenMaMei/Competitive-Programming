#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll mod = 998244353;
ll epow(ll b, ll e, ll m){
    b %=m;
    ll ans = 1;
    while(e>0){
        if(e&1){
            ans = (ans*b)%m;
        }
        b = (b*b)%m;
        e>>=1;
    }
    return ans;
}
int main()
{
    ll n,m,l,r; cin>>n>>m>>l>>r;
    if((n*m)%2==1){
        cout<<epow(r-l+1,n*m,mod)%mod<<"\n";

    }else{
        ll e = r/2 - (l-1)/2;
        ll o = (r-l+1)-e;
        cout<<(epow(e+o,m*n,mod)+epow(e-o,m*n,mod))*(mod+1)/2%mod<<"\n";
    }
    return 0;
}
