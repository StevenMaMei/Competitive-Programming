#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
int main()
{FIN;
    int T; cin>>T;
    while(T--){
        int n;cin>>n;
        ll ans=0,mi=1e18;
        vector<ll> a,b;
        fore(i,0,n){
            ll x,y; cin>>x>>y;
            a.pb(x); b.pb(y);
        }
        fore(i,0,n){
            int nextI = (i+1)%n;
            ll val= min(a[nextI],b[i]);
            ans += a[nextI] - val;
            mi = min(mi,val);
        }
        ans+= mi;
        cout<<ans<<"\n";
    }
    return 0;
}
