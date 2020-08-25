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

class HomeAwayLeague{
    ll mod = ll(1e9)+7;

    ll binpow(ll a, ll b){
        ll ans = 1;
        while(b){
            if(b%2){
                ans *= a;
                ans %= mod;
            }
            a = (a%mod*a%mod)%mod;
            b>>=1;
        }
        return ans;
    }
    ll mult(ll a, ll b){
        return (a%mod*b%mod)%mod;
    }
    ll inv(ll a){
        return binpow(a,mod-2);
    }
    public: int matches(int x){
        vector<ll> fact(500010);
        fact[0]=1;
        fore(i,1,500010){
            fact[i]= mult(ll(i), fact[i-1]);
        }
        vector<ll> derang(500010);
        derang[1]=0;
        derang[2]=1;
        fore(i,3,500010){
            derang[i]= (derang[i-1]%mod+ derang[i-2]%mod)%mod;
            derang[i] = mult(derang[i], ll(i-1));
        }
        ll ans = mult(fact[x/2], derang[x/2]);
        ll comb = mult(fact[x], inv( mult(fact[x/2],fact[x/2]) ) );
        ans = mult(ans,comb);
        return int(ans);
    };
};

int main(){FIN;
    HomeAwayLeague l;
    cout<<l.matches(4);
    return 0;
}
