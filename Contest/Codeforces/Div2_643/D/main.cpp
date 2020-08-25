#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;

int main()
{FIN;
    int n,s; cin>>n>>s;
    vector<int> strat(n,1);
    strat[n-1] += s - n;
    int l = (strat[n-1]==1?n:n-1);
    int r= strat[n-1];
    bool can=false;
    int k =0;
    for(int i=l+1; i<r;i++){
        if(s-i> l && s-i<r){
            can=true;
            k=i;
            break;
        }
    }
    if(can){
        cout<<"YES\n";
        fore(i,0,n){
            cout<<strat[i]<<" ";
        }
        cout<<"\n";
        cout<<k<<"\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}
