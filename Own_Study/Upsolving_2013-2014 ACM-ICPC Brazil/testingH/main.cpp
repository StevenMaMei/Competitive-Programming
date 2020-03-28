#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define forn(x,n) for(int x = 0; x < n; ++x)
#define SIZE 350

using namespace std;
typedef long long int ll;

int NN;
void mul(ll a[SIZE][SIZE], ll b[SIZE][SIZE]){
    ll res[SIZE][SIZE]={{0}};
    forn(i,NN) forn(j,NN) forn(k,NN) res[i][j]+=a[i][k]*b[k][j];
    forn(i,NN) forn(j,NN) a[i][j]=res[i][j];
}
void powmat(ll a[SIZE][SIZE],ll n,ll res[SIZE][SIZE]){
    forn(i,NN) forn (j,NN) res[i][j]=(i==j);
    while(n){
        if(n&1){
            mul(res,a);
            n--;
        }else{
            mul(a,a);
            n/=2;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    NN =2;

    ll n,k,l;
    cin>>n>>k>>l;
    ll a[SIZE][SIZE];
    ll res[SIZE][SIZE];

    a[0][0] = k;
    a[0][1]= l;
    a[1][0] = 1;
    a[1][1] = 0;

    mul(a,a);
    exit(0);
    powmat(a,n/5-2,res);

    ll ans = res[0][0]*(k*k+l)+res[0][1]*l;
    ans+= res[0][1]*(k*k+l);
    cout<<ans<<endl;


    return 0;
}
