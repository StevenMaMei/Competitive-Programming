#include <bits/stdc++.h>


using namespace std;
typedef long long int ll;
ll INF = 9e18;
int main()
{
    int t; cin>>t;
    while(t--){
        ll x,y,a,b; cin>>x>>y>>a>>b;
        ll ans = INF;
        ans = min((x+y)*a,ans);
        ans = min(abs(x-y)*a+ min(x,y)*b,ans);
        cout<<ans<<"\n";
    }
    return 0;
}
