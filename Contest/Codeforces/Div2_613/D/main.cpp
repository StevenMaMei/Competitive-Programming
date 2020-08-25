#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
vector<int> a;

int solve(vector<int> &c, int bit){
    if(bit<0) return 0;
    vector<int> curr0, curr1;
    for(int i: c){
        if( (i>>bit)&1 ){
            curr1.pb(i);
        }else{
            curr0.pb(i);
        }
    }
    if(sz(curr0) == 0) return solve(curr1,bit-1);
    if(sz(curr1) == 0) return solve(curr0,bit-1);
    return min(solve(curr0,bit-1),solve(curr1,bit-1))+ (1<<bit);
}
int main(){FIN;
    int n;
    cin>>n; a.resize(n);
    fore(i,0,n){
        cin>>a[i];
    }
    cout<<solve(a,29)<<"\n";

    return 0;
}
