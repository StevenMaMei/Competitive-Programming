#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
using namespace std;
typedef long long int ll;

int main()
{
    int t; cin>>t;
    while(t--){
        ll n,p,k;cin>>n>>p>>k;
        vector<ll>prices;
        vector<ll> acums;
        prices.resize(n);
        ll accum = 0;
        for(int i = 0; i<n;i++){
            cin>>prices[i];
        }
        sort(prices.begin(),prices.end());

        int maxs= 0;
        for(int j=0;j<=k;j++){
            ll acc = accum;
            if(acc >p) break;
            int ind = j;
            for(int i = j+k-1; i<n;i+=k){
                if(acc + prices[i] <= p){
                        //cout<<"jejej "<<prices[i]<<" " <<j<<endl;
                    acc += prices[i];
                    ind += k;
                }else{
                    break;
                }
            }
            accum += prices[j];
           // ind += act;
            //if(j+1<k) ind -=j;
            maxs = max(ind,maxs);

        }
        cout<<maxs<<endl;
    }
    return 0;
}
