#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(long long int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
int main()
{FIN;
    int Q; cin>>Q;
    while(Q--){
        ll n,m; cin>>n>>m;
        vector<pair<ll,ii>> track(n+1);
        track[0]= {0,{m,m}};
        fore(i,1,n+1){
            ll t,l,h; cin>>t>>l>>h;
            track[i]={t,{l,h}};
        }
        ii lastInter = {m,m};
        bool can = true;
        fore(i,1,n+1){
            ll dt = track[i].ff - track[i-1].ff;
            ii currInter = track[i].ss;
            ii aux = {lastInter.ff-dt, lastInter.ss+dt};
            ii candidate= {max(aux.ff,currInter.ff),min(aux.ss,currInter.ss)};
            if(candidate.ff > candidate.ss){
                can= false;
                break;
            }else{
                lastInter = candidate;
            }
        }
        if(can)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
