#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;


int main(){FIN;
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        vector<int> nums(n);
        fore(i,0,n)cin>>nums[i];
        int acum=0;
        bool can=true;
        sort(nums.begin(),nums.end(),greater<int>());
        fore(i,0,n){
            if(nums[i]<=2048)
                acum+=nums[i];
            if(acum==2048){
                break;
            }else if(acum>2048){
                can=false;
                break;
            }
        }
        if(acum<2048)can=false;
        if(can)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
