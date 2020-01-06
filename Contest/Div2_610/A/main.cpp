#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int a,b,c,r; cin>>a>>b>>c>>r;
        if(a>b){
            swap(a,b);
        }
        if(a<0){
            b+=abs(a);
            c+= abs(a);
            a+=abs(a);
        }
        int d1 = b-(a);
       // cout<<d1<<endl;
        int d2 =c+r<0?0: min(b,c+r)-max(a,c-r);
        if(d2 <0)d2 = 0;
        //cout<<d2<<endl;

        cout<<max(0,d1-d2)<<endl;

    }

    return 0;
}
