#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;
ll INF= 1e18+10;
int const MAXN=3*1e5+10;

ll a[MAXN],b[MAXN];
ll dp[3][MAXN];
int n;
ll calc(int added, int pos){
    ll &ans= dp[added][pos];
    if(ans !=-1)return ans;
    ans = INF;
    if(pos == n)return ans=0;
    fore(x,0,3){
        if(pos == 0 || a[pos]+x != a[pos-1]+added){
            ans = min(ans, calc(x,pos+1)+ b[pos]*x);
        }

    }
    return ans;
}
int main(){FIN;
    int q; cin>>q;
    while(q--){
        cin>>n;
        fore(i,0,n){
            int aa,bb; cin>>aa>>bb;
            a[i]=aa; b[i]=bb;
        }
        fore(i,0,n+1){
            dp[0][i]=dp[1][i]=dp[2][i]=-1;
        }
        cout<<calc(0,0)<<"\n";
    }
    return 0;
}
