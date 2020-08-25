#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;


int main(){FIN;
    int n; cin>>n;
    double ans = 0;
    fore(i,1,n+1){
        ans += 1.0/double(i);
    }
    cout<<fixed<<setprecision(13)<<ans;
    return 0;
}
