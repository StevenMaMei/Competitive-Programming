#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;

int main(){FIN;
    int n; cin>>n;
    vector<ll> original(n);
    fore(i,0,n){
        cin>>original[i];
    }
    ll originalTotal=0;
    vector<ll> parcialSumsOrig(n);
    parcialSumsOrig[0]=original[0];
    fore(i,1,n){
        parcialSumsOrig[i]=original[i]+parcialSumsOrig[i-1];
        originalTotal+= (i+1)*original[i];
    }

    return 0;
}
