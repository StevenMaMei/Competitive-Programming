#include <bits/stdc++.h>
#define ff first
#define ss second


using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int x,y,a,b; cin>>x>>y>>a>>b;
        int seg = y-x;
        bool can = false;
        if(seg % (a+b)==0){
            can=true;
            seg /= (a+b);
        }
        if(can)cout<<seg<<"\n";
        else cout<<-1<<"\n";

    }
    return 0;
}
