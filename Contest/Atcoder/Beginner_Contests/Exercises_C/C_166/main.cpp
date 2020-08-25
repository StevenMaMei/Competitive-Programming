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
    int n,m; cin>>n>>m;
    vector<int> heights(n+1);
    fore(i,1,n+1){
        cin>>heights[i];
    }
    vector<int> neighs(n+1);
    fore(i,0,m){
        int a,b; cin>>a>>b;
        neighs[a] = max(neighs[a],heights[b]);
        neighs[b] = max(neighs[b], heights[a]);
    }
    int cnt = 0;
    fore(i,1,n+1){
        if(neighs[i]< heights[i]){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;

}
