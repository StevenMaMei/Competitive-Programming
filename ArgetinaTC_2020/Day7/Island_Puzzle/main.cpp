#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;


int main(){FIN;
    int n; cin>>n;
    vector<int> a,b;
    fore(i,0,n){
        int c; cin>>c;
        if(c!= 0)
            a.pb(c);
    }
    fore(i,0,n-1){
        a.pb(a[i]);
    }
//    fore(i,0,2*n-2){
//        cout<<a[i]<<" | ";
//    }
//    cout<<"\n";
    fore(i,0,n){
        int c; cin>>c;
        if(c!= 0)
            b.pb(c);
    }
//    fore(i,0,n-1){
//        cout<<b[i]<<" | ";
//    }
//    cout<<"\n";
    bool can=false;
    fore(i,0,2*n-2){
        if(a[i]==b[0]){
//            cout<<i<<" jejej\n";
            bool pos=true;
            if(i+n-2<=2*n-2){
                fore(j,0,n-1){
                    if(a[i+j]!= b[j]){
                        pos=false;
                    }
                }
            }else{
                pos=false;
            }
            can |= pos;
        }

    }
    if(can){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}
