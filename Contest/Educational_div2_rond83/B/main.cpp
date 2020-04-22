#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i =a,thxicesi=b; i<thxicesi;i++)

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        fore(i,0,n){
            cin>>a[i];
        }
        sort(a.begin(),a.end(),greater<>());
        fore(i,0,n){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
