#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        vector<ll> p(61);
        ll sum=0;
        fore(i,0,m){
            ll a; cin>>a;
            p[ll(log2(a))]++;
//            cout<<"jejje "<<int(log2(a))<<endl;
            sum+=a;
        }
        if(sum<n){
            cout <<"-1\n";
            continue;
        }
        ll i = 0;
        ll divs = 0;
        while(i<60){
            if( ((ll(1)<<i)&n) != ll(0) ){
                if(p[i]>0){
                    p[i]--;
                }else{
                    while(i<60 && p[i]== 0){
//                        cout<<"jejjCe "<<i<<endl;
                        divs++;
                        i++;
                    }
                    p[i]--;
                    continue;
                }
            }
            p[i+1]+= p[i]/2;
            i++;
        }
        cout<<divs<<"\n";
    }
    return 0;
}
