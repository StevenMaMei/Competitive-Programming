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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> nums(1025);
        fore(i,0,n){
            int a; cin>>a;
            nums[a]++;
        }
        int ans=-1;
        fore(i,1,1025){
            bool same=true;
            fore(j,0,1025){
                int aux= j;
                if(nums[j]>0){
                        if((aux^i) <=1024  && nums[(aux^i)] >0){

                        }else{
                            same=false;
                        }
                }
            }


            if(same){
                ans=i; break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
