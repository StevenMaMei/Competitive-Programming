#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
using namespace std;
typedef long long int ll;
ll n,k;
ll counter(ll x){
    ll p= 2;
    ll cant = 1;
    while(p*x+p-1 <= n){
        cant += p;
        p *=2;
    }
    //p /=2;
    if(p*x <= n && p*x+p-1>n){
       cant += n -(p*x)+1;
    }

    return cant;
}
int main()
{
    cin>>n>>k;
    ll last1 = 1, last2 = 1;
    ll l=1,r=n;
    while(l<r){
        ll mid = (l+r)/2;
        if(mid %2 != 0){
            mid++;
        }
        //cout<<l<<" l r "<<r<<endl;
        //cout<<mid<<endl;
       //cout<<counter(mid) +counter(mid+1)<<" "<<mid<<endl;
        if(counter(mid)+counter(mid+1)>= k){
            last1 = max(mid,last1);
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    //cout<<last1<<endl;
    l=1; r= n;
    while(l<r){
        ll mid = (l+r)/2;
        if(mid %2 == 0){
            mid++;
        }
        if(counter(mid)>= k){
            last2 = max(mid,last2);
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<max(last1,last2)<<endl;
    return 0;
}
