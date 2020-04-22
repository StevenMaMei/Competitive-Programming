#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main()
{FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        fore(i,0,n){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int i=n%2==0?n/2-1:n/2,j=i+1;
        vector<int> ans;

        while(i>=0 || j<n){
            if(i>=0) ans.pb(a[i--]);            if(j<n) ans.pb(a[j++]);

        }
        fore(i,0,n){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
