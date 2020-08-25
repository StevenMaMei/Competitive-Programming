#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef pair<int,int>ii;
typedef long long int ll;



int main(){FIN;
    int n,m; cin>>n>>m;
    map<int,int> times;
    int acum =0;
    fore(i,0,n){
        int c,t; cin>>c>>t;
        int temp = c*t;
        acum += temp;
        times[acum]=i+1;
    }
    fore(i,0,m){
        int v; cin>>v;
        auto it= times.lower_bound(v);
        cout<<it -> second<<"\n";
    }
    return 0;
}
