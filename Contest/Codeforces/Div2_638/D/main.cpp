#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;

int main()
{FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a;
        for(int i = 1; i<=n; i *=2){
            a.pb(i);
            n -=i;
        }
        if(n>0){
            a.pb(n);
            sort(a.begin(),a.end());
        }
        cout<<sz(a)-1<<"\n";
        fore(i,1,sz(a)){
            cout<<a[i]-a[i-1]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
