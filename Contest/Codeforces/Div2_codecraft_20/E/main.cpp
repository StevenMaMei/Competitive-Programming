#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(long long int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define M 100005
using namespace std;
typedef long long int ll;
ll a[M], skills[M][7],ind[M];
ll dp[M][(1<<7)];
bool comp (ll x, ll y){
    return a[x]> a[y];
}
int main()
{FIN;
    ll n,p,k; cin>>n>>p>>k;
    fore(i,1,n+1){
        cin>>a[i];
    }
    fore(i,1,n+1)fore(j,0,p){
        cin>>skills[i][j];
    }
    memset(dp,-1,sizeof(dp));

    fore(i,1,n+1)ind[i]=i;
    sort(ind+1,ind+n+1,comp);
    dp[0][0]=0;
    fore(i,1,n+1){
        ll x = ind[i];
        for(ll mask=0; mask<(1<<p);mask++){
            ll ct = 0;
            for(ll j=0; j<p;j++)if((mask&(1<<j))){
                ct++;
            }
            ll z = (i-1)-ct;
            if(z<k){
                if(dp[i-1][mask]!= -1)
                    dp[i][mask]= dp[i-1][mask]+a[x];
            }else{

                if(dp[i-1][mask]!= -1)
                    dp[i][mask]= dp[i-1][mask];
            }
            fore(j,0,p){
                if( (mask&(1<<j)) && dp[i-1][((mask)^(1<<j))]!= -1){
                    ll neww = dp[i-1][((mask)^(1<<j))] + skills[x][j];
                    dp[i][mask] = max(dp[i][mask], neww);
                }
            }
        }
    }
    cout<<dp[n][(1<<p)-1]<<"\n";
    return 0;
}
