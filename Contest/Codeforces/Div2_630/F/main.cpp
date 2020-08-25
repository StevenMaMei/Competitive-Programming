#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define pb push_back
using namespace std;
typedef long long int ll;
ll mod = 998244353;
vector<ll> tree[300005];
ll dp[300005][2];
ll f[300005];
void dfs(ll node, ll parent){
    dp[node][0]=dp[node][1]=f[node]=1;

    for(ll c : tree[node]){
        if(c == parent) continue;
        dfs(c,node);
        dp[node][0] += mod;
        dp[node][0] *= ((2*dp[c][0]+mod)%mod + (2*dp[c][1]+mod)%mod - f[c]+mod)%mod;
        dp[node][0] %=mod;

        dp[node][1] +=mod;
        dp[node][1] *= (2*dp[c][0]%mod + dp[c][1]%mod - f[c]+mod)%mod;
        dp[node][1] %=mod;

        f[node]+=mod;
        f[node] *= (dp[c][0] +  dp[c][1] - f[c]+mod)%mod;
        f[node] %= mod;
    }
}
int main()
{
    int n; cin>>n;
    fore(i,1,n){
        int a,b; cin>>a>>b;
        tree[a].pb(b); tree[b].pb(a);
    }
    dfs(1,0);
    ll ans = dp[1][0]+dp[1][1]-f[1]+mod+mod;
    ans %= mod;
    ans -=1;
    cout<<ans<<endl;
    return 0;
}
