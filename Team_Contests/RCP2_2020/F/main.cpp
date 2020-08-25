#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)

using namespace std;
typedef long long int ll;
int main()
{FIN;
    ll n,c; cin>>n>>c;
    map<ll,ll> bucks;
    vector<ll> vals;
    fore(i,0,n){
        ll x; cin>>x;
        vals.pb(x);
        bucks[x]++;
    }
    sort(vals.begin(),vals.end(),greater<>());
    ll mn = 0;
    fore(i,0,n){
        ll curr= vals[i];
        if(bucks.find(curr)!= bucks.end()&&bucks[curr]>0){
            bucks[curr]--;
            if(bucks[curr]== 0) bucks.erase(bucks.find(curr));
            auto it = bucks.upper_bound(c-curr);
            if(it != bucks.begin() && bucks.size()>0){
                it--;

                bucks[it -> first]--;
                if(bucks[it ->first]== 0)bucks.erase(it);
            }
            mn++;
        }
    }
    cout<<mn<<"\n";

    return 0;
}
