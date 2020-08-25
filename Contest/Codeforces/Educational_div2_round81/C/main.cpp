#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
const int N = 100010;
int INF = 1e9;
int nxt[N][26];
int main()
{FIN;
    int T; cin>>T;
    while(T--){
        string s,t; cin>>s>>t;
//        memset(nxt,INF,sizeof(nxt));
        fore(i,0,N)fore(j,0,26)nxt[i][j]=INF;
        int ans = 1, pos= 0;
        for(int i = sz(s)-1; i>=0 ; i--){
            fore(j,0,26){
                nxt[i][j] = nxt[i+1][j];
            }
            nxt[i][s[i]-'a'] = i;
        }
        fore(i,0,sz(t)){
            if(pos == sz(s)){
                ans++;
                pos =0 ;
            }
            if(nxt[pos][t[i]-'a'] == INF){
                pos =0;
                ans++;
            }
            if(pos == 0 && nxt[pos][t[i]-'a'] == INF){
                ans = INF; break;
            }
            pos = nxt[pos][t[i]-'a']+1;

        }
        if(ans >= INF )cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
