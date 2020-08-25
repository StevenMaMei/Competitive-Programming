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

int main(){FIN;
    int n; cin>>n;
    vector<ii> pairs;
    fore(i,0,n){
        int a,b; cin>>a>>b;
        pairs.pb({a,b});
    }
    sort(pairs.begin(),pairs.end(),greater<ii>());
    int cnt = 1;
    int last = pairs[0].ff;
    fore(i,1,n){
        if(pairs[i].ss < last){
            last = pairs[i].ff;
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
