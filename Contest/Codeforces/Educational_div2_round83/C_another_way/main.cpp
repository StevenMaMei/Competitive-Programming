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
        ll maxK = 1;
        while(maxK*k <= 1e16) maxK *=k;

        bool can = true;
        while(maxK >0 && can){
            int cant = 0;
            fore(i,0,arr.size()){
                if(arr[i] >= maxK){
                    cant++;
                    arr[i] -= maxK;
                }
            }
            maxK /= k;
            if(cant >1) can = false;

        }
        fore(i,0,arr.size()){
            if(arr[i]!= 0){
                can= false; break;
            }
        }
        if(can) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
