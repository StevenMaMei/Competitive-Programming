#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll u,v; cin>>u>>v;
    if(u>v || u%2 != v%2) cout<<"-1"<<endl;
    else if(u==0 && v==0) cout<<"0"<<endl;
    else if(u == v){
        cout<<"1"<<endl;
        cout<<u<<endl;
    }
    else{
        ll x = (v-u)/2;
        if((x&u)== 0){
            cout<<"2"<<endl;
            cout<<u+x<<" "<<x<<endl;
        }else{
            cout<<"3"<<endl;
            cout<<u<<" "<<x<<" "<<x<<endl;
        }
    }
    return 0;
}
