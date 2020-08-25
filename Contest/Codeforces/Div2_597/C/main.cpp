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
ll mod = 1e9+7;
ll dp[int(1e5)+10];
int main(){FIN;
    string s; cin>>s;
    dp[0]=1;
    int n= sz(s);
    fore(i,0,n){
        if(s[i]=='w' || s[i]=='m'){
            cout<<"0\n";return 0;
        }
    }
    fore(i,0,n){
        dp[i+1]=dp[i];
        if(i-1>=0){
            if(s[i]=='u' && s[i-1]=='u'){
                dp[i+1] += dp[i-1];
                dp[i+1] %= mod;
            }else if(s[i]=='n' && s[i-1]=='n'){
                dp[i+1] += dp[i-1];
                dp[i+1] %=mod;
            }
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
