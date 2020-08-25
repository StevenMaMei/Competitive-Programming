#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(ll i=a,thx=b;i<thx;i++)
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long int ll;
ll p[200000];
void build(ll a, ll b){
    fore(i,1,a*b+1){
        p[i]= p[i-1];
        if((i%a)%b != (i%b)%a){
            p[i]++;
        }
    }
}
ll query(ll g,ll a , ll b){
    ll seg = g/(a*b);
    ll rem = g%(a*b);
    return seg*p[a*b]+ p[rem];
}
ll query(ll l, ll r, ll a, ll b){
    return query(r,a,b) - query(l-1,a,b);
}
int main()
{FIN;
    int T;cin>>T;
    while(T--){
        ll a,b,q; cin>>a>>b>>q;
        memset(p,0,sizeof(p));
        build(a,b);
        fore(i,0,q){
            ll l,r; cin>>l>>r;
            cout<<query(l,r,a,b)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
