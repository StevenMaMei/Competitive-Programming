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
    int t; cin>>t;
    while(t--){
        int n,m,k; cin>>n>>m>>k;
        int div = n/k;
        if(div>=m){
            cout<<m<<"\n";
        }else{
            int mx = int(ceil(double(m-div)/double(k-1)));
//            cout<<m-div<<" "<<n-1<<"\n";
            cout<<div-mx<<"\n";
        }
    }
    return 0;
}
