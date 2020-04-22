#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int acum = 0;
        fore(i,0,n){
            int x; cin>>x;
            acum +=x;
//        cout<<x<<" x "<<endl;
        }
        cout<<min(m,acum)<<"\n";

    }
    return 0;
}
