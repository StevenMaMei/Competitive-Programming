#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n),b(n);
        fore(i,0,n){
            cin>>a[i];
        }
        fore(i,0,n){
            cin>>b[i];
        }
        vector<bool> neg(n),pos(n);
        bool nega=false,post=false;
        fore(i,0,n){
            neg[i]=nega;
            pos[i]=post;
            if(a[i]<0) nega=true;
            if(a[i]>0) post=true;
        }
        bool can=true;
        for(int i = n-1; i>=0 && can;i--){
            int r= b[i]-a[i];
            if(r>0 && !pos[i]) can=false;
            if(r<0 && !neg[i]) can=false;
        }
        if(b[0]!= a[0]) can=false;
        if(can)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}
