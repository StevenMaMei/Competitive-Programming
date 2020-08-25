#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
#define N 200010
using namespace std;
char s[N];
int ocurr[N][26];
int main()
{FIN;
    cin>>(s+1);
    int q; cin>>q;
    int n = strlen(s+1);
    fore(i,1,n+1){
        fore(j,0,26){
            ocurr[i][j]= ocurr[i-1][j];

        }
        ocurr[i][s[i]-'a']++;
    }

    fore(i,0,q){
        int l,r; cin>>l>>r;
        int cnt = 0;
        fore(j,0,26){
            cnt += (ocurr[r][j]-ocurr[l][j]>0);
        }
        if(cnt >=3 || r-l== 0 || s[l]!= s[r]){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
