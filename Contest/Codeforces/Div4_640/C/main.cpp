#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(ll i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long int ll;
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        ll cuant = k/(n-1) ;
        ll ans = 0;

        if(k<=n-1){
            cout<<k<<"\n";
            continue;
        }
        if(k == cuant*(n-1)){
            cout<<n*cuant-1<<"\n";
        }else{
            int rem = k-(cuant*(n-1));
            cout<<cuant*n+rem<<"\n";
        }

    }
    return 0;
}
