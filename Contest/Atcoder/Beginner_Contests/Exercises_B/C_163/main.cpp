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
    int n; cin>>n;
    vector<int> a(n+1);
    fore(i,0,n-1){
        int b; cin>>b;
        a[b]++;
    }
    fore(i,1,1+n){
        cout<<a[i]<<"\n";
    }
    return 0;
}
