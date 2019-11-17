#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
typedef long long int ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int n,m;cin>>n>>m;
    vector<ll> sugar;
    ll acm[n+1];
    sugar.resize(n+1);
    sugar[0]=0;
    for(int i =1; i<=n;i++){
        cin>>sugar[i];
    }
    ll antRes=0;
    memset(acm,0,sizeof(acm));
    sort(sugar.begin(),sugar.end());
    for(int i = 1;i <= n;i++){
        int mi= 0;
        if(i<=m){
            mi=i-1;
        }else{
            mi=m;
        }

        ll nvAcm= 0;
        if(i<=m){
            nvAcm=sugar[i];
        }else{
            nvAcm= acm[i-mi]+sugar[i];
        }
        antRes= antRes+nvAcm;
        acm[i]=nvAcm;
        if(i== n)
            cout<<antRes<<endl;
        else
            cout<<antRes<<" ";
    }

    return 0;
}
