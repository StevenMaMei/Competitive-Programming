#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i = low;i<n;i++)

using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

    int t; cin>> t;
    while(t--){
        ll n; cin>>n;
        set<ll> picked;
        vector<ll> vals;

        ll s = (ll)sqrt(n);
        for(int i = 0; i<= s; i++ ){
            vals.pb(i);
        }
        for(int i = 1; i<= s; i++ ){
            vals.pb(n/i);
        }
        sort(begin(vals),end(vals));
        vals.erase(unique(vals.begin(),vals.end()),vals.end());
        cout<<vals.size()<<endl;
        int cant = vals.size();
        for(int i = 0; i<cant; i++){
            if(i+1 == cant){
                cout<<vals[i]<<endl;
            }else{
                cout<<vals[i]<<" ";
            }
        }
    }
    return 0;
}
