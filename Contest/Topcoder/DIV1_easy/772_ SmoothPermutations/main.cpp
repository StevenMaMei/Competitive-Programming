#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
#define oper mul
#define NEUT 1
using namespace std;
typedef long long ll;
    ll mod;
    ll mul(ll a , ll b){
        return ( (a%mod) * (b%mod) )%mod;
    }
    struct STree { // segment tree for min over integers
        vector<ll> st;ll n;
        STree(ll n): st(4*n+5,NEUT), n(n) {}
        void init(ll k, ll s, ll e, ll *a){
            if(s+1==e){st[k]=a[s];return;}
            ll m=(s+e)/2;
            init(2*k,s,m,a);init(2*k+1,m,e,a);
            st[k]=oper(st[2*k],st[2*k+1]);
        }
        ll query(ll k, ll s, ll e, ll a, ll b){
            if(s>=b||e<=a)return NEUT;
            if(s>=a&&e<=b)return st[k];
            ll m=(s+e)/2;
            return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
        }
        void init(ll *a){init(1,0,n,a);}
        ll query(ll a, ll b){return query(1,0,n,a,b);}
    }; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);
class SmoothPermutations{

    public: long long countPermutations(int T, int M, int MX, int seed, vector <int> prefN, vector <int> prefK, vector <int> prefX){
        mod=M;
        vector<int> A(3 * T);
        A[0] = seed;
        for (int i = 1; i < 3 * T; ++i) {
            A[i] = (A[i - 1] * 1103515245LL + 12345) % 2147483648LL;
        }
        vector<int> N(T), K(T), X(T);
        int LEN = prefN.size();
        for (int i = 0; i < LEN; ++i) {
            N[i] = prefN[i];
            K[i] = prefK[i];
            X[i] = prefX[i];
        }
        for (int i = LEN; i < T; ++i) {
            N[i] = (A[i] % MX) + 1;
            K[i] = (A[T + i] % N[i]) + 1;
            X[i] = (A[2 * T + i] % N[i]) + 1;
        }
        ll fact[200010];
        fact[0]=ll(1);
        fore(i,1,200010){
            fact[i]= ll(i);
        }
        STree rmq(200010);
        rmq.init(fact);
        ll ans = 0;
        for(int i = 0; i<T;i++){
            ll n=ll(N[i]), k=ll(K[i]),x=ll(X[i]);
            if(x>=k){
                ll s= x-k+1, e=x+1;
                ll partAns= rmq.query(s,e);
                partAns= mul(rmq.query(ll(0),n-k+1),partAns);
                ans+= partAns;
            }
        }
        return ans;
    };
};

//int main(){FIN;
//    return 0;
//}
