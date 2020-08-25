#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;

class 	AllEven{
    ll dp[20][(1<<10)];

    ll countGood(ll num){
        ll temp = num;
        int len = 0;
        while(temp){
            temp/=10;
            len++;
        }
        ll ans=0;
        for(int i = 1; i<len;i++){
            for(int j = 1; j<10;j++){
                int k = (1<<j);
                ans += dp[i-1][k];
            }
        }
        string snum= to_string(num);
        //aqui falta lo de igual a longitud L
        if(sz(snum)%2==0){
            int mask = 0;
            fore(i,0,sz(snum)){
                fore(j,0,snum[i]-'0'){
                    if(i==0 && j==0)continue;
                    ans += dp[sz(snum)-i-1][(mask^(1<<j))];
                }
                mask ^= (1<<(snum[i]-'0'));
            }
        }
        return ans;
    }
    public: ll countInRange(ll lo, ll hi){
        dp[0][0]=1;
        for(int i = 1; i<=19;i++){
            for(int j = 0; j<(1<<10);j++){
                for(int k =0;k<10;k++){
                    int num= (1<<k);
                    dp[i][j]+= dp[i-1][(j^num)];
                }
            }
        }
//        cout<<countGood(hi+1)<<"\n";
        return countGood(hi+1)-countGood(lo);

    };
};

//int main(){FIN;
//    AllEven a;
//    cout<<a.countInRange(
//0,10);
//    return 0;
//}
