#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<int> picked;
        vector<int> nums;
        fore(i,0,n){
            int toPush; cin>>toPush;
            if(toPush%2 == 0 && picked.count(toPush)==0){
                picked.insert(toPush);
                nums.pb(toPush);
            }
        }
        sort(nums.begin(),nums.end());
        int quant =0;
        for(int i = nums.size()-1;i>= 0; i--){
            int num = nums[i];
            while(num%2 == 0){
            //cout<<num<<endl;
                num /=2;
                quant++;
                if(picked.count(num)){
                    break;
                }
            }
        }
        cout<<quant<<"\n";
    }
    return 0;
}
