#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;
ll n,m;
typedef pair<ll,ll> ii;
map<ll,ll> a,b;
vector<ii> aa,bb;

bool can(ll x){
    bool c = true;
    map<ll,ll> mapToComp;
    for(auto p : a){
        ll f = (p.ff+x) % m;
        if(mapToComp.find(f) != mapToComp.end()){
            mapToComp[f] += p.ss;

        }else{
            mapToComp[f] = p.ss;
        }
    }
    for(auto p : mapToComp){
        if(b.find(p.ff) != b.end()){
            if(b[p.ff] != p.ss){
                c = false;
            }
        }else{
            c = false;
        }
    }
    return c;
}
int main()
{
     cin>>n>>m;
    fore(i,0,n){
        ll num; cin>>num;
        a[num]++;
    }
    fore(i,0,n){
        ll num; cin>>num;
        b[num]++;
    }
    for(auto p: a){
        aa.pb({p.ss,p.ff});
    }
    for(auto p: b){
        bb.pb({p.ss,p.ff});
    }
    sort(aa.begin(),aa.begin(),greater<ii>());
    ll x = 1e10;
    fore(i,0,bb.size()){
        if(aa[0].ff <= bb[i].ff){
            //cout<<"jejej"<<endl;
            ll na = aa[0].ss, nb = bb[i].ss;
            ll possibleX= 0;
            if(na < nb){
                possibleX = nb-na;
            }else if( na>nb){
                possibleX = (nb+m) -na;
            }else{
                possibleX = 0;
            }
            if(possibleX < x && can(possibleX)){
                x = possibleX;
            }
        }
    }
    cout<<x<<endl;
    return 0;
}
