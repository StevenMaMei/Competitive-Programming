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
        acums.resize(n);
        prices.resize(n);
        ll accum = 0;
        fore(i,0,n){
            cin>>prices[i];
            accum += prices[i];
            acums[i] = accum;
        }
        sort(prices.begin(),prices.end());

        int maxs= 0;
        fore(j,0,k){
            ll acc = 0;
            int ind = 0;
            bool act= false;
            int last=-1;
            for(int i = j; i<n;i+=k){
                if(acc + prices[i] <= p){
                        //cout<<"jejej "<<prices[i]<<" " <<j<<endl;
                    acc += prices[i];
                    last = i;
                    act = true;
                    ind = i;
                }else{
                    break;
                }
            }
            if(acc<p && j+1 != k){
                fore(i,0,j){
                    if(acc + prices[i] <=p){
                        acc+= prices[i];
                        ind++;
                    }else{
                        break;
                    }
                }
            }
            if(acc<p ){
               if(last >-1) fore(i,last+1,n){
                   if(acc + prices[i] <=p){
                        acc+= prices[i];
                        ind++;
                    }else{
                        break;
                    }
                }
            }
            ind += act;
            if(j+1==k) ind -=j;
            maxs = max(ind,maxs);

        }
        cout<<maxs<<endl;
    }
    return 0;
}
