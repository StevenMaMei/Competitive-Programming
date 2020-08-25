#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
vector<int> a;
int n,k;
bool check(int x, int cur){
    int ans = 0;
    fore(i,0,sz(a)){
        if(!cur){
            ans++;
            cur ^=1;
        }else{
            if(a[i]<=x){
                ans++;
                cur^=1;
            }
        }
    }
    return ans>=k;
}
int binSearch(){
    int lo = 0, hi= 1e9+5;
    while(hi-lo>1){
        int mid = (hi+lo)/2;
        if(check(mid,0) || check(mid,1)){
            hi=mid;
        }else{
            lo=mid;
        }
    }
    return hi;
}
int main(){FIN;
    cin>>n>>k;
    a.resize(n);
    fore(i,0,n){
        cin>>a[i];
    }
    cout<<binSearch()<<"\n";
    return 0;
}
