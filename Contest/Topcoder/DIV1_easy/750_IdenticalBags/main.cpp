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
class IdenticalBags{
    public:  long long makeBags(vector<long long> candy, long long bagSize){
        ll lo=0,hi=1e18+10;
        while(hi-lo>1){
            ll med = (hi+lo)/2;
            ll cant = 0;
            for(ll c: candy){
                cant += c/med;
                if(cant>=bagSize)break;
            }
            if(cant>=bagSize)lo=med;else hi=med;
        }
        return lo;
    };
};

int main(){FIN;
    return 0;
}
