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
        int cnt = 0;
        vector<int> ans;
        vector<int> divs = {10000,1000,100,10};
        fore(i,0,4){
            if(n>= divs[i]){
                int d = n/divs[i];
                ans.pb(d*divs[i]);
                n-= d*divs[i];
            }
        }
        if(n<10 && n>0){
            ans.pb(n);
        }
        cout<<sz(ans)<<"\n";
        fore(i,0,sz(ans)){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";

    }
    return 0;
}
