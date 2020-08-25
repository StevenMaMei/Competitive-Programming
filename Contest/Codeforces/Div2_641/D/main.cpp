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
        vector<int> a(n+1);
        bool can = false;
        for(int i =1; i<=n;i++){
            int b; cin>>b;
            if(b<k)a[i]=0;
            else if(b==k){ a[i]=1; can = true;}
            else a[i]=2;
        }
        if (!can){
            cout<<"no\n";continue;
        }
        if(n==1){
            cout <<"yes\n";continue;
        }
        can=false;
        for(int i=1; i<=n;i++){
            for(int j= i+1;j<=n && j-i<=2;j++){
                if(a[i]&&a[j]){
                    can =true; i=n+1; j=n+1;
                }

            }
        }
        if(can){
            cout<<"yes\n";
        }else{
        cout<<"no\n";}
    }
    return 0;
}
