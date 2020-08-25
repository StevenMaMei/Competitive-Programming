#include <bits/stdc++.h>


using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n,a,b,c,d; cin>>n>>a>>b>>c>>d;
        int l = a-b, r = a+b;
        bool can = false;
        for(int i = c-d; i<= c+d;i++){
            if(i%n == 0 && i/n>=l && i/n <=r){
                can= true;
                break;
            }else if(i%n != 0 && i/n>=l && i/n <=r && (i/n+1)>=l && (i/n+1) <=r){
                can = true;
                break;
            }
        }
        if(can)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
