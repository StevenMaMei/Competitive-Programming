#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;


int main(){FIN;
    int q; cin>>q;
    while(q--){
        int c,m,x; cin>>c>>m>>x;
        int maxT = (c+m+x)/3;
        maxT= min(maxT,c);
        maxT=min(maxT,m);
        cout<<maxT<<"\n";

    }
    return 0;
}
