#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(long long i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;

int main(){FIN;
    ll x0,y0,ax,ay,bx,by,xs,ys,t; cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
    ll limit = (1LL <<62)-1;
    vector<ll> x(1,x0),y(1,y0);
    while((limit-bx) / ax >= x.back() && (limit - by) / ay >= y.back()){
        x.pb(ax*x.back() +bx);
        y.pb(ay*y.back()+ by);
    }
    ll ans = 0;
    fore(i,0,sz(x)){
        fore(j,i,sz(y)){
            ll len = x[j]-x[i] + y[j]-y[i];
            ll distLeft = abs(xs-x[i]) + abs(ys-y[i]);
            ll distRight = abs(xs-x[j]) + abs(ys-y[j]);
            if(len <= t- distLeft || len<= t-distRight) ans = max(ans, j-i+1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
