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
    int T; cin>>T;
    while(T--){
        int n,pos,k; cin>>n>>pos>>k;
        vector<int> a(n);
        fore(i,0,n)cin>>a[i];
        int control = min(pos-1,k);
        int remain = n-pos+1;
        int ans = -1;
        fore(i,0,control+1){
            int currCase = 1e9;
            for(int j= 0; j<= (pos-1)-control; j++){
                currCase = min(currCase, max(a[i+j],a[i+j+(n-pos)]) );
            }
            ans = max(ans, currCase);
        }
        cout<<ans<<"\n";

    }
    return 0;
}
