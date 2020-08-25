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
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        if(n==2)cout<<"2\n";
        else if(n%2){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }
    }

    return 0;
}
