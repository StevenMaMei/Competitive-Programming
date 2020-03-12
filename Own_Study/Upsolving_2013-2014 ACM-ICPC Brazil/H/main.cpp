#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long int ll;
const int SIZE = 350;
const ll mod = 1e6;
#define SIZE 350
#define forn(x,n) for(int x = 0; x < n; ++x)
int NN;
ll a[SIZE][SIZE];
ll res[SIZE][SIZE];
void mul(ll a[SIZE][SIZE], ll b[SIZE][SIZE]){
    ll res[SIZE][SIZE]={{0}};
    forn(i,NN) forn(j,NN) forn(k,NN) {
        res[i][j]+=(a[i][k]*b[k][j])%mod; 
        res[i][j]%= mod;
    }
    forn(i,NN) forn(j,NN) a[i][j]=res[i][j]%=mod;
}
void powmat(ll a[SIZE][SIZE],ll n,ll res[SIZE][SIZE]){
    forn(i,NN) forn (j,NN) res[i][j]=(i==j);
    while(n){
        if(n&1)mul(res,a),n--;
        else mul(a,a),n/=2;
    }
}



int main()
{
    NN =2;

    ll n,k,l;
    cin>>n>>k>>l;
    

    a[0][0] = k%mod;
    a[0][1]= l%mod;
    a[1][0] = 1;
    a[1][1] = 0;
    powmat(a,n/5,res);

    ll ans = (res[0][0])%mod;
    string s = to_string(ans);
    int faltantes = 6 -s.size();
    for(int i = 0; i<faltantes;i++){
        s= "0"+s;
    }
    cout<<s<<endl;


    return 0;
}
