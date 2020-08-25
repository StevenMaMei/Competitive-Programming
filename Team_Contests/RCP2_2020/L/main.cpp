#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long int ll;
ll dp[(1<<15)][15];
ll s[(1<<15)];
ll cost(ll x,ll y){
    //x wins
    if(s[x]>s[y])return 0;
    return abs(s[x]-s[y]) *abs(s[x]-s[y]);
}
int main()
{FIN;
    int r; cin>>r;
    memset(dp,-1,sizeof(dp));
    int n = (1<<r);
    fore(i,0,(1<<r)){
        cin>>s[i];
    }
    fore(i,0,n){
        dp[i][0]= 0;
    }
    int rango = 1;
    fore(i,1,r+1){
        fore(j,0,n) dp[j][i]= 9e18;
        for(int j= 0; j<n; j+= 2*rango){
            int l = j, mid = l+rango,r=mid+rango;
            fore(k,l,mid)fore(kk,mid,r){
                dp[k][i]= min(dp[k][i],dp[k][i-1]+dp[kk][i-1]+cost(k,kk));
                dp[kk][i] = min(dp[kk][i],dp[kk][i-1]+dp[k][i-1]+cost(kk,k));
            }
        }
        rango *=2;
    }
    cout<<dp[0][r]<<"\n";
    return 0;
}
