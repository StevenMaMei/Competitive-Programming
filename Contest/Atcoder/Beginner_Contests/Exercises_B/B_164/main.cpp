#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;

int main()
{FIN;
    int a,b,c,d; cin>>a>>b>>c>>d;
    bool takaturn= true;
    while(a>0 && c>0){
        if(takaturn){
            c -= b;
        }else{
            a -= d;
        }
        takaturn = !takaturn;
    }
    if(a<=0) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}
