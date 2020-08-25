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
    int l=0,r=0;
    fore(i,0,n){
        char a ; cin>>a;
        if(a=='L')l--;
        else r++;
    }
    cout<<r-l+1<<"\n";
    return 0;
}
