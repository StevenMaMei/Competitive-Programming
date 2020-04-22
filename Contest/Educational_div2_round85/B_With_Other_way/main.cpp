#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long int ll;
int main()
{FIN;
    int T; cin>>T;
    while(T--){
        ll n,x; cin>>n>>x;
        vector<ll> a;
        fore(i,0,n){
            ll xx; cin>>xx;
            a.pb(xx);
        }
        sort(a.begin(),a.end(),greater<>());
        int cnt=0; ll sum =0;
        for(int i = 0; i< n;i++){
            if(sum + a[i] >=(i+1)*x){
                cnt++;
                sum += a[i];
            }else{
                break;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
