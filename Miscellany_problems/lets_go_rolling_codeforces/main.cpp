#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int N = 3005;
ii info[N];
ll dp[N][N];
int main()
{FIN;
    int n; cin>>n;
    fore(i,0,n){
        ll a,b; cin>>a>>b;
        info[i]={a,b};
    }
    sort(info,info+n);
//    cout<<"ejjee\n";
    fore(i,0,n){
//        cout<<info[i].ff<< " "<<info[i].ss<<endl;
    }
    dp[0][0]=info[0].ss;
    ll last = dp[0][0];
    for(int i =1; i< n;i++){
        dp[i][i]=last+info[i].ss;
        last = dp[i][i];
        for(int j=0;j<i;j++){
            dp[i][j]=dp[i-1][j] + abs(info[i].ff - info[j].ff);
            last = min(dp[i][j],last);
        }
    }
    ll ans = 9e18;
    for(int i = 0; i<n;i++){
        ans = min(ans, dp[n-1][i]);
//        cout<< i<<" "<<dp[n-1][i]<<endl;
    }
    cout<<ans<<"\n";
    return 0;
}
