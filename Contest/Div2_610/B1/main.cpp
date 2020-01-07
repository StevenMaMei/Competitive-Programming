#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;

int main()
{
    int t; cin>>t;
    while(t--){
        ll n,p,k;cin>>n>>p>>k;
        vector<ll>prices;
        prices.resize(n);
        fore(i,0,n){
            cin>>prices[i];
        }
        sort(prices.begin(),prices.end());
        int maxs= 0;
        fore(j,0,k){
            ll acc =0;
            int ind = 0;
            bool act= false;
            for(int i = j; i<n;i+=k){
                if(acc + prices[i] <= p){
                    acc += prices[i];
                    act = true;
                    ind = i;
                }else{
                    break;
                }
            }

            maxs = max(ind+(act),maxs);
        }
        cout<<maxs<<endl;
    }
    return 0;
}
