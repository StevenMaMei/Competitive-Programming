#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
ll mod = ll(1e9)+7;
ll calcMin(ll k){
    ll ans =k*(k-1)/2;
    return ans%mod;
}
ll calcMax(ll n,ll k){
    ll ans = n*(n-1)/2;
    ans-= (n-k)*(n-k-1)/2;
    return ans%mod;
}
int main()
{FIN;
    ll n,k; cin>>n>>k;
    ll ans = 0;

    for(ll i = k; i<=n+1;i++){
        ans += (calcMax(n+1,i)-calcMin(i)+1+mod)%mod;
//        cout<<calcMax(n+1,i)<<" i\n";
        ans %= mod;
    }
    cout<<ans<<"\n";
    return 0;
}
