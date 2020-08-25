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
        int n, k; cin>>n>>k;
        set<int> diff;
        vector<int> a(n);
        vector<int> f;
        fore(i,0,n){
            cin>>a[i];
            if(diff.count(a[i])==0){
                diff.insert(a[i]);
                f.pb(a[i]);
            }
        }
        while(sz(f)<k){
            f.pb(1);
        }
        if(sz(diff)<=k){
            cout<<k*n<<"\n";
            fore(i,0,n){
                fore(j,0,k){
                    cout<<f[j]<<" ";
                }
            }
            cout<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}
