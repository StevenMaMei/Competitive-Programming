#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(ll i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;

int main(){FIN;
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
//        cout<<"jjej\n";
        ll ans= 0;
        if(n==1){
            cout<<"1\n";continue;
        }
        while(n){
            ans+= n;
            n/=2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
