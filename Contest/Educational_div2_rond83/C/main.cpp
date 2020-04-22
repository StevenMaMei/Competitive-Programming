#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long int ll;
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        vector<ll> arr;
        ll n,k; cin>>n>>k;
        fore(i,0,n){
            ll a; cin>>a;
            if(a!= 0){
                arr.pb(a);
            }
        }
        vector<bool> powPicked(100);
        bool can = true;
        fore(i,0,arr.size()){
            ll currN = arr[i];
            int cnt=0;
            while(currN >= 1){
                if(currN == 1 || currN % k != 0){
                    if(powPicked[cnt]){
                        can =false; break;
                    }else{
                        powPicked[cnt]=1;
                    }
                    currN--;
                }else{
                    cnt++;
                    currN /= k;
                }
            }
        }
        if(can) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
