#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        int x,y,x1,y1,x2,y2; cin>>x>>y>>x1>>y1>>x2>>y2;
        if(x1-x2 == 0 && (a!= 0 || b != 0)){
            cout<<"No"<<"\n";
        }else if(y1-y2 == 0 && (c!= 0 || d!= 0)){
            cout<<"No"<<"\n";
        }else{
            if((b-a+x) >x2 || (b-a+x)<x1){
                cout<<"No"<<"\n";
            }else if( (d-c+y) <y1 || (d-c+y) >y2){
                cout<<"No"<<"\n";
            }else{
                cout<<"Yes"<<"\n";

            }
        }

    }
    return 0;
}
