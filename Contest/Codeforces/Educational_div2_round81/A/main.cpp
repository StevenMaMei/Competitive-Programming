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
        int n; cin>>n;
        int op1= n/2+(n%2)/3;
        int op2= n/3+(n%3)/2;
//        cout<<op1<<" "<<op2<<"\n";;
        if(op1>op2){
            int cant1 = (n%2 == 1? n/2-1:n/2);
            if(n%2 == 1){
                for(int i = 0; i<1;i++){
                    cout<<"7";
                }

            }
            for(int i = 0; i<cant1;i++){
                cout<<"1";
            }
        }else{
            int cant7=(n%3 == 1?n/3-1:n/3);
            for(int i = 0; i<cant7;i++){
                cout<<"7";
            }
            if(n%3 ==1){
                for(int i = 0; i<2;i++){
                    cout<<"1";
                }
            }else{
                for(int i = 0; i<(n%3)/2;i++){
                    cout<<"1";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
