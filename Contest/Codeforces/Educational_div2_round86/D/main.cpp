#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)

using namespace std;

int main()
{FIN;
    int n,k; cin>>n>>k;
    vector<int> a(n),c(k+1);
    fore(i,0,n){
        cin>>a[i];
    }
    fore(i,1,k+1){
        cin>>c[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    int ans  =0;
    for(int i = k, g =0; i>=1;i--){
        while(g<n && a[g]==i)g++;
        ans = max(ans, (g+c[i]-1)/c[i]);
    }
    cout<<ans<<"\n";
    vector<vector<int>> t(ans);
    fore(i,0,n){
        t[i%ans].pb(a[i]);
    }
    fore(i,0,ans){
        cout<<t[i].size()<<" ";
        fore(j,0,int(t[i].size())){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
