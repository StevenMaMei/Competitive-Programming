#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i< thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long int ll;
int main()
{FIN;
    ll n,m; cin>>n>>m;
    vector<ll> sums(m+1);
    vector<ll> lens(m+1);
    ll acum = 0;
    bool can = true;
    fore(i,0,m){
        ll a; cin>>a;
        lens[i+1]=a;
        if(i+a>n) can = false;
    }
    for(int i= m; i>=1;i--){
        acum+= lens[i];
        sums[i]= acum;
    }
    if (acum <n) can = false;

    if(!can){
        cout<<"-1"<<"\n";
    }else{
        fore(i,1,m+1){
//            cout<<"jej "<<i<<" "<<sums[i]<<endl;
            cout<<max(ll(i),n-sums[i]+1)<<" ";
        }
    }

    return 0;
}
