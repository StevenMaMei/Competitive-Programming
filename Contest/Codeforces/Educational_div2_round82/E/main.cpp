#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int INF = int(1e9);
string s,t;
bool can(string &a, string &b, vector<vector<int>> &nxt){
    vector<vector<int>> dp(SZ(a)+1, vector<int>(SZ(b)+1,INF));
    dp[0][0]=0;
    fore(i,0,SZ(a)+1)fore(j,0,SZ(b)+1){
        if(dp[i][j]>SZ(s))continue;

        int len = dp[i][j];
        if(i+1<= SZ(a) && nxt[len][a[i]]<INF){
            dp[i+1][j]= min(dp[i+1][j],nxt[len][a[i]]+1);
        }
        if(j+1 <= SZ(b) && nxt[len][b[j]] <INF){
            dp[i][j+1] = min(dp[i][j+1], nxt[len][b[j]]+1);
        }
    }
    return dp[SZ(a)][SZ(b)]<INF;
}
int main()
{FIN;
    int T; cin>>T;
    while(T--){
        cin>>s>>t;
        for(auto &c: s){
            c-='a';
        }
        for(auto &c: t){
            c-='a';
        }
        vector<vector<int>> nxt(SZ(s)+1,vector<int>(26,INF));
//        cout<<"jejej"<<endl;
        for(int i = SZ(s)-1;i>=0;i--){
            nxt[i] = nxt[i+1];
            nxt[i][s[i]]=i;
        }
        bool cann= false;
        fore(i,0,SZ(t)){
            string a = t.substr(0,i), b= t.substr(i,SZ(t));

            if(can(a,b,nxt)){
                cann = true;break;
            }
        }
        if(cann)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
