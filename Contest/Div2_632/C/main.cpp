#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
using namespace std;
typedef long long int ll;
int main()
{
    int n; cin>>n;
    vector<ll> prefix(n+1);
    fore(i,0,n){
        ll x;cin>>x;
        prefix[i+1]=prefix[i]+x;
    }
    set<ll> s;
    s.insert(0);
    ll ans=0;
    ll i=0,j=0;
    while(i<n){
        while(j<n && !s.count(prefix[j+1])){
            j++;
            s.insert(prefix[j]);
        }
        ans+= j-i;
        s.erase(prefix[i]);
        i++;


    }
    cout<<ans<<"\n";
    return 0;
}
