#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
ll mod = 1e8;
ll dp[101][101][11][11];
int k1,k2;
ll getans(int f, int h, int remf, int remh){
    if(f+h ==0)return 1;
    if(dp[f][h][remf][remh]!= -1 )return dp[f][h][remf][remh];
    int x= 0;
    if(f>0 && remf>0)x= getans(f-1,h,remf-1,k2);

    int y= 0;
    if(h>0 && remh>0) y = getans(f,h-1,k1,remh-1);

    return dp[f][h][remf][remh] = (x+y)%mod;
}

int main()
{FIN;
    int f,h;cin>>f>>h>>k1>>k2;
    memset(dp,-1,sizeof(dp));
    cout<<getans(f,h,k1,k2)<<"\n";
    return 0;
}
