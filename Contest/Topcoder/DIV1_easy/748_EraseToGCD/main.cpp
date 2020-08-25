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
class EraseToGCD{
    public:  int countWays(vector <int> S, int goal){
        vector<int> old(1001);
        for(int s: S){

            vector<int> newG= old;

            for(int i = 1; i<=1000;i++){
                int g = __gcd(s,i);
                newG[g]+=old[i];
                newG[g]%=mod;
            }

            newG[s]++; newG[s]%=mod;
            old=newG;
        }
        return old[goal];
    };
};

int main(){FIN;
    return 0;
}
