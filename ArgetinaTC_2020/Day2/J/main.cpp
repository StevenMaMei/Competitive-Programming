#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;

int main(){FIN;
    ll n,k; cin>>n>>k;
    ll curN= k*(k+1)/2-1;
    curN -= k-2;

    if(curN <n){
        cout<<-1<<"\n";
        return 0;
    }
    if(n==1){
        cout<<0<<"\n";
        return 0;
    }
    if(n<k-1 || n==k){
        cout<<1<<"\n";
        return 0;
    }
    if(n==k-1){
        cout<<2<<"\n";
        return 0;
    }
    ll lo=0,hi=k;
    while(hi-lo>1){
        ll mid = (hi+lo)/2;
        ll cnt = mid*(mid+1)/2;
        if(curN-cnt>= n){
            lo=mid;
        }else{
            hi=mid;
        }
    }
//    cout<<"jeje "<<lo<<"\n";
    cout<<k-1-lo<<"\n";
    return 0;
}
