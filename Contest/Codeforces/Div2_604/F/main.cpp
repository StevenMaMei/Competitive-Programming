#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low; i<n;i++)
using namespace std;
typedef long long int ll;
const ll MOD = 998244353;

ll fpow(ll a, ll k){
    ll r = 1; ll t = a;
    while(k){
        if(k&1){
            r = r*t %MOD;
        }
        t = t*t%MOD;
        k >>= 1;
    }
    return r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

    string s; cin>>s;
    int n = s.size();
    vector<vector<ll>> dp (n, vector<ll>(n));
    vector<ll> f(n+1);
    for(int i = 0; i < n; i++){
        f[i+1] = f[i];
        f[i+1] += s[i]== '?';
    }
    for(int len = 2; len <= n; len++){
        for(int i = 0; i< n-len+1; i++){
            int j = i+len-1;
            if(s[i] != '('){
                dp[i][j] += dp[i+1][j];
                dp[i][j] %= MOD;
            }
            if(s[j] != ')'){
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
            if(s[i] != '(' && s[j] != ')'){
                dp[i][j] -= dp[i+1][j-1];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
            if(s[i] != ')' && s[j] != '('){
                dp[i][j] += dp[i + 1][j - 1];
                dp[i][j] %= MOD;
                dp[i][j] += fpow((ll)2, (ll)(f[j]- f[i+1]));
                dp[i][j] %= MOD;
            }
        }
    }
    cout<< dp[0][n-1]<<endl;
    return 0;
}
