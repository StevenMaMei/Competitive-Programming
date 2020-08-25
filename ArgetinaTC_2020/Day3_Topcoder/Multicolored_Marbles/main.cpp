#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

int mod = int(1e9)+7;
int toggle(int inicial){
    if(inicial == 1){
        return 0;
    }else{
        return 1;
    }
}
int solve(int n, int inicial){
    vector<int> cnt(2);
    int acum = 0;
    for(int i = 0; i<n;i++){
        acum = (acum + cnt[toggle(inicial)]+1)%mod;
        cnt[toggle(inicial)] = (cnt[toggle(inicial)]+cnt[inicial]+1)%mod;
        cnt[inicial] =(cnt[inicial]+1)%mod;
        inicial = toggle(inicial);
//        cout<<acum<<" "<<i<<"\n";
    }
//    cout<<cnt[0]<<" "<<cnt[1]<<"\n";
    return acum;
}
int main(){FIN;
    int n; cin>>n;
//    solve(n,0);
    int ans = max(solve(n,0), solve(n,1));
    cout<<ans<<"\n";
    return 0;
}
