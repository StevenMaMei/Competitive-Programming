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
        vector<ll> acums;
        acums.resize(n);
        prices.resize(n);
        ll accum = 0;
        fore(i,0,n){
            cin>>prices[i];

        }
        sort(prices.begin(),prices.end());
        fore(i,0,n){
            accum += prices[i];
            acums[i] = accum;
        }
        int maxs= 0;
        fore(j,0,k){
            ll acc =(j>0 && j+1<k)?acums[j-1]:0;
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
