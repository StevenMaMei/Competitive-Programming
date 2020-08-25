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
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> a(n);
        ll tot= 0;
        fore(i,0,n)cin>>a[i],tot+=a[i];

        ll mx = -9e18;
        ll cnt = 0;
        ll mxS= -9e18;
        fore(i,0,n){
            if(cnt<n){
                mxS = max(mxS, mx);
            }

            if(a[i]>=mx+a[i]){
                mx = a[i];
                cnt = 1;
//                cout<<i<<"\n";
            }else{
                cnt++;
                mx+=a[i];
//            if(i==n-1){
//                cout<<mxS<<" "<<cnt<<"jejej\n";
//
//            }
            }
            if(cnt<n){
                mxS = max(mxS, mx);
            }
        }
//        cout<<mxS<<"\n";
        if(tot>mxS){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
