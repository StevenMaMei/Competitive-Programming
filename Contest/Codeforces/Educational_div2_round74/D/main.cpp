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

int main(){FIN;
    ll n; cin>>n;
    string s; cin>>s;
    ll ans = n*(n-1)/2;
    fore(x,0,2){
        ll cur = 1;
        fore(i,1,n){
            if(s[i]==s[i-1]){
                cur++;
            }else{
                ans -= cur-x;
                cur=1;
            }
        }
        reverse(s.begin(),s.end());
    }
    cout<<ans<<"\n";
    return 0;
}
