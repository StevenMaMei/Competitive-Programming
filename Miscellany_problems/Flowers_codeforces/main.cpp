#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
ll t,k;
ll dp[100005];
ll mod = 1e9+7;
ll acum[100005];
int main()
{FIN;
     cin>>t>>k;
    fore(i,0,100005) dp[0]=1;
    for(int i = 0; i<=100000;i++){
        dp[i+1] =(dp[i+1]+dp[i])%mod;
        if(i+k<=100000){
            dp[i+k] +=dp[i];
            dp[i+k] %=mod;
        }
    }
    for(int i = 1; i<=100000;i++){
        acum[i]= (acum[i-1]+dp[i])%mod;
    }
    while(t--){
        int a,b; cin>>a>>b;
        ll ans = (acum[b]-acum[a-1]+mod)%mod;

        cout<<ans<<"\n";
    }
    return 0;
}
