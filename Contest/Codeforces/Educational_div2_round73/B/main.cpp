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
    bool turn = false;
    fore(i,0,n){
        if(i%2==0){
            fore(j,0,n){
                if(j%2==0){
                    cout<<"W";
                }else{
                    cout<<"B";
                }
            }
        }else{
            fore(j,0,n){
                if(j%2==0){
                    cout<<"B";
                }else{
                    cout<<"W";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
