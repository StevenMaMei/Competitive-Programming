#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define SZ(s) int(s.size())
using namespace std;
typedef long long int ll;
int main()
{
    int T; cin>>T;
    while(T--){
        ll n,x; cin>>n>>x;
        vector<ll> minor,great;
        fore(i,0,n){
            ll a; cin>>a;
            if(a<x){
                minor.pb(a);
            }else{
                great.pb(a);
            }
        }
        if(SZ(great)==0) {
            cout<<"0"<<"\n";
            continue;
        }
        if(SZ(minor)== 0){
            cout<<SZ(great)<<"\n";
            continue;
        }
        sort(minor.begin(),minor.end(),greater<>());
        sort(great.begin(),great.begin(),greater<>());
        ll cant = ll(great.size());
        ll im=0,ig=0;
        ll sum=minor[0]+great[0];
        while(im < ll(SZ(minor)) && ig < ll(SZ(great)) ){
            if(sum/(im+1+ig+1)>=x){
                cant++;
                im++;
                if(im < SZ(minor)){
                    sum+= minor[im];
                }
            }else{
                ig++;
                if(ig < SZ(great)){
                    sum+= great[ig];
                }
            }
        }
        cout<<cant<<"\n";
    }
    return 0;
}
