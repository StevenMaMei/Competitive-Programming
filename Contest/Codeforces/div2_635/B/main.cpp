#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int x,n,m; cin>>x>>n>>m;
        fore(i,0,n){
            if(x>20){
                x/=2; x+=10;

            }
        }
        fore(i,0,m){
            x-=10;
        }
        if(x<=0)cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}
