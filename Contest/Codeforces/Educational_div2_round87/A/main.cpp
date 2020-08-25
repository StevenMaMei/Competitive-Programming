#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        if(a<=b){
            cout<<b<<"\n";
            continue;
        }
        if(d>=c){
            cout<<"-1\n";
            continue;
        }
        ll rem = (ll)ceil(double(a-b)/double(c-d));
        ll ans = b+rem*c;
        cout<<ans<<"\n";

    }
    return 0;
}
