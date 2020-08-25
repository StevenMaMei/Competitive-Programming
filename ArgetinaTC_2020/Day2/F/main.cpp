#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

int mod = int(1e9)+7;

int main(){FIN;
    int n,k; cin>>n>>k;
    vector<vector<int>> dp(k+1,vector<int>(n+1));
    for(int i = 1; i<=n; i++){
        dp[k][i]=1;
    }
    for(int i = k-1; i>=1;i--){
        for(int j = 1; j<=n;j++){
            for(int l =j; l<=n;l+=j){
                dp[i][j] += dp[i+1][l];
                dp[i][j] %=mod;
            }
        }
    }
    int ans =0;
    for(int i =1; i<=n;i++){
        ans = (ans +dp[1][i])%mod;
    }
    cout<<ans<<"\n";
    return 0;
}
