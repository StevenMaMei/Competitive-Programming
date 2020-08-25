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
        int n; cin>>n;
        vector<int> cnt(n+1);
        for(int i = 0; i<n; i++){
            int a; cin>>a;
            cnt[a]++;
        }
        int ans =0;
        int last=0;
        for(int i =1; i<=n;i++){
            ans += cnt[i]/i;
            last+= cnt[i]%i;
            if(last>=i){
                ans+= last/i;
                last = last%i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
