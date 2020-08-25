#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long int ll;
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> a(n);
        fore(i,0,n){
            cin>>a[i];
        }
        ll ans = 0;
        fore(i,1,n){
            ll chx = a[i-1] - a[i];
            if(chx >0){
                ll cnt=0;
                while(chx){
                    cnt++;
                    chx >>=1;
                }
                a[i]=a[i-1];
                ans=max(ans,cnt);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
