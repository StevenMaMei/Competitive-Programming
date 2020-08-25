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
        string s; cin>>s;
        string t; cin>>t;
        int n=sz(s);
        bool common=false;
        fore(i,0,n){
            fore(j,0,n){
                if(s[i]==t[j]) common=true;
            }
        }
        if(common){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}
