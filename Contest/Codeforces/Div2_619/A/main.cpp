#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

int main()
{FIN;
    int t; cin>>t;
    while(t--){
        string a,b,c; cin>>a>>b>>c;
        bool can = true;
        fore(i,0,a.size()){
            if(a[i]!= b[i]){
                if(c[i]!=a[i] && c[i]!= b[i]){
                    can = false;break;
                }

            }else{
                if(c[i]!=b[i]){
                    can=false;break;
                }
            }
        }
        cout<<(can?"YES":"NO")<<"\n";

    }
    return 0;
}
