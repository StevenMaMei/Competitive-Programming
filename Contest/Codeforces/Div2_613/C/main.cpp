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
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){FIN;
    ll x; cin>>x;
    ll mn =9e18;
    for(ll i = 1; i*i<=x;i++){
//            cout<<i<<"\n";
        if(x%i==0){
            ll b= x/i;
            if(i*b / gcd(i,b)== x)
                mn = min(mn, max(i,b));
        }
    }
    cout<<mn<<" "<<x/mn<<"\n";
    return 0;
}
