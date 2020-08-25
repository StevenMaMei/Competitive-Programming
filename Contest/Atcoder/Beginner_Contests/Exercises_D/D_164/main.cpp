#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
ll mod = 2019;
int main()
{FIN;
    string s; cin>>s;
    int n= sz(s);
    vector<ll> cnt_suf(mod);
    ll suf = 0;
    ll power10 = 1;
    cnt_suf[suf]++;
    ll ans = 0;
    for(int i = n-1; i>= 0; i--){
        suf = (suf + power10* (s[i]-'0') )%mod;
        power10 = (10 *power10)%mod;
        ans += cnt_suf[suf];
        cnt_suf[suf]++;
    }
    cout<<ans<<"\n";
    return 0;
}
