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
        ll n; cin>>n;
        vector<ll> orgi;
        vector<ll> a;
        fore(i,0,n){
            int x; cin>>x;
            orgi.pb(x);
        }
        fore(i,0,n){
            if(orgi[i]==-1)continue;
            if(i-1>=0 && orgi[i-1]==-1 ){
                a.pb(orgi[i]);
            }else if(i+1<n && orgi[i+1]==-1){
                a.pb(orgi[i]);

            }
        }
        sort(a.begin(),a.end());
        ll ans = 0;
        if(a.size() != 0){
            int mn = a[0], mx=a[a.size()-1];
            ans = (mn+mx)/2;
        }
        fore(i,0,n) if(orgi[i]==-1)orgi[i]=ans;
        ll mx = 0;
        fore(i,0,n-1){
            mx = max(mx,abs(orgi[i]-orgi[i+1]));
        }
        cout<<mx<<" "<<ans<<"\n";
    }
    return 0;
}
