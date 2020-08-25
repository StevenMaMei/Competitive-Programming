#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long ll;
ll n;
ll x,a,y,b,k;
vector<ll> prices;
bool ok(ll cant){
    ll acum=0;
    vector<bool> picked(n+1);
    int indx=n-1;
    cant = min(cant,n);
    for(int i=1; i<=cant;i++){
        if(!picked[i] && i%a==0 && i%b==0 ){
            picked[i]=true;
            acum += prices[indx]*(x+y)/100;
            indx--;
        }
    }
    for(int i=1; i<=cant;i++){
        if(!picked[i] && i%a==0){
            picked[i]=true;
            acum += prices[indx]*(x)/100;
            indx--;
        }
    }
    for(int i=1; i<=cant;i++){
        if(!picked[i] && i%b==0){
            picked[i]=true;
            acum += prices[indx]*(y)/100;
            indx--;
        }
    }
    return acum>=k;
}
int main(){FIN;
    int q; cin>>q;
    while(q--){
        cin>>n;
        prices.clear();prices.resize(n);
        fore(i,0,n)cin>>prices[i];
        sort(prices.begin(),prices.end());
        cin>>x>>a>>y>>b>>k;
        if(x<y){
            swap(x,y);
            swap(a,b);
        }
        ll l=0,r=ll(2*(1e5)+10);
        ll ans=-1;
        while(r-l>1){
            ll mid= (l+r)/2;
//            cout<<mid<<" jeje\n";
            if(ok(mid)){
                ans=mid;
                r=mid;
            }else{
                l=mid;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

