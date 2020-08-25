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
    int n,k; cin>>n>>k;
    vector<int> snukes(n);
    fore(i,0,k){
        int d; cin>>d;
        fore(j,0,d){
            int s; cin>>s;
            snukes[s-1]++;
        }
    }
    int cnt = 0;
    fore(i,0,n){
        if(snukes[i]== 0) cnt++;
    }
    cout<<cnt<<"\n";
    return 0;

}
