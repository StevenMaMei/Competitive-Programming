#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
class BagPacking{
    public:  int minPay(vector <int> bagsizes){
        int cnt=0;
        vector<int>freq(101);
        for(int b: bagsizes){
            freq[b]++;
        }
        for(int c: freq){
            cnt = max(cnt, c);
        }

        return cnt;
    };
};

int main(){FIN;
    return 0;
}
