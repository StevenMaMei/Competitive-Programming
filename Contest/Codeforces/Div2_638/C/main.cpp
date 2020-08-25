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
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<char> s(n);
        fore(i,0,n){
            cin>>s[i];
        }
        sort(s.begin(),s.end());
        if(s[0]!= s[k-1]){
            cout<<s[k-1]<<"\n";
            continue;
        }
        cout<<s[0];
        if(s[k]!=s[n-1]){
            for(int i = k; i<n;i++){
                cout<<s[i];
            }
        }else{
            for(int i = 0; i<(n-k+k-1)/k;i++){
                cout<<s[k];
            }
        }
        cout<<"\n";
    }
    return 0;
}
