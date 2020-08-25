#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

bool dist(int n){
    vector<bool> pick(10);
    while(n){
        if(!pick[n%10]){
            pick[n%10]=true;
            n/=10;
        }else{
            return false;
        }
    }
    return true;
}
int main(){FIN;
    int l,r; cin>>l>>r;
    int ans=-1;
    fore(i,l,r+1){
        if(dist(i)){
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
