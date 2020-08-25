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
    int T; cin>>T;
    while(T--){
        vector<int> a(4);
        fore(i,0,4)cin>>a[i];
        bool can = false;
        for(int i = 1; i<=15;i++){
//                cout<<"jejje\n";
            int sum = 0;
            for(int j =0; j<=3;j++){
                if( (1<<j)&i ){
                    sum+= a[j];
                }
            }
            if(sum == 0) can=true;
        }
        cout<<(can?"Yes\n": "No\n");
    }
    return 0;
}
