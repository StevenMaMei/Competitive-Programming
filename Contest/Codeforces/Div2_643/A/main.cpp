#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        ll a,k; cin>>a>>k;
        k--;
        while(k--){
            ll ta= a;
            ll mn=9,mx=0;
            while(ta){
                ll c=ta%10;
                mn=min(c,mn);
                mx= max(c,mx);
                ta/=10;
            }
//            cout<<k+1<<" "<<mn<<" "<<mx<<"\n";
            a = a+mn*mx;
            if(mn == 0)break;
        }
        cout<<a<<"\n";
    }
    return 0;
}
