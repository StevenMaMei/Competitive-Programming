#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
void mult(ll a[][2], ll b[][2],ll dim){
    ll ans[dim][dim];
    fore(i,0,2){
        fore(j,0,2){
            ans[i][j]=0;
            fore(k,0,2){
                ans[i][j]+= (a[i][k]*b[k][j]) % mod;
                ans[i][j] %=mod;
            }
        }
    }
    fore(i,0,dim)fore(j,0,dim){
        a[i][j]= ans[i][j];
    }
}
ll matrixpow(ll a[][2],ll n){
    if(n<=2)return n;
    ll ans[2][2]; ans[0][0]= 1; ans[1][1]=1; ans[0][1] = ans[1][0]=0;
    n--;
    while(n){
        if(n&1) mult(ans,a,2);
        mult(a,a,2);
        n>>=1;
    }
    ll retu =  ( (ll(1)*ans[0][0])%mod + (ll(2) * ans[1][0]) %mod )%mod;
    return retu;
}
int main()
{FIN;
    int T; cin>>T;
    while(T--){
        ll n; cin>>n;
        ll a[2][2]; a[0][0]=0; a[0][1]=1; a[1][0]=1; a[1][1]=1;
        cout<<matrixpow(a,n)<<"\n";
    }
    return 0;
}
