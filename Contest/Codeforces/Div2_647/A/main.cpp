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
    int t; cin>>t;
    while(t--){
        ll a,b; cin>>a>>b;
        if(a>b)swap(a,b);
        ll ans=0;
        while(a<b){
            a<<=1;
            ans++;
        }
        if(a>b){
            cout<<"-1\n";
        }else{
            ll to= ans/3;
            if(ans%3)to++;
            cout<<to<<"\n";
        }

    }
    return 0;
}
