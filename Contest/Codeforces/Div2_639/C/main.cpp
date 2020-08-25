#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(ll i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long int ll;
ll mod(ll a, ll b){
    return (a%b+b)%b;
}
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> a(n);
        fore(i,0,n){
            cin>>a[i];
        }
        set<ll> pos;
        bool can= true;
        fore(i,0,n){
            ll k = mod(i+a[mod(i,n)],n);
            if(pos.count(k)==0){
                pos.insert(k);
            }else{
                can= false; break;
            }
        }
        if(can){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
