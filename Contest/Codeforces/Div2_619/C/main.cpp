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
    int t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        ll ans = (n+1)*n/2;
        ll k= (n-m)/(m+1);
        ans -= (k*(k+1)/2)*(m+1);
        ans -= (k+1)*((n-m)%(m+1));
        cout<<ans<<"\n";
    }
    return 0;
}
