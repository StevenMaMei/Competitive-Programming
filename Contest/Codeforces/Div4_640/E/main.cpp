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
    int t; cin>> t;
    while(t--){
        int n; cin>>n;
        map<int,int> mp;
        vector<int> ve(n);
        set<int> picked;
        fore(i,0,n){
            int a;cin>>a;
            ve[i]= a;
            mp[a]++;
        }
        int ans = 0;
        for(int i = 0; i<n;i++){
            int sum =ve[i];
            for(int j = i+1; j<n;j++){
                sum+= ve[j];
                if(mp.find(sum) != mp.end() && picked.count(sum)==0){
//                    cout<<sum<<"\n";
                    ans += mp[sum];
                    picked.insert(sum);
                }
            }

        }
        cout<<ans<<"\n";
    }
    return 0;
}
