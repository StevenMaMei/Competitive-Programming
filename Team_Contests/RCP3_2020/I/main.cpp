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
    vector<int> a(n+1);
    fore(i,1,n+1){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    double ans = 1e9;
    fore(i,1,n+1){
        double f = double(a[i])/i;
        if(f>1){
            cout<<"impossible\n";
            return 0;
        }
        ans = min(ans, f);
    }
    cout<<fixed<<setprecision(9)<<ans<<"\n";
    return 0;
}

