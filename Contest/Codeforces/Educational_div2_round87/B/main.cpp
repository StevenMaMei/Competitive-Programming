#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;

int main()
{FIN;
    int t; cin>>t;
    while(t--){
        string s; cin>>s;

        int n = sz(s);
        vector<vector<int>> suf(n,vector<int>(4)),pre(n,vector<int>(4));
        fore(i,0,n)fore(j,0,4){
            suf[i][j]=-1;
            pre[i][j]=-1;
        }
        fore(i,0,n){
            if(i>0){
                pre[i]=pre[i-1];
            }
            pre[i][s[i]-'0'] = i;
        }
        for(int i =n-1;i>=0;i--){
            if(i<n-1){
                suf[i] = suf[i+1];
            }
            suf[i][s[i]-'0'] = i;
        }
        int mnlen = 1e9;

        for(int i = 0;i<n;i++){
            int curr = s[i]-'0';
            vector<int> miss;
            for(int j=1; j<=3;j++){
                if(curr != j){
                    miss.pb(j);
                }
            }

            if(pre[i][miss[0]] !=-1 && pre[i][miss[1]] != -1){
                int len = i - min(pre[i][miss[0]],pre[i][miss[1]])+1;
//                cout<<i<<" "<<miss[0]<<" "<<pre[i][miss[0]]<<"\n";
                mnlen = min(mnlen, len);
            }
            if(suf[i][miss[0]] !=-1 && suf[i][miss[1]] != -1){
                int len =  max(suf[i][miss[0]],suf[i][miss[1]] )-i +1;
                mnlen = min(mnlen, len);
            }
        }
        if(mnlen==1e9){
            cout<<"0\n";
            continue;
        }
        cout<<mnlen<<"\n";
    }
    return 0;
}
