#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long int ll;
ll n,l,r;
vector<ll> ans;
bool intersect(ll l1,ll r1, ll l2, ll r2){
    return min(r1,r2)>=max(l1,l2);
}
void solve(ll left,ll right, ll &realIndex){
    ll acum = 0;
    fore(i,1,n+1){
        if(intersect(l,r,realIndex,realIndex+2*(n-i))){
            fore(j,i+1,n+1){
                if(realIndex>=l && realIndex<=r){
                  ans.pb(i);
                }
                realIndex++;
                if(realIndex>=l && realIndex<=r) {
                    ans.pb(j);
                }
                realIndex++;
            }
        }else{
            realIndex += 2*(n-i);

        }
//        realIndex= acum;

    }
    if(l<=realIndex && realIndex<= r){
            ans.pb(1);
    }
}
int main()
{FIN;
    int t; cin>> t;
    while(t--){
         cin>>n>>l>>r;
        ans.clear();
        ll realI=1;
        solve(0,n-1,realI);

        fore(i,0,ans.size()){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";

    }
    return 0;
}
