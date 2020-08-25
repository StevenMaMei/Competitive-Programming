#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(ll i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long ll;

int main(){FIN;
    int T; cin>>T;
    while(T--){
        int h,c,t; cin>>h>>c>>t;
        ll l = 1;
        ll r = 1e7;
        ll mn = 1e9;
        if(h==t){
            cout<<1<<"\n";
            continue;
        }
        while(l<=r){
            ll mid = (l+r)/2;
            double avg = double(mid*h+ (mid-1)*c)/double(mid+mid-1);
            if(avg>=t){
                mn = mid;
                l = mid+1;
            }else r= mid-1;
        }
        double diff = abs(double(t) - double(h+c)/2.0);
        ll ans = 2;
//        cout<<mn<<"\n";
        fore(i,mn,mn+20){
            double avg = abs(double(t) - double(i*h+ (i-1)*c )/ double(i+i-1) );
            if(avg < diff){
                diff = avg;
                ans = i+i-1;
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}
