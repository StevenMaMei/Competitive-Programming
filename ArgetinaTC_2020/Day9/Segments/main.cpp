#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef pair<int,int> ii;

int main(){FIN;
    int n; cin>>n;
    vector<ii> segments(n);
    fore(i,0,n){
        int a,b; cin>>a>>b;
        if(a>b)swap(a,b);
        segments[i]={a,b};
    }
    sort(segments.begin(), segments.end(),greater<ii>());
    int last = segments[0].ff;
    vector<int> pos;
    pos.pb(last);
    int nails=1;
    fore(i,1,n){
        if(segments[i].ss<last){
            nails++;
            last = segments[i].ff;
            pos.pb(last);
        }
    }
    cout<<nails<<"\n";
    fore(i,0,nails){
        cout<<pos[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
