#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int cnt = 0;
        char ans[n][m];
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                ans[i][j]= 'B';
            }
        }
        ans[0][0]='W';

        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
               cout<<ans[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
