#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
const int N = (1e6)+10;
int dp[N];
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i = 0; i<N;i++)dp[i]=1;
        vector<int> a(n+1);
        fore(i,1,n+1){
            cin>>a[i];
        }

        int ans = 0;
        for(int i = 1; i<=n;i++){
            ans = max(dp[i],ans);
            for(int j = i+i; j<=n;j+=i){
                if(a[j]>a[i])
                dp[j]= max(dp[j], dp[i]+1);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
