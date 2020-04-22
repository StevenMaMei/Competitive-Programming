#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi; i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long int ll;
ll sq(ll x){return x*x;}
void getmin(vector<ll> &a,vector<ll> &b, vector<ll> &c, ll &ans){
    for(ll x : a){
        auto y = lower_bound(b.begin(), b.end(),x);
        auto z = upper_bound(c.begin(),c.end(),x);
        if(y== b.end() || z == c.begin()) continue;
        z--;
        ans = min(ans,sq(x-*y)+sq(*y-*z)+sq(*z-x) );

    }
}
int main()
{FIN;
    int t; cin>>t;
    while(t--){

        vector<ll> r,g,b;

        int nr,ng,nb; cin>>nr>>ng>>nb;
        fore(i,0,nr){
            ll a; cin>>a;
            r.pb(a);
        }
        fore(i,0,ng){
            ll a; cin>>a;
            g.pb(a);
        }
        fore(i,0,nb){
            ll a; cin>>a;
            b.pb(a);
        }
        ll ans = 9e18;
        sort(r.begin(),r.end());
        sort(g.begin(),g.end());
        sort(b.begin(),b.end());
        getmin(r,g,b,ans);getmin(r,b,g,ans);
        getmin(g,r,b,ans);getmin(g,b,r,ans);
        getmin(b,r,g,ans);getmin(b,g,r,ans);
        cout<<ans<<"\n";
    }
    return 0;
}
