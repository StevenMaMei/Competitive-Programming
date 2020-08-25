#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i< thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
int main(){
 int t ; cin>>t;
    while(t--){

        ll n; cin>>n;
        vector<ll> pl;
        fore(i,0,n){
            ll a; cin>>a;
            pl.pb(a);
        }
        vector<ll> sumIzq(n),sumDer(n),difIzq(n),difDer(n);

        vector<bool> nums(n+1);
        ll cnt = 0;
        ll dif=0;
        fore(i,0,n){
            if(!nums[pl[i]]){
                nums[pl[i]]=1;
                dif++;
            }
            difIzq[i]= dif;
            cnt += pl[i];
            sumIzq[i]=cnt;
        }
        dif=0;
        nums.clear();
        nums.resize(n+1);
        for(int i=n-1;i>=0;i--){
            if(!nums[pl[i]]){
                nums[pl[i]]=1;
                dif++;
            }
            difDer[i]= dif;
        }
        fore(i,0,n){

            sumDer[i]= cnt;
            cnt-= pl[i];
        }
        int k = 0;
        vector<ii> ans;
        for(ll i = 0; i<n-1;i++){
            ll n1= i+1;
            ll n2 = n-n1;
            if(n1*(n1+1)/2 == sumIzq[i] && n2*(n2+1)/2 == sumDer[i+1] && difIzq[i]==n1 && difDer[i+1] == n2){
                k++;
                ans.pb({n1,n2});
            }
        }
        cout<<k<<"\n";
        fore(i,0,k){
            cout<<ans[i].ff<<" "<<ans[i].ss<<"\n";
        }

    }
    return 0;
}
