#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(long long i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long int ll;
int main()
{FIN;
    ll n,k;cin>>n>>k;
    vector<ll> a(n+1),b(n+1);
    vector<vector<bool>> dp(n+1,vector<bool>(k+1));
    dp[0][0] = true;
    ll tot = 0;
    fore(i,1,n+1){
        cin>>a[i];cin>>b[i];
        tot +=a[i]+b[i];
    }
    fore(i,1,n+1){
        fore(j,0,k){
            dp[i][j] = dp[i-1][(j-a[i]%k+k)%k];
            fore(l,0,min(k-1,a[i])){
                if((a[i]-l+k)%k+b[i]>=k)
                    dp[i][j] = dp[i-1][(j-l+k)%k] || dp[i][j];
            }
        }
    }
    ll ans = 0;
//    cout<<tot<<"\n";
    fore(i,0,k){
        if(dp[n][i]){
            ans = max(ans, (tot-i)/k);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
