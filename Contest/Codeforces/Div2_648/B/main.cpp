#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef pair<int,int> ii;

int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n),b(n);
        fore(i,0,n){
            cin>>a[i];
        }
        int ze=0;
        int on=0;
        fore(i,0,n){
            cin>>b[i];
            if(b[i]==1)on=1;
            else ze=1;
        }
        vector<ii> pairs(n);
        fore(i,0,n){
            pairs[i]={a[i],b[i]};

        }
        bool can= (ze>0 && on>0);
        bool ordered=true;
        fore(i,0,n-1){
            if(a[i]>a[i+1])ordered=false;
        }
        can = can || ordered;
        if(can)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
