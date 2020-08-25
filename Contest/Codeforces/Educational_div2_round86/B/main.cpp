#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;

int main()
{FIN;
    int T; cin>>T;
    while(T--){
        string t; cin>>t;
        bool k1=true;
        fore(i,0,sz(t)){
            if(t[0]!= t[i]){
                k1=false;
                break;
            }
        }
        if(k1){
            cout<<t<<"\n";continue;
        }
        cout<<t[0];
        fore(i,1,sz(t)){
            if(t[i]== t[i-1]){
                if(t[i]=='0')cout<<"1";
                else cout<<"0";
            }
            cout<<t[i];
        }
        cout<<"\n";
    }
    return 0;
}
