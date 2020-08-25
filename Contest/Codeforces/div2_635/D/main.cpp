#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi; i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
typedef long long int ll;

int main()
{FIN;
    int t; cin>>t;
    while(t--){

        set<ll> r,g,b;
        set<ll,greater<ll>> rr,rg,rb;
        int nr,ng,nb; cin>>nr>>ng>>nb;
        fore(i,0,nr){
            ll a; cin>>a;
            r.insert(a);
            rr.insert(a);
        }
        fore(i,0,ng){
            ll a; cin>>a;
            g.insert(a);
            rg.insert(a);
        }
        fore(i,0,nb){
            ll a; cin>>a;
            b.insert(a);
            rb.insert(a);
        }
        ll ans = 9e18;
        for(ll c: g ){
            vector<ll> y,z;
            if(r.lower_bound(c) != r.end()) y.pb(*r.lower_bound(c));
            if(r.upper_bound(c) != r.end()) y.pb(*r.upper_bound(c));
            if(rr.lower_bound(c) != rr.end()) y.pb(*rr.lower_bound(c));
            if(rr.upper_bound(c) != rr.end()) y.pb(*rr.upper_bound(c));
            if(b.lower_bound(c) != b.end()) z.pb(*b.lower_bound(c));
             if(b.upper_bound(c) != b.end()) z.pb(*b.upper_bound(c));
            if(rb.lower_bound(c) != rb.end()) z.pb(*rb.lower_bound(c));
             if(rb.upper_bound(c) != rb.end()) z.pb(*rb.upper_bound(c));
            fore(i,0,y.size()){
                fore(j,0,z.size()){
//                cout<<z [j]<<" dd\n";
                    ans = min(ans, (c-y[i])*(c-y[i]) + (y[i]-z[j])*(y[i]-z[j]) + (c-z[j])*(c-z[j]));
                }
            }
        }
        for(ll c: r ){
            vector<ll> y,z;
            if(g.lower_bound(c) != g.end()) y.pb(*g.lower_bound(c));
            if(g.upper_bound(c) != g.end()) y.pb(*g.upper_bound(c));
            if(rg.lower_bound(c) != rg.end()) y.pb(*rg.lower_bound(c));
            if(rg.upper_bound(c) != rg.end()) y.pb(*rg.upper_bound(c));
            if(b.lower_bound(c) != b.end()) z.pb(*b.lower_bound(c));
             if(b.upper_bound(c) != b.end()) z.pb(*b.upper_bound(c));
            if(rb.lower_bound(c) != rb.end()) z.pb(*rb.lower_bound(c));
             if(rb.upper_bound(c) != rb.end()) z.pb(*rb.upper_bound(c));
            fore(i,0,y.size()){
                fore(j,0,z.size()){
//                cout<<z [j]<<" dd\n";
                    ans = min(ans, (c-y[i])*(c-y[i]) + (y[i]-z[j])*(y[i]-z[j]) + (c-z[j])*(c-z[j]));
                }
            }
        }
        for(ll c: b ){
            vector<ll> y,z;
            if(g.lower_bound(c) != g.end()) y.pb(*g.lower_bound(c));
            if(g.upper_bound(c) != g.end()) y.pb(*g.upper_bound(c));
            if(rg.lower_bound(c) != rg.end()) y.pb(*rg.lower_bound(c));
            if(rg.upper_bound(c) != rg.end()) y.pb(*rg.upper_bound(c));
            if(r.lower_bound(c) != r.end()) z.pb(*r.lower_bound(c));
             if(r.upper_bound(c) != r.end()) z.pb(*r.upper_bound(c));
            if(rr.lower_bound(c) != rr.end()) z.pb(*rr.lower_bound(c));
             if(rr.upper_bound(c) != rr.end()) z.pb(*rr.upper_bound(c));
            fore(i,0,y.size()){
                fore(j,0,z.size()){
//                cout<<z [j]<<" dd\n";
                    ans = min(ans, (c-y[i])*(c-y[i]) + (y[i]-z[j])*(y[i]-z[j]) + (c-z[j])*(c-z[j]));
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
