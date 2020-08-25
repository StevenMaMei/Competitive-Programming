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

class EllysPalMul{

    int tryPal(int x, int left,int right){
        ll pal = ll(left);
        for(;right>0; right/=10){
            pal = pal*10 + right%10;
        }
        if(pal%ll(x)==0 && pal/ll(x)<=ll(1e9)) return int(pal/x);
        return int(1e9+5);
    }

    public: int getMin(int X){
        int ans =int(1e9+5);
        for(int i = 1; i<= 10000000; i++){
            ans = min(ans, tryPal(X,i,i));
            ans = min(ans, tryPal(X,i,i/10));
        }
        if(ans == int(1e9 +5)) return -1;
        return ans;
    };
};

