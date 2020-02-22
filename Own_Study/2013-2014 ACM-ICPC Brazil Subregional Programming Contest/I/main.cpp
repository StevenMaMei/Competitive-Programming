#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
using namespace std;

typedef long long int ll;

    ll N,C,T1,T2,n;
    ll holes[2005];
    ll dp[2005];

ll dfs(ll st, ll acum){
    int indx = upper_bound(holes,holes+N,acum)-holes;
    if(indx -st>= n ) return 0;
    if(dp[indx] != -1) return dp[indx];
    ll minx = min(dfs(st,holes[indx]+T1)+T1, dfs(st,holes[indx]+T2)+T2);
    dp[indx] = minx;
    return minx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>C>>T1>>T2;
    fore(i,0,n){
        cin>>holes[i];
    }
    N = 2*n;
    fore(i,n,N) holes[i] = holes[i-n]+C;
    ll res = 1e18;
    fore(i,0,n){
        memset(dp,-1,sizeof(dp));
        res = min(res, dfs(i,holes[i]-1));
        //cout<<res<<endl;
    }
    cout<<res<<endl;
    return 0;
}
