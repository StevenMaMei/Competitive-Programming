#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long int ll;
ll calc(ll l){
    ll ans = 3*l*l+l;
    ans /=2;
    return ans;
}
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll lvl = sqrt(n);
            ll cant = 0;
        for(ll i = lvl; i>=1;i--){
            if(n>= calc(i)){
                cant++;
                n-=calc(i);
                i++;
            }
        }
        cout<<cant<<"\n";
    }
    return 0;
}
