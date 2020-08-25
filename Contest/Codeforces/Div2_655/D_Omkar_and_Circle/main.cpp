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
typedef pair<int, int> ii;


int main(){FIN;
    int n; cin>>n;
    vector<ll>  ori(n);
    fore(i,0,n){
        cin>>ori[i];
    }
    vector<ll> cic;
    fore(i,0,n){
        if(i%2==0)cic.pb(ori[i]);
    }
    fore(i,0,n){
        if(i%2)cic.pb(ori[i]);
    }
    fore(i,0,n){
        cic.pb(cic[i]);
    }
    ll mx = 0;
    vector<ll> preSum(2*n);
    preSum[0]= cic[0];
    fore(i,1,2*n){
        preSum[i] = preSum[i-1]+ cic[i];
    }
    int len = (n+1)/2-1;
    fore(i,0,2*n){
        if(i+len<2*n){
            ll cant = preSum[i+len];
            if(i-1>=0) cant -= preSum[i-1];
            mx = max(mx,cant);
        }
    }
    cout<<mx<<"\n";
    return 0;
}
