#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
const int N = 3*(1e5)+10;
int INF =1e9;
int l[N],r[N],dp[N];

int main(){FIN;
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        fore(i,0,n+1){
            l[i]=INF;
            r[i]=-INF;
            dp[i]=0;
        }
        vector<int> v;
        fore(i,0,n){
            int a; cin>>a;
            a--;
            l[a]=min(l[a],i);
            r[a]=max(r[a],i);
            v.pb(a);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int ans = 1e9;
        for(int i = sz(v)-1; i>= 0; i--){
            if(i+1 == sz(v) || r[v[i]] > l[v[i+1]]) {
                dp[i]=1;
            }else{
                dp[i]=dp[i+1]+1;
            }
            ans = min(ans, sz(v)- dp[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
