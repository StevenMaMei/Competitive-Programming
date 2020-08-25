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
    if(left == right) return;
//        cout<<left<<" "<< right<<endl;
    if(intersect(l,r,realIndex, realIndex+2*(right-left))){
        fore(i,left+1, right+1){
            if(l <= realIndex && realIndex<r){
                ans.pb(left);
            }
            realIndex++;
            if(l <= realIndex && realIndex<r){
                ans.pb(i);
            }
            realIndex++;
        }
    }else{
        realIndex += 2*(right -left);
    }
    solve(left+1,right,realIndex);
    if(left == 0){
        if(l<=realIndex && realIndex< r){
            ans.pb(left);
        }
            realIndex++;
    }
}
int main()
{FIN;
    int t; cin>> t;
    while(t--){
         cin>>n>>l>>r;
        ans.clear();
        l--;
        ll realI=0;
        solve(0,n-1,realI);

        fore(i,0,ans.size()){
            cout<<ans[i]+1<<" ";
        }
        cout<<"\n";

    }
    return 0;
}
