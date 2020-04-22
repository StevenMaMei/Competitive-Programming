#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i< thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
vector<ll> pl;
bool check(ll pos, ll ma){
    vector<bool> che(pl.size()+1);
    int c=ma;
    while(c--){

        che[pl[pos++]]= true;
    }
    fore(i,1,ma+1){
        if(!che[i])return 0;
    }
    return 1;
}
int main()
{FIN;
    int t ; cin>>t;
    while(t--){

        ll n; cin>>n;
        pl.clear();
        ll ma = -1;
        fore(i,0,n){
            ll a; cin>>a;
            if(ma< a)ma=a;
            pl.pb(a);
        }
        int k = 0;
        vector<ii> ans;
        if(check(0,ma)&& check(ma,n-ma)){
            k++;
            ans.pb({ma,n-ma});
        }

        if(ma*2!= n && check(0,n-ma) && check(n-ma,ma)){
            k++;
            ans.pb({n-ma,ma});
        }
        cout<<k<<"\n";
        fore(i,0,k){
            cout<<ans[i].ff<<" "<<ans[i].ss<<"\n";
        }
    }
    return 0;
}
