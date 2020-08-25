#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

bool comp1(ii p1, ii p2){
    if(p1.ss > p2.ss){
        return true;
    }if(p1.ss == p2.ss){
        if(p1.ff> p2.ff){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<ii> pairs(m);
        fore(i,0,m){
            ll a,b; cin>>a>>b;
            pairs[i]={a,b};
        }
        sort(pairs.begin(),pairs.end());
        vector<ll> a(m);
        fore(i,0,m)a[i]=pairs[i].ff;
        vector<ll> preSum(m);
        preSum[m-1]=pairs[m-1].ff;
        for(int i = m-2; i>=0; i--){
            preSum[i] = preSum[i+1] + pairs[i].ff;
        }
        ll ans = 0;
        fore(i,0,m){
            ll curB= pairs[i].ss;
            auto it = upper_bound(a.begin(),a.end(), curB);
            int lo = it-a.begin();

            if(m-lo > n){
                lo = m-n;
            }
//            if(i==0)cout<<lo<<" "<<preSum[lo]<<" jejej \n";
            ll temp = 0;
            if(lo <m){
                temp = preSum[lo];
            }
            if(n-(m-lo) >0){
                int cant = n-(m-lo);
                if(lo<= i){
                    temp +=(cant* pairs[i].ss);
                }else{
                    temp += pairs[i].ff + ((cant-1)* pairs[i].ss);
                }
            }
            ans = max(ans,temp);
        }
        cout<<ans<<"\n";

    }
    return 0;
}
