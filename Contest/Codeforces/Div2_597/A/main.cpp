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
        int a,b; cin>>a>>b;
        if(__gcd(a,b)==1){
            cout<<"Finite\n";
        }else{
            cout<<"Infinite\n";
        }
    }
    return 0;
}
