#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2* int(1e6)+5;
ll mod = ll(1e9) +7;
ll dp[N];

int main(){FIN;
    dp[2]=4;
    for(int i = 3; i< N;i++){
        dp[i]= ( (2*dp[i-2])%mod + dp[i-1]%mod) % mod;
        dp[i] = (dp[i] + (i%3==2)*4)%mod;
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<dp[n-1]<<"\n";
    }
    return 0;
}
