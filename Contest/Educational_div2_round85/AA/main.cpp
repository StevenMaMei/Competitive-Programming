#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T; cin>>T;
    while(T--){
        bool can = true;
        int n; cin>>n;
        int lp=-1,lc=-1;
        for(int i=0;i<n;i++){
            int p,c; cin>>p>>c;
            if(c>p || lp>p || lc>c){
                can = false;
            }else{
                if( (c-lc > p-lp )){
                    can = false;
                }else{
                    lp=p; lc=c;

                }
            }
        }
        if(can) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}
