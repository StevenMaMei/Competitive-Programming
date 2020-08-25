#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
string bfs(int n){
    if(n==1)return "1";
    vector<string> dp(n);
    dp[1]="1";
    queue<int>q;
    q.push(1);
    while(sz(q)){
        int r = q.front(); q.pop();
        if(r == 0)return dp[r];
        for(int i : {0,1}){
            int new_r=(r*10+i)%n;
            if(dp[new_r].empty()){
                q.push(new_r);
                dp[new_r] = dp[r]+ char('0'+i);
            }
        }
    }

    assert(false);
}
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<bfs(n)<<"\n";
    }
    return 0;
}
