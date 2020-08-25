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
        int n,m; cin>>n>>m;
        if(n >m)swap(n,m);
        if(n==1){
            cout<<"YES\n";
        }else if(n==2 && m == 2){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
