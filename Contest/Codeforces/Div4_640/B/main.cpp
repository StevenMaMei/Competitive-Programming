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
        int n,k; cin>>n>>k;
        if(n<k){
            cout<<"NO\n";
            continue;
        }
        if(n%2== 0){

            int tempN = n;
            vector<int> ans;
            fore(i,0,k-1){
                tempN -=1;
                ans.pb(1);
            }
            if( (tempN %2 != 0 &&   tempN > 0) ){
                cout<<"YES\n";
                if(tempN != 0)
                    ans.pb(tempN);
                fore(i,0,sz(ans)){
                    cout<<ans[i]<<" ";
                }
                cout<<"\n";
                continue;
            }
            tempN = n;
            ans.clear();
            fore(i,0,k-1){
                tempN -=2;
                ans.pb(2);
            }
            if( tempN%2 == 0 && tempN > 0){
                cout<<"YES\n";
                if(tempN != 0)
                    ans.pb(tempN);
                fore(i,0,sz(ans))cout<<ans[i]<<" ";
                cout<<"\n";
                continue;
            }
            cout<<"NO\n";
        }else{
            if(k%2== 0){
                cout<<"NO\n";
                continue;
            }
            int tempN = n;
            vector<int> ans;
            fore(i,0,k-1){
                tempN -=1;
                ans.pb(1);
            }
            if(( tempN %2 != 0 &&  tempN > 0) ){
                    cout<<"YES\n";
                if(tempN != 0)
                    ans.pb(tempN);
                fore(i,0,sz(ans)){
                    cout<<ans[i]<<" ";
                }
                cout<<"\n";
                continue;
            }
            cout<<"NO\n";
        }

    }
    return 0;
}
