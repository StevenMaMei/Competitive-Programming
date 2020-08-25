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

int main(){FIN;
    int m,n; cin>>m>>n;
    vector<vector<ll>> grid(n,vector<ll>(m));
    vector<ll> hei(n*m);
    fore(i,0,m*n){
        cin>>hei[i];
    }
    sort(hei.begin(),hei.end(),greater<ll>());
    int maxDim= min(m,n);
    ll ans = 0;
    int nextW= 4, nextH= 6;
    int dH=2, dW=3;
    fore(i,0,maxDim*maxDim){
        if(i==1 || i==2){
            ans += 2*hei[i];
        }else if(i==0){
            ans += 4*hei[i];
        }
        else if( i== nextW){
            ans += 2*hei[i];
            nextH = nextW+dH;
            dH++;
        }else if(i== nextH){
            ans += 2*hei[i];
            nextW=nextH+dW;
            dW++;
        }
    }
    int rem = max(m,n)-maxDim;
    int indx = maxDim*maxDim;
    fore(i,0,rem){
        ans += 2*hei[indx];
        indx+=maxDim;
    }
    cout<<ans<<"\n";
    return 0;
}
