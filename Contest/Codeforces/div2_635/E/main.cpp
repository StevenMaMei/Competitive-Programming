#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
typedef long long int ll;
ll mod =  998244353;
char s[30000],t[30000];
int main()
{FIN;
    cin>>(s+1)>>(t+1);
    int n= strlen(s+1),m = strlen(t+1);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    fore(i,m,n+1){
        if(i>m || s[i]== t[m]){
            dp[i][0] =1;
        }
        if(s[i]==t[1]){
            dp[i][1]=1;
        }
    }
    for(int i = n; i>1;i--){
        for(int j = 0; j<=n-i+1;j++){
            if(j+1>m || s[i-1]== t[j+1]){
                dp[i-1][j+1] += dp[i][j];
                dp[i-1][j+1] %=mod;
            }

            if( i>1&&(i-1+j >m || s[i-1]== t[i-1+j])){
                dp[i-1][j] += dp[i][j];
                dp[i-1][j] %= mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i<n+1;i++){
        ans += dp[1][i];
        ans %=mod;
    }
    cout<<ans<<"\n";
    return 0;
}
