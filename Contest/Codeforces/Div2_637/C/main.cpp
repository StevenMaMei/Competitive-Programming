#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

int main()
{FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int,int> origi;
        set<int> avaible;
        fore(i,0,n){
            int x; cin>>x;
            origi[x]=i;
            avaible.insert(i);
        }
        auto lastIt = avaible.end();
        int pos = 0;
        bool can = true;
        fore(i,1,n+1){
            pos = origi[i];
            if(lastIt == avaible.end()){
                avaible.erase(pos);
                lastIt = avaible.lower_bound(pos+1);
            }else{
                if(pos!= *lastIt){
//                    cout<< i <<" pos "<<pos<<" it "<<*lastIt<<"\n";
                    can=false;break;
                }else{
                    avaible.erase(pos);
                    lastIt = avaible.lower_bound(pos+1);
                }
            }
        }
        if(can)cout<<"Yes\n";
        else cout<<"No\n";

    }
    return 0;
}
