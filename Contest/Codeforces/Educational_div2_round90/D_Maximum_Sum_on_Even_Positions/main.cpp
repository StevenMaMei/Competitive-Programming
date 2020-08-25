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

pair<ii,int> mx = {{0,0},0};
vector<ll> a;
ll solve(){
    vector<vector<ll>> dp(sz(a)+1, vector<ll>(3));
    for(int i = 0; i<sz(a);i++){
        dp[i+1][0]= max(dp[i+1][0],dp[i][0] + (i%2==0?a[i]:0));
        if(i+2<=sz(a)){
            dp[i+2][1] = max(dp[i+2][1], max(dp[i][0],dp[i][1]) + (i%2==0?a[i+1]:a[i]) );
        }
        dp[i+1][2] = max(dp[i+1][2], max(dp[i][0],max(dp[i][1],dp[i][2])) + (i%2==0?a[i]:0));
    }
    return max({dp[sz(a)][0], dp[sz(a)][1], dp[sz(a)][2] });
}
int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        a.clear();
        a.resize(n);
        fore(i,0,n){
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    return 0;
}
