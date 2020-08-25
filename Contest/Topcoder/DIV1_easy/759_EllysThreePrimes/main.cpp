#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class 	EllysThreePrimes{
    public:  vector <int> getPrimes(vector <int> sums){
        vector<int> lp(100005);
        for(int i = 2; i<100000;i++){
            if(lp[i]==0){
                for(int j = i; j<100000;j+=i){
                    lp[j]=i;
                }
            }
        }
        vector<int> primes;
        for(int i = 10000; i<100000;i++){
            if(lp[i]==i){
                primes.pb(i);
            }
        }
        vector<int> ans;
        for(int i = 0; i<sz(primes);i++){
            for(int j = i+1; j<sz(primes);j++){
                int d5 = sums[4] - (primes[i]/10000)%10 - (primes[j]/10000)%10;
                if(d5 <=0 || d5>=10)continue;
                int d4 = sums[3] - (primes[i]/1000)%10 -(primes[j]/1000)%10;
                if(d4<0 || d4>=10)continue;
                int d3 = sums[2] - (primes[i]/100)%10 - (primes[j]/100)%10;
                if(d3<0 || d3>=10)continue;
                int d2 = sums[1] - (primes[i]/10)%10 - (primes[j]/10)%10;
                if(d2<0 || d2>=10)continue;
                int d1 = sums[0] - (primes[i])%10 - (primes[j])%10;
                if(d1<0 || d1>=10)continue;
                int num = d5*10000+ d4*1000 + d3* 100 +d2*10+d1;
                if(lp[num]==num && primes[i]!= num && primes[j]!= num){
                    ans.pb(primes[i]);
                    ans.pb(primes[j]);
                    ans.pb(num);
                    return ans;
                }
            }
        }
        return ans;
    };
};

int main(){FIN;
    return 0;
}
